// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2020-2020 Oplus. All rights reserved.
 */

#ifndef __OPLUS_CHG_WLS_H__
#define __OPLUS_CHG_WLS_H__

#include <linux/completion.h>
#include <linux/mutex.h>
#ifdef CONFIG_OPLUS_CHG_OOS
#include <linux/oem/oplus_chg.h>
#include <linux/oem/oplus_chg_voter.h>
#else
#include <linux/oplus_chg.h>
#include <linux/oplus_chg_voter.h>
#endif
#include <linux/miscdevice.h>
#include "oplus_chg_comm.h"
#include "oplus_chg_strategy.h"

#define JEITA_VOTER		"JEITA_VOTER"
#define STEP_VOTER		"STEP_VOTER"
#define USER_VOTER		"USER_VOTER"
#define DEF_VOTER		"DEF_VOTER"
#define MAX_VOTER		"MAX_VOTER"
#define BASE_MAX_VOTER		"BASE_MAX_VOTER"
#define RX_MAX_VOTER		"RX_MAX_VOTER"
#define EXIT_VOTER		"EXIT_VOTER"
#define FCC_VOTER		"FCC_VOTER"
#define CEP_VOTER		"CEP_VOTER"
#define QUIET_VOTER		"QUIET_VOTER"
#define BATT_VOL_VOTER		"BATT_VOL_VOTER"
#define BATT_CURR_VOTER		"BATT_CURR_VOTER"
#define IOUT_CURR_VOTER		"IOUT_CURR_VOTER"
#define SKIN_VOTER		"SKIN_VOTER"
#define STARTUP_CEP_VOTER	"STARTUP_CEP_VOTER"
#define HW_ERR_VOTER		"HW_ERR_VOTER"
#define CURR_ERR_VOTER		"CURR_ERR_VOTER"
#define OTG_EN_VOTER		"OTG_EN_VOTER"
#define TRX_EN_VOTER		"TRX_EN_VOTER"
#define UPGRADE_FW_VOTER	"UPGRADE_FW_VOTER"
#define DEBUG_VOTER		"DEBUG_VOTER"
#define FFC_VOTER		"FFC_VOTER"
#define USB_VOTER		"USB_VOTER"
#define UPGRADE_VOTER		"UPGRADE_VOTER"
#define CONNECT_VOTER		"CONNECT_VOTER"
#define UOVP_VOTER		"UOVP_VOTER"
#define STOP_VOTER		"STOP_VOTER"
#define FTM_TEST_VOTER		"FTM_TEST_VOTER"
#define CAMERA_VOTER		"CAMERA_VOTER"
#define CALL_VOTER		"CALL_VOTER"
#define COOL_DOWN_VOTER		"COOL_DOWN_VOTER"
#define RX_IIC_VOTER		"RX_IIC_VOTER"
#define TIMEOUT_VOTER		"TIMEOUT_VOTER"
#define CHG_DONE_VOTER		"CHG_DONE_VOTER"

#define WLS_SUPPORT_OPLUS_CHG

#define WLS_TRX_STATUS_READY		BIT(0)
#define WLS_TRX_STATUS_DIGITALPING	BIT(1)
#define WLS_TRX_STATUS_ANALOGPING	BIT(2)
#define WLS_TRX_STATUS_TRANSFER		BIT(3)

#define WLS_TRX_ERR_RXAC		BIT(0)
#define WLS_TRX_ERR_OCP			BIT(1)
#define WLS_TRX_ERR_OVP			BIT(2)
#define WLS_TRX_ERR_LVP			BIT(3)
#define WLS_TRX_ERR_FOD			BIT(4)
#define WLS_TRX_ERR_OTP			BIT(5)
#define WLS_TRX_ERR_CEPTIMEOUT		BIT(6)
#define WLS_TRX_ERR_RXEPT		BIT(7)

