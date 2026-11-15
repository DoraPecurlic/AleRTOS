#include "UserButton.hpp"

UserButton::UserButton(
		GPIO_TypeDef* port,
		uint16_t pin,
		GPIO_PinState pressedLevel,
		uint32_t debounceMs
		)
		: port_(port),
		  pin_(pin),
		  pressedLevel_(pressedLevel),
		  debounceMs_(debounceMs),
		  lastChangeMs_(HAL_GetTick()),
		  lastRawPressed_(HAL_GPIO_ReadPin(port, pin) == pressedLevel),
		  stablePressed_(lastRawPressed_)
{

}

bool UserButton::wasPressed(uint32_t nowMs)
{
	bool rawPressed = HAL_GPIO_ReadPin(port_, pin_) == pressedLevel_;

	if(rawPressed != lastRawPressed_)
	{
		lastRawPressed_ = rawPressed;
		lastChangeMs_ = nowMs;
	}

	if ((nowMs - lastChangeMs_) >= debounceMs_)
	{
		if (rawPressed != stablePressed_)
		{
			stablePressed_ = rawPressed;

			if (stablePressed_)
			{
				return true;
			}
		}

	}
	return false;
}
