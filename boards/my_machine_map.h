/*
  my_machine_map.h - Pin mapping for Pico2w (RP2350) with PD42S1 driver
                     Based on user-provided pinout table.
*/

#ifndef MY_MACHINE_MAP_H
#define MY_MACHINE_MAP_H

// 板卡名称（会在 $I 中显示）
#define BOARD_NAME "PD42S1_4AXIS_LASER"

// ============================================================================
// 激光模块 PWM
// ============================================================================
#define SPINDLE_PWM_PIN         1          // GP1 输出 PWM 控制激光功率
#define SPINDLE_PORT            GPIO_OUTPUT

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
#define DIRECTION_OUTMODE       GPIO_SHIFT2   // 方向引脚连续（GP2~GP5）

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
// 可选扩展（根据需要取消注释）
// ============================================================================
// 如果需要激光使能信号（M8/M9），可使用冷却引脚
// #define COOLANT_FLOOD_PIN       14

// 如果需要探针对刀
// #define PROBE_PIN               28

// 如果需要外部按钮（急停、进给保持、循环启动）
// #define RESET_PIN               26
// #define FEED_HOLD_PIN           27
// #define CYCLE_START_PIN         25

#endif // MY_MACHINE_MAP_H
