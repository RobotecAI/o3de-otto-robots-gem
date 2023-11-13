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
    class OTTORobotsModule : public OTTORobotsModuleInterface
    {
    public:
        AZ_RTTI(OTTORobotsModule, "{e0aa0a84-73ec-497f-9ddb-2955aeb1f7fd}", OTTORobotsModuleInterface);
        AZ_CLASS_ALLOCATOR(OTTORobotsModule, AZ::SystemAllocator);
    };
} // namespace OTTORobots

AZ_DECLARE_MODULE_CLASS(Gem_OTTORobots, OTTORobots::OTTORobotsModule)
