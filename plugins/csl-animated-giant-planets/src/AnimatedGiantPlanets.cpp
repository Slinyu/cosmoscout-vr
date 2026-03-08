////////////////////////////////////////////////////////////////////////////////////////////////////
//                               This file is part of CosmoScout VR                               //
////////////////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: German Aerospace Center (DLR) <cosmoscout@dlr.de>
// SPDX-License-Identifier: MIT

#include "AnimatedGiantPlanets.hpp"

#include "logger.hpp"

namespace csl::animatedgiantplanets {

////////////////////////////////////////////////////////////////////////////////////////////////////

AnimatedGiantPlanets::AnimatedGiantPlanets() {}

////////////////////////////////////////////////////////////////////////////////////////////////////

AnimatedGiantPlanets::~AnimatedGiantPlanets() {}

////////////////////////////////////////////////////////////////////////////////////////////////////


void AnimatedGiantPlanets::startGeneratingImages(const std::string &sDestPath) {
  logger().info("----------> Received Dest Path: {}", sDestPath);

  /* (executable.running()) {
    logger().warn("Executable is already running. Terminating it before starting a new one.");
    //executable.terminate();
  }*/

 //#ifdef _WIN32
  std::string exe = "../share/resources/executables/gaseous-giganticus.exe";
  //#else
  //const char* exe = "../share/resources/executables/gaseous-giganticus";
  //#endif

  std::string outputPath = sDestPath + "frame";
  std::string inputPath = "../share/resources/executables/colors.png";

  logger().info("----------> Using output path {}", outputPath);
  logger().info("----------> Using input path {}", inputPath);

  executable = boost::process::child::child(
    exe,
    "-V",
    "--sinusoidal",
    "--noise-scale", "2,0",
    "--velocity-factor", "800",
    "--bands", "20",
    "-i", inputPath,
    "-o", outputPath,
    "--equirectangular", "1024",
    "--vortex-band-threshold", "0,01",
    "--vortex-size", "0,22",
    "--vortices", "1",
    "--large-pixels",
    "--count", "1500",
    "--wstep", "0,1",
    "--vortex-speed", "0,0001",
    "--vortex-lat", "-22",
    "--image-save-period", "1"
  );
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void AnimatedGiantPlanets::stopGeneratingImages() {}
  //executable.terminate();
} // namespace csl::animatedgiantplanets
