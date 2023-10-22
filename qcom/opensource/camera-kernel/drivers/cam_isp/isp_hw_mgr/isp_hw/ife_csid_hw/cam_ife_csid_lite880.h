/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _CAM_IFE_CSID_LITE_880_H_
#define _CAM_IFE_CSID_LITE_880_H_

#include "cam_ife_csid_common.h"
#include "cam_ife_csid_dev.h"
#include "cam_ife_csid_hw_ver2.h"
#include "cam_irq_controller.h"
#include "cam_isp_hw_mgr_intf.h"

static const struct cam_ife_csid_irq_desc cam_ife_csid_lite_880_rx_irq_desc[] = {
	{
		.bitmask = BIT(0),
		.desc = "DL0_EOT",
	},
	{
		.bitmask = BIT(1),
		.desc = "DL1_EOT",
	},
	{
		.bitmask = BIT(2),
		.desc = "DL2_EOT",
	},
	{
		.bitmask = BIT(3),
		.desc = "DL3_EOT",
	},
	{
		.bitmask = BIT(4),
		.desc = "DL0_SOT",
	},
	{
		.bitmask = BIT(5),
		.desc = "DL1_SOT",
	},
	{
		.bitmask = BIT(6),
		.desc = "DL2_SOT",
	},
	{
		.bitmask = BIT(7),
		.desc = "DL3_SOT",
	},
	{
		.bitmask = BIT(8),
		.desc = "LONG_PKT",
	},
	{
		.bitmask = BIT(9),
		.desc = "SHORT_PKT",
	},
	{
		.bitmask = BIT(10),
		.desc = "CPHY_PKT_HDR",
	},
	{
		.bitmask = BIT(11),
		.desc = "ERROR_CPHY_EOT_RECEPTION",
	},
	{
		.bitmask = BIT(12),
		.desc = "ERROR_CPHY_SOT_RECEPTION",
	},
	{
		.bitmask = BIT(13),
		.desc = "ERROR_CPHY_PH_CRC",
	},
	{
		.bitmask = BIT(14),
		.desc = "WARNING_ECC",
	},
	{
		.bitmask = BIT(15),
		.desc = "ERROR_LANE0_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(16),
		.desc = "ERROR_LANE1_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(17),
		.desc = "ERROR_LANE2_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(18),
		.desc = "ERROR_LANE3_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(19),
		.desc = "ERROR_CRC",
	},
	{
		.bitmask = BIT(20),
		.desc = "ERROR_ECC",
	},
	{
		.bitmask = BIT(21),
		.desc = "ERROR_MMAPPED_VC_DT",
	},
	{
		.bitmask = BIT(22),
		.desc = "ERROR_UNMAPPED_VC_DT",
	},
	{
		.bitmask = BIT(23),
		.desc = "ERROR_STREAM_UNDERFLOW",
	},
	{
		.bitmask = BIT(24),
		.desc = "ERROR_UNBOUNDED_FRAME",
	},
	{
		.bitmask = BIT(25),
		.desc = "ERROR_ILLEGAL_PROGRAMMING_IRQ",
	},
	{
		.bitmask = BIT(26),
		.desc = "INFO_SENSOR_MODE_ID_CHANGE_IRQ",
	},
};

static const struct cam_ife_csid_irq_desc cam_ife_csid_lite_880_path_irq_desc[] = {
	{
		.bitmask = BIT(0),
		.err_type = CAM_ISP_HW_ERROR_CSID_FATAL,
		.desc = "ILLEGAL_PROGRAMMING",
		.err_handler = cam_ife_csid_ver2_print_illegal_programming_irq_status,
	},
	{
		.bitmask = BIT(1),
		.desc = "EROOR_MSG_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(2),
		.desc = "ERROR_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(3),
		.desc = "CAMIF_EOF",
	},
	{
		.bitmask = BIT(4),
		.desc = "CAMIF_SOF",
	},
	{
		.bitmask = BIT(5),
		.desc = "FRAME_DROP_EOF",
	},
	{
		.bitmask = BIT(6),
		.desc = "FRAME_DROP_EOL",
	},
	{
		.bitmask = BIT(7),
		.desc = "FRAME_DROP_SOL",
	},
	{
		.bitmask = BIT(8),
		.desc = "FRAME_DROP_SOF",
	},
	{
		.bitmask = BIT(9),
		.desc = "INFO_INPUT_EOF",
	},
	{
		.bitmask = BIT(10),
		.desc = "INFO_INPUT_EOL",
	},
	{
		.bitmask = BIT(11),
		.desc = "INFO_INPUT_SOL",
	},
	{
		.bitmask = BIT(12),
		.desc = "INFO_INPUT_SOF",
	},
	{
		.bitmask = BIT(13),
		.err_type = CAM_ISP_HW_ERROR_CSID_FRAME_SIZE,
		.desc = "ERROR_PIX_COUNT",
		.err_handler = cam_ife_csid_ver2_print_format_measure_info,
	},
	{
		.bitmask = BIT(14),
		.err_type = CAM_ISP_HW_ERROR_CSID_FRAME_SIZE,
		.desc = "ERROR_PIX_COUNT",
		.err_handler = cam_ife_csid_ver2_print_format_measure_info,
	},
	{
		.bitmask = BIT(15),
		.desc = "VCDT_GRP0_SEL",
	},
	{
		.bitmask = BIT(16),
		.desc = "VCDT_GRP1_SEL",
	},
	{
		.bitmask = BIT(17),
		.desc = "VCDT_GRP_CHANGE",
	},
	{
		.bitmask = BIT(18),
		.desc = "FRAME_DROP",
	},
	{
		.bitmask = BIT(19),
		.err_type = CAM_ISP_HW_ERROR_RECOVERY_OVERFLOW,
		.desc = "OVERFLOW_RECOVERY: Back pressure/output fifo ovrfl",
	},
	{
		.bitmask = BIT(20),
		.desc = "ERROR_REC_CCIF_VIOLATION From Camif",
	},
	{
		.bitmask = BIT(21),
		.desc = "CAMIF_EPOCH0",
	},
	{
		.bitmask = BIT(22),
		.desc = "CAMIF_EPOCH1",
	},
	{
		.bitmask = BIT(23),
		.desc = "RUP_DONE",
	},
	{
		.bitmask = BIT(24),
		.desc = "ILLEGAL_BATCH_ID",
	},
	{
		.bitmask = BIT(25),
		.desc = "BATCH_END_MISSING_VIOLATION",
	},
	{
		.bitmask = BIT(26),
		.desc = "HEIGHT_VIOLATION",
	},
	{
		.bitmask = BIT(27),
		.desc = "WIDTH_VIOLATION",
	},
	{
		.bitmask = BIT(28),
		.desc = "SENSOR_SWITCH_OUT_OF_SYNC_FRAME_DROP",
		.err_handler = cam_ife_csid_hw_ver2_mup_mismatch_handler,
	},
	{
		.bitmask = BIT(29),
		.desc = "CCIF_VIOLATION: Bad frame timings",
	},
};

