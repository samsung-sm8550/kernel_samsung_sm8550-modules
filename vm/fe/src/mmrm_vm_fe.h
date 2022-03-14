/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __MMRM_VM_FE_H__
#define __MMRM_VM_FE_H__

#include <mmrm_vm_msgq.h>
#include <mmrm_vm_interface.h>

struct mmrm_vm_fe_clk_src_info {
	struct mmrm_clk_client_desc client_desc;
	int flags;
};


struct mmrm_vm_fe_clk_src_set {
	struct mmrm_vm_fe_clk_src_info *clk_src_tbl;
	u32 count;
};

struct mmrm_vm_fe_priv {
	struct device *dev;

	struct mmrm_client *client_tbl;

	struct list_head mmrm_work_list;
	struct mutex work_list_lock;

	struct mmrm_vm_fe_clk_src_set clk_src_set;
	struct mutex msg_send_lock;
	int  seq_no;
};

/*
 * mmrm_vm_fe_recv_cb -- FE message receiving thread call this function
 *                       for transfer receiving packet to FE
 * @mmrm_vm: specific device driver info
 * @data: message pointer
 * @size: message size
 */
void mmrm_vm_fe_recv_cb(struct mmrm_vm_driver_data *mmrm_vm, void *data, size_t size);

/*
 * mmrm_vm_fe_request_send -- FE send mmrm request message
 * @mmrm_vm: device data, includes message handle
 * @msg_pkt: request message pointer
 * @msg_size: message size
 */
int mmrm_vm_fe_request_send(struct mmrm_vm_driver_data *mmrm_vm,
	struct mmrm_vm_request_msg_pkt *msg_pkt, size_t msg_size);

/*
 * get_client_id_2_handle -- get handle from client ID
 * @client_id: client ID
 */
struct mmrm_client *mmrm_vm_fe_get_client(u32 client_id);

/*
 * load_clk_resource_info -- get clk resource info from DT
 * @drv_priv: device data
 */
int mmrm_vm_fe_load_clk_rsrc(struct mmrm_vm_driver_data *drv_priv);

/*
 * mmrm_vm_fe_recv -- process received response info
 * @mmrm_vm: device data
 * @data: received response info buffer
 * @size: message size
 */
void mmrm_vm_fe_recv(struct mmrm_vm_driver_data *mmrm_vm, void *data, size_t size);

#endif /* __MMRM_VM_FE_H__ */


