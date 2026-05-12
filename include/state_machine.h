#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdbool.h>
#include "stddef.h"

typedef enum
{
    STATE_IDLE = 0,
    STATE_ARMED,
    STATE_MEASURING,
    STATE_SENDING,
    STATE_ERROR
}state_t;

typedef enum
{
    EVENT_NONE = 0,
    EVENT_BUTTON_SHORT,
    EVENT_BUTTON_LONG,
    EVENT_SENSOR_READY,
    EVENT_SEND_OK,
    EVENT_SEND_FAIL,
    EVENT_RESET
}event_t;

typedef struct 
{
    state_t current_state;
}state_machine_t;

void sm_init(state_machine_t *sm);
state_t sm_get_state(const state_machine_t *sm);
bool sm_handle_event(state_machine_t *sm, event_t event);

#endif
