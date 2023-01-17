# Copyright 2019-2022, Collabora, Ltd.
# Copyright 2019, Benjamin Saunders <ben.e.saunders@gmail.com>
# SPDX-License-Identifier: BSL-1.0

# Get input from main CMake script
set(MANIFEST_TEMPLATE /workspace/monado/cmake/openxr_monado.in.json)
set(DESTINATION share/openxr/1)
set(OUT_FILENAME openxr_monado.json)
set(CONFIGURE_OUTPUT_FILE /workspace/build/src/xrt/targets/openxr/openxr_monado.json)
set(IS_INSTALL ON)
set(RUNTIME_TARGET openxr_monado)
# Runtime install dir relative to install prefix
set(RELATIVE_RUNTIME_DIR usr/lib)
# Runtime so/dll filename
set(RUNTIME_FILENAME libopenxr_monado.so)
# The relative path from the manifest dir to the runtime. Optional.
set(RUNTIME_DIR_RELATIVE_TO_MANIFEST
    ../../../usr/lib)
# Config option
set(ABSOLUTE_RUNTIME_PATH FALSE)

if(RUNTIME_PATH)
    # This is at build time, not install time
    set(CONFIGURE_OUTPUT_FILE "${OUT_FILE}")
elseif(ABSOLUTE_RUNTIME_PATH)
    # Absolute path to runtime
    message(
        STATUS
            "Installing OpenXR runtime manifest with absolute path to runtime")
    set(RUNTIME_PATH ${RELATIVE_RUNTIME_DIR}/${RUNTIME_FILENAME})
    if(NOT IS_ABSOLUTE ${RELATIVE_RUNTIME_DIR})
        set(RUNTIME_PATH ${CMAKE_INSTALL_PREFIX}/${RUNTIME_PATH})
    endif()
elseif(RUNTIME_DIR_RELATIVE_TO_MANIFEST)
    # Relative path to runtime.
    message(
        STATUS
            "Installing OpenXR runtime manifest with JSON-relative path to runtime"
    )
    set(RUNTIME_PATH ${RUNTIME_DIR_RELATIVE_TO_MANIFEST}/${RUNTIME_FILENAME})
else()
    # Unqualified runtime filename: requires it exist on the system shared library search path.
    message(
        STATUS
            "Installing OpenXR runtime manifest with unqualified runtime filename (uses system search path)"
    )
    set(RUNTIME_PATH ${RUNTIME_FILENAME})
endif()

if(WIN32)
    # Windows really wants backslashes in the manifest, and they must be escaped.
    string(REPLACE "/" [[\\]] RUNTIME_PATH ${RUNTIME_PATH})
endif()

set(runtime_path ${RUNTIME_PATH})
# Create manifest
configure_file("${MANIFEST_TEMPLATE}" "${CONFIGURE_OUTPUT_FILE}")

if(IS_INSTALL)
    if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx"
       OR NOT CMAKE_INSTALL_COMPONENT)

        # Install it
        file(
            INSTALL
            DESTINATION "${CMAKE_INSTALL_PREFIX}/${DESTINATION}"
            TYPE FILE FILES "${CONFIGURE_OUTPUT_FILE}")
    endif()
endif()
