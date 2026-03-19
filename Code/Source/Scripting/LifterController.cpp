/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root
 * of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "LifterController.h"
#include <AzCore/Component/Component.h>
#include <AzCore/Debug/Trace.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/string/string.h>
#include <ROS2/Frame/ROS2FrameComponent.h>
#include <ROS2Controllers/Manipulation/MotorizedJoints/PidMotorControllerComponent.h>
#include <ROS2/ROS2Bus.h>
#include <std_msgs/msg/detail/bool__struct.hpp>

namespace OTTORobots
{
    void LifterControllerComponent::Reflect(AZ::ReflectContext* context)
    {
        AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context);
        if (serialize)
        {
            serialize->Class<LifterControllerComponent, AZ::Component>()
                ->Version(1)
                ->Field("TopicConfiguration", &LifterControllerComponent::m_topicConfiguration)
                ->Field("MotorSetpoint", &LifterControllerComponent::m_setpoint);
            if (AZ::EditContext* editContext = serialize->GetEditContext())
            {
                editContext->Class<LifterControllerComponent>("LifterControllerComponent", "LifterControllerComponent")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "OTTORobots")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"))
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default, &LifterControllerComponent::m_topicConfiguration, "Topic configuration", "")
                    ->DataElement(AZ::Edit::UIHandlers::Default, &LifterControllerComponent::m_setpoint, "Extended motor setpoint", "")
                    ->Attribute(AZ::Edit::Attributes::Min, 0.);
            }
        }
    }

    void LifterControllerComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        required.push_back(AZ_CRC("ROS2Frame"));
    }

    void LifterControllerComponent::Activate()
    {
        auto* ros2Interface = ROS2::ROS2Interface::Get();
        AZ_Assert(ros2Interface, "ROS2 interface not available");

        AZStd::string namespaceFromFrame;
        ROS2::ROS2FrameComponentBus::EventResult(namespaceFromFrame, m_entity->GetId(), &ROS2::ROS2FrameComponentRequests::GetNamespace);

        AZStd::string namespacedTopicName;
        ROS2::ROS2NamesRequestBus::BroadcastResult(
            namespacedTopicName, &ROS2::ROS2NamesRequestBus::Events::GetNamespacedName, namespaceFromFrame, m_topicConfiguration.m_topic);

        m_lifterTopicSubscriber = ros2Interface->GetNode()->create_subscription<std_msgs::msg::Bool>(
            namespacedTopicName.c_str(),
            m_topicConfiguration.GetQoS(),
            [&](std_msgs::msg::Bool msg)
            {
                float setpoint = msg.data ? m_setpoint : 0.;
                ROS2Controllers::PidMotorControllerRequestBus::Event(
                    GetEntityId(), &ROS2Controllers::PidMotorControllerRequestBus::Events::SetSetpoint, setpoint);
            });
    }

    void LifterControllerComponent::Deactivate()
    {
        m_lifterTopicSubscriber.reset();
    }
} // namespace OTTORobots
