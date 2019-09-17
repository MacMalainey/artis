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

#include "prj_types.h"
#include "prj_config.h"

#include "btn.h"
#include "btn_drv.h"

/* DEFINES AND TYPES */

/* CONSTANTS */

/* VARIABLES */

static bool is_init = false;

static btn_callback_t event_callback;

/* PROCEDURES */

static void driver_callback();

/* FUNCTION DEFINITIONS */

void btn_init()
{
    btn_drv_set_callback(&driver_callback);

    // Initialize the button interrupts
    btn_drv_init_pin(BTN_1_INTERRUPT_PIN);
    btn_drv_init_pin(BTN_2_INTERRUPT_PIN);
    btn_drv_init_pin(BTN_S_INTERRUPT_PIN);

    is_init = true;
}

void btn_set_callback(btn_callback_t callback)
{
    event_callback = callback;
}

static void driver_callback(btn_drv_pin_t pin)
{
    event_callbacks(pin);
}