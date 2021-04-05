# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src/fastdds"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src/fastdds-build"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/temp_install/fastrtps-2.0.1"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/tmp"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src/fastdds-stamp"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src"
  "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src/fastdds-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
  file(MAKE_DIRECTORY "/home/marlar/zephyr_microros_pingpong_success/zephyr_microros_pingpong/build/microxrcedds_agent/fastdds/src/fastdds-stamp/${subDir}")
endforeach()
