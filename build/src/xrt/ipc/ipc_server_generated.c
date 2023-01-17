// Copyright 2020, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  Generated IPC server code.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @ingroup ipc_server
 */

#include "xrt/xrt_limits.h"

#include "shared/ipc_protocol.h"
#include "shared/ipc_utils.h"

#include "server/ipc_server.h"

#include "ipc_server_generated.h"


xrt_result_t
ipc_dispatch(volatile struct ipc_client_state *ics, ipc_command_t *ipc_command)
{
	switch (*ipc_command) {
	case IPC_INSTANCE_GET_SHM_FD: {
		IPC_TRACE(ics->server, "Dispatching instance_get_shm_fd");

		struct ipc_result_reply reply = {0};
		xrt_shmem_handle_t handles[XRT_MAX_IPC_HANDLES] = {0};
		uint32_t handle_count = {0};


		reply.result = ipc_handle_instance_get_shm_fd(ics,
		                                              XRT_MAX_IPC_HANDLES,
		                                              handles,
		                                              &handle_count);

		xrt_result_t ret = ipc_send_handles_shmem((struct ipc_message_channel *)&ics->imc,
		                                          &reply,
		                                          sizeof(reply),
		                                          handles,
		                                          handle_count);
		return ret;
	}
	case IPC_SYSTEM_GET_CLIENT_INFO: {
		IPC_TRACE(ics->server, "Dispatching system_get_client_info");

		struct ipc_system_get_client_info_msg *msg = (struct ipc_system_get_client_info_msg *)ipc_command;
		struct ipc_system_get_client_info_reply reply = {0};


		reply.result = ipc_handle_system_get_client_info(ics,
		                                                 msg->id,
		                                                 &reply.desc);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_SET_CLIENT_INFO: {
		IPC_TRACE(ics->server, "Dispatching system_set_client_info");

		struct ipc_system_set_client_info_msg *msg = (struct ipc_system_set_client_info_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_system_set_client_info(ics,
		                                                 &msg->desc);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_GET_CLIENTS: {
		IPC_TRACE(ics->server, "Dispatching system_get_clients");

		struct ipc_system_get_clients_reply reply = {0};


		reply.result = ipc_handle_system_get_clients(ics,
		                                             &reply.clients);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_SET_PRIMARY_CLIENT: {
		IPC_TRACE(ics->server, "Dispatching system_set_primary_client");

		struct ipc_system_set_primary_client_msg *msg = (struct ipc_system_set_primary_client_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_system_set_primary_client(ics,
		                                                    msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_SET_FOCUSED_CLIENT: {
		IPC_TRACE(ics->server, "Dispatching system_set_focused_client");

		struct ipc_system_set_focused_client_msg *msg = (struct ipc_system_set_focused_client_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_system_set_focused_client(ics,
		                                                    msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_TOGGLE_IO_CLIENT: {
		IPC_TRACE(ics->server, "Dispatching system_toggle_io_client");

		struct ipc_system_toggle_io_client_msg *msg = (struct ipc_system_toggle_io_client_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_system_toggle_io_client(ics,
		                                                  msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_TOGGLE_IO_DEVICE: {
		IPC_TRACE(ics->server, "Dispatching system_toggle_io_device");

		struct ipc_system_toggle_io_device_msg *msg = (struct ipc_system_toggle_io_device_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_system_toggle_io_device(ics,
		                                                  msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SYSTEM_COMPOSITOR_GET_INFO: {
		IPC_TRACE(ics->server, "Dispatching system_compositor_get_info");

		struct ipc_system_compositor_get_info_reply reply = {0};


		reply.result = ipc_handle_system_compositor_get_info(ics,
		                                                     &reply.info);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SESSION_CREATE: {
		IPC_TRACE(ics->server, "Dispatching session_create");

		struct ipc_session_create_msg *msg = (struct ipc_session_create_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_session_create(ics,
		                                         &msg->overlay_info);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SESSION_BEGIN: {
		IPC_TRACE(ics->server, "Dispatching session_begin");

		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_session_begin(ics);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SESSION_END: {
		IPC_TRACE(ics->server, "Dispatching session_end");

		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_session_end(ics);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SESSION_DESTROY: {
		IPC_TRACE(ics->server, "Dispatching session_destroy");

		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_session_destroy(ics);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_GET_INFO: {
		IPC_TRACE(ics->server, "Dispatching compositor_get_info");

		struct ipc_compositor_get_info_reply reply = {0};


		reply.result = ipc_handle_compositor_get_info(ics,
		                                              &reply.info);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_PREDICT_FRAME: {
		IPC_TRACE(ics->server, "Dispatching compositor_predict_frame");

		struct ipc_compositor_predict_frame_reply reply = {0};


		reply.result = ipc_handle_compositor_predict_frame(ics,
		                                                   &reply.frame_id,
		                                                   &reply.wake_up_time,
		                                                   &reply.predicted_display_time,
		                                                   &reply.predicted_display_period);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_WAIT_WOKE: {
		IPC_TRACE(ics->server, "Dispatching compositor_wait_woke");

		struct ipc_compositor_wait_woke_msg *msg = (struct ipc_compositor_wait_woke_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_compositor_wait_woke(ics,
		                                               msg->frame_id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_BEGIN_FRAME: {
		IPC_TRACE(ics->server, "Dispatching compositor_begin_frame");

		struct ipc_compositor_begin_frame_msg *msg = (struct ipc_compositor_begin_frame_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_compositor_begin_frame(ics,
		                                                 msg->frame_id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_DISCARD_FRAME: {
		IPC_TRACE(ics->server, "Dispatching compositor_discard_frame");

		struct ipc_compositor_discard_frame_msg *msg = (struct ipc_compositor_discard_frame_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_compositor_discard_frame(ics,
		                                                   msg->frame_id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_LAYER_SYNC: {
		IPC_TRACE(ics->server, "Dispatching compositor_layer_sync");

		struct ipc_compositor_layer_sync_msg *msg = (struct ipc_compositor_layer_sync_msg *)ipc_command;
		struct ipc_compositor_layer_sync_reply reply = {0};
		struct ipc_result_reply _sync = {XRT_SUCCESS};
		xrt_graphics_sync_handle_t in_handles[XRT_MAX_IPC_HANDLES] = {0};
		struct ipc_command_msg _handle_msg = {0};

		if (msg->handle_count > XRT_MAX_IPC_HANDLES) {
			return XRT_ERROR_IPC_FAILURE;
		}

		xrt_result_t sync_result = ipc_send((struct ipc_message_channel *)&ics->imc,
		                                    &_sync,
		                                    sizeof(_sync));
		if (sync_result != XRT_SUCCESS) {
			return sync_result;
		}

		xrt_result_t receive_handle_result = ipc_receive_handles_graphics_sync((struct ipc_message_channel *)&ics->imc,
		                                                                       &_handle_msg,
		                                                                       sizeof(_handle_msg),
		                                                                       in_handles,
		                                                                       msg->handle_count);
		if (receive_handle_result != XRT_SUCCESS) {
			return receive_handle_result;
		}
		if (_handle_msg.cmd != IPC_COMPOSITOR_LAYER_SYNC) {
			return XRT_ERROR_IPC_FAILURE;
		}

		reply.result = ipc_handle_compositor_layer_sync(ics,
		                                                msg->frame_id,
		                                                msg->slot_id,
		                                                &reply.free_slot_id,
		                                                &in_handles[0],
		                                                msg->handle_count);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_LAYER_SYNC_WITH_SEMAPHORE: {
		IPC_TRACE(ics->server, "Dispatching compositor_layer_sync_with_semaphore");

		struct ipc_compositor_layer_sync_with_semaphore_msg *msg = (struct ipc_compositor_layer_sync_with_semaphore_msg *)ipc_command;
		struct ipc_compositor_layer_sync_with_semaphore_reply reply = {0};


		reply.result = ipc_handle_compositor_layer_sync_with_semaphore(ics,
		                                                               msg->frame_id,
		                                                               msg->slot_id,
		                                                               msg->semaphore_id,
		                                                               msg->semaphore_value,
		                                                               &reply.free_slot_id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_POLL_EVENTS: {
		IPC_TRACE(ics->server, "Dispatching compositor_poll_events");

		struct ipc_compositor_poll_events_reply reply = {0};


		reply.result = ipc_handle_compositor_poll_events(ics,
		                                                 &reply.event);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_GET_PROPERTIES: {
		IPC_TRACE(ics->server, "Dispatching swapchain_get_properties");

		struct ipc_swapchain_get_properties_msg *msg = (struct ipc_swapchain_get_properties_msg *)ipc_command;
		struct ipc_swapchain_get_properties_reply reply = {0};


		reply.result = ipc_handle_swapchain_get_properties(ics,
		                                                   &msg->info,
		                                                   &reply.xsccp);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_CREATE: {
		IPC_TRACE(ics->server, "Dispatching swapchain_create");

		struct ipc_swapchain_create_msg *msg = (struct ipc_swapchain_create_msg *)ipc_command;
		struct ipc_swapchain_create_reply reply = {0};
		xrt_graphics_buffer_handle_t handles[XRT_MAX_IPC_HANDLES] = {0};
		uint32_t handle_count = {0};


		reply.result = ipc_handle_swapchain_create(ics,
		                                           &msg->info,
		                                           &reply.id,
		                                           &reply.image_count,
		                                           &reply.size,
		                                           &reply.use_dedicated_allocation,
		                                           XRT_MAX_IPC_HANDLES,
		                                           handles,
		                                           &handle_count);

		xrt_result_t ret = ipc_send_handles_graphics_buffer((struct ipc_message_channel *)&ics->imc,
		                                                    &reply,
		                                                    sizeof(reply),
		                                                    handles,
		                                                    handle_count);
		return ret;
	}
	case IPC_SWAPCHAIN_IMPORT: {
		IPC_TRACE(ics->server, "Dispatching swapchain_import");

		struct ipc_swapchain_import_msg *msg = (struct ipc_swapchain_import_msg *)ipc_command;
		struct ipc_swapchain_import_reply reply = {0};
		struct ipc_result_reply _sync = {XRT_SUCCESS};
		xrt_graphics_buffer_handle_t in_handles[XRT_MAX_IPC_HANDLES] = {0};
		struct ipc_command_msg _handle_msg = {0};

		if (msg->handle_count > XRT_MAX_IPC_HANDLES) {
			return XRT_ERROR_IPC_FAILURE;
		}

		xrt_result_t sync_result = ipc_send((struct ipc_message_channel *)&ics->imc,
		                                    &_sync,
		                                    sizeof(_sync));
		if (sync_result != XRT_SUCCESS) {
			return sync_result;
		}

		xrt_result_t receive_handle_result = ipc_receive_handles_graphics_buffer((struct ipc_message_channel *)&ics->imc,
		                                                                         &_handle_msg,
		                                                                         sizeof(_handle_msg),
		                                                                         in_handles,
		                                                                         msg->handle_count);
		if (receive_handle_result != XRT_SUCCESS) {
			return receive_handle_result;
		}
		if (_handle_msg.cmd != IPC_SWAPCHAIN_IMPORT) {
			return XRT_ERROR_IPC_FAILURE;
		}

		reply.result = ipc_handle_swapchain_import(ics,
		                                           &msg->info,
		                                           &msg->args,
		                                           &reply.id,
		                                           &in_handles[0],
		                                           msg->handle_count);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_WAIT_IMAGE: {
		IPC_TRACE(ics->server, "Dispatching swapchain_wait_image");

		struct ipc_swapchain_wait_image_msg *msg = (struct ipc_swapchain_wait_image_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_swapchain_wait_image(ics,
		                                               msg->id,
		                                               msg->timeout_ns,
		                                               msg->index);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_ACQUIRE_IMAGE: {
		IPC_TRACE(ics->server, "Dispatching swapchain_acquire_image");

		struct ipc_swapchain_acquire_image_msg *msg = (struct ipc_swapchain_acquire_image_msg *)ipc_command;
		struct ipc_swapchain_acquire_image_reply reply = {0};


		reply.result = ipc_handle_swapchain_acquire_image(ics,
		                                                  msg->id,
		                                                  &reply.index);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_RELEASE_IMAGE: {
		IPC_TRACE(ics->server, "Dispatching swapchain_release_image");

		struct ipc_swapchain_release_image_msg *msg = (struct ipc_swapchain_release_image_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_swapchain_release_image(ics,
		                                                  msg->id,
		                                                  msg->index);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_SWAPCHAIN_DESTROY: {
		IPC_TRACE(ics->server, "Dispatching swapchain_destroy");

		struct ipc_swapchain_destroy_msg *msg = (struct ipc_swapchain_destroy_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_swapchain_destroy(ics,
		                                            msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_COMPOSITOR_SEMAPHORE_CREATE: {
		IPC_TRACE(ics->server, "Dispatching compositor_semaphore_create");

		struct ipc_compositor_semaphore_create_reply reply = {0};
		xrt_graphics_sync_handle_t handles[XRT_MAX_IPC_HANDLES] = {0};
		uint32_t handle_count = {0};


		reply.result = ipc_handle_compositor_semaphore_create(ics,
		                                                      &reply.id,
		                                                      XRT_MAX_IPC_HANDLES,
		                                                      handles,
		                                                      &handle_count);

		xrt_result_t ret = ipc_send_handles_graphics_sync((struct ipc_message_channel *)&ics->imc,
		                                                  &reply,
		                                                  sizeof(reply),
		                                                  handles,
		                                                  handle_count);
		return ret;
	}
	case IPC_COMPOSITOR_SEMAPHORE_DESTROY: {
		IPC_TRACE(ics->server, "Dispatching compositor_semaphore_destroy");

		struct ipc_compositor_semaphore_destroy_msg *msg = (struct ipc_compositor_semaphore_destroy_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_compositor_semaphore_destroy(ics,
		                                                       msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_DEVICE_UPDATE_INPUT: {
		IPC_TRACE(ics->server, "Dispatching device_update_input");

		struct ipc_device_update_input_msg *msg = (struct ipc_device_update_input_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_device_update_input(ics,
		                                              msg->id);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_DEVICE_GET_TRACKED_POSE: {
		IPC_TRACE(ics->server, "Dispatching device_get_tracked_pose");

		struct ipc_device_get_tracked_pose_msg *msg = (struct ipc_device_get_tracked_pose_msg *)ipc_command;
		struct ipc_device_get_tracked_pose_reply reply = {0};


		reply.result = ipc_handle_device_get_tracked_pose(ics,
		                                                  msg->id,
		                                                  msg->name,
		                                                  msg->at_timestamp,
		                                                  &reply.relation);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_DEVICE_GET_HAND_TRACKING: {
		IPC_TRACE(ics->server, "Dispatching device_get_hand_tracking");

		struct ipc_device_get_hand_tracking_msg *msg = (struct ipc_device_get_hand_tracking_msg *)ipc_command;
		struct ipc_device_get_hand_tracking_reply reply = {0};


		reply.result = ipc_handle_device_get_hand_tracking(ics,
		                                                   msg->id,
		                                                   msg->name,
		                                                   msg->at_timestamp,
		                                                   &reply.value,
		                                                   &reply.timestamp);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_DEVICE_GET_VIEW_POSES_2: {
		IPC_TRACE(ics->server, "Dispatching device_get_view_poses_2");

		struct ipc_device_get_view_poses_2_msg *msg = (struct ipc_device_get_view_poses_2_msg *)ipc_command;
		struct ipc_device_get_view_poses_2_reply reply = {0};


		reply.result = ipc_handle_device_get_view_poses_2(ics,
		                                                  msg->id,
		                                                  &msg->fallback_eye_relation,
		                                                  msg->at_timestamp_ns,
		                                                  &reply.info);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	case IPC_DEVICE_SET_OUTPUT: {
		IPC_TRACE(ics->server, "Dispatching device_set_output");

		struct ipc_device_set_output_msg *msg = (struct ipc_device_set_output_msg *)ipc_command;
		struct ipc_result_reply reply = {0};


		reply.result = ipc_handle_device_set_output(ics,
		                                            msg->id,
		                                            msg->name,
		                                            &msg->value);

		xrt_result_t ret = ipc_send((struct ipc_message_channel *)&ics->imc,
		                            &reply,
		                            sizeof(reply));
		return ret;
	}
	default:
		U_LOG_E("UNHANDLED IPC MESSAGE! %d", *ipc_command);
		return XRT_ERROR_IPC_FAILURE;
	}
}

