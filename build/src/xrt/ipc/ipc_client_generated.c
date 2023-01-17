// Copyright 2020, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  Generated IPC client code.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @ingroup ipc_client
 */

#include "client/ipc_client.h"
#include "ipc_protocol_generated.h"




xrt_result_t
ipc_call_instance_get_shm_fd(struct ipc_connection *ipc_c,
                             xrt_shmem_handle_t *handles,
                             uint32_t handle_count)
{
	IPC_TRACE(ipc_c, "Calling instance_get_shm_fd");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_INSTANCE_GET_SHM_FD,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive_handles_shmem(&ipc_c->imc,
	                                &_reply,
	                                sizeof(_reply),
	                                handles,
	                                handle_count);
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_get_client_info(struct ipc_connection *ipc_c,
                                uint32_t id,
                                struct ipc_app_state *out_desc)
{
	IPC_TRACE(ipc_c, "Calling system_get_client_info");

	struct ipc_system_get_client_info_msg _msg = {
	    .cmd = IPC_SYSTEM_GET_CLIENT_INFO,
	    .id = id,
	};
	struct ipc_system_get_client_info_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_desc = _reply.desc;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_set_client_info(struct ipc_connection *ipc_c,
                                const struct ipc_app_state *desc)
{
	IPC_TRACE(ipc_c, "Calling system_set_client_info");

	struct ipc_system_set_client_info_msg _msg = {
	    .cmd = IPC_SYSTEM_SET_CLIENT_INFO,
	    .desc = *desc,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_get_clients(struct ipc_connection *ipc_c,
                            struct ipc_client_list *out_clients)
{
	IPC_TRACE(ipc_c, "Calling system_get_clients");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_SYSTEM_GET_CLIENTS,
	};
	struct ipc_system_get_clients_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_clients = _reply.clients;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_set_primary_client(struct ipc_connection *ipc_c,
                                   uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling system_set_primary_client");

	struct ipc_system_set_primary_client_msg _msg = {
	    .cmd = IPC_SYSTEM_SET_PRIMARY_CLIENT,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_set_focused_client(struct ipc_connection *ipc_c,
                                   uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling system_set_focused_client");

	struct ipc_system_set_focused_client_msg _msg = {
	    .cmd = IPC_SYSTEM_SET_FOCUSED_CLIENT,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_toggle_io_client(struct ipc_connection *ipc_c,
                                 uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling system_toggle_io_client");

	struct ipc_system_toggle_io_client_msg _msg = {
	    .cmd = IPC_SYSTEM_TOGGLE_IO_CLIENT,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_toggle_io_device(struct ipc_connection *ipc_c,
                                 uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling system_toggle_io_device");

	struct ipc_system_toggle_io_device_msg _msg = {
	    .cmd = IPC_SYSTEM_TOGGLE_IO_DEVICE,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_system_compositor_get_info(struct ipc_connection *ipc_c,
                                    struct xrt_system_compositor_info *out_info)
{
	IPC_TRACE(ipc_c, "Calling system_compositor_get_info");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_SYSTEM_COMPOSITOR_GET_INFO,
	};
	struct ipc_system_compositor_get_info_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_info = _reply.info;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_session_create(struct ipc_connection *ipc_c,
                        const struct xrt_session_info *overlay_info)
{
	IPC_TRACE(ipc_c, "Calling session_create");

	struct ipc_session_create_msg _msg = {
	    .cmd = IPC_SESSION_CREATE,
	    .overlay_info = *overlay_info,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_session_begin(struct ipc_connection *ipc_c)
{
	IPC_TRACE(ipc_c, "Calling session_begin");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_SESSION_BEGIN,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_session_end(struct ipc_connection *ipc_c)
{
	IPC_TRACE(ipc_c, "Calling session_end");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_SESSION_END,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_session_destroy(struct ipc_connection *ipc_c)
{
	IPC_TRACE(ipc_c, "Calling session_destroy");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_SESSION_DESTROY,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_get_info(struct ipc_connection *ipc_c,
                             struct xrt_compositor_info *out_info)
{
	IPC_TRACE(ipc_c, "Calling compositor_get_info");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_COMPOSITOR_GET_INFO,
	};
	struct ipc_compositor_get_info_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_info = _reply.info;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_predict_frame(struct ipc_connection *ipc_c,
                                  int64_t *out_frame_id,
                                  uint64_t *out_wake_up_time,
                                  uint64_t *out_predicted_display_time,
                                  uint64_t *out_predicted_display_period)
{
	IPC_TRACE(ipc_c, "Calling compositor_predict_frame");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_COMPOSITOR_PREDICT_FRAME,
	};
	struct ipc_compositor_predict_frame_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_frame_id = _reply.frame_id;
	*out_wake_up_time = _reply.wake_up_time;
	*out_predicted_display_time = _reply.predicted_display_time;
	*out_predicted_display_period = _reply.predicted_display_period;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_wait_woke(struct ipc_connection *ipc_c,
                              int64_t frame_id)
{
	IPC_TRACE(ipc_c, "Calling compositor_wait_woke");

	struct ipc_compositor_wait_woke_msg _msg = {
	    .cmd = IPC_COMPOSITOR_WAIT_WOKE,
	    .frame_id = frame_id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_begin_frame(struct ipc_connection *ipc_c,
                                int64_t frame_id)
{
	IPC_TRACE(ipc_c, "Calling compositor_begin_frame");

	struct ipc_compositor_begin_frame_msg _msg = {
	    .cmd = IPC_COMPOSITOR_BEGIN_FRAME,
	    .frame_id = frame_id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_discard_frame(struct ipc_connection *ipc_c,
                                  int64_t frame_id)
{
	IPC_TRACE(ipc_c, "Calling compositor_discard_frame");

	struct ipc_compositor_discard_frame_msg _msg = {
	    .cmd = IPC_COMPOSITOR_DISCARD_FRAME,
	    .frame_id = frame_id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_layer_sync(struct ipc_connection *ipc_c,
                               int64_t frame_id,
                               uint32_t slot_id,
                               const xrt_graphics_sync_handle_t *handles,
                               const uint32_t handle_count,
                               uint32_t *out_free_slot_id)
{
	IPC_TRACE(ipc_c, "Calling compositor_layer_sync");

	struct ipc_compositor_layer_sync_msg _msg = {
	    .cmd = IPC_COMPOSITOR_LAYER_SYNC,
	    .frame_id = frame_id,
	    .slot_id = slot_id,
	    .handle_count = handle_count,
	};
	struct ipc_compositor_layer_sync_reply _reply;
	struct ipc_result_reply _sync = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Send our handles separately

	// Wait for server sync
	ret = ipc_receive(&ipc_c->imc,
	                  &_sync,
	                  sizeof(_sync));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// We need this message data as filler only
	struct ipc_command_msg _handle_msg = {
	    .cmd = IPC_COMPOSITOR_LAYER_SYNC,
	};

	ret = ipc_send_handles_graphics_sync(&ipc_c->imc,
	                                     &_handle_msg,
	                                     sizeof(_handle_msg),
	                                     handles,
	                                     handle_count);
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_free_slot_id = _reply.free_slot_id;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_layer_sync_with_semaphore(struct ipc_connection *ipc_c,
                                              int64_t frame_id,
                                              uint32_t slot_id,
                                              uint32_t semaphore_id,
                                              uint64_t semaphore_value,
                                              uint32_t *out_free_slot_id)
{
	IPC_TRACE(ipc_c, "Calling compositor_layer_sync_with_semaphore");

	struct ipc_compositor_layer_sync_with_semaphore_msg _msg = {
	    .cmd = IPC_COMPOSITOR_LAYER_SYNC_WITH_SEMAPHORE,
	    .frame_id = frame_id,
	    .slot_id = slot_id,
	    .semaphore_id = semaphore_id,
	    .semaphore_value = semaphore_value,
	};
	struct ipc_compositor_layer_sync_with_semaphore_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_free_slot_id = _reply.free_slot_id;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_poll_events(struct ipc_connection *ipc_c,
                                union xrt_compositor_event *out_event)
{
	IPC_TRACE(ipc_c, "Calling compositor_poll_events");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_COMPOSITOR_POLL_EVENTS,
	};
	struct ipc_compositor_poll_events_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_event = _reply.event;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_get_properties(struct ipc_connection *ipc_c,
                                  const struct xrt_swapchain_create_info *info,
                                  struct xrt_swapchain_create_properties *out_xsccp)
{
	IPC_TRACE(ipc_c, "Calling swapchain_get_properties");

	struct ipc_swapchain_get_properties_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_GET_PROPERTIES,
	    .info = *info,
	};
	struct ipc_swapchain_get_properties_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_xsccp = _reply.xsccp;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_create(struct ipc_connection *ipc_c,
                          const struct xrt_swapchain_create_info *info,
                          uint32_t *out_id,
                          uint32_t *out_image_count,
                          uint64_t *out_size,
                          bool *out_use_dedicated_allocation,
                          xrt_graphics_buffer_handle_t *handles,
                          uint32_t handle_count)
{
	IPC_TRACE(ipc_c, "Calling swapchain_create");

	struct ipc_swapchain_create_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_CREATE,
	    .info = *info,
	};
	struct ipc_swapchain_create_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive_handles_graphics_buffer(&ipc_c->imc,
	                                          &_reply,
	                                          sizeof(_reply),
	                                          handles,
	                                          handle_count);
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_id = _reply.id;
	*out_image_count = _reply.image_count;
	*out_size = _reply.size;
	*out_use_dedicated_allocation = _reply.use_dedicated_allocation;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_import(struct ipc_connection *ipc_c,
                          const struct xrt_swapchain_create_info *info,
                          const struct ipc_arg_swapchain_from_native *args,
                          const xrt_graphics_buffer_handle_t *handles,
                          const uint32_t handle_count,
                          uint32_t *out_id)
{
	IPC_TRACE(ipc_c, "Calling swapchain_import");

	struct ipc_swapchain_import_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_IMPORT,
	    .info = *info,
	    .args = *args,
	    .handle_count = handle_count,
	};
	struct ipc_swapchain_import_reply _reply;
	struct ipc_result_reply _sync = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Send our handles separately

	// Wait for server sync
	ret = ipc_receive(&ipc_c->imc,
	                  &_sync,
	                  sizeof(_sync));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// We need this message data as filler only
	struct ipc_command_msg _handle_msg = {
	    .cmd = IPC_SWAPCHAIN_IMPORT,
	};

	ret = ipc_send_handles_graphics_buffer(&ipc_c->imc,
	                                       &_handle_msg,
	                                       sizeof(_handle_msg),
	                                       handles,
	                                       handle_count);
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_id = _reply.id;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_wait_image(struct ipc_connection *ipc_c,
                              uint32_t id,
                              uint64_t timeout_ns,
                              uint32_t index)
{
	IPC_TRACE(ipc_c, "Calling swapchain_wait_image");

	struct ipc_swapchain_wait_image_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_WAIT_IMAGE,
	    .id = id,
	    .timeout_ns = timeout_ns,
	    .index = index,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_acquire_image(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 uint32_t *out_index)
{
	IPC_TRACE(ipc_c, "Calling swapchain_acquire_image");

	struct ipc_swapchain_acquire_image_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_ACQUIRE_IMAGE,
	    .id = id,
	};
	struct ipc_swapchain_acquire_image_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_index = _reply.index;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_release_image(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 uint32_t index)
{
	IPC_TRACE(ipc_c, "Calling swapchain_release_image");

	struct ipc_swapchain_release_image_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_RELEASE_IMAGE,
	    .id = id,
	    .index = index,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_swapchain_destroy(struct ipc_connection *ipc_c,
                           uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling swapchain_destroy");

	struct ipc_swapchain_destroy_msg _msg = {
	    .cmd = IPC_SWAPCHAIN_DESTROY,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_semaphore_create(struct ipc_connection *ipc_c,
                                     uint32_t *out_id,
                                     xrt_graphics_sync_handle_t *handles,
                                     uint32_t handle_count)
{
	IPC_TRACE(ipc_c, "Calling compositor_semaphore_create");

	struct ipc_command_msg _msg = {
	    .cmd = IPC_COMPOSITOR_SEMAPHORE_CREATE,
	};
	struct ipc_compositor_semaphore_create_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive_handles_graphics_sync(&ipc_c->imc,
	                                        &_reply,
	                                        sizeof(_reply),
	                                        handles,
	                                        handle_count);
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_id = _reply.id;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_compositor_semaphore_destroy(struct ipc_connection *ipc_c,
                                      uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling compositor_semaphore_destroy");

	struct ipc_compositor_semaphore_destroy_msg _msg = {
	    .cmd = IPC_COMPOSITOR_SEMAPHORE_DESTROY,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_device_update_input(struct ipc_connection *ipc_c,
                             uint32_t id)
{
	IPC_TRACE(ipc_c, "Calling device_update_input");

	struct ipc_device_update_input_msg _msg = {
	    .cmd = IPC_DEVICE_UPDATE_INPUT,
	    .id = id,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_device_get_tracked_pose(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 enum xrt_input_name name,
                                 uint64_t at_timestamp,
                                 struct xrt_space_relation *out_relation)
{
	IPC_TRACE(ipc_c, "Calling device_get_tracked_pose");

	struct ipc_device_get_tracked_pose_msg _msg = {
	    .cmd = IPC_DEVICE_GET_TRACKED_POSE,
	    .id = id,
	    .name = name,
	    .at_timestamp = at_timestamp,
	};
	struct ipc_device_get_tracked_pose_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_relation = _reply.relation;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_device_get_hand_tracking(struct ipc_connection *ipc_c,
                                  uint32_t id,
                                  enum xrt_input_name name,
                                  uint64_t at_timestamp,
                                  struct xrt_hand_joint_set *out_value,
                                  uint64_t *out_timestamp)
{
	IPC_TRACE(ipc_c, "Calling device_get_hand_tracking");

	struct ipc_device_get_hand_tracking_msg _msg = {
	    .cmd = IPC_DEVICE_GET_HAND_TRACKING,
	    .id = id,
	    .name = name,
	    .at_timestamp = at_timestamp,
	};
	struct ipc_device_get_hand_tracking_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_value = _reply.value;
	*out_timestamp = _reply.timestamp;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_device_get_view_poses_2(struct ipc_connection *ipc_c,
                                 uint32_t id,
                                 const struct xrt_vec3 *fallback_eye_relation,
                                 uint64_t at_timestamp_ns,
                                 struct ipc_info_get_view_poses_2 *out_info)
{
	IPC_TRACE(ipc_c, "Calling device_get_view_poses_2");

	struct ipc_device_get_view_poses_2_msg _msg = {
	    .cmd = IPC_DEVICE_GET_VIEW_POSES_2,
	    .id = id,
	    .fallback_eye_relation = *fallback_eye_relation,
	    .at_timestamp_ns = at_timestamp_ns,
	};
	struct ipc_device_get_view_poses_2_reply _reply;

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}
	*out_info = _reply.info;

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}

xrt_result_t
ipc_call_device_set_output(struct ipc_connection *ipc_c,
                           uint32_t id,
                           enum xrt_output_name name,
                           const union xrt_output_value *value)
{
	IPC_TRACE(ipc_c, "Calling device_set_output");

	struct ipc_device_set_output_msg _msg = {
	    .cmd = IPC_DEVICE_SET_OUTPUT,
	    .id = id,
	    .name = name,
	    .value = *value,
	};
	struct ipc_result_reply _reply = {0};

	// Other threads must not read/write the fd while we wait for reply
	os_mutex_lock(&ipc_c->mutex);

	// Send our request
	xrt_result_t ret = ipc_send(&ipc_c->imc,
	                            &_msg,
	                            sizeof(_msg));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	// Await the reply
	ret = ipc_receive(&ipc_c->imc,
	                  &_reply,
	                  sizeof(_reply));
	if (ret != XRT_SUCCESS) {
		os_mutex_unlock(&ipc_c->mutex);
		return ret;
	}

	os_mutex_unlock(&ipc_c->mutex);
	return _reply.result;
}
