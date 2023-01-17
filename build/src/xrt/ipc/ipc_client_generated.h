// Copyright 2020, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  Generated IPC client code.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @ingroup ipc_client
 */

#pragma once

#include "shared/ipc_protocol.h"
#include "ipc_protocol_generated.h"
#include "client/ipc_client.h"




xrt_result_t
ipc_call_instance_get_shm_fd(struct ipc_connection *ipc_c,
                             xrt_shmem_handle_t *handles,
                             uint32_t handle_count);

xrt_result_t
ipc_call_system_get_client_info(struct ipc_connection *ipc_c,
                                uint32_t id,
                                struct ipc_app_state *out_desc);

xrt_result_t
ipc_call_system_set_client_info(struct ipc_connection *ipc_c,
                                const struct ipc_app_state *desc);

xrt_result_t
ipc_call_system_get_clients(struct ipc_connection *ipc_c,
                            struct ipc_client_list *out_clients);

xrt_result_t
ipc_call_system_set_primary_client(struct ipc_connection *ipc_c,
                                   uint32_t id);

xrt_result_t
ipc_call_system_set_focused_client(struct ipc_connection *ipc_c,
                                   uint32_t id);

xrt_result_t
ipc_call_system_toggle_io_client(struct ipc_connection *ipc_c,
                                 uint32_t id);

xrt_result_t
ipc_call_system_toggle_io_device(struct ipc_connection *ipc_c,
                                 uint32_t id);

xrt_result_t
ipc_call_system_compositor_get_info(struct ipc_connection *ipc_c,
                                    struct xrt_system_compositor_info *out_info);

xrt_result_t
ipc_call_session_create(struct ipc_connection *ipc_c,
                        const struct xrt_session_info *overlay_info);

xrt_result_t
ipc_call_session_begin(struct ipc_connection *ipc_c);

xrt_result_t
ipc_call_session_end(struct ipc_connection *ipc_c);

xrt_result_t
ipc_call_session_destroy(struct ipc_connection *ipc_c);

xrt_result_t
ipc_call_compositor_get_info(struct ipc_connection *ipc_c,
                             struct xrt_compositor_info *out_info);

xrt_result_t
ipc_call_compositor_predict_frame(struct ipc_connection *ipc_c,
                                  int64_t *out_frame_id,
                                  uint64_t *out_wake_up_time,
                                  uint64_t *out_predicted_display_time,
                                  uint64_t *out_predicted_display_period);

xrt_result_t
ipc_call_compositor_wait_woke(struct ipc_connection *ipc_c,
                              int64_t frame_id);

xrt_result_t
ipc_call_compositor_begin_frame(struct ipc_connection *ipc_c,
                                int64_t frame_id);

xrt_result_t
ipc_call_compositor_discard_frame(struct ipc_connection *ipc_c,
                                  int64_t frame_id);

xrt_result_t
ipc_call_compositor_layer_sync(struct ipc_connection *ipc_c,
                               int64_t frame_id,
                               uint32_t slot_id,
                               const xrt_graphics_sync_handle_t *handles,
                               const uint32_t handle_count,
                               uint32_t *out_free_slot_id);

xrt_result_t
ipc_call_compositor_layer_sync_with_semaphore(struct ipc_connection *ipc_c,
                                              int64_t frame_id,
                                              uint32_t slot_id,
                                              uint32_t semaphore_id,
                                              uint64_t semaphore_value,
                                              uint32_t *out_free_slot_id);

xrt_result_t
ipc_call_compositor_poll_events(struct ipc_connection *ipc_c,
                                union xrt_compositor_event *out_event);

xrt_result_t
ipc_call_swapchain_get_properties(struct ipc_connection *ipc_c,
                                  const struct xrt_swapchain_create_info *info,
                                  struct xrt_swapchain_create_properties *out_xsccp);

xrt_result_t
ipc_call_swapchain_create(struct ipc_connection *ipc_c,
                          const struct xrt_swapchain_create_info *info,
                          uint32_t *out_id,
                          uint32_t *out_image_count,
                          uint64_t *out_size,
                          bool *out_use_dedicated_allocation,
                          xrt_graphics_buffer_handle_t *handles,
                          uint32_t handle_count);

xrt_result_t
ipc_call_swapchain_import(struct ipc_connection *ipc_c,
                          const struct xrt_swapchain_create_info *info,
                          const struct ipc_arg_swapchain_from_native *args,
                          const xrt_graphics_buffer_handle_t *handles,
                          const uint32_t handle_count,
                          uint32_t *out_id);

xrt_result_t
ipc_call_swapchain_wait_image(struct ipc_connection *ipc_c,
                              uint32_t id,
                              uint64_t timeout_ns,
                              uint32_t index);

xrt_result_t
ipc_call_swapchain_acquire_image(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 uint32_t *out_index);

xrt_result_t
ipc_call_swapchain_release_image(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 uint32_t index);

xrt_result_t
ipc_call_swapchain_destroy(struct ipc_connection *ipc_c,
                           uint32_t id);

xrt_result_t
ipc_call_compositor_semaphore_create(struct ipc_connection *ipc_c,
                                     uint32_t *out_id,
                                     xrt_graphics_sync_handle_t *handles,
                                     uint32_t handle_count);

xrt_result_t
ipc_call_compositor_semaphore_destroy(struct ipc_connection *ipc_c,
                                      uint32_t id);

xrt_result_t
ipc_call_device_update_input(struct ipc_connection *ipc_c,
                             uint32_t id);

xrt_result_t
ipc_call_device_get_tracked_pose(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 enum xrt_input_name name,
                                 uint64_t at_timestamp,
                                 struct xrt_space_relation *out_relation);

xrt_result_t
ipc_call_device_get_hand_tracking(struct ipc_connection *ipc_c,
                                  uint32_t id,
                                  enum xrt_input_name name,
                                  uint64_t at_timestamp,
                                  struct xrt_hand_joint_set *out_value,
                                  uint64_t *out_timestamp);

xrt_result_t
ipc_call_device_get_view_poses_2(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 const struct xrt_vec3 *fallback_eye_relation,
                                 uint64_t at_timestamp_ns,
                                 struct ipc_info_get_view_poses_2 *out_info);

xrt_result_t
ipc_call_device_set_output(struct ipc_connection *ipc_c,
                           uint32_t id,
                           enum xrt_output_name name,
                           const union xrt_output_value *value);
