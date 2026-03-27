/*
  pd42s1_map.h - Pin mapping for Pico2w(RP2350) with PD42S1 driver
                 Pulse mode configuration
  
  Part of grblHAL

  Copyright (c) 2026 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __BOARD_MAP_H__
#define __BOARD_MAP_H__

#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

#define BOARD_NAME "PD42S1"
// #define HAS_BOARD_INIT  // 不需要特殊的板级初始化

// ============================================================================
// 激光模块 PWM
// ============================================================================
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PORT            GPIO_OUTPUT
#define SPINDLE_PWM_PIN         1  // GP1 - 激光 PWM
#endif

// ============================================================================
// PD42S1 脉冲模式配置
// ============================================================================

// 步进脉冲输出 (使用 PIO 状态机生成精确脉冲)
#define STEP_PORT               GPIO_PIO      // N_AXIS pin PIO SM
#define STEP_PINS_BASE          6             // GP6-9: STP_X/Y/Z/A

// 方向输出
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         2             // GP2 - DIR_X
#define Y_DIRECTION_PIN         3             // GP3 - DIR_Y
#define Z_DIRECTION_PIN         4             // GP4 - DIR_Z
#define DIRECTION_OUTMODE       GPIO_SHIFT2   // 从 GP2 开始的移位寄存器模式

// A 轴专用引脚定义 (第 4 轴)
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE            1
#define M3_STEP_PIN             9             // GP9 - STP_A (PIO 通道 3)
#define M3_DIRECTION_PIN        5             // GP5 - DIR_A
#define M3_LIMIT_PIN            21            // GP21 - L_A
#endif

// 步进使能输出
#define ENABLE_PORT             GPIO_OUTPUT
#define X_ENABLE_PIN            10            // GP10 - EN_X
#define Y_ENABLE_PIN            11            // GP11 - EN_Y
#define Z_ENABLE_PIN            12            // GP12 - EN_Z
#if N_ABC_MOTORS > 0
#define M3_ENABLE_PIN           13            // GP13 - EN_A
#endif

// ============================================================================
// 限位开关输入
// ============================================================================
#define X_LIMIT_PIN             18            // GP18 - L_X
#define Y_LIMIT_PIN             19            // GP19 - L_Y
#define Z_LIMIT_PIN             20            // GP20 - L_Z
#if N_ABC_MOTORS > 0
#define M3_LIMIT_PIN            21            // GP21 - L_A
#endif
#define LIMIT_INMODE            GPIO_MAP      // 映射模式

// ============================================================================
// I2C 设备接口
// ============================================================================
#if I2C_ENABLE
#define I2C_PORT                0
#define I2C_SDA                 16            // GP16 - I2C0_SDA
#define I2C_SCL                 17            // GP17 - I2C0_SCL
#endif

// ============================================================================
// 辅助 IO 和用户控制
// ============================================================================

// 可用的辅助输入引脚
#define AUXINPUT0_PIN           22            // 通用 IO
#define AUXINPUT1_PIN           28            // 通用 IO/探针备选

// 用户控制 (急停、进给保持、循环启动)
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PIN               26            // 急停/复位按钮
#endif

#if CONTROL_ENABLE & CONTROL_FEED_HOLD
#define FEED_HOLD_PIN           27            // 进给保持按钮
#endif

#if CONTROL_ENABLE & CONTROL_CYCLE_START
#define CYCLE_START_PIN         25            // 循环启动按钮
#endif

// 探针输入
#if PROBE_ENABLE
#define PROBE_PIN               28            // GP28 - 探针
#endif

// 安全门输入
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         22            // GP22 - 安全门开关
#endif

// ============================================================================
// 冷却液控制 (可选)
// ============================================================================
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PIN       14            // GP14 - 水冷
#define COOLANT_FLOOD_PORT      GPIO_OUTPUT   // 冷却液端口定义
#endif

#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PIN        15            // GP15 - 气雾
#define COOLANT_MIST_PORT       GPIO_OUTPUT   // 冷却液端口定义
#endif

// ============================================================================
// SPI 接口 (可选，用于 SD 卡或以太网)
// ============================================================================
#if SDCARD_ENABLE || ETHERNET_ENABLE
#define SPI_PORT                1
#define SPI_SCK_PIN             0             // GP0
#define SPI_MOSI_PIN            3             // GP3 (注意：与 DIR_Y 冲突，需禁用)
#define SPI_MISO_PIN            4             // GP4 (注意：与 DIR_Z 冲突，需禁用)
#define SPI_CS_PIN              5             // GP5
#warning "SPI 引脚与方向引脚冲突，请检查配置！"
#endif

// ============================================================================
// RGB LED (可选)
// ============================================================================
#if RGB_LED_ENABLE
#define NEOPIXELS_PIN           25            // WS2812 RGB LED
#define NEOPIXELS_NUM           1
#endif

// ============================================================================
// WiFi (Pico W 内置)
// ============================================================================
#if WIFI_ENABLE
// CYW43439 WiFi 芯片已集成在 Pico W 中
// 无需额外引脚定义
#endif

// HAS_BOARD_INIT 已移除 - 不需要特殊的板级初始化

#endif // __BOARD_MAP_H__
