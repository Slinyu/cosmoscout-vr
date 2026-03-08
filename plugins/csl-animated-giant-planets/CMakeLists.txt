# ------------------------------------------------------------------------------------------------ #
#                                This file is part of CosmoScout VR                                #
# ------------------------------------------------------------------------------------------------ #

# SPDX-FileCopyrightText: German Aerospace Center (DLR) <cosmoscout@dlr.de>
# SPDX-License-Identifier: MIT

option(CSL_ANIMATED_GIANT_PLANETS "Enable compilation of this plugin library" ON)

if (NOT CSL_ANIMATED_GIANT_PLANETS)
  return()
endif()

# build plugin -------------------------------------------------------------------------------------

file(GLOB SOURCE_FILES src/*.cpp)
# file(GLOB SOURCE_FILES src/*.cpp src/gaseous-giganticus/*.c)

# Resource files and header files are only added in order to make them available in your IDE.
file(GLOB HEADER_FILES src/*.hpp)
file(GLOB_RECURSE RESOURCE_FILES executables/*)

add_library(csl-animated-giant-planets SHARED
  ${SOURCE_FILES}
  ${HEADER_FILES}
  ${RESOURCE_FILES}
)

target_link_libraries(csl-animated-giant-planets
  PUBLIC
    cs-core
)

# Add this plugin library to a "plugins" folder in your IDE.
set_property(TARGET csl-animated-giant-planets PROPERTY FOLDER "plugins")

# We mark all resource files as "header" in order to make sure that no one tries to compile them.
set_source_files_properties(${RESOURCE_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)

# Make directory structure available in your IDE.
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
  ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES}
)

target_include_directories(csl-animated-giant-planets PUBLIC
    ${CMAKE_BINARY_DIR}/plugins/csl-animated-giant-planets
)

# install plugin -----------------------------------------------------------------------------------

install(TARGETS csl-animated-giant-planets DESTINATION "lib")
install(DIRECTORY "executables"        DESTINATION "share/resources")

# export header ------------------------------------------------------------------------------------

generate_export_header(csl-animated-giant-planets
    EXPORT_FILE_NAME csl_animated_giant_planets_export.hpp
)
