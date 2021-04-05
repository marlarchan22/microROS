# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src/spdlog"
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src/spdlog-build"
  "/home/marlar/movelt/build/microxrcedds_agent/temp_install/spdlog-1.4.2"
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/tmp"
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src/spdlog-stamp"
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src"
  "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src/spdlog-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt/build/microxrcedds_agent/spdlog/src/spdlog-stamp/${subDir}")
endforeach()
