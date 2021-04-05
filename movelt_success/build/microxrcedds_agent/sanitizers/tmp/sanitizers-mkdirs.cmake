# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src/sanitizers"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src/sanitizers-build"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/tmp"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src"
  "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/${subDir}")
endforeach()
