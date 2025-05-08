#include "LED.h"

/**
 * @brief 初始化LED GPIO配置
 * @return esp_err_t 
 *         - ESP_OK 成功
 *         - ESP_FAIL 配置失败
 */
esp_err_t LED_Init() {
    gpio_config_t LedGpioConfigStruct;
    LedGpioConfigStruct.intr_type = GPIO_INTR_DISABLE;    // 禁用中断
    LedGpioConfigStruct.mode = GPIO_MODE_OUTPUT;          // 设置为输出模式
    LedGpioConfigStruct.pin_bit_mask = (uint64_t)(1 << LED_PIN);  // 设置GPIO位掩码（转换为64位类型）
    LedGpioConfigStruct.pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉电阻
    LedGpioConfigStruct.pull_up_en = GPIO_PULLUP_ENABLE;  // [!注意] 实际启用了上拉电阻（原注释有误）
    return gpio_config(&LedGpioConfigStruct);
}

/**
 * @brief 开启LED（低电平有效）
 * @note 根据硬件设计，设置低电平点亮LED
 */
void LED_Open() {
    gpio_set_level(LED_PIN, 0);  // 输出低电平点亮LED
}

/**
 * @brief 关闭LED（高电平有效）
 * @note 根据硬件设计，设置高电平熄灭LED
 */
void LED_Close() {
    gpio_set_level(LED_PIN, 1);  // 输出高电平熄灭LED
}