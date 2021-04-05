# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

set(quiet "")
set(script_dir "/usr/share/cmake-3.20/Modules/ExternalProject")
include(${script_dir}/captured_process_setup.cmake)

function(check_file_hash has_hash hash_is_good)
  if("${has_hash}" STREQUAL "")
    _ep_message_quiet_capture(FATAL_ERROR "has_hash Can't be empty")
  endif()

  if("${hash_is_good}" STREQUAL "")
    _ep_message_quiet_capture(FATAL_ERROR "hash_is_good Can't be empty")
  endif()

  if("MD5" STREQUAL "")
    # No check
    set("${has_hash}" FALSE PARENT_SCOPE)
    set("${hash_is_good}" FALSE PARENT_SCOPE)
    return()
  endif()

  set("${has_hash}" TRUE PARENT_SCOPE)

  _ep_message_quiet_capture(STATUS "verifying file...
       file='/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip'")
  set(accumulated_output "${accumulated_output}" PARENT_SCOPE)

  file("MD5" "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip" actual_value)

  if(NOT "${actual_value}" STREQUAL "b595f0ab0735c04c7f6ed0a798a3eff7")
    set("${hash_is_good}" FALSE PARENT_SCOPE)
    _ep_message_quiet_capture(STATUS "MD5 hash of
    /home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip
  does not match expected value
    expected: 'b595f0ab0735c04c7f6ed0a798a3eff7'
      actual: '${actual_value}'")
    set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
  else()
    set("${hash_is_good}" TRUE PARENT_SCOPE)
  endif()
endfunction()

function(sleep_before_download attempt)
  if(attempt EQUAL 0)
    return()
  endif()

  if(attempt EQUAL 1)
    _ep_message_quiet_capture(STATUS "Retrying...")
    set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
    return()
  endif()

  set(sleep_seconds 0)

  if(attempt EQUAL 2)
    set(sleep_seconds 5)
  elseif(attempt EQUAL 3)
    set(sleep_seconds 5)
  elseif(attempt EQUAL 4)
    set(sleep_seconds 15)
  elseif(attempt EQUAL 5)
    set(sleep_seconds 60)
  elseif(attempt EQUAL 6)
    set(sleep_seconds 90)
  elseif(attempt EQUAL 7)
    set(sleep_seconds 300)
  else()
    set(sleep_seconds 1200)
  endif()

  _ep_message_quiet_capture(STATUS
    "Retry after ${sleep_seconds} seconds (attempt #${attempt}) ..."
  )
  set(accumulated_output "${accumulated_output}" PARENT_SCOPE)

  execute_process(COMMAND "${CMAKE_COMMAND}" -E sleep "${sleep_seconds}")
endfunction()

if("/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip" STREQUAL "")
  message(FATAL_ERROR "LOCAL can't be empty")
endif()

if("https://github.com/yaml/libyaml/archive/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip" STREQUAL "")
  message(FATAL_ERROR "REMOTE can't be empty")
endif()

function(download_and_verify)
  if(EXISTS "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip")
    check_file_hash(has_hash hash_is_good)
    if(has_hash)
      if(hash_is_good)
        _ep_message_quiet_capture(STATUS
"File already exists and hash match (skip download):
  file='/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip'
  MD5='b595f0ab0735c04c7f6ed0a798a3eff7'"
        )
        set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
        return()
      else()
        _ep_message_quiet_capture(STATUS
          "File already exists but hash mismatch. Removing..."
        )
        set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
        file(REMOVE "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip")
      endif()
    else()
      _ep_message_quiet_capture(STATUS
"File already exists but no hash specified (use URL_HASH):
  file='/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip'
Old file will be removed and new file downloaded from URL."
      )
      file(REMOVE "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip")
    endif()
  endif()

  set(retry_number 5)

  _ep_message_quiet_capture(STATUS "Downloading...
   dst='/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip'
   timeout='60 seconds'
   inactivity timeout='none'"
  )
  set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
  set(download_retry_codes 7 6 8 15)
  set(skip_url_list)
  set(status_code)
  foreach(i RANGE ${retry_number})
    if(status_code IN_LIST download_retry_codes)
      sleep_before_download(${i})
    endif()
    foreach(url https://github.com/yaml/libyaml/archive/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip)
      if(NOT url IN_LIST skip_url_list)
        _ep_message_quiet_capture(STATUS "Using src='${url}'")
        set(accumulated_output "${accumulated_output}" PARENT_SCOPE)

        
        
        
        

        file(
          DOWNLOAD
          "${url}" "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip"
          SHOW_PROGRESS
          TIMEOUT;60
          # no INACTIVITY_TIMEOUT
          STATUS status
          LOG log
          
          
          )

        list(GET status 0 status_code)
        list(GET status 1 status_string)

        if(status_code EQUAL 0)
          check_file_hash(has_hash hash_is_good)
          if(has_hash AND NOT hash_is_good)
            _ep_message_quiet_capture(STATUS "Hash mismatch, removing...")
            set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
            file(REMOVE "/home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/src/10c907871f1ccd779c7fccf6b81a62762b5c4e7b.zip")
          else()
            _ep_message_quiet_capture(STATUS "Downloading... done")
            set(accumulated_output "${accumulated_output}" PARENT_SCOPE)
            return()
          endif()
        else()
          string(APPEND logFailedURLs
"error: downloading '${url}' failed
        status_code: ${status_code}
        status_string: ${status_string}
        log:
        --- LOG BEGIN ---
        ${log}
        --- LOG END ---
        "
          )
        if(NOT status_code IN_LIST download_retry_codes)
          list(APPEND skip_url_list "${url}")
          break()
        endif()
      endif()
    endif()
    endforeach()
  endforeach()

  _ep_message_quiet_capture(FATAL_ERROR
"Each download failed!
  ${logFailedURLs}
  "
  )

endfunction()

download_and_verify()

set(extract_script /home/marlar/movelt_success/firmware/mcu_ws/build/libyaml_vendor/libyaml-10c9078-prefix/tmp/extract-libyaml-10c9078.cmake)
if(NOT "${extract_script}" STREQUAL "")
  include(${extract_script})
endif()
