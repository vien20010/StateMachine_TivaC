/*
 * LedGreenStateMachine.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Lam Vien
 */

#ifndef LEDGREENSTATEMACHINE_H_
#define LEDGREENSTATEMACHINE_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "switches.h"
#include "led.h"
#include "uartstdio.h"
#include "debug.h"

extern uint32_t ledGTimer;
void ledGreenStateMachineUpdate(void);

#endif /* LEDGREENSTATEMACHINE_H_ */
