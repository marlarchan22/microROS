# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

set(quiet "")
set(script_dir "/usr/share/cmake-3.20/Modules/ExternalProject")
include(${script_dir}/captured_process_setup.cmake)

execute_process(
  COMMAND  [==[/usr/bin/cmake]==] [==[-E]==] [==[copy]==] [==[/home/marlar/movelt_success/firmware/mcu_ws/ros2/tinydir_vendor/tinydir_cmakelists.txt]==] [==[/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4/CMakeLists.txt]==]
  WORKING_DIRECTORY "/home/marlar/movelt_success/firmware/mcu_ws/build/tinydir_vendor/tinydir-1.2.4/src/tinydir-1.2.4"
  RESULT_VARIABLE result
  ${capture_output}
)
_ep_command_check_result(result)
