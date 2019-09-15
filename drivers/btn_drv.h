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

#ifndef BTN_DRV_H
#define BTN_DRV_H

/* INCLUDES */

#include "prj_types.h"

#include "nrfx_gpiote.h"
#include "nrf_gpio.h"

/* DEFINES */

typedef nrfx_gpiote_pin_t btn_drv_pin_t;

typedef void (*btn_event_callback)(btn_drv_pin_t pin);

/* VARIABLES */

/* PROCEDURES */

void btn_drv_init_pin(btn_drv_pin_t pin);

void btn_drv_uninit_pin(btn_drv_pin_t pin);

void btn_drv_set_callback(btn_event_callback callback);

#endif