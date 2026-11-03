/*
 * LogicTask.h
 *
 *  Created on: Nov 3, 2026
 *      Author: Dora_
 */

#ifndef INC_LOGICTASK_H_
#define INC_LOGICTASK_H_

#include "cmsis_os2.h"


#ifdef __cplusplus
extern "C" {
#endif

void LogicTask_Run(osMessageQueueId_t stateQueue);


#ifdef __cplusplus
}
#endif

#endif /* INC_LOGICTASK_H_ */
