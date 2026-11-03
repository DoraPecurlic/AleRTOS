#include "OutputTask.h"
#include "LedIndicator.hpp"
#include "main.h"
#include "AlarmState.hpp"
#include "cmsis_os2.h"



extern "C" void OutputTask_Run(void)
{
	LedIndicator led(LED_GPIO_Port, LED_Pin);

	AlarmState state = AlarmState::Active;


	while(true)
	{
		switch(state)
		{
			case AlarmState::Inactive:
				led.turnOff();
				osDelay(100);
				break;

			case AlarmState::Active:
				led.toggle();
				osDelay(500);
				break;

			case AlarmState::Alert:
				led.toggle();
				osDelay(100);
				break;
		}
	}


}
