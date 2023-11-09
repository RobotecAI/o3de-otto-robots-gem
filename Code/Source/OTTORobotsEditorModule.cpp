/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root
 * of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#include <OTTORobotsModuleInterface.h>

namespace OTTORobots
{
    class OTTORobotsEditorModule : public OTTORobotsModuleInterface
    {
    public:
        AZ_RTTI(OTTORobotsEditorModule, "{bac489f5-fecb-4e11-a437-1436cbbb00c2}", OTTORobotsModuleInterface);
        AZ_CLASS_ALLOCATOR(OTTORobotsEditorModule, AZ::SystemAllocator);

        OTTORobotsEditorModule()
        {
            m_descriptors.insert(m_descriptors.end(), {});
        }
    };
} // namespace OTTORobots

AZ_DECLARE_MODULE_CLASS(Gem_OTTORobots, OTTORobots::OTTORobotsEditorModule)
