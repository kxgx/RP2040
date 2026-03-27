/*
  my_machine_map.h - Pin mapping for Pico2w (RP2350) with PD42S1 driver
                     Based on user-provided pinout table.
                     Enhanced with auxiliary I/O definitions from generic_map_4axis.h.
*/

#ifndef MY_MACHINE_MAP_H
#define MY_MACHINE_MAP_H

// 板卡名称（会在 $I 中显示）
#define BOARD_NAME "PD42S1_4AXIS_LASER"

// 设置默认方向反转：A 轴反向
#define DEFAULT_DIRECTION_MASK 8
// ============================================================================
// 激光模块 PWM
// ============================================================================
#define SPINDLE_PWM_PIN         1          // GP1 输出 PWM 控制激光功率

// ============================================================================
// 步进电机接口（PIO 脉冲 + 独立方向）
// ============================================================================
// 脉冲输出：使用 PIO 状态机，基址 GP6~GP9 对应 X、Y、Z、A 轴
#define STEP_PORT               GPIO_PIO
#define STEP_PINS_BASE          6          // GP6: STP_X, GP7: STP_Y, GP8: STP_Z, GP9: STP_A

// 方向输出：独立 GPIO 引脚
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         2          // GP2 DIR_X
#define Y_DIRECTION_PIN         3          // GP3 DIR_Y
#define Z_DIRECTION_PIN         4          // GP4 DIR_Z
#define A_DIRECTION_PIN         5          // GP5 DIR_A
// DIRECTION_OUTMODE 已删除（因为方向引脚已单独定义）

// 使能输出（低电平有效，若驱动器不同可通过 $4 取反）
#define ENABLE_PORT             GPIO_OUTPUT
#define X_ENABLE_PIN            10         // GP10 EN_X
#define Y_ENABLE_PIN            11         // GP11 EN_Y
#define Z_ENABLE_PIN            12         // GP12 EN_Z
#define A_ENABLE_PIN            13         // GP13 EN_A

// ============================================================================
// 限位开关（常闭，低电平触发）
// ============================================================================
#define X_LIMIT_PIN             18         // GP18 L_X
#define Y_LIMIT_PIN             19         // GP19 L_Y
#define Z_LIMIT_PIN             20         // GP20 L_Z
#define A_LIMIT_PIN             21         // GP21 L_A
#define LIMIT_INMODE            GPIO_MAP

// ============================================================================
// I2C 接口（可选，用于扩展设备）
// ============================================================================
#if I2C_ENABLE
#define I2C_PORT                0
#define I2C_SDA                 16         // GP16 I2C0_SDA
#define I2C_SCL                 17         // GP17 I2C0_SCL
#endif

// ============================================================================
// 辅助输出（AUXOUTPUT）—— 用于扩展功能，参考 generic_map_4axis.h
// 以下引脚均未被占用，可根据需要取消注释
// ============================================================================
// #define AUXOUTPUT0_PIN         14        // GP14 空闲，可作冷却/风扇/其他
// #define AUXOUTPUT1_PIN         15        // GP15 空闲
// #define AUXOUTPUT2_PIN         22        // GP22 空闲
// #define AUXOUTPUT3_PIN         26        // GP26 空闲（ADC可用作数字）
// #define AUXOUTPUT4_PIN         27        // GP27 空闲
// #define AUXOUTPUT5_PIN         28        // GP28 空闲

// ============================================================================
// 辅助输入（AUXINPUT）—— 用于扩展功能，参考 generic_map_4axis.h
// 以下引脚均未被占用，可根据需要取消注释
// ============================================================================
// #define AUXINPUT0_PIN          14        // GP14
// #define AUXINPUT1_PIN          15        // GP15
// #define AUXINPUT2_PIN          22        // GP22
// #define AUXINPUT3_PIN          26        // GP26
// #define AUXINPUT4_PIN          27        // GP27
// #define AUXINPUT5_PIN          28        // GP28

// ============================================================================
// 冷却液控制（可选，使用 AUXOUTPUT）
// ============================================================================
#if COOLANT_ENABLE
#define COOLANT_PORT            GPIO_OUTPUT
#endif
#if COOLANT_ENABLE & COOLANT_FLOOD
// #define COOLANT_FLOOD_PIN       AUXOUTPUT0_PIN    // 使用 GP14
#endif
#if COOLANT_ENABLE & COOLANT_MIST
// #define COOLANT_MIST_PIN        AUXOUTPUT1_PIN    // 使用 GP15
#endif

// ============================================================================
// 用户控制按钮（急停、进给保持、循环启动）
// ============================================================================
#if CONTROL_ENABLE & CONTROL_HALT
// #define RESET_PIN               AUXINPUT4_PIN    // 使用 GP27
#endif
#if CONTROL_ENABLE & CONTROL_FEED_HOLD
// #define FEED_HOLD_PIN           AUXINPUT5_PIN    // 使用 GP28
#endif
#if CONTROL_ENABLE & CONTROL_CYCLE_START
// #define CYCLE_START_PIN         AUXINPUT3_PIN    // 使用 GP26
#endif

// ============================================================================
// 探针输入（可选）
// ============================================================================
#if PROBE_ENABLE
// #define PROBE_PIN               AUXINPUT2_PIN    // 使用 GP22
#endif

// ============================================================================
// 安全门输入（可选）
// ============================================================================
#if SAFETY_DOOR_ENABLE
// #define SAFETY_DOOR_PIN         AUXINPUT1_PIN    // 使用 GP15
#endif

#endif // MY_MACHINE_MAP_H