static const struct cam_ife_csid_top_irq_desc cam_ife_csid_lite_880_top_irq_desc[] = {
	{
		.bitmask  = BIT(1),
		.err_type = CAM_ISP_HW_ERROR_CSID_SENSOR_SWITCH_ERROR,
		.err_name = "FATAL_SENSOR_SWITCHING_IRQ",
		.desc = "Fatal Error duirng dynamically switching between 2 sensors",
	},
	{
		.bitmask  = BIT(18),
		.err_type = CAM_ISP_HW_ERROR_RECOVERY_OVERFLOW,
		.err_name = "ERROR_NO_VOTE_DN",
		.desc = "vote_up is asserted before IDLE is encountered in a frame",
	},
	{
		.bitmask  = BIT(19),
		.err_type = CAM_ISP_HW_ERROR_RECOVERY_OVERFLOW,
		.err_name = "ERROR_VOTE_UP_LATE",
		.desc = "vote_up is asserted at the same time as an SOF",
	},
	{
		.bitmask  = BIT(20),
		.err_type = CAM_ISP_HW_ERROR_CSID_OUTPUT_FIFO_OVERFLOW,
		.err_name = "ERROR_RDI_LINE_BUFFER_CONFLICT",
		.desc = "Two or more RDIs programmed to access the shared line buffer",
		.err_handler = cam_ife_csid_hw_ver2_rdi_line_buffer_conflict_handler,
	},
};

static struct cam_irq_register_set cam_ife_csid_lite_880_irq_reg_set[9] = {
	/* Top */
	{
		.mask_reg_offset   = 0x00001080,
		.clear_reg_offset  = 0x00001084,
		.status_reg_offset = 0x0000107C,
		.set_reg_offset    = 0x00001088,
		.test_set_val      = BIT(0),
		.test_sub_val      = BIT(0),
	},
	/* RX */
	{
		.mask_reg_offset   = 0x000010A0,
		.clear_reg_offset  = 0x000010A4,
		.status_reg_offset = 0x0000109C,
	},
	/* RDI0 */
	{
		.mask_reg_offset   = 0x000010F0,
		.clear_reg_offset  = 0x000010F4,
		.status_reg_offset = 0x000010EC,
	},
	/* RDI1 */
	{
		.mask_reg_offset   = 0x00001100,
		.clear_reg_offset  = 0x00001104,
		.status_reg_offset = 0x000010FC,
	},
	/* RDI2 */
	{
		.mask_reg_offset   = 0x00001110,
		.clear_reg_offset  = 0x00001114,
		.status_reg_offset = 0x0000110C,
	},
	/* RDI3 */
	{
		.mask_reg_offset   = 0x00001120,
		.clear_reg_offset  = 0x00001124,
		.status_reg_offset = 0x0000111C,
	},
	{}, /* no RDI4 */
	/* IPP */
	{
		.mask_reg_offset   = 0x000010B0,
		.clear_reg_offset  = 0x000010B4,
		.status_reg_offset = 0x000010AC,
	},
	{}, /* no PPP */
};

static struct cam_irq_controller_reg_info cam_ife_csid_lite_880_top_irq_reg_info = {
	.num_registers = 1,
	.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_TOP],
	.global_irq_cmd_offset = 0x00001014,
	.global_set_bitmask    = 0x00000010,
	.global_clear_bitmask  = 0x00000001,
	.clear_all_bitmask     = 0xFFFFFFFF,
};

static struct cam_irq_controller_reg_info cam_ife_csid_lite_880_rx_irq_reg_info = {
	.num_registers = 1,
	.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_RX], /* RX */
	.global_irq_cmd_offset = 0,
};

