/*
 * OutputTask.h
 *
 *  Created on: Nov 3, 2026
 *      Author: Dora_
 */

#ifndef INC_OUTPUTTASK_H_
#define INC_OUTPUTTASK_H_

#include "cmsis_os2.h"

#ifdef __cplusplus
extern "C" {
#endif

void OutputTask_Run(osMessageQueueId_t stateQueue);




#ifdef __cplusplus
}
#endif

#endif /* INC_OUTPUTTASK_H_ */
