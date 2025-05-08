#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "LED.h"

/**
 * @brief 主应用程序入口函数，用于控制LED周期性闪烁
 * 
 * 本函数初始化LED硬件，并进入无限循环周期性地切换LED开关状态。
 * 切换间隔为1秒，通过FreeRTOS的vTaskDelay实现延时。
 * 
 * @param void 无输入参数
 * @return void 无返回值
 */
void app_main(void)
{
    uint8_t flag = 0; // 初始化标志位为0
    LED_Init();
    
    /* LED状态控制主循环 */
    while (1) {
        vTaskDelay(1000);  // 维持当前状态1秒（基于FreeRTOS时钟节拍）
        flag = ~flag; // 翻转标志位
        
        /* 根据标志位状态切换LED */
        if(flag)
            LED_Open();
        else
            LED_Close();
    }
}