#define WLS_CMD_INDENTIFY_ADAPTER	0xA1
#define WLS_CMD_INTO_FASTCHAGE		0xA2
#define WLS_CMD_INTO_USB_CHARGE		0xA3
#define WLS_CMD_INTO_NORMAL_CHARGE	0xA4
#define WLS_CMD_SET_NORMAL_MODE		0xA5
#define WLS_CMD_SET_QUIET_MODE		0xA6
#define WLS_CMD_SET_LED_BRIGHTNESS	0xAC
#define WLS_CMD_SET_CEP_TIMEOUT		0xAD
#define WLS_CMD_SET_FAN_SPEED		0xAE

#define WLS_CMD_GET_TX_ID		0x05
#define WLS_CMD_GET_TX_PWR		0x4A

#define WLS_MSG_TYPE_EXTENDED_MSG	0x5F
#define WLS_MSG_TYPE_STANDARD_MSG	0x4F

#define WLS_RESPONE_ADAPTER_TYPE	0xF1
#define WLS_RESPONE_INTO_FASTCHAGE	0xF2
#define WLS_RESPONE_INTO_USB_CHARGE	0xF3
#define WLS_RESPONE_INTO_NORMAL_CHARGER	0xF4
#define WLS_RESPONE_INTO_NORMAL_MODE	0xF5
#define WLS_RESPONE_INTO_QUIET_MODE	0xF6
#define WLS_RESPONE_LED_BRIGHTNESS	0xFC
#define WLS_RESPONE_CEP_TIMEOUT		0xFD
#define WLS_RESPONE_FAN_SPEED		0xFE
#define WLS_RESPONE_READY_FOR_EPP	0xFA
#define WLS_RESPONE_WORKING_IN_EPP	0xFB

#define WLS_ADAPTER_TYPE_MASK		0x07
#define WLS_ADAPTER_ID_MASK		0xF8
#define WLS_ADAPTER_POWER_MASK		0xF5
#define WLS_ADAPTER_TYPE_UNKNOWN	0x00
#define WLS_ADAPTER_TYPE_WARP		0x01
#define WLS_ADAPTER_TYPE_SWARP		0x02
#define WLS_ADAPTER_TYPE_USB		0x03
#define WLS_ADAPTER_TYPE_NORMAL		0x04
#define WLS_ADAPTER_TYPE_EPP		0x05
#define WLS_ADAPTER_TYPE_PD_65W		0x07

#define WLS_CHARGE_TYPE_DEFAULT		0x00
#define WLS_CHARGE_TYPE_FAST		0x01
#define WLS_CHARGE_TYPE_USB		0x02
#define WLS_CHARGE_TYPE_NORMAL		0x03
#define WLS_CHARGE_TYPE_EPP		0x04

#define WLS_TRX_MODE_VOL_MV		5500

#define WLS_CEP_ERR_MAX			3
#define WLS_RX_VOL_MAX_MV		20000
#define WLS_VOL_ADJUST_MAX		150
#define WLS_IBAT_MAX_MA			6000
#define WLS_CURR_ERR_MIN_MA		50

#define WLS_VOUT_DEFAULT_MV		5000
#define WLS_VOUT_EPP_MV			10000
#define WLS_VOUT_EPP_PLUS_MV		WLS_VOUT_EPP_MV
#define WLS_FASTCHG_MODE_VOL_MIN_MV	WLS_VOUT_EPP_MV
#define WLS_VOUT_FTM_MV			17000
#define WLS_VOUT_FASTCHG_INIT_MV	12000

#define WLS_CURR_WAIT_FAST_MA		300
#define WLS_CURR_STOP_CHG_MA		300
#define WLS_FASTCHG_CURR_45W_MAX_MA	2250
#define WLS_FASTCHG_CURR_40W_MAX_MA	2000
#define WLS_FASTCHG_CURR_30W_MAX_MA	1500
#define WLS_FASTCHG_CURR_20W_MAX_MA	1000
#define WLS_FASTCHG_CURR_15W_MAX_MA	800
#define WLS_FASTCHG_CURR_EXIT_MA	500
#define WLS_FASTCHG_CURR_ERR_MA		50
#define WLS_FASTCHG_CURR_MIN_MA		600
#define WLS_FASTCHG_CURR_DISCHG_MAX_MA	1000
#define WLS_FASTCHG_IOUT_CURR_MIN_MA	450

