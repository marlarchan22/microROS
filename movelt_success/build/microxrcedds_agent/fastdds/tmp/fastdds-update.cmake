# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

set(quiet "")
set(script_dir "/usr/share/cmake-3.20/Modules/ExternalProject")
include(${script_dir}/captured_process_setup.cmake)

execute_process(
  COMMAND  [==[/usr/bin/cmake]==] [==[-E]==] [==[copy]==] [==[/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/src/cpp/CMakeLists.txt]==] [==[/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/src/cpp/CMakeLists.txt.bak]==]
  WORKING_DIRECTORY "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds"
  RESULT_VARIABLE result
  ${capture_output}
)
_ep_command_check_result(result)

execute_process(
  COMMAND  [==[/usr/bin/cmake]==] [==[-DSOVERSION_FILE=/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/src/cpp/CMakeLists.txt]==] [==[-P]==] [==[/home/marlar/movelt/src/eProsima/Micro-XRCE-DDS-Agent/cmake/Soversion.cmake]==]
  WORKING_DIRECTORY "/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds"
  RESULT_VARIABLE result
  ${capture_output}
)
_ep_command_check_result(result)
