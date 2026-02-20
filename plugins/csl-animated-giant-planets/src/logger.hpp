////////////////////////////////////////////////////////////////////////////////////////////////////
//                               This file is part of CosmoScout VR                               //
////////////////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: German Aerospace Center (DLR) <cosmoscout@dlr.de>
// SPDX-License-Identifier: MIT

#ifndef CSL_ANIMATED_GIANT_PLANETS_LOGGER_HPP
#define CSL_ANIMATED_GIANT_PLANETS_LOGGER_HPP

#include <spdlog/spdlog.h>

namespace csl::animatedgiantplanets {

/// This creates the default singleton logger for "csl-animated-giant-planets" when called for the first time
/// and returns it. See cs-utils/logger.hpp for more logging details.
spdlog::logger& logger();

} // namespace csl::animatedgiantplanets

#endif // CSL_ANIMATED_GIANT_PLANETS_LOGGER_HPP