#define WLS_WARP_PWR_MAX_MW		15000

#define WLS_MAX_STEP_CHG_ENTRIES	8

#define WLS_SKIN_TEMP_MAX		500

#define CHARGE_FULL_FAN_THREOD_LO	350
#define CHARGE_FULL_FAN_THREOD_HI	380
#define QUIET_MODE_LED_BRIGHTNESS	3
#define QUIET_MODE_FAN_THR_SPEED	0

#define WLS_ADAPTER_MODEL_0		0x00
#define WLS_ADAPTER_MODEL_1		0x01
#define WLS_ADAPTER_MODEL_2		0x02
#define WLS_ADAPTER_MODEL_7		0x07
#define WLS_ADAPTER_MODEL_15		0x0F

struct oplus_chg_wls;

struct oplus_wls_chg_rx {
	struct oplus_chg_wls *wls_dev;
	struct device *dev;
	struct oplus_chg_ic_dev *rx_ic;
	struct delayed_work cep_check_work;
	struct completion cep_ok_ack;
	struct oplus_chg_mod *wls_ocm;
	struct oplus_chg_mod *usb_ocm;
	struct wakeup_source *update_fw_wake_lock;

	bool cep_is_ok;
	bool clean_source;

	int vol_set_mv;
};

struct oplus_wls_chg_fast {
	struct oplus_chg_wls *wls_dev;
	struct device *dev;
	struct oplus_chg_ic_dev *fast_ic;
};

struct oplus_wls_chg_normal {
	struct oplus_chg_wls *wls_dev;
	struct device *dev;
	struct oplus_chg_ic_dev *nor_ic;
	struct delayed_work icl_set_work;
	struct delayed_work fcc_set_work;
	struct oplus_chg_mod *batt_ocm;

	struct mutex icl_lock;
	struct mutex fcc_lock;

	int icl_target_ma;
	int icl_step_ma;
	int icl_set_ma;
	int fcc_target_ma;
	int fcc_step_ma;
	int fcc_set_ma;

	bool clean_source;
};

enum oplus_chg_wls_rx_state {
	OPLUS_CHG_WLS_RX_STATE_DEFAULT,
	OPLUS_CHG_WLS_RX_STATE_BPP,
	OPLUS_CHG_WLS_RX_STATE_EPP,
	OPLUS_CHG_WLS_RX_STATE_EPP_PLUS,
	OPLUS_CHG_WLS_RX_STATE_FAST,
	OPLUS_CHG_WLS_RX_STATE_FFC,
	OPLUS_CHG_WLS_RX_STATE_DONE,
	OPLUS_CHG_WLS_RX_STATE_QUIET,
	OPLUS_CHG_WLS_RX_STATE_STOP,
	OPLUS_CHG_WLS_RX_STATE_DEBUG,
	OPLUS_CHG_WLS_RX_STATE_FTM,
	OPLUS_CHG_WLS_RX_STATE_ERROR,
};

enum oplus_chg_wls_fast_sub_state {
	OPLUS_CHG_WLS_FAST_SUB_STATE_INIT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_FAST,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_IOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_VOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_CHECK_IOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_START,
};

enum oplus_chg_wls_trx_state {
	OPLUS_CHG_WLS_TRX_STATE_DEFAULT,
	OPLUS_CHG_WLS_TRX_STATE_READY,
	OPLUS_CHG_WLS_TRX_STATE_WAIT_PING,
	OPLUS_CHG_WLS_TRX_STATE_TRANSFER,
	OPLUS_CHG_WLS_TRX_STATE_OFF,
};

