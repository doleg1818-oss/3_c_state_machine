#include <stdio.h>
#include "state_machine.h"

static const char *state_to_string(state_t state)
{
    switch(state)
    {
        case STATE_IDLE: return "IDLE";
        case STATE_ARMED: return "ARMED"; 
        case STATE_MEASURING: return "MEASURING";
        case STATE_SENDING: return "SENDING";
        case STATE_ERROR: return "ERROR";
        default: return "UNCKNOWN";
    }
}

int main(void)
{
    state_machine_t sm;

    sm_init(&sm);

    printf("Current state %s\n ", state_to_string(sm_get_state(&sm)));

    sm_handle_event(&sm, EVENT_BUTTON_SHORT);
    printf("Current state %s\n ", state_to_string(sm_get_state(&sm)));

    sm_handle_event(&sm, EVENT_BUTTON_LONG);
    printf("Current state %s\n ", state_to_string(sm_get_state(&sm)));

    sm_handle_event(&sm, EVENT_SENSOR_READY);
    printf("Current state %s\n ", state_to_string(sm_get_state(&sm)));

    sm_handle_event(&sm, EVENT_SEND_OK);
    printf("Current state %s\n ", state_to_string(sm_get_state(&sm)));

    return 0;
}