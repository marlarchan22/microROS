# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/libyaml-10c9078"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/libyaml-10c9078-build"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/tmp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/libyaml-10c9078-stamp"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src"
  "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/libyaml-10c9078-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/libyaml-10c9078-stamp/${subDir}")
endforeach()
