# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/tmp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4-stamp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4-stamp/${subDir}")
endforeach()
