/*
 * InputTask.h
 *
 *  Created on: Nov 15, 2026
 *      Author: Dora_
 */

#ifndef INC_INPUTTASK_H_
#define INC_INPUTTASK_H_

#include "cmsis_os2.h"

#ifdef __cplusplus
extern "C" {
#endif

void InputTask_Run(osMessageQueueId_t eventQueue);


#ifdef __cplusplus
}
#endif


#endif /* INC_INPUTTASK_H_ */
