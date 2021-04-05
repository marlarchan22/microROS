# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt_success/firmware/mcu_ws/eProsima/Micro-CDR"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix/tmp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix/src/ucdr-stamp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix/src"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix/src/ucdr-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt_success/firmware/mcu_ws/build/microcdr/ucdr-prefix/src/ucdr-stamp/${subDir}")
endforeach()
