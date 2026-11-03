#include "LedIndicator.hpp"

LedIndicator::LedIndicator(GPIO_TypeDef* port, uint16_t pin): port_(port), pin_(pin)
{

}

void LedIndicator::turnOff() const
{
	HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_RESET);
}

void LedIndicator::toggle() const
{
    HAL_GPIO_TogglePin(port_, pin_);
}
