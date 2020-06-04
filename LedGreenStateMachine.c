/*
 * LedGreenStateMachine.c
 *
 *  Created on: Jun 4, 2020
 *      Author: Lam Vien
 */

#include "LedGreenStateMachine.h"

typedef enum {S_LEDGON=0,S_WAITLEDGON1,S_WAITLEDGON2,S_LEDGOFF,S_WAITLEDGOFF1,S_WAITLEDGOFF2} LedGState_t;

static LedGState_t State = S_LEDGOFF;

#ifdef DEBUG
    static const char *stateName[6]={"S_LEDGON",
                                     "S_WAITLEDGON1",
                                     "S_WAITLEDGON2",
                                     "S_LEDGOFF",
                                     "S_WAITLEDGOFF1",
                                     "S_WAITLEDGOFF2"};
#endif

void ledGreenStateMachineUpdate(void)
{
    switch (State)
    {
        case S_LEDGOFF:
            if (switchState(2)==PRESSED)
            {
                State=S_WAITLEDGON1;
                ledGTimer=3000;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDGON1:
            if (switchState(2)==RELEASED)
            {
                State=S_LEDGOFF;
                DBG("State = %s\n",stateName[State]);
            }
            else if(ledGTimer==0)
            {
                State=S_WAITLEDGON2;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDGON2:
            if (switchState(2)==RELEASED)
            {
                State=S_LEDGON;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_LEDGON:
            if (switchState(2)==PRESSED)
            {
                State=S_WAITLEDGOFF1;
                ledGTimer=6000;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDGOFF1:
            if (switchState(2)==RELEASED)
            {
                State=S_LEDGON;
                DBG("State = %s\n",stateName[State]);
            }
            else if (ledGTimer==0)
            {
                State=S_WAITLEDGOFF2;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDGOFF2:
            if (switchState(2)==RELEASED)
            {
                State=S_LEDGOFF;
                DBG("State = %s\n",stateName[State]);
            }
            break;
    }
    switch (State)
    {
        case S_LEDGOFF:
        case S_WAITLEDGON1:
        case S_WAITLEDGOFF2:
            ledControl(LEDGREEN, OFF);
            break;
        case S_LEDGON:
        case S_WAITLEDGOFF1:
        case S_WAITLEDGON2:
            ledControl(LEDGREEN, ON);
            break;
    }
}
