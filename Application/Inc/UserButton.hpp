#pragma once

#include "stm32f4xx_hal.h"
#include <cstdint>

class UserButton{
public:
	UserButton(GPIO_TypeDef* port, uint16_t pin,  GPIO_PinState pressedLevel, uint32_t debounceMs = 30);

	bool wasPressed(uint32_t nowMS);


private:
	GPIO_TypeDef* port_;
	uint16_t pin_;
	GPIO_PinState pressedLevel_;

	uint32_t debounceMs_;
	uint32_t lastChangeMs_;

	bool lastRawPressed_;
	bool stablePressed_;

};
