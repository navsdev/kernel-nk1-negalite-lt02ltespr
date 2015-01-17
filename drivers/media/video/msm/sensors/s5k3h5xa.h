/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <mach/board.h>

/* CAMERA GPIO
#define GPIO_CAM_IO_EN		0
#define GPIO_CAM_FLASH_NOW			3
#define GPIO_CAM_SUB_MCLK		4
#define GPIO_CAM_MAIN_MCLK		5
#define GPIO_CAM_CORE_EN	6
#define GPIO_CAM_A_EN	47
#define GPIO_CAM_MIPI_EN		46
#define GPIO_CAM_MAIN_STBY		54
#define GPIO_CAM_AF_EN		66
#define GPIO_CAM_VT_RST		76
#define GPIO_CAM_MAIN_RST		107
*/

extern struct platform_driver s5k3h5xa_driver;
#define IMX175_30FPS_SUPPORT

int32_t msm_sensor_enable_i2c_mux(struct msm_camera_i2c_conf *i2c_conf);
int32_t msm_sensor_disable_i2c_mux(struct msm_camera_i2c_conf *i2c_conf);

static struct msm_camera_i2c_reg_conf s5k3h5xa_start_settings[] = {
	{0x0100, 0x01},
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_stop_settings[] = {
	{0x0100, 0x00},
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_groupon_settings[] = {
	{0x104, 0x01},
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_groupoff_settings[] = {
	{0x104, 0x00},
};

static uint8_t init_contiguous_setting[] = {
	0x10, 0xB5,
	0x00, 0xF0,
	0x05, 0xF8,
	0x00, 0xF0,
	0xBF, 0xFA,
	0x10, 0xBC,
	0x08, 0xBC,
	0x18, 0x47,
	0x78, 0x47,
	0xC0, 0x46,
	0x9F, 0xE5,
	0x14, 0x10,
	0x9F, 0xE5,
	0x14, 0x00,
	0x9F, 0xE5,
	0x14, 0x20,
	0x80, 0xE5,
	0x50, 0x10,
	0x42, 0xE0,
	0x01, 0x10,
	0xC0, 0xE1,
	0xB4, 0x15,
	0x2F, 0xE1,
	0x1E, 0xFF,
	0x00, 0x70,
	0x74, 0x1D,
	0x00, 0x70,
	0x70, 0x05,
	0x00, 0x70,
	0x90, 0x2D,
	0x9F, 0xE5,
	0x6C, 0x10,
	0x9F, 0xE5,
	0x6C, 0x00,
	0x9F, 0xE5,
	0x6C, 0x20,
	0x80, 0xE5,
	0x28, 0x10,
	0x81, 0xE1,
	0xC1, 0x1C,
	0x80, 0xE5,
	0x24, 0x10,
	0x9F, 0xE5,
	0x60, 0x10,
	0x9F, 0xE5,
	0x60, 0x30,
	0xC1, 0xE1,
	0xB8, 0x25,
	0xA0, 0xE3,
	0x28, 0x20,
	0xC1, 0xE1,
	0xBA, 0x25,
	0x80, 0xE5,
	0x38, 0x30,
	0x9F, 0xE5,
	0x50, 0x00,
	0xC1, 0xE1,
	0xBC, 0x25,
	0xA0, 0xE3,
	0x06, 0x10,
	0xC0, 0xE1,
	0xB6, 0x16,
	0x9F, 0xE5,
	0x44, 0x10,
	0x80, 0xE5,
	0x78, 0x10,
	0x83, 0xE0,
	0x02, 0x10,
	0x80, 0xE5,
	0x7C, 0x10,
	0x81, 0xE2,
	0x3C, 0x10,
	0x80, 0xE5,
	0x80, 0x10,
	0x2F, 0xE1,
	0x1E, 0xFF,
	0x9F, 0xE5,
	0x2C, 0x00,
	0x9F, 0xE5,
	0x10, 0x10,
	0x90, 0xE5,
	0x50, 0x00,
	0x81, 0xE5,
	0x2C, 0x00,
	0x81, 0xE5,
	0x3C, 0x00,
	0x00, 0xEA,
	0x12, 0x01,
	0x00, 0x70,
	0x90, 0x2D,
	0x00, 0x70,
	0x70, 0x04,
	0x00, 0x00,
	0x28, 0x05,
	0x00, 0x70,
	0xA0, 0x12,
	0x00, 0x70,
	0xE0, 0x32,
	0x00, 0x70,
	0x60, 0x16,
	0x00, 0x70,
	0x50, 0x1D,
	0x00, 0x70,
	0x70, 0x05,
	0x2D, 0xE9,
	0xF8, 0x4F,
	0x9F, 0xE5,
	0x64, 0x84,
	0xA0, 0xE1,
	0x00, 0x90,
	0x98, 0xE5,
	0x00, 0xA0,
	0x9F, 0xE5,
	0x54, 0x74,
	0x9F, 0xE5,
	0x58, 0x04,
	0xD7, 0xE1,
	0xBE, 0x5E,
	0xD0, 0xE1,
	0xBC, 0x03,
	0xDA, 0xE5,
	0x9D, 0x10,
	0xDA, 0xE5,
	0x9F, 0xB0,
	0x40, 0xE0,
	0x01, 0x00,
	0x00, 0xE0,
	0x95, 0x00,
	0x55, 0xE1,
	0x0B, 0x00,
	0xA0, 0xE1,
	0x20, 0x05,
	0x00, 0x2A,
	0x1B, 0x00,
	0x5B, 0xE1,
	0x00, 0x00,
	0x00, 0x8A,
	0x0B, 0x00,
	0xA0, 0xE3,
	0x00, 0x40,
	0xC7, 0xE1,
	0xBE, 0xBE,
	0x87, 0xE0,
	0x04, 0x61,
	0x96, 0xE5,
	0xF8, 0x00,
	0xA0, 0xE1,
	0x0B, 0x10,
	0x00, 0xE0,
	0x95, 0x00,
	0x00, 0xEB,
	0x18, 0x01,
	0x84, 0xE2,
	0x01, 0x40,
	0x54, 0xE3,
	0x04, 0x00,
	0x86, 0xE5,
	0xF8, 0x00,
	0xFF, 0x3A,
	0xF6, 0xFF,
	0x00, 0xEA,
	0x0D, 0x00,
	0xDA, 0xE5,
	0x9E, 0x00,
	0x50, 0xE1,
	0x05, 0x00,
	0x00, 0x2A,
	0x0A, 0x00,
	0xA0, 0xE3,
	0x00, 0x40,
	0xC7, 0xE1,
	0xBE, 0x0E,
	0x87, 0xE0,
	0x04, 0x61,
	0x96, 0xE5,
	0xF8, 0x00,
	0xDA, 0xE5,
	0x9E, 0x10,
	0x00, 0xE0,
	0x95, 0x00,
	0x00, 0xEB,
	0x09, 0x01,
	0x84, 0xE2,
	0x01, 0x40,
	0x54, 0xE3,
	0x04, 0x00,
	0x86, 0xE5,
	0xF8, 0x00,
	0xFF, 0x3A,
	0xF6, 0xFF,
	0x9F, 0xE5,
	0xC4, 0x03,
	0x87, 0xE2,
	0xC8, 0x30,
	0x8D, 0xE5,
	0x00, 0x30,
	0xD0, 0xE5,
	0xB9, 0x20,
	0xD0, 0xE1,
	0xB6, 0x18,
	0x9F, 0xE5,
	0xB4, 0x03,
	0xA0, 0xE1,
	0x09, 0x30,
	0x90, 0xE5,
	0x28, 0xC0,
	0x87, 0xE2,
	0xE8, 0x00,
	0xA0, 0xE1,
	0x0F, 0xE0,
	0x2F, 0xE1,
	0x1C, 0xFF,
	0x50, 0xE3,
	0x00, 0x00,
	0x00, 0x1B,
	0xFA, 0x00,
	0x9F, 0xE5,
	0x98, 0x03,
	0x98, 0xE5,
	0x00, 0x10,
	0xD0, 0xE1,
	0xBA, 0x05,
	0xD1, 0xE5,
	0x9C, 0x10,
	0x9F, 0xE5,
	0x8C, 0x33,
	0x50, 0xE1,
	0x01, 0x00,
	0xA0, 0xE3,
	0x00, 0x00,
	0x00, 0x2A,
	0x13, 0x00,
	0x00, 0xEA,
	0x05, 0x00,
	0xD1, 0xE1,
	0xB2, 0x10,
	0x82, 0xE2,
	0x0D, 0x22,
	0xC2, 0xE1,
	0xB0, 0x10,
	0x80, 0xE2,
	0x01, 0x00,
	0x50, 0xE3,
	0x14, 0x00,
	0x00, 0xAA,
	0x04, 0x00,
	0x80, 0xE0,
	0x80, 0x10,
	0x83, 0xE0,
	0x81, 0x10,
	0xD1, 0xE1,
	0xB0, 0x20,
	0x52, 0xE3,
	0x00, 0x00,
	0xFF, 0x1A,
	0xF4, 0xFF,
	0xBD, 0xE8,
	0xF8, 0x4F,
	0x2F, 0xE1,
	0x1E, 0xFF,
	0xD1, 0xE1,
	0xB4, 0x10,
	0x82, 0xE2,
	0x0D, 0x22,
	0xC2, 0xE1,
	0xB0, 0x10,
	0x80, 0xE2,
	0x01, 0x00,
	0x50, 0xE3,
	0x14, 0x00,
	0xFF, 0xAA,
	0xF7, 0xFF,
	0x80, 0xE0,
	0x80, 0x10,
	0x83, 0xE0,
	0x81, 0x10,
	0xD1, 0xE1,
	0xB0, 0x20,
	0x52, 0xE3,
	0x00, 0x00,
	0xFF, 0x1A,
	0xF4, 0xFF,
	0xFF, 0xEA,
	0xF1, 0xFF,
	0x2D, 0xE9,
	0xFC, 0x5F,
	0xA0, 0xE1,
	0x00, 0x70,
	0x9D, 0xE5,
	0x34, 0x90,
	0x40, 0xE2,
	0x09, 0x0A,
	0x50, 0xE2,
	0x62, 0x0E,
	0xA0, 0xE1,
	0x01, 0x80,
	0xA0, 0xE1,
	0x02, 0xA0,
	0xA0, 0xE1,
	0x03, 0x50,
	0xA0, 0xE3,
	0x01, 0x60,
	0x00, 0x1A,
	0x19, 0x00,
	0x9F, 0xE5,
	0xF0, 0x02,
	0x9F, 0xE5,
	0xF0, 0xB2,
	0xD0, 0xE1,
	0xB0, 0x00,
	0xA0, 0xE1,
	0x05, 0x30,
	0xA0, 0xE1,
	0x16, 0x10,
	0x80, 0xE2,
	0x01, 0x00,
	0x81, 0xE1,
	0x16, 0x00,
	0xDB, 0xE1,
	0xB0, 0x10,
	0xC1, 0xE1,
	0x00, 0x00,
	0xCB, 0xE1,
	0xB0, 0x00,
	0x9D, 0xE5,
	0x30, 0x20,
	0xA0, 0xE1,
	0x08, 0x10,
	0x8D, 0xE8,
	0x04, 0x02,
	0xA0, 0xE1,
	0x0A, 0x20,
	0xA0, 0xE1,
	0x07, 0x00,
	0x00, 0xEB,
	0xC0, 0x00,
	0xA0, 0xE1,
	0x00, 0x40,
	0x9F, 0xE5,
	0xAC, 0x02,
	0xD0, 0xE1,
	0xB0, 0x00,
	0xA0, 0xE1,
	0x16, 0x10,
	0x80, 0xE2,
	0x01, 0x00,
	0x81, 0xE1,
	0x16, 0x00,
	0xDB, 0xE1,
	0xB0, 0x10,
	0x80, 0xE1,
	0x01, 0x00,
	0xCB, 0xE1,
	0xB0, 0x00,
	0x00, 0xEA,
	0x2A, 0x00,
	0xA0, 0xE1,
	0x05, 0x00,
	0x00, 0xEB,
	0xB6, 0x00,
	0x60, 0xE2,
	0x20, 0x40,
	0xA0, 0xE1,
	0x16, 0x04,
	0x40, 0xE0,
	0x05, 0x20,
	0x9F, 0xE5,
	0x7C, 0x02,
	0x90, 0xE5,
	0x00, 0x00,
	0xD0, 0xE5,
	0x80, 0x61,
	0x56, 0xE3,
	0x00, 0x00,
	0x00, 0x0A,
	0x0F, 0x00,
	0x47, 0xE2,
	0x09, 0x0A,
	0x50, 0xE2,
	0x61, 0x0E,
	0x66, 0x02,
	0x01, 0x6C,
	0xA0, 0xE1,
	0x06, 0x10,
	0xA0, 0xE3,
	0x01, 0x0C,
	0x00, 0xEB,
	0xA2, 0x00,
	0x00, 0xEB,
	0xA7, 0x00,
	0x60, 0xE2,
	0x1E, 0x10,
	0x00, 0xEA,
	0x00, 0x00,
	0x81, 0xE2,
	0x01, 0x10,
	0x84, 0xE0,
	0x01, 0x00,
	0x80, 0xE2,
	0x01, 0x20,
	0xA0, 0xE1,
	0x16, 0x22,
	0x75, 0xE0,
	0x22, 0x24,
	0xFF, 0x4A,
	0xF9, 0xFF,
	0xA0, 0xE1,
	0x00, 0x40,
	0x9D, 0xE5,
	0x30, 0x00,
	0x45, 0xE0,
	0x02, 0x10,
	0x80, 0xE0,
	0x09, 0x00,
	0x01, 0xE0,
	0x90, 0x01,
	0x02, 0xE0,
	0x90, 0x02,
	0x00, 0xE0,
	0x95, 0x00,
	0x88, 0xE0,
	0x21, 0x11,
	0x81, 0xE0,
	0x0A, 0x10,
	0x81, 0xE0,
	0xA2, 0x20,
	0x42, 0xE0,
	0x09, 0x30,
	0x88, 0xE0,
	0xA0, 0x00,
	0x40, 0xE0,
	0x09, 0x20,
	0x87, 0xE2,
	0x0D, 0x02,
	0xC0, 0xE1,
	0xB0, 0x80,
	0xC0, 0xE1,
	0xB2, 0x20,
	0xC0, 0xE1,
	0xB4, 0x10,
	0xC0, 0xE1,
	0xB6, 0x30,
	0xA0, 0xE1,
	0x04, 0x00,
	0xBD, 0xE8,
	0xFC, 0x5F,
	0x2F, 0xE1,
	0x1E, 0xFF,
	0x2D, 0xE9,
	0xF0, 0x4F,
	0xA0, 0xE1,
	0x00, 0x70,
	0x9F, 0xE5,
	0xD0, 0x01,
	0xA0, 0xE1,
	0x01, 0x50,
	0x90, 0xE5,
	0x00, 0x00,
	0x4D, 0xE2,
	0x14, 0xD0,
	0xD0, 0xE5,
	0x72, 0x21,
	0x80, 0xE2,
	0x01, 0x1C,
	0xD1, 0xE1,
	0xB0, 0x67,
	0xD0, 0xE5,
	0x73, 0xA1,
	0x8D, 0xE5,
	0x10, 0x20,
	0xD1, 0xE1,
	0xB4, 0x17,
	0xA0, 0xE3,
	0x00, 0x40,
	0x8D, 0xE5,
	0x0C, 0x10,
	0xD0, 0xE5,
	0x76, 0x01,
	0x8D, 0xE5,
	0x08, 0x00,
	0xA0, 0xE1,
	0x27, 0x05,
	0x8D, 0xE5,
	0x04, 0x00,
	0x00, 0xEB,
	0x79, 0x00,
	0x9F, 0xE5,
	0x90, 0x81,
	0x8D, 0xE5,
	0x00, 0x00,
	0xD8, 0xE5,
	0x18, 0x00,
	0x9F, 0xE5,
	0x88, 0xB1,
	0xA0, 0xE1,
	0x07, 0x7B,
	0xA0, 0xE3,
	0x00, 0x90,
	0xA0, 0xE1,
	0x27, 0x7B,
	0xCB, 0xE1,
	0xB8, 0x00,
	0xDB, 0xE1,
	0xB8, 0x00,
	0x50, 0xE3,
	0x00, 0x00,
	0xFF, 0x1A,
	0xFC, 0xFF,
	0x56, 0xE3,
	0x00, 0x00,
	0x00, 0x0A,
	0x06, 0x00,
	0xD8, 0xE5,
	0x29, 0x00,
	0xD8, 0xE5,
	0x1B, 0x10,
	0x9D, 0xE5,
	0x10, 0x30,
	0x40, 0xE0,
	0x01, 0x20,
	0x9D, 0xE5,
	0x04, 0x00,
	0xA0, 0xE1,
	0x06, 0x10,
	0x00, 0xEB,
	0x67, 0x00,
	0x9D, 0xE5,
	0x0C, 0x00,
	0x50, 0xE3,
	0x00, 0x00,
	0x00, 0x0A,
	0x05, 0x00,
	0xD8, 0xE5,
	0x29, 0x00,
	0xD8, 0xE5,
	0x1B, 0x10,
	0x40, 0xE0,
	0x01, 0x20,
	0x9D, 0xE9,
	0x09, 0x00,
	0x9D, 0xE5,
	0x0C, 0x10,
	0x00, 0xEB,
	0x5E, 0x00,
	0xA0, 0xE3,
	0x01, 0x00,
	0xCB, 0xE1,
	0xB4, 0x00,
	0xA0, 0xE1,
	0x87, 0x61,
	0x9F, 0xE5,
	0x18, 0x71,
	0x00, 0xEA,
	0x19, 0x00,
	0x15, 0xE3,
	0x01, 0x00,
	0x00, 0x0A,
	0x0E, 0x00,
	0xD8, 0xE5,
	0x35, 0x20,
	0x9D, 0xE5,
	0x04, 0x00,
	0xA0, 0xE1,
	0x06, 0x10,
	0x00, 0xEB,
	0x55, 0x00,
	0x9D, 0xE5,
	0x04, 0x00,
	0x84, 0xE2,
	0x01, 0x40,
	0x14, 0xE3,
	0x01, 0x00,
	0x00, 0x0A,
	0x02, 0x00,
	0x00, 0xEB,
	0x52, 0x00,
	0xA0, 0xE1,
	0x00, 0x90,
	0x00, 0xEA,
	0x03, 0x00,
	0x00, 0xEB,
	0x4F, 0x00,
	0x50, 0xE3,
	0x00, 0x00,
	0x59, 0x13,
	0x00, 0x00,
	0xA0, 0x13,
	0x00, 0x40,
	0x5A, 0xE3,
	0x00, 0x00,
	0xD7, 0x05,
	0x03, 0x00,
	0x50, 0x01,
	0x04, 0x00,
	0xA0, 0x03,
	0x00, 0x40,
	0x00, 0x0A,
	0x01, 0x00,
	0x54, 0xE3,
	0x00, 0x00,
	0x00, 0x1A,
	0x01, 0x00,
	0x86, 0xE2,
	0x01, 0x60,
	0xA0, 0xE1,
	0xA5, 0x50,
	0x55, 0xE3,
	0x00, 0x00,
	0xD7, 0x15,
	0x03, 0x00,
	0x50, 0x11,
	0x04, 0x00,
	0xFF, 0x8A,
	0xE1, 0xFF,
	0xA0, 0xE3,
	0x00, 0x00,
	0xCB, 0xE1,
	0xB4, 0x00,
	0x9D, 0xE5,
	0x04, 0x00,
	0x9D, 0xE5,
	0x00, 0x10,
	0x00, 0xEB,
	0x3C, 0x00,
	0xD7, 0xE5,
	0x03, 0x00,
	0x8D, 0xE2,
	0x14, 0xD0,
	0x50, 0xE1,
	0x04, 0x00,
	0xBD, 0xE8,
	0xF0, 0x4F,
	0xA0, 0x93,
	0x00, 0x00,
	0xA0, 0x83,
	0x01, 0x00,
	0x2F, 0xE1,
	0x1E, 0xFF,
	0x9F, 0xE5,
	0x6C, 0x00,
	0x9F, 0xE5,
	0x6C, 0x10,
	0x2D, 0xE9,
	0x10, 0x40,
	0x81, 0xE5,
	0x78, 0x00,
	0x9F, 0xE5,
	0x64, 0x00,
	0x4F, 0xE2,
	0x66, 0x1F,
	0x00, 0xEB,
	0x30, 0x00,
	0x9F, 0xE5,
	0x5C, 0x00,
	0x4F, 0xE2,
	0xBB, 0x1F,
	0x00, 0xEB,
	0x2D, 0x00,
	0x9F, 0xE5,
	0x2C, 0x10,
	0xC1, 0xE1,
	0xB0, 0x00,
	0xBD, 0xE8,
	0x10, 0x40,
	0x9F, 0xE5,
	0x48, 0x10,
	0x9F, 0xE5,
	0x48, 0x00,
	0x00, 0xEA,
	0x27, 0x00,
	0x00, 0x70,
	0x70, 0x14,
	0x00, 0x70,
	0x00, 0x00,
	0x00, 0x70,
	0x80, 0x0C,
	0x00, 0x70,
	0x30, 0x13,
	0x00, 0x70,
	0xF8, 0x04,
	0x00, 0x70,
	0x70, 0x15,
	0x00, 0x70,
	0x00, 0x2D,
	0x00, 0x70,
	0x70, 0x1D,
	0x00, 0xD0,
	0x00, 0x61,
	0x00, 0x70,
	0x04, 0x00,
	0x00, 0x70,
	0xF0, 0x16,
	0x00, 0xD0,
	0x00, 0x83,
	0x00, 0x70,
	0xE0, 0x0D,
	0x00, 0x70,
	0x50, 0x1D,
	0x00, 0x70,
	0x60, 0x16,
	0x00, 0x00,
	0x44, 0xBF,
	0x00, 0x00,
	0xB0, 0x9A,
	0x00, 0x70,
	0x3C, 0x18,
	0x00, 0x00,
	0xA0, 0x1C,
	0x78, 0x47,
	0xC0, 0x46,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0xA4, 0xD0,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x20, 0xE1,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x64, 0x1C,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0xB0, 0x9A,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x78, 0xE2,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0xB4, 0xBB,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x7C, 0xBC,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x74, 0xBD,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0xF8, 0xBE,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x2C, 0xBC,
	0x1F, 0xE5,
	0x04, 0xF0,
	0x00, 0x00,
	0x20, 0xD0,
	0x0A, 0x00,
	0x00, 0x04,
	0x01, 0x0A,
	0x04, 0x0A,	
	0x0A, 0x01,
	0x0A, 0x00,
	0x00, 0x02,
	0x01, 0x0A,
	0x02, 0x0A,
	0x0A, 0x01,
	0x09, 0x01,
	0x01, 0x04,
	0x01, 0x09,
	0x02, 0x09,
	0x09, 0x01,
	0x00, 0x00,
}; 
static struct msm_camera_i2c_reg_conf s5k3h5xa_init_settings1[] = {
	{0x3902, 0x0002},
	{0x3158, 0x0215},
	{0x32B4, 0xF4B6},
	{0x32B6, 0xF466},
	{0x32B8, 0xF456},
	{0x32BA, 0xF45E},
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_init_settings2[] = {
	{0x32BC, 0x10},
	{0x32BD, 0x00},
	{0x32BE, 0x00},
	{0x330E, 0x00},	//#senHal_bUseTmc
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_init_settings3[] = {
	{0x3338, 0x0214},
	{0x6218, 0xF1D0},
	{0x6214, 0xF9F0},
	{0x6226, 0x0001},
	
	{0xF446, 0x0029},
	{0xF448, 0x001D},
	{0xF440, 0x0071},
	{0xF42E, 0x00C1},
	{0xF42A, 0x0802},
	{0xB0C8, 0x0044},
	{0x6226, 0x0000},
	{0x6218, 0xF9F0},
	{0x34A2, 0x00D6},
	{0x34B2, 0x01FA},
	{0x34CA, 0x00D6},
	{0x34DA, 0x01FA},
	{0x3522, 0x00D6},
	{0x3532, 0x01FA},
	{0x3254, 0x79D3},
	{0x3256, 0x79D3},
	{0x3258, 0x79D3},
	{0x325A, 0x79D3},
	{0x325C, 0x79D3},
	{0x325E, 0x79D3},
	{0x357A, 0x00BD},
	{0x32F6, 0x1110},
	
	{0x6028, 0xD000},
	{0x6226, 0x0001},
	{0x6100, 0x0003},
	{0x6110, 0x1CA0},
	{0x6112, 0x1CA4},
	{0x6150, 0x172C},
	{0x6152, 0x1730},
	
	{0x6028, 0x7000},
	{0x602A, 0x172C},
	{0x6F12, 0x1FE5},
	{0x6F12, 0x04F0},
	{0x6F12, 0x0070},
	{0x6F12, 0x7018},
	{0x6028, 0xD000},
	
	{0x6226, 0x0000},
	{0x1a00, 0x0340},
	{0x1a04, 0x0120},
	{0x0112, 0x0a0a},
	{0x0200, 0x0BEF},
	{0x0204, 0x0020},
	//set PLL
	{0x0300, 0x0002},
	{0x0302, 0x0001},
	{0x0304, 0x0006},
	{0x0306, 0x0094},//296MHz	{0x0306, 0x0094},//296MHz
	{0x0308, 0x0008},
	{0x030A, 0x0001},
	{0x030C, 0x0006},
	{0x030E, 0x00B9},//296MHz	{0x030E, 0x00B9},//296MHz
	//
	{0x32CE, 0x0094},
	{0x32D0, 0x0024},

	{0x32D4, 0x00EC},	//#senHal_uAddColsNoHorBin
	
	{0x0380, 0x0001},
	{0x0382, 0x0001},
	{0x0384, 0x0001},
	{0x0386, 0x0001},
	{0x0086, 0x0200},
	{0x32F4, 0x1111},
	{0x35F6, 0x000A},
	{0x35FE, 0x00DC},
};

static struct msm_camera_i2c_reg_conf s5k3h5xa_init_settings4[] = {
	{0x012C, 0x60},
	{0x012D, 0x4F},
	{0x012E, 0x2F},
	{0x012F, 0x40},
	{0x1B00, 0xE0},
	{0x3819, 0x02},
	{0x381A, 0x02},
	{0x392A, 0x10},
	{0x392B, 0x10},
	{0x392C, 0x10},
	{0x392D, 0x10},
	{0x391E, 0x20},
	{0x391F, 0x20},
	{0x1a02, 0x00},
	{0x1a03, 0x00},
	{0x1a06, 0x04},
	{0x3985, 0x3B},
	{0x3986, 0xA0},
	{0x3984, 0x20},
	{0x3987, 0x20},
	{0x0101, 0x00},
	{0x0114, 0x03},
	{0x0120, 0x00},
	{0x0900, 0x01},
	{0x0105, 0x00},
	{0x304F, 0x01},
};
