/*
 * InputTask.cpp
 *
 *  Created on: Nov 15, 2026
 *      Author: Dora_
 */
#include "InputTask.h"
#include "UserButton.hpp"
#include "AlarmEvent.hpp"
#include "main.h"



extern "C" void InputTask_Run(osMessageQueueId_t eventQueue)
{
	UserButton button(BUTTON_GPIO_Port,BUTTON_Pin, GPIO_PIN_SET);

	while(true){
		uint32_t nowMs = HAL_GetTick();

		if(button.wasPressed(nowMs)){
			uint32_t event = static_cast<uint32_t>(AlarmEvent::ButtonPressed);
			osMessageQueuePut(eventQueue, &event,0,0);

			osDelay(10);
		}
	}
}
