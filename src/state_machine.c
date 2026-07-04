#include "state_machine.h"

void sm_init(state_machine_t *sm)
{
    if(sm == NULL)
    {
        return;
    }
    sm->current_state = STATE_IDLE; 
}
state_t sm_get_state(const state_machine_t *sm)
{
    if(sm == NULL)
    {
        return STATE_ERROR;
    }
    return sm->current_state;
}
bool sm_handle_event(state_machine_t *sm, event_t event)
{
    if(sm == NULL)
    {
        return false;
    }

    switch(sm->current_state)
    {
        case STATE_IDLE:
            if(event== EVENT_BUTTON_SHORT)
            {
                sm->current_state = STATE_ARMED;
                return true;
            }
            break;
        
        case STATE_ARMED:
            if(event == EVENT_BUTTON_LONG)
            {
                sm->current_state = STATE_MEASURING;
                return true;
            }
            else if(event == EVENT_RESET)
            {
                sm->current_state = STATE_IDLE;
                return true;
            }
            break;
        
        case STATE_MEASURING:
            if(event == EVENT_SENSOR_READY)
            {
                sm->current_state = STATE_SENDING;
                return true;
            }
            else if(event == EVENT_RESET)
            {
                sm->current_state = STATE_IDLE;
                return true;
            }
            break;

        case STATE_SENDING:
            if(event == EVENT_SEND_OK)
            {
                sm->current_state = STATE_IDLE;
                return true;
            }
            else if(event == EVENT_SEND_FAIL)
            {
                sm->current_state = STATE_ERROR;
                return true;
            }
            break;
        
        case STATE_ERROR:
            if(event == EVENT_RESET)
            {
                sm->current_state = STATE_IDLE;
                return true;
            }
            break;

        default:
            sm->current_state = STATE_ERROR;
            return false;
    }
    return false;
}

