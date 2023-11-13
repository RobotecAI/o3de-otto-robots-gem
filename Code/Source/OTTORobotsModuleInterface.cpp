/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root
 * of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#include "OTTORobotsModuleInterface.h"

#include <AzCore/Memory/Memory.h>
#include <Lights/LightController.h>
#include <Scripting/LifterController.h>

namespace OTTORobots
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(OTTORobotsModuleInterface, "OTTORobotsModuleInterface", "{a513487a-c56f-4765-84ce-375d6f20d30f}");
    AZ_RTTI_NO_TYPE_INFO_IMPL(OTTORobotsModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(OTTORobotsModuleInterface, AZ::SystemAllocator);

    OTTORobotsModuleInterface::OTTORobotsModuleInterface()
    {
        m_descriptors.insert(
            m_descriptors.end(),
            { ROS2::OTTORobots::LifterControllerComponent::CreateDescriptor(), ROS2::OTTORobots::LightController::CreateDescriptor() });
    }
} // namespace OTTORobots