enum oplus_chg_wls_force_type {
	OPLUS_CHG_WLS_FORCE_TYPE_NOEN,
	OPLUS_CHG_WLS_FORCE_TYPE_BPP,
	OPLUS_CHG_WLS_FORCE_TYPE_EPP,
	OPLUS_CHG_WLS_FORCE_TYPE_EPP_PLUS,
	OPLUS_CHG_WLS_FORCE_TYPE_FAST,
	OPLUS_CHG_WLS_FORCE_TYPE_AUTO,
};

enum oplus_chg_wls_path_ctrl_type {
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_ALL,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_ENABLE_NOR,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_NOR,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_ENABLE_FAST,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_FAST,
};

enum oplus_chg_wls_chg_mode {
	OPLUS_WLS_CHG_MODE_BPP,
	OPLUS_WLS_CHG_MODE_EPP,
	OPLUS_WLS_CHG_MODE_EPP_PLUS,
	OPLUS_WLS_CHG_MODE_FAST,
	OPLUS_WLS_CHG_MODE_MAX,
};

enum oplus_chg_wls_batt_cl {
	OPLUS_WLS_CHG_BATT_CL_LOW,
	OPLUS_WLS_CHG_BATT_CL_HIGH,
	OPLUS_WLS_CHG_BATT_CL_MAX,
};

struct oplus_chg_rx_msg {
	u8 msg_type;
	u8 data;
	u8 respone_type;
	bool pending;
};

struct oplus_chg_wls_status {
	u8 adapter_type;
	u8 adapter_id;
	u8 adapter_power;
	u8 charge_type;
	enum oplus_chg_wls_rx_state current_rx_state;
	enum oplus_chg_wls_rx_state next_rx_state;
	enum oplus_chg_wls_rx_state target_rx_state;
	enum oplus_chg_wls_rx_state target_rx_state_backup;
	enum oplus_chg_wls_trx_state trx_state;
	enum oplus_chg_wls_type wls_type;

	int batt_temp_dynamic_thr[BATT_TEMP_INVALID - 1];
	int ffc_temp_dynamic_thr[FFC_TEMP_INVALID - 1];
	enum oplus_chg_temp_region temp_region;
	enum oplus_chg_ffc_temp_region ffc_temp_region;

	int state_sub_step;
	int iout_ma;
	int iout_ma_conunt;
	int vout_mv;
	int vrect_mv;
	int trx_curr_ma;
	int trx_vol_mv;
	int fastchg_target_curr_ma;
	int fastchg_target_vol_mv;
	int fastchg_curr_max_ma;
	int fastchg_ibat_max_ma;
	int fastchg_level;
	// Record the initial temperature when switching to the next gear.
	int fastchg_level_init_temp;
	int tx_pwr_mw;
	int rx_pwr_mw;
	int ploos_mw;
	int epp_plus_skin_step;
	int epp_skin_step;
	int bpp_skin_step;
	int epp_plus_led_on_skin_step;
	int epp_led_on_skin_step;
	int pwr_max_mw;
	int quiet_mode_need;
	int adapter_info_cmd_count;
	int fastchg_retry_count;
#ifndef CONFIG_OPLUS_CHG_OOS
	int cool_down;
#endif

	unsigned long cep_ok_wait_timeout;
	unsigned long fastchg_retry_timer;

	bool rx_online;
	bool rx_present;
	bool trx_online;
	bool trx_present;
	bool is_op_trx;
	bool epp_working;
	bool epp_5w;
	bool quiet_mode;
	bool switch_quiet_mode;
	bool cep_timeout_adjusted;
	bool upgrade_fw_pending;
	bool fw_upgrading;
	bool fastchg_started;
	bool fastchg_disable;
	bool fastchg_vol_set_ok;
	bool fastchg_curr_set_ok;
	bool fastchg_curr_need_dec;
	bool normal_chg_disabled;
	bool ffc_check;
	bool wait_cep_stable;
	bool fastchg_restart;
	bool ffc_done;
	bool online_keep;
	bool boot_online_keep; // The driver loading phase of the shutdown charging is set to true
	bool led_on;
	bool rx_adc_test_enable;
	bool rx_adc_test_pass;
	bool fod_parm_for_fastchg;
	bool chg_done;
	bool chg_done_quiet_mode;
};