static struct cam_irq_controller_reg_info cam_ife_csid_lite_880_path_irq_reg_info[6] = {
	{
		.num_registers = 1,
		.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_RDI_0],
		.global_irq_cmd_offset = 0,
	},
	{
		.num_registers = 1,
		.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_RDI_1],
		.global_irq_cmd_offset = 0,
	},
	{
		.num_registers = 1,
		.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_RDI_2],
		.global_irq_cmd_offset = 0,
	},
	{
		.num_registers = 1,
		.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_RDI_3],
		.global_irq_cmd_offset = 0,
	},
	{}, /* no RDI4 */
	{
		.num_registers = 1,
		.irq_reg_set = &cam_ife_csid_lite_880_irq_reg_set[CAM_IFE_CSID_IRQ_REG_IPP],
		.global_irq_cmd_offset = 0,
	},
};

static struct cam_irq_register_set cam_ife_csid_lite_880_buf_done_irq_reg_set[1] = {
	{
		.mask_reg_offset   = 0x00001090,
		.clear_reg_offset  = 0x00001094,
		.status_reg_offset = 0x0000108C,
	},
};

static struct cam_irq_controller_reg_info
	cam_ife_csid_lite_880_buf_done_irq_reg_info = {
	.num_registers = 1,
	.irq_reg_set = cam_ife_csid_lite_880_buf_done_irq_reg_set,
	.global_irq_cmd_offset  = 0, /* intentionally set to zero */
};

static struct cam_ife_csid_ver2_common_reg_info
			cam_ife_csid_lite_880_cmn_reg_info = {
	.hw_version_addr                              = 0x1000,
	.cfg0_addr                                    = 0x1004,
	.global_cmd_addr                              = 0x1008,
	.reset_cfg_addr                               = 0x100c,
	.reset_cmd_addr                               = 0x1010,
	.irq_cmd_addr                                 = 0x1014,
	.rup_aup_cmd_addr                             = 0x1018,
	.offline_cmd_addr                             = 0x101C,
	.shdr_master_slave_cfg_addr                   = 0x1020,
	.top_irq_status_addr                          = 0x107C,
	.top_irq_mask_addr                            = 0x1080,
	.top_irq_clear_addr                           = 0x1084,
	.top_irq_set_addr                             = 0x1088,
	.buf_done_irq_status_addr                     = 0x108C,
	.buf_done_irq_mask_addr                       = 0x1090,
	.buf_done_irq_clear_addr                      = 0x1094,
	.buf_done_irq_set_addr                        = 0x1098,
	.path_domain_id_cfg0                          = 0x0,
	.path_domain_id_cfg1                          = 0x4,

	/*configurations */
	.major_version                                = 6,
	.minor_version                                = 8,
	.version_incr                                 = 0,
	.num_rdis                                     = 4,
	.num_pix                                      = 1,
	.num_ppp                                      = 0,
	.rst_done_shift_val                           = 1,
	.path_en_shift_val                            = 31,
	.dt_id_shift_val                              = 27,
	.vc_shift_val                                 = 22,
	.vc_mask                                      = 0x1F,
	.dt_shift_val                                 = 16,
	.dt_mask                                      = 0x3F,
	.crop_shift_val                               = 16,
	.decode_format_shift_val                      = 12,
	.decode_format1_shift_val                     = 16,
	.decode_format_mask                           = 0xF,
	.decode_format1_supported                     = true,
	.frame_id_decode_en_shift_val                 = 1,
	.multi_vcdt_vc1_shift_val                     = 2,
	.multi_vcdt_dt1_shift_val                     = 7,
	.multi_vcdt_en_shift_val                      = 0,
	.timestamp_stb_sel_shift_val                  = 8,
	.vfr_en_shift_val                             = 0,
	.early_eof_supported                          = 1,
	.vfr_supported                                = 1,
	.multi_vcdt_supported                         = 1,
	.frame_id_dec_supported                       = 1,
	.measure_en_hbi_vbi_cnt_mask                  = 0xc,
	.measure_pixel_line_en_mask                   = 0x3,
	.crop_pix_start_mask                          = 0x3fff,
	.crop_pix_end_mask                            = 0xffff,
	.crop_line_start_mask                         = 0x3fff,
	.crop_line_end_mask                           = 0xffff,
	.drop_supported                               = 1,
	.ipp_irq_mask_all                             = 0x7FFF,
	.rdi_irq_mask_all                             = 0x7FFF,
	.rst_loc_path_only_val                        = 0x0,
	.rst_location_shift_val                       = 4,
	.rst_loc_complete_csid_val                    = 0x1,
	.rst_mode_frame_boundary_val                  = 0x0,
	.rst_mode_immediate_val                       = 0x1,
	.rst_cmd_hw_reset_complete_val                = 0x1,
	.rst_cmd_sw_reset_complete_val                = 0x2,
	.rst_cmd_irq_ctrl_only_val                    = 0x4,
	.timestamp_strobe_val                         = 0x2,
	.global_reset                                 = 1,
	.rup_supported                                = 1,
	.only_master_rup                              = 1,
	.top_reset_irq_mask                           = 0x1,
	.top_buf_done_irq_mask                        = 0x2000,
	.decode_format_payload_only                   = 0xF,
	.phy_sel_base_idx                             = 1,
	.timestamp_enabled_in_cfg0                    = true,
	.camif_irq_support                            = true,
};

