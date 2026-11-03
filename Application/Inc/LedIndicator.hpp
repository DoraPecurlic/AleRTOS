#pragma once

#include "stm32f4xx_hal.h"

class LedIndicator{
public:
	LedIndicator(GPIO_TypeDef* port, uint16_t pin);

	void turnOff() const;
	void toggle() const;

private:
	GPIO_TypeDef* port_;
	uint16_t pin_;
};
