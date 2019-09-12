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

#include <stdbool.h>

#include "prj_types.h"

#include "btn_drv.h"

#include "nrfx_gpiote.h"
#include "nrf_gpio.h"

/* DEFINES AND TYPES */

/* CONSTANTS */

/* VARIABLES */

btn_event_callback registered_callback;

/* PROCEDURES */

static void handle_interrupt(btn_drv_pin_t pin, nrf_gpiote_polarity_t polarity);

/* FUNCTION DEFINITIONS */

void btn_drv_init_pin(btn_drv_pin_t pin)
{
    // Configure in event
    nrfx_gpiote_in_config_t in_event_config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(false);
    in_event_config.pull = NRF_GPIO_PIN_PULLUP;

    nrfx_gpiote_in_init(pin, &in_event_config, &handle_interrupt);
}

void btn_drv_uninit_pin(btn_drv_pin_t pin)
{
    nrfx_gpiote_in_uninit(pin);
}

void btn_drv_set_callback(btn_event_callback callback)
{
    registered_callback = callback;
}

static void handle_interrupt(btn_drv_pin_t pin, nrf_gpiote_polarity_t polarity)
{
    if (registered_callback != NULL)
    {
        registered_callback(pin);
    }
}