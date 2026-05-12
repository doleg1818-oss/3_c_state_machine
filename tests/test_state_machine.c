#include <assert.h>
#include <stdio.h>
#include "stddef.h"

#include "state_machine.h"

int main(void)
{
    state_machine_t sm;

    sm_init(&sm);

    assert(sm_get_state(&sm) == STATE_IDLE);

    assert(sm_handle_event(&sm, EVENT_BUTTON_SHORT) == true);
    assert(sm_get_state(&sm) == STATE_ARMED);

    assert(sm_handle_event(&sm, EVENT_BUTTON_LONG) == true);
    assert(sm_get_state(&sm) == STATE_MEASURING);

    assert(sm_handle_event(&sm, EVENT_SENSOR_READY) == true);
    assert(sm_get_state(&sm) == STATE_SENDING);

    assert(sm_handle_event(&sm, EVENT_SEND_OK) == true);
    assert(sm_get_state(&sm) == STATE_IDLE);


    
    printf("TEST PASS\n");

    return 0;
}