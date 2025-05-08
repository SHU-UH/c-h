#ifndef _LED_H
#define _LED_H

#define LED_PIN 4 // LED pin number
#include "driver/gpio.h"

esp_err_t LED_Init();
void LED_Open();
void LED_Close();

#endif // !_LED_H    