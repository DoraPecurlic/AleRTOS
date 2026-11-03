#include "LogicTask.h"
#include "AlarmController.hpp"

#include <cstdint>

extern "C" void LogicTask_Run(osMessageQueueId_t stateQueue)
{
	AlarmController alarm;

	uint32_t state = static_cast<uint32_t>(alarm.getState());

	osMessageQueuePut(stateQueue, &state, 0, osWaitForever);

	const AlarmEvent events[] = {
	    AlarmEvent::ButtonPressed,
	    AlarmEvent::ObjectDetected,
	    AlarmEvent::ObjectCleared,
	    AlarmEvent::ButtonPressed
	};

	while(true){
		for(AlarmEvent event : events)
		{
			osDelay(2000);

			if(alarm.handleEvent(event)){
				state = static_cast<uint32_t>(alarm.getState());
			}

			osMessageQueuePut(stateQueue, &state,0, osWaitForever);
		}
	}
}
