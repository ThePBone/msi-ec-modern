#ifndef __MSI_EC_CONSTANTS__
#define __MSI_EC_CONSTANTS__

#include <linux/kernel.h>

#define MSI_DRIVER_NAME "msi-ec"
#define MSI_EC_FN_WIN_ADDRESS 0xe8
#define MSI_EC_FN_WIN_BIT 4
#define MSI_EC_FN_KEY_LEFT 1
#define MSI_EC_FN_KEY_RIGHT 0
#define MSI_EC_WIN_KEY_LEFT 0
#define MSI_EC_WIN_KEY_RIGHT 1

#define MSI_EC_BATTERY_MODE_ADDRESS 0xd7
#define MSI_EC_BATTERY_MODE_MAX_CHARGE 0xe4
#define MSI_EC_BATTERY_MODE_MEDIUM_CHARGE 0xd0
#define MSI_EC_BATTERY_MODE_MIN_CHARGE 0xbc
#define MSI_EC_COOLER_BOOST_ADDRESS 0x98
#define MSI_EC_COOLER_BOOST_BIT 7
#define MSI_EC_SHIFT_MODE_ADDRESS 0xf2
#define MSI_EC_SHIFT_MODE_OVERCLOCK 0xc0
#define MSI_EC_SHIFT_MODE_BALANCED 0xc1
#define MSI_EC_SHIFT_MODE_ECO 0xc2
#define MSI_EC_SHIFT_MODE_OFF 0x80
#define MSI_EC_FW_VERSION_ADDRESS 0xa0
#define MSI_EC_FW_VERSION_LENGTH 12
#define MSI_EC_FW_DATE_ADDRESS 0xac
#define MSI_EC_FW_DATE_LENGTH 8
#define MSI_EC_FW_TIME_ADDRESS 0xb4
#define MSI_EC_FW_TIME_LENGTH 8
#define MSI_EC_CPU_REALTIME_TEMPERATURE_ADDRESS 0x68
#define MSI_EC_CPU_REALTIME_FAN_SPEED_ADDRESS 0x71
#define MSI_EC_CPU_REALTIME_FAN_SPEED_BASE_MIN 0x19
#define MSI_EC_CPU_REALTIME_FAN_SPEED_BASE_MAX 0x37
#define MSI_EC_GPU_REALTIME_TEMPERATURE_ADDRESS 0x80
#define MSI_EC_GPU_REALTIME_FAN_SPEED_ADDRESS 0x89
#define MSI_EC_FAN_MODE_ADDRESS 0xd4
#define MSI_EC_FAN_MODE_SILENT_BIT 4
#define MSI_EC_FAN_MODE_BASIC_BIT 6 /* Modern 15: unused by MSI Center; useless due to unknown BASIC_FAN_SPEED_ADDRESS  */
#define MSI_EC_FAN_MODE_ADVANCED_BIT 7

#define MSI_EC_POWER_ADDRESS 0x30
#define MSI_EC_POWER_LID_OPEN_BIT 1
#define MSI_EC_POWER_AC_CONNECTED_BIT 0

// Keyboard, webcam device controls
#define MSI_EC_KBD_LED_MICMUTE_ADDRESS 0x2c
#define MSI_EC_KBD_LED_MICMUTE_BIT 1
#define MSI_EC_KBD_LED_MUTE_ADDRESS 0x2d
#define MSI_EC_KBD_LED_MUTE_BIT 1
#define MSI_EC_WEBCAM_ADDRESS 0x2e
#define MSI_EC_WEBCAM_BIT 1
#define MSI_EC_WEBCAM_HARD_ADDRESS 0x2f
#define MSI_EC_WEBCAM_HARD_BIT 1 /* hotkey has no effect if this address disables the cam */

#define MSI_EC_KBD_BL_ADDRESS 0xd3
#define MSI_EC_KBD_BL_STATE_MASK 0x3
#define MSI_EC_KBD_BL_STATE_OFF 0x80
#define MSI_EC_KBD_BL_STATE_ON 0x81
#define MSI_EC_KBD_BL_STATE_HALF 0x82
#define MSI_EC_KBD_BL_STATE_FULL 0x83
static int MSI_EC_KBD_BL_STATE[4] = {
    MSI_EC_KBD_BL_STATE_OFF,
    MSI_EC_KBD_BL_STATE_ON,
    MSI_EC_KBD_BL_STATE_HALF,
    MSI_EC_KBD_BL_STATE_FULL
};

/* Presets/user scenarios taken from MSI Center Pro */
static u8 MSI_EC_PRESET_MEMORY_TABLE[6]= {
	/* CPU pwr?, GPU pwr?, Shift mode, KBD brightness, Silent flag (1 bit), Battery saving flags(?) */
	0x79, 0x91, 0xD2, 0xD3, 0xD4, 0xEB
};

static u8 MSI_EC_PRESET_VALUE_TABLE[4][6] = {
	{ 70U, 70U, 0xC2, 0x81, 0U, 0x8F}, /* Super battery */
	{ 75U, 70U, 0xC1, 0x82, 1U, 0x80}, /* Silent */
	{ 75U, 70U, 0xC1, 0x83, 0U, 0x80}, /* Balanced */
	{ 80U, 75U, 0xC0, 0x83, 0U, 0x80}, /* High performance */
};

#define MSI_EC_PRESET_SUPER_BATTERY 0
#define MSI_EC_PRESET_SILENT 1
#define MSI_EC_PRESET_BALANCED 2
#define MSI_EC_PRESET_HIGH_PERFORMANCE 3

#define MSI_EC_PRESET_COLUMN_CPU_POWER 0
#define MSI_EC_PRESET_COLUMN_GPU_POWER 1
#define MSI_EC_PRESET_COLUMN_SHIFT_MODE 2
#define MSI_EC_PRESET_COLUMN_KBD_BL 3
#define MSI_EC_PRESET_COLUMN_SILENT_FLAG 4
#define MSI_EC_PRESET_COLUMN_BATTERY_SAVING 5

#endif // __MSI_EC_CONSTANTS__
