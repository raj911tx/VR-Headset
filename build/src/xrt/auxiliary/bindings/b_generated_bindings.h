// Copyright 2020-2022, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  Generated bindings data header.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @author Christoph Haag <christoph.haag@collabora.com>
 * @ingroup oxr_api
 */

#pragma once

#include <stddef.h>

#include "xrt/xrt_defines.h"

// clang-format off

bool
oxr_verify_khr_simple_controller_subpath(const char *str, size_t length);

bool
oxr_verify_khr_simple_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_khr_simple_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_google_daydream_controller_subpath(const char *str, size_t length);

bool
oxr_verify_google_daydream_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_google_daydream_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_htc_vive_controller_subpath(const char *str, size_t length);

bool
oxr_verify_htc_vive_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_htc_vive_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_htc_vive_pro_subpath(const char *str, size_t length);

bool
oxr_verify_htc_vive_pro_dpad_path(const char *str, size_t length);

bool
oxr_verify_htc_vive_pro_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_microsoft_motion_controller_subpath(const char *str, size_t length);

bool
oxr_verify_microsoft_motion_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_microsoft_motion_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_microsoft_xbox_controller_subpath(const char *str, size_t length);

bool
oxr_verify_microsoft_xbox_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_microsoft_xbox_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_oculus_go_controller_subpath(const char *str, size_t length);

bool
oxr_verify_oculus_go_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_oculus_go_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_oculus_touch_controller_subpath(const char *str, size_t length);

bool
oxr_verify_oculus_touch_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_oculus_touch_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_valve_index_controller_subpath(const char *str, size_t length);

bool
oxr_verify_valve_index_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_valve_index_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_microsoft_hand_interaction_subpath(const char *str, size_t length);

bool
oxr_verify_microsoft_hand_interaction_dpad_path(const char *str, size_t length);

bool
oxr_verify_microsoft_hand_interaction_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_mndx_ball_on_a_stick_controller_subpath(const char *str, size_t length);

bool
oxr_verify_mndx_ball_on_a_stick_controller_dpad_path(const char *str, size_t length);

bool
oxr_verify_mndx_ball_on_a_stick_controller_dpad_emulator(const char *str, size_t length);

bool
oxr_verify_mndx_hydra_subpath(const char *str, size_t length);

bool
oxr_verify_mndx_hydra_dpad_path(const char *str, size_t length);

bool
oxr_verify_mndx_hydra_dpad_emulator(const char *str, size_t length);

#define PATHS_PER_BINDING_TEMPLATE 16

enum oxr_dpad_binding_point
{
	OXR_DPAD_BINDING_POINT_NONE,
	OXR_DPAD_BINDING_POINT_UP,
	OXR_DPAD_BINDING_POINT_DOWN,
	OXR_DPAD_BINDING_POINT_LEFT,
	OXR_DPAD_BINDING_POINT_RIGHT,
};

struct dpad_emulation
{
	const char *subaction_path;
	const char *paths[PATHS_PER_BINDING_TEMPLATE];
	enum xrt_input_name position;
	enum xrt_input_name activate; // Can be zero
};

struct binding_template
{
	const char *subaction_path;
	const char *steamvr_path;
	const char *localized_name;
	const char *paths[PATHS_PER_BINDING_TEMPLATE];
	enum xrt_input_name input;
	enum xrt_input_name dpad_activate;
	enum xrt_output_name output;
};

struct profile_template
{
	enum xrt_device_name name;
	const char *path;
	const char *localized_name;
	const char *steamvr_input_profile_path;
	const char *steamvr_controller_type;
	struct binding_template *bindings;
	size_t binding_count;
	struct dpad_emulation *dpads;
	size_t dpad_count;
};

#define NUM_PROFILE_TEMPLATES 12
extern struct profile_template profile_templates[NUM_PROFILE_TEMPLATES];

const char *
xrt_input_name_string(enum xrt_input_name input);

enum xrt_input_name
xrt_input_name_enum(const char *input);

const char *
xrt_output_name_string(enum xrt_output_name output);

enum xrt_output_name
xrt_output_name_enum(const char *output);


// clang-format on
