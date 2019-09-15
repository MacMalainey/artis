//     Copyright (C) 2019  Mackenzie Malainey, Lora Ma

//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.

//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.

//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

/* INCLUDES */

#include <stdlib.h>
#include <string.h>

#include "prj_types.h"
#include "prj_config.h"

#include "vib_drv.h"

/* DEFINES AND TYPES */

struct vib_task_info;
struct vib_task_info {

    uint8 next_pulse;
    uint16 * pulses;
    struct vib_task_info * next_task;

};
typedef struct vib_task_info vib_task_info;

/* CONSTANTS */

/* VARIABLES */

static vib_task_info * current_task;

/* PROCEDURES */

static void timer_callback(void);

static void trigger_pulse(uint16 length);

/* FUNCTION DEFINITIONS */

void vib_init(void)
{
    vib_drv_init(VIB_PIN, VIB_PIN_PORT);
    current_task = NULL;
}

void vib_pulse_many(uint16 * pulses)
{
    // Copy memory so that it doesn't get pushed off the stack
    uint16 * task_pulses = (uint16 *)malloc(sizeof(pulses));
    memcpy(task_pulses, pulses, sizeof(pulses));

    vib_task_info * new_task = malloc(sizeof(vib_task_info));
    new_task->pulses = task_pulses;
    new_task->next_pulse = 0;
    new_task->next_task = NULL;

    if (current_task == NULL)
    {
        current_task = new_task;
        timer_callback();
    }
    else
    {
        // Traverse the queue to find the last element
        // In THEORY this should be ATMOST 3 tasks...  We need to keep an eye on this...
        vib_task_info * stack_task = current_task;
        while ( stack_task->next_task != NULL )
        {
            stack_task = stack_task->next_task;
        }

        stack_task->next_task = new_task;
    }

}

void vib_pulse(uint16 pulse)
{
    uint16 pulses[1];
    pulses[0] = pulse;
    vib_pulse_many(pulses);
}

static void timer_callback(void)
{
    if (current_task->next_pulse < ARRAY_LENGTH(current_task->pulses, uint16))
    {
        trigger_pulse(current_task->pulses[current_task->next_pulse]);
        current_task->next_pulse++;
    }
    else
    {
        vib_task_info * free_task = current_task;

        // Go to next task
        current_task = current_task->next_task;

        // Free memory
        free(free_task);

        if (current_task != NULL)
        {
            trigger_pulse(current_task->pulses[current_task->next_pulse]);
            current_task->next_pulse++;
        }
    }

}

static void trigger_pulse(uint16 length)
{

}