#define WLS_MAX_STEP_CHG_ENTRIES	8
#define WLS_FOD_PARM_LENGTH		12
struct oplus_chg_wls_range_data {
	int32_t low_threshold;
	int32_t high_threshold;
	uint32_t curr_ma;
	uint32_t vol_max_mv;
	int32_t need_wait;
	int32_t max_soc;
} __attribute__ ((packed));

struct oplus_chg_wls_skin_range_data {
	int32_t low_threshold;
	int32_t high_threshold;
	uint32_t curr_ma;
} __attribute__ ((packed));

struct oplus_chg_wls_fcc_step {
	int max_step;
	struct oplus_chg_wls_range_data *fcc_step;
	bool allow_fallback[WLS_MAX_STEP_CHG_ENTRIES];
	unsigned long fcc_wait_timeout;
} __attribute__ ((packed));

struct oplus_chg_wls_skin_step {
	int max_step;
	struct oplus_chg_wls_skin_range_data *skin_step;
};

struct oplus_chg_wls_static_config {
	bool fastchg_fod_enable;
	bool fastchg_12V_fod_enable;
	u8 fastchg_match_q;
	u8 fastchg_fod_parm[WLS_FOD_PARM_LENGTH];
	u8 fastchg_fod_parm_12V[WLS_FOD_PARM_LENGTH];
};

struct oplus_chg_wls_dynamic_config {
	int32_t batt_vol_max_mv;
	int32_t iclmax_ma[OPLUS_WLS_CHG_BATT_CL_MAX][OPLUS_WLS_CHG_MODE_MAX][BATT_TEMP_INVALID];
	struct oplus_chg_wls_range_data fcc_step[WLS_MAX_STEP_CHG_ENTRIES];
	struct oplus_chg_wls_skin_range_data epp_plus_skin_step[WLS_MAX_STEP_CHG_ENTRIES];
	struct oplus_chg_wls_skin_range_data epp_skin_step[WLS_MAX_STEP_CHG_ENTRIES];
	struct oplus_chg_wls_skin_range_data bpp_skin_step[WLS_MAX_STEP_CHG_ENTRIES];
	int32_t fastchg_curr_max_ma;
	struct oplus_chg_strategy_data wls_fast_chg_led_off_strategy_data[CHG_STRATEGY_DATA_TABLE_MAX];
	struct oplus_chg_strategy_data wls_fast_chg_led_on_strategy_data[CHG_STRATEGY_DATA_TABLE_MAX];
	struct oplus_chg_wls_skin_range_data epp_plus_led_on_skin_step[WLS_MAX_STEP_CHG_ENTRIES];
	struct oplus_chg_wls_skin_range_data epp_led_on_skin_step[WLS_MAX_STEP_CHG_ENTRIES];
	int32_t wls_fast_chg_call_on_curr_ma;
	int32_t wls_fast_chg_camera_on_curr_ma;
	int32_t bpp_vol_mv;
	int32_t epp_vol_mv;
	int32_t epp_plus_vol_mv;
	int32_t warp_vol_mv;
	int32_t swarp_vol_mv;
} __attribute__ ((packed));

struct oplus_chg_wls_fod_cal_data {
	int fod_bpp;
	int fod_epp;
	int fod_fast;
};

struct wls_base_type {
	u8 id;
	int power_max_mw;
};