static struct cam_ife_csid_csi2_rx_reg_info
	cam_ife_csid_lite_880_csi2_reg_info = {
		.irq_status_addr                      = 0x109C,
		.irq_mask_addr                        = 0x10A0,
		.irq_clear_addr                       = 0x10A4,
		.irq_set_addr                         = 0x10A8,
		/*CSI2 rx control */
		.cfg0_addr                            = 0x1200,
		.cfg1_addr                            = 0x1204,
		.capture_ctrl_addr                    = 0x1208,
		.rst_strobes_addr                     = 0x120C,
		.cap_unmap_long_pkt_hdr_0_addr        = 0x1210,
		.cap_unmap_long_pkt_hdr_1_addr        = 0x1214,
		.captured_short_pkt_0_addr            = 0x1218,
		.captured_short_pkt_1_addr            = 0x121c,
		.captured_long_pkt_0_addr             = 0x1220,
		.captured_long_pkt_1_addr             = 0x1224,
		.captured_long_pkt_ftr_addr           = 0x1228,
		.captured_cphy_pkt_hdr_addr           = 0x122c,
		.lane0_misr_addr                      = 0x1230,
		.lane1_misr_addr                      = 0x1234,
		.lane2_misr_addr                      = 0x1238,
		.lane3_misr_addr                      = 0x123c,
		.total_pkts_rcvd_addr                 = 0x1240,
		.stats_ecc_addr                       = 0x1244,
		.total_crc_err_addr                   = 0x1248,
		.de_scramble_type3_cfg0_addr          = 0x124C,
		.de_scramble_type3_cfg1_addr          = 0x1250,
		.de_scramble_type2_cfg0_addr          = 0x1254,
		.de_scramble_type2_cfg1_addr          = 0x1258,
		.de_scramble_type1_cfg0_addr          = 0x125C,
		.de_scramble_type1_cfg1_addr          = 0x1260,
		.de_scramble_type0_cfg0_addr          = 0x1264,
		.de_scramble_type0_cfg1_addr          = 0x1268,
		.secure_cfg0                          = 0x8,
		.secure_mask_cfg0                     = 0xC,

		.rst_done_shift_val                   = 27,
		.irq_mask_all                         = 0xFFFFFFF,
		.misr_enable_shift_val                = 6,
		.vc_mode_shift_val                    = 2,
		.capture_long_pkt_en_shift            = 0,
		.capture_short_pkt_en_shift           = 1,
		.capture_cphy_pkt_en_shift            = 2,
		.capture_long_pkt_dt_shift            = 4,
		.capture_long_pkt_vc_shift            = 10,
		.capture_short_pkt_vc_shift           = 15,
		.capture_cphy_pkt_dt_shift            = 20,
		.capture_cphy_pkt_vc_shift            = 26,
		.phy_num_mask                         = 0xf,
		.vc_mask                              = 0x7C00000,
		.dt_mask                              = 0x3f0000,
		.wc_mask                              = 0xffff,
		.vc_shift                             = 0x16,
		.dt_shift                             = 0x10,
		.wc_shift                             = 0,
		.calc_crc_mask                        = 0xffff,
		.expected_crc_mask                    = 0xffff,
		.calc_crc_shift                       = 0x10,
		.ecc_correction_shift_en              = 0,
		.lane_num_shift                       = 0,
		.lane_cfg_shift                       = 4,
		.phy_type_shift                       = 24,
		.phy_num_shift                        = 20,
		.tpg_mux_en_shift                     = 27,
		.tpg_num_sel_shift                    = 28,
		.phy_bist_shift_en                    = 7,
		.epd_mode_shift_en                    = 8,
		.eotp_shift_en                        = 9,
		.dyn_sensor_switch_shift_en           = 10,
		.rup_aup_latch_shift                  = 11,
		.rup_aup_latch_supported              = true,
		.long_pkt_strobe_rst_shift            = 0,
		.short_pkt_strobe_rst_shift           = 1,
		.cphy_pkt_strobe_rst_shift            = 2,
		.unmapped_pkt_strobe_rst_shift        = 3,
		.fatal_err_mask                       = 0x19FA800,
		.part_fatal_err_mask                  = 0x0001000,
		.non_fatal_err_mask                   = 0x0200000,
		.top_irq_mask                         = 0x4,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_880_ipp_reg_info = {
		.irq_status_addr                      = 0x10AC,
		.irq_mask_addr                        = 0x10B0,
		.irq_clear_addr                       = 0x10B4,
		.irq_set_addr                         = 0x10B8,
		.cfg0_addr                            = 0x1300,
		.ctrl_addr                            = 0x1304,
		.debug_clr_cmd_addr                   = 0x1308,
		.multi_vcdt_cfg0_addr                 = 0x130c,
		.cfg1_addr                            = 0x1310,
		.err_recovery_cfg0_addr               = 0x1318,
		.err_recovery_cfg1_addr               = 0x131C,
		.err_recovery_cfg2_addr               = 0x1320,
		.camif_frame_cfg_addr                 = 0x1330,
		.epoch_irq_cfg_addr                   = 0x1334,
		.epoch0_subsample_ptrn_addr           = 0x1338,
		.epoch1_subsample_ptrn_addr           = 0x133C,
		.debug_camif_1_addr                   = 0x1340,
		.debug_camif_0_addr                   = 0x1344,
		.debug_halt_status_addr               = 0x1348,
		.debug_misr_val0_addr                 = 0x134C,
		.debug_misr_val1_addr                 = 0x1350,
		.debug_misr_val2_addr                 = 0x1354,
		.debug_misr_val3_addr                 = 0x1358,
		.hcrop_addr                           = 0x135c,
		.vcrop_addr                           = 0x1360,
		.pix_drop_pattern_addr                = 0x1364,
		.pix_drop_period_addr                 = 0x1368,
		.line_drop_pattern_addr               = 0x136C,
		.line_drop_period_addr                = 0x1370,
		.frm_drop_pattern_addr                = 0x1374,
		.frm_drop_period_addr                 = 0x1378,
		.irq_subsample_pattern_addr           = 0x137C,
		.irq_subsample_period_addr            = 0x1380,
		.format_measure_cfg0_addr             = 0x1384,
		.format_measure_cfg1_addr             = 0x1388,
		.format_measure0_addr                 = 0x138C,
		.format_measure1_addr                 = 0x1390,
		.format_measure2_addr                 = 0x1394,
		.timestamp_curr0_sof_addr             = 0x1398,
		.timestamp_curr1_sof_addr             = 0x139C,
		.timestamp_perv0_sof_addr             = 0x13A0,
		.timestamp_perv1_sof_addr             = 0x13A4,
		.timestamp_curr0_eof_addr             = 0x13A8,
		.timestamp_curr1_eof_addr             = 0x13AC,
		.timestamp_perv0_eof_addr             = 0x13B0,
		.timestamp_perv1_eof_addr             = 0x13B4,
		.batch_period_cfg_addr                = 0x13C4,
		.batch_stream_id_cfg_addr             = 0x13C8,
		.epoch0_cfg_batch_id0_addr            = 0x13CC,
		.epoch1_cfg_batch_id0_addr            = 0x13D0,
		.epoch0_cfg_batch_id1_addr            = 0x13D4,
		.epoch1_cfg_batch_id1_addr            = 0x13D8,
		.epoch0_cfg_batch_id2_addr            = 0x13DC,
		.epoch1_cfg_batch_id2_addr            = 0x13E0,
		.epoch0_cfg_batch_id3_addr            = 0x13E4,
		.epoch1_cfg_batch_id3_addr            = 0x13E8,
		.epoch0_cfg_batch_id4_addr            = 0x13EC,
		.epoch1_cfg_batch_id4_addr            = 0x13F0,
		.epoch0_cfg_batch_id5_addr            = 0x13F4,
		.epoch1_cfg_batch_id5_addr            = 0x13F8,
		.secure_mask_cfg0                     = 0x10,

		/* configurations */
		.start_mode_internal                  = 0x0,
		.start_mode_global                    = 0x1,
		.start_mode_master                    = 0x2,
		.start_mode_slave                     = 0x3,
		.start_mode_shift                     = 2,
		.start_master_sel_val                 = 0,
		.start_master_sel_shift               = 4,
		.resume_frame_boundary                = 1,
		.crop_v_en_shift_val                  = 13,
		.crop_h_en_shift_val                  = 12,
		.drop_v_en_shift_val                  = 11,
		.drop_h_en_shift_val                  = 10,
		.pix_store_en_shift_val               = 14,
		.early_eof_en_shift_val               = 16,
		.format_measure_en_shift_val          = 8,
		.timestamp_en_shift_val               = 6,
		.overflow_ctrl_en                     = 1,
		.overflow_ctrl_mode_val               = 0x8,
		.min_hbi_shift_val                    = 4,
		.start_master_sel_shift_val           = 4,
		.fatal_err_mask                       = 0x7,
		.non_fatal_err_mask                   = 0x10080000,
		.sof_irq_mask                         = 0x10,
		.rup_irq_mask                         = 0x800000,
		.epoch0_irq_mask                      = 0x200000,
		.epoch1_irq_mask                      = 0x400000,
		.eof_irq_mask                         = 0x8,
		.rup_aup_mask                         = 0x10001,
		.top_irq_mask                         = 0x10,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_880_rdi_0_reg_info = {
		.irq_status_addr                     = 0x10EC,
		.irq_mask_addr                       = 0x10F0,
		.irq_clear_addr                      = 0x10F4,
		.irq_set_addr                        = 0x10F8,
		.cfg0_addr                           = 0x1500,
		.ctrl_addr                           = 0x1504,
		.debug_clr_cmd_addr                  = 0x1508,
		.multi_vcdt_cfg0_addr                = 0x150c,
		.cfg1_addr                           = 0x1510,
		.err_recovery_cfg0_addr              = 0x1514,
		.err_recovery_cfg1_addr              = 0x1518,
		.err_recovery_cfg2_addr              = 0x151C,
		.debug_byte_cntr_ping_addr           = 0x1520,
		.debug_byte_cntr_pong_addr           = 0x1524,
		.camif_frame_cfg_addr                = 0x1528,
		.epoch_irq_cfg_addr                  = 0x152C,
		.epoch0_subsample_ptrn_addr          = 0x1530,
		.epoch1_subsample_ptrn_addr          = 0x1534,
		.debug_camif_1_addr                  = 0x1538,
		.debug_camif_0_addr                  = 0x153C,
		.frm_drop_pattern_addr               = 0x1540,
		.frm_drop_period_addr                = 0x1540,
		.irq_subsample_pattern_addr          = 0x1548,
		.irq_subsample_period_addr           = 0x154C,
		.hcrop_addr                          = 0x1550,
		.vcrop_addr                          = 0x1554,
		.pix_drop_pattern_addr               = 0x1558,
		.pix_drop_period_addr                = 0x155C,
		.line_drop_pattern_addr              = 0x1560,
		.line_drop_period_addr               = 0x1564,
		.debug_halt_status_addr              = 0x1568,
		.debug_misr_val0_addr                = 0x1570,
		.debug_misr_val1_addr                = 0x1574,
		.debug_misr_val2_addr                = 0x1578,
		.debug_misr_val3_addr                = 0x157C,
		.format_measure_cfg0_addr            = 0x1580,
		.format_measure_cfg1_addr            = 0x1584,
		.format_measure0_addr                = 0x1588,
		.format_measure1_addr                = 0x158C,
		.format_measure2_addr                = 0x1590,
		.timestamp_curr0_sof_addr            = 0x1594,
		.timestamp_curr1_sof_addr            = 0x1598,
		.timestamp_perv0_sof_addr            = 0x159C,
		.timestamp_perv1_sof_addr            = 0x15A0,
		.timestamp_curr0_eof_addr            = 0x15A4,
		.timestamp_curr1_eof_addr            = 0x15A8,
		.timestamp_perv0_eof_addr            = 0x15AC,
		.timestamp_perv1_eof_addr            = 0x15B0,
		.batch_period_cfg_addr               = 0x15BC,
		.batch_stream_id_cfg_addr            = 0x15C0,
		.epoch0_cfg_batch_id0_addr           = 0x15C4,
		.epoch1_cfg_batch_id0_addr           = 0x15C8,
		.epoch0_cfg_batch_id1_addr           = 0x15CC,
		.epoch1_cfg_batch_id1_addr           = 0x15D0,
		.epoch0_cfg_batch_id2_addr           = 0x15D4,
		.epoch1_cfg_batch_id2_addr           = 0x15D8,
		.epoch0_cfg_batch_id3_addr           = 0x15DC,
		.epoch1_cfg_batch_id3_addr           = 0x15E0,
		.epoch0_cfg_batch_id4_addr           = 0x15E4,
		.epoch1_cfg_batch_id4_addr           = 0x15E8,
		.epoch0_cfg_batch_id5_addr           = 0x15EC,
		.epoch1_cfg_batch_id5_addr           = 0x15F0,
		.secure_mask_cfg0                    = 0x18,

		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.mipi_pack_supported                 = 1,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.sof_irq_mask                        = 0x10,
		.rup_irq_mask                        = 0x800000,
		.epoch0_irq_mask                     = 0x200000,
		.epoch1_irq_mask                     = 0x400000,
		.eof_irq_mask                        = 0x8,
		.rup_aup_mask                        = 0x100010,
		.top_irq_mask                        = 0x100,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_880_rdi_1_reg_info = {
		.irq_status_addr                     = 0x10FC,
		.irq_mask_addr                       = 0x1100,
		.irq_clear_addr                      = 0x1104,
		.irq_set_addr                        = 0x1108,
		.cfg0_addr                           = 0x1600,
		.ctrl_addr                           = 0x1604,
		.debug_clr_cmd_addr                  = 0x1608,
		.multi_vcdt_cfg0_addr                = 0x160c,
		.cfg1_addr                           = 0x1610,
		.err_recovery_cfg0_addr              = 0x1614,
		.err_recovery_cfg1_addr              = 0x1618,
		.err_recovery_cfg2_addr              = 0x161C,
		.debug_byte_cntr_ping_addr           = 0x1620,
		.debug_byte_cntr_pong_addr           = 0x1624,
		.camif_frame_cfg_addr                = 0x1628,
		.epoch_irq_cfg_addr                  = 0x162C,
		.epoch0_subsample_ptrn_addr          = 0x1630,
		.epoch1_subsample_ptrn_addr          = 0x1634,
		.debug_camif_1_addr                  = 0x1638,
		.debug_camif_0_addr                  = 0x163C,
		.frm_drop_pattern_addr               = 0x1640,
		.frm_drop_period_addr                = 0x1644,
		.irq_subsample_pattern_addr          = 0x1648,
		.irq_subsample_period_addr           = 0x164C,
		.hcrop_addr                          = 0x1650,
		.vcrop_addr                          = 0x1654,
		.pix_drop_pattern_addr               = 0x1658,
		.pix_drop_period_addr                = 0x165C,
		.line_drop_pattern_addr              = 0x1660,
		.line_drop_period_addr               = 0x1664,
		.debug_halt_status_addr              = 0x166C,
		.debug_misr_val0_addr                = 0x1670,
		.debug_misr_val1_addr                = 0x1674,
		.debug_misr_val2_addr                = 0x1678,
		.debug_misr_val3_addr                = 0x167C,
		.format_measure_cfg0_addr            = 0x1680,
		.format_measure_cfg1_addr            = 0x1684,
		.format_measure0_addr                = 0x1688,
		.format_measure1_addr                = 0x168C,
		.format_measure2_addr                = 0x1690,
		.timestamp_curr0_sof_addr            = 0x1694,
		.timestamp_curr1_sof_addr            = 0x1698,
		.timestamp_perv0_sof_addr            = 0x169C,
		.timestamp_perv1_sof_addr            = 0x16A0,
		.timestamp_curr0_eof_addr            = 0x16A4,
		.timestamp_curr1_eof_addr            = 0x16A8,
		.timestamp_perv0_eof_addr            = 0x16AC,
		.timestamp_perv1_eof_addr            = 0x16B0,
		.batch_period_cfg_addr               = 0x16BC,
		.batch_stream_id_cfg_addr            = 0x16C0,
		.epoch0_cfg_batch_id0_addr           = 0x16C4,
		.epoch1_cfg_batch_id0_addr           = 0x16C8,
		.epoch0_cfg_batch_id1_addr           = 0x16CC,
		.epoch1_cfg_batch_id1_addr           = 0x16D0,
		.epoch0_cfg_batch_id2_addr           = 0x16D4,
		.epoch1_cfg_batch_id2_addr           = 0x16D8,
		.epoch0_cfg_batch_id3_addr           = 0x16DC,
		.epoch1_cfg_batch_id3_addr           = 0x16E0,
		.epoch0_cfg_batch_id4_addr           = 0x16E4,
		.epoch1_cfg_batch_id4_addr           = 0x16E8,
		.epoch0_cfg_batch_id5_addr           = 0x16EC,
		.epoch1_cfg_batch_id5_addr           = 0x16F0,
		.secure_mask_cfg0                    = 0x1C,

		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.mipi_pack_supported                 = 1,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.sof_irq_mask                        = 0x10,
		.rup_irq_mask                        = 0x800000,
		.epoch0_irq_mask                     = 0x200000,
		.epoch1_irq_mask                     = 0x400000,
		.eof_irq_mask                        = 0x8,
		.rup_aup_mask                        = 0x200020,
		.top_irq_mask                        = 0x200,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_880_rdi_2_reg_info = {
		.irq_status_addr                     = 0x110C,
		.irq_mask_addr                       = 0x1110,
		.irq_clear_addr                      = 0x1114,
		.irq_set_addr                        = 0x1118,
		.cfg0_addr                           = 0x1700,
		.ctrl_addr                           = 0x1704,
		.debug_clr_cmd_addr                  = 0x1708,
		.multi_vcdt_cfg0_addr                = 0x170c,
		.cfg1_addr                           = 0x1710,
		.err_recovery_cfg0_addr              = 0x1714,
		.err_recovery_cfg1_addr              = 0x1718,
		.err_recovery_cfg2_addr              = 0x171C,
		.debug_byte_cntr_ping_addr           = 0x1720,
		.debug_byte_cntr_pong_addr           = 0x1724,
		.camif_frame_cfg_addr                = 0x1728,
		.epoch_irq_cfg_addr                  = 0x172C,
		.epoch0_subsample_ptrn_addr          = 0x1730,
		.epoch1_subsample_ptrn_addr          = 0x1734,
		.debug_camif_1_addr                  = 0x1738,
		.debug_camif_0_addr                  = 0x173C,
		.frm_drop_pattern_addr               = 0x1740,
		.frm_drop_period_addr                = 0x1744,
		.irq_subsample_pattern_addr          = 0x1748,
		.irq_subsample_period_addr           = 0x174C,
		.hcrop_addr                          = 0x1750,
		.vcrop_addr                          = 0x1754,
		.pix_drop_pattern_addr               = 0x1758,
		.pix_drop_period_addr                = 0x175C,
		.line_drop_pattern_addr              = 0x1760,
		.line_drop_period_addr               = 0x1764,
		.debug_halt_status_addr              = 0x176C,
		.debug_misr_val0_addr                = 0x1770,
		.debug_misr_val1_addr                = 0x1774,
		.debug_misr_val2_addr                = 0x1778,
		.debug_misr_val3_addr                = 0x177C,
		.format_measure_cfg0_addr            = 0x1780,
		.format_measure_cfg1_addr            = 0x1784,
		.format_measure0_addr                = 0x1788,
		.format_measure1_addr                = 0x178C,
		.format_measure2_addr                = 0x1790,
		.timestamp_curr0_sof_addr            = 0x1794,
		.timestamp_curr1_sof_addr            = 0x1798,
		.timestamp_perv0_sof_addr            = 0x179C,
		.timestamp_perv1_sof_addr            = 0x17A0,
		.timestamp_curr0_eof_addr            = 0x17A4,
		.timestamp_curr1_eof_addr            = 0x17A8,
		.timestamp_perv0_eof_addr            = 0x17AC,
		.timestamp_perv1_eof_addr            = 0x17B0,
		.batch_period_cfg_addr               = 0x17BC,
		.batch_stream_id_cfg_addr            = 0x17C0,
		.epoch0_cfg_batch_id0_addr           = 0x17C4,
		.epoch1_cfg_batch_id0_addr           = 0x17C8,
		.epoch0_cfg_batch_id1_addr           = 0x17CC,
		.epoch1_cfg_batch_id1_addr           = 0x17D0,
		.epoch0_cfg_batch_id2_addr           = 0x17D4,
		.epoch1_cfg_batch_id2_addr           = 0x17D8,
		.epoch0_cfg_batch_id3_addr           = 0x17DC,
		.epoch1_cfg_batch_id3_addr           = 0x17E0,
		.epoch0_cfg_batch_id4_addr           = 0x17E4,
		.epoch1_cfg_batch_id4_addr           = 0x17E8,
		.epoch0_cfg_batch_id5_addr           = 0x17EC,
		.epoch1_cfg_batch_id5_addr           = 0x17F0,
		.secure_mask_cfg0                    = 0x20,

		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.mipi_pack_supported                 = 1,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.sof_irq_mask                        = 0x10,
		.rup_irq_mask                        = 0x800000,
		.epoch0_irq_mask                     = 0x200000,
		.epoch1_irq_mask                     = 0x400000,
		.eof_irq_mask                        = 0x8,
		.rup_aup_mask                        = 0x400040,
		.top_irq_mask                        = 0x400,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_880_rdi_3_reg_info = {
		.irq_status_addr                     = 0x111C,
		.irq_mask_addr                       = 0x1120,
		.irq_clear_addr                      = 0x1124,
		.irq_set_addr                        = 0x1128,
		.cfg0_addr                           = 0x1800,
		.ctrl_addr                           = 0x1804,
		.debug_clr_cmd_addr                  = 0x1808,
		.multi_vcdt_cfg0_addr                = 0x180c,
		.cfg1_addr                           = 0x1810,
		.err_recovery_cfg0_addr              = 0x1814,
		.err_recovery_cfg1_addr              = 0x1818,
		.err_recovery_cfg2_addr              = 0x181C,
		.debug_byte_cntr_ping_addr           = 0x1820,
		.debug_byte_cntr_pong_addr           = 0x1824,
		.camif_frame_cfg_addr                = 0x1828,
		.epoch_irq_cfg_addr                  = 0x182C,
		.epoch0_subsample_ptrn_addr          = 0x1830,
		.epoch1_subsample_ptrn_addr          = 0x1834,
		.debug_camif_1_addr                  = 0x1838,
		.debug_camif_0_addr                  = 0x183C,
		.frm_drop_pattern_addr               = 0x1840,
		.frm_drop_period_addr                = 0x1840,
		.irq_subsample_pattern_addr          = 0x1848,
		.irq_subsample_period_addr           = 0x184C,
		.hcrop_addr                          = 0x1850,
		.vcrop_addr                          = 0x1854,
		.pix_drop_pattern_addr               = 0x1858,
		.pix_drop_period_addr                = 0x185C,
		.line_drop_pattern_addr              = 0x1860,
		.line_drop_period_addr               = 0x1864,
		.debug_halt_status_addr              = 0x1868,
		.debug_misr_val0_addr                = 0x1870,
		.debug_misr_val1_addr                = 0x1874,
		.debug_misr_val2_addr                = 0x1878,
		.debug_misr_val3_addr                = 0x187C,
		.format_measure_cfg0_addr            = 0x1880,
		.format_measure_cfg1_addr            = 0x1884,
		.format_measure0_addr                = 0x1888,
		.format_measure1_addr                = 0x188C,
		.format_measure2_addr                = 0x1890,
		.timestamp_curr0_sof_addr            = 0x1894,
		.timestamp_curr1_sof_addr            = 0x1898,
		.timestamp_perv0_sof_addr            = 0x189C,
		.timestamp_perv1_sof_addr            = 0x18A0,
		.timestamp_curr0_eof_addr            = 0x18A4,
		.timestamp_curr1_eof_addr            = 0x18A8,
		.timestamp_perv0_eof_addr            = 0x18AC,
		.timestamp_perv1_eof_addr            = 0x18B0,
		.batch_period_cfg_addr               = 0x18BC,
		.batch_stream_id_cfg_addr            = 0x18C0,
		.epoch0_cfg_batch_id0_addr           = 0x18C4,
		.epoch1_cfg_batch_id0_addr           = 0x18C8,
		.epoch0_cfg_batch_id1_addr           = 0x18CC,
		.epoch1_cfg_batch_id1_addr           = 0x18D0,
		.epoch0_cfg_batch_id2_addr           = 0x18D4,
		.epoch1_cfg_batch_id2_addr           = 0x18D8,
		.epoch0_cfg_batch_id3_addr           = 0x18DC,
		.epoch1_cfg_batch_id3_addr           = 0x18E0,
		.epoch0_cfg_batch_id4_addr           = 0x18E4,
		.epoch1_cfg_batch_id4_addr           = 0x18E8,
		.epoch0_cfg_batch_id5_addr           = 0x18EC,
		.epoch1_cfg_batch_id5_addr           = 0x18F0,
		.secure_mask_cfg0                    = 0x24,

		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.mipi_pack_supported                 = 1,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.sof_irq_mask                        = 0x10,
		.rup_irq_mask                        = 0x800000,
		.epoch0_irq_mask                     = 0x200000,
		.epoch1_irq_mask                     = 0x400000,
		.eof_irq_mask                        = 0x8,
		.rup_aup_mask                        = 0x800080,
		.top_irq_mask                        = 0x800,
};

static struct cam_ife_csid_ver2_reg_info cam_ife_csid_lite_880_reg_info = {
	.top_irq_reg_info      = &cam_ife_csid_lite_880_top_irq_reg_info,
	.rx_irq_reg_info       = &cam_ife_csid_lite_880_rx_irq_reg_info,
	.path_irq_reg_info     = {
		&cam_ife_csid_lite_880_path_irq_reg_info[CAM_IFE_PIX_PATH_RES_RDI_0],
		&cam_ife_csid_lite_880_path_irq_reg_info[CAM_IFE_PIX_PATH_RES_RDI_1],
		&cam_ife_csid_lite_880_path_irq_reg_info[CAM_IFE_PIX_PATH_RES_RDI_2],
		&cam_ife_csid_lite_880_path_irq_reg_info[CAM_IFE_PIX_PATH_RES_RDI_3],
		NULL,
		&cam_ife_csid_lite_880_path_irq_reg_info[CAM_IFE_PIX_PATH_RES_IPP],
		},
	.buf_done_irq_reg_info = &cam_ife_csid_lite_880_buf_done_irq_reg_info,
	.cmn_reg               = &cam_ife_csid_lite_880_cmn_reg_info,
	.csi2_reg              = &cam_ife_csid_lite_880_csi2_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_IPP]   = &cam_ife_csid_lite_880_ipp_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_PPP]   = NULL,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_0] = &cam_ife_csid_lite_880_rdi_0_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_1] = &cam_ife_csid_lite_880_rdi_1_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_2] = &cam_ife_csid_lite_880_rdi_2_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_3] = &cam_ife_csid_lite_880_rdi_3_reg_info,
	.need_top_cfg = 0,
	.rx_irq_desc        = cam_ife_csid_lite_880_rx_irq_desc,
	.path_irq_desc      = cam_ife_csid_lite_880_path_irq_desc,
	.top_irq_desc       = cam_ife_csid_lite_880_top_irq_desc,
	.num_top_err_irqs   = ARRAY_SIZE(cam_ife_csid_lite_880_top_irq_desc),
};
#endif /* _CAM_IFE_CSID_LITE_780_H_ */
