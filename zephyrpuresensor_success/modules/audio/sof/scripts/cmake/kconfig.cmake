# SPDX-License-Identifier: BSD-3-Clause

# Kconfig targets

include(${CMAKE_CURRENT_LIST_DIR}/defconfigs.cmake)

add_custom_target(
	menuconfig
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/menuconfig.py
		${PROJECT_SOURCE_DIR}/Kconfig
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	VERBATIM
	USES_TERMINAL
)

add_custom_target(
	overrideconfig
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/overrideconfig.py
		${PROJECT_SOURCE_DIR}/Kconfig
		${PROJECT_BINARY_DIR}/override.config
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	VERBATIM
	USES_TERMINAL
)

file(GLOB_RECURSE KCONFIG_FILES "${SOF_ROOT_SOURCE_DIRECTORY}/Kconfig")

if(EXISTS ${DOT_CONFIG_PATH})
	# Update with olddefconfig only if config was previously generated
	add_custom_command(
		OUTPUT ${DOT_CONFIG_PATH}
		COMMAND ${CMAKE_COMMAND} -E env
			srctree=${PROJECT_SOURCE_DIR}
			CC_VERSION_TEXT=${CC_VERSION_TEXT}
			ARCH=${ARCH}
			${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/olddefconfig.py
			${PROJECT_SOURCE_DIR}/Kconfig
		DEPENDS ${KCONFIG_FILES}
		WORKING_DIRECTORY ${GENERATED_DIRECTORY}
		COMMENT "Regenerating .config with olddefconfig"
		VERBATIM
		USES_TERMINAL
	)
endif()

add_custom_command(
	OUTPUT ${CONFIG_H_PATH}
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/genconfig.py
		--header-path ${CONFIG_H_PATH}
		${PROJECT_SOURCE_DIR}/Kconfig
	DEPENDS ${DOT_CONFIG_PATH}
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	COMMENT "Generating ${CONFIG_H_PATH}"
	VERBATIM
	USES_TERMINAL
)

add_custom_target(genconfig DEPENDS ${CONFIG_H_PATH})

add_custom_target(
	olddefconfig
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/olddefconfig.py
		${PROJECT_SOURCE_DIR}/Kconfig
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	VERBATIM
	USES_TERMINAL
)

add_custom_target(
	alldefconfig
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/alldefconfig.py
		${PROJECT_SOURCE_DIR}/Kconfig
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	VERBATIM
	USES_TERMINAL
)

add_custom_target(
	savedefconfig
	COMMAND ${CMAKE_COMMAND} -E env
		srctree=${PROJECT_SOURCE_DIR}
		CC_VERSION_TEXT=${CC_VERSION_TEXT}
		ARCH=${ARCH}
		${PYTHON3} ${PROJECT_SOURCE_DIR}/scripts/kconfig/savedefconfig.py
		${PROJECT_SOURCE_DIR}/Kconfig
		${PROJECT_BINARY_DIR}/defconfig
	WORKING_DIRECTORY ${GENERATED_DIRECTORY}
	COMMENT "Saving minimal configuration to: ${PROJECT_BINARY_DIR}/defconfig"
	VERBATIM
	USES_TERMINAL
)
