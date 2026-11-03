#include "OutputTask.h"
#include "LedIndicator.hpp"
#include "main.h"
#include "AlarmState.hpp"
#include "cmsis_os2.h"

#include <cstdint>

extern "C" void OutputTask_Run(osMessageQueueId_t stateQueue)
{
	LedIndicator led(LED_GPIO_Port, LED_Pin);

	AlarmState currentState = AlarmState::Inactive;

	led.turnOff();

	uint32_t receivedState = 0;

	while(true)
	{
		while(osMessageQueueGet(stateQueue, &receivedState, nullptr,0) == osOK){
			currentState = static_cast<AlarmState>(receivedState);
		}
		switch(currentState)
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
