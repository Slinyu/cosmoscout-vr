////////////////////////////////////////////////////////////////////////////////////////////////////
//                               This file is part of CosmoScout VR                               //
////////////////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: German Aerospace Center (DLR) <cosmoscout@dlr.de>
// SPDX-License-Identifier: MIT

#ifndef CSL_ANIMATED_GIANT_PLANETS_ANIMATED_GIANT_PLANETS_HPP
#define CSL_ANIMATED_GIANT_PLANETS_ANIMATED_GIANT_PLANETS_HPP

#include "csl_animated_giant_planets_export.hpp"

#include <string>
#include <boost/process.hpp>

namespace csl::animatedgiantplanets {

class CSL_ANIMATED_GIANT_PLANETS_EXPORT AnimatedGiantPlanets {
public:
  AnimatedGiantPlanets();
  ~AnimatedGiantPlanets();

  void startGeneratingImages(const std::string &sDestPath);
  void stopGeneratingImages();

private:
  boost::process::child executable;

};

} // namespace csl::animatedgiantplanets

#endif // CSL_ANIMATED_GIANT_PLANETS_ANIMATED_GIANT_PLANETS_HPP
