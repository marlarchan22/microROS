# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds"
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds-build"
  "/home/marlar/movelt/build/microxrcedds_agent/temp_install/fastrtps-2.0.1"
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/tmp"
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds-stamp"
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src"
  "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds-stamp/${subDir}")
endforeach()
