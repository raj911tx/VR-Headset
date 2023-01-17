# Copyright 2019, Benjamin Saunders <ben.e.saunders@gmail.com>
# SPDX-License-Identifier: BSL-1.0

include(GNUInstallDirs)

set(MANIFEST_RELATIVE_DIR share/openxr/1/)
set(XR_API_MAJOR 1)
set(RUNTIME_TARGET openxr_monado)

execute_process(
	COMMAND
		${CMAKE_COMMAND} -E create_symlink
		${CMAKE_INSTALL_PREFIX}/${MANIFEST_RELATIVE_DIR}/${RUNTIME_TARGET}.json
		${CMAKE_BINARY_DIR}/active_runtime.json
	)
file(
	INSTALL
	DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/xdg/openxr/${XR_API_MAJOR}"
	TYPE FILE FILES "${CMAKE_BINARY_DIR}/active_runtime.json"
	)
