# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/src/eProsima/Micro-XRCE-DDS-Agent"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix/tmp"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix/src/uagent-stamp"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix/src"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix/src/uagent-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/uagent-prefix/src/uagent-stamp/${subDir}")
endforeach()
