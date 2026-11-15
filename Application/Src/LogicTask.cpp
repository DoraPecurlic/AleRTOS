#include "LogicTask.h"
#include "AlarmController.hpp"

#include <cstdint>

extern "C" void LogicTask_Run(osMessageQueueId_t eventQueue, osMessageQueueId_t stateQueue)
{
	AlarmController alarm;

	uint32_t state = static_cast<uint32_t>(alarm.getState());

	osMessageQueuePut(stateQueue, &state, 0, osWaitForever);


	while(true){
		uint32_t receivedEvent = 0;

		osStatus_t status = osMessageQueueGet(eventQueue, &receivedEvent, nullptr, osWaitForever);

		if(status != osOK){
			continue;
		}

		if(receivedEvent > static_cast<uint32_t>(AlarmEvent::ObjectCleared)){
			continue;
		}

		AlarmEvent event = static_cast<AlarmEvent>(receivedEvent);
		if(alarm.handleEvent(event))
		{
			state = static_cast<uint32_t>(alarm.getState());

			osMessageQueuePut(stateQueue, &state, 0, osWaitForever);
		}

	}
}