struct oplus_chg_wls {
	struct device *dev;
	wait_queue_head_t read_wq;
	struct miscdevice misc_dev;
	struct oplus_chg_mod *wls_ocm;
	struct power_supply *wls_psy;
	struct oplus_chg_mod *usb_ocm;
	struct oplus_chg_mod *batt_ocm;
	struct oplus_chg_mod *comm_ocm;
	struct notifier_block wls_changed_nb;
	struct notifier_block wls_event_nb;
	struct notifier_block wls_mod_nb;
	struct workqueue_struct	*wls_wq;
	struct delayed_work wls_rx_sm_work;
	struct delayed_work wls_trx_sm_work;
	struct delayed_work wls_connect_work;
	struct delayed_work wls_send_msg_work;
	struct delayed_work wls_upgrade_fw_work;
	struct delayed_work wls_data_update_work;
	struct delayed_work usb_int_work;
	struct delayed_work wls_trx_disconnect_work;
	struct delayed_work usb_connect_work;
	struct delayed_work fod_cal_work;
	struct delayed_work rx_restore_work;
	struct delayed_work rx_iic_restore_work;
	struct delayed_work rx_restart_work;
	struct delayed_work online_keep_remove_work;
	struct wakeup_source *rx_wake_lock;
	struct wakeup_source *trx_wake_lock;
	struct mutex connect_lock;
	struct mutex read_lock;
	struct mutex fod_data_lock;
	struct mutex send_msg_lock;

	struct votable *fcc_votable;
	struct votable *fastchg_disable_votable;
	struct votable *rx_disable_votable;
	struct votable *wrx_en_votable;
	struct votable *nor_icl_votable;
	struct votable *nor_fcc_votable;
	struct votable *nor_fv_votable;
	struct votable *nor_out_disable_votable;

	struct oplus_wls_chg_rx *wls_rx;
	struct oplus_wls_chg_fast *wls_fast;
	struct oplus_wls_chg_normal *wls_nor;

	struct oplus_chg_wls_status wls_status;
	struct oplus_chg_wls_static_config static_config;
	struct oplus_chg_wls_dynamic_config dynamic_config;
	struct oplus_chg_wls_fcc_step wls_fcc_step;
	struct oplus_chg_wls_skin_step epp_plus_skin_step;
	struct oplus_chg_wls_skin_step epp_skin_step;
	struct oplus_chg_wls_skin_step bpp_skin_step;
	struct oplus_chg_strategy wls_fast_chg_led_off_strategy;
	struct oplus_chg_strategy wls_fast_chg_led_on_strategy;
	struct oplus_chg_wls_skin_step epp_plus_led_on_skin_step;
	struct oplus_chg_wls_skin_step epp_led_on_skin_step;

	enum oplus_chg_wls_type wls_type;
	struct oplus_chg_rx_msg rx_msg;
	struct completion msg_ack;

	u8 *fw_buf;
	int fw_size;
	bool fw_upgrade_by_buf;

	int wrx_en_gpio;
	int cp_boost_en_gpio;
	int usb_int_gpio;
	int usb_int_irq;
	struct pinctrl *pinctrl;
	struct pinctrl_state *wrx_en_active;
	struct pinctrl_state *wrx_en_sleep;
	struct pinctrl_state *cp_boost_en_active;
	struct pinctrl_state *cp_boost_en_sleep;

	bool support_fastchg;
	bool support_get_tx_pwr;
	bool support_epp_plus;
	bool rx_wake_lock_on;
	bool trx_wake_lock_on;
	bool usb_present;
	bool charge_enable;
	bool batt_charge_enable;
	bool ftm_mode;
	bool debug_mode;
	bool factory_mode;
	bool fod_is_cal;  // fod is calibrated
	bool fod_cal_data_ok;
	bool msg_callback_ok;

	struct oplus_chg_wls_fod_cal_data cal_data;

	enum oplus_chg_wls_force_type force_type;
	enum oplus_chg_wls_path_ctrl_type path_ctrl_type;

	int icl_max_ma[OPLUS_WLS_CHG_MODE_MAX];

	const char *wls_chg_fw_name;
};

#ifdef CONFIG_OPLUS_CHG_DYNAMIC_CONFIG
int oplus_chg_wls_set_config(struct oplus_chg_mod *wls_ocm, u8 *buf);
#endif

#endif /* __OPLUS_CHG_WLS_H__ */