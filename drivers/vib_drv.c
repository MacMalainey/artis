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
#include "nrf_gpio.h"

/* DEFINES */

/* CONSTANTS */

/* VARIABLES */

/* PROCEDURES */

/* FUNCTION DEFINITIONS */

// Initialize the vibrator pin
void vib_drv_init(uint32_t pin, uint32_t port)
{
    nrf_gpio_cfg_output(NRF_GPIO_PIN_MAP(port, pin));
}

// Set the vibrator pin to HIGH
void vib_drv_set(uint32_t pin, uint32_t port)
{
    nrf_gpio_pin_set(NRF_GPIO_PIN_MAP(port, pin));
}

// Clear the vibrator pin to LOW
void vib_drv_clear(uint32_t pin, uint32_t port)
{
    nrf_gpio_pin_clear(NRF_GPIO_PIN_MAP(port, pin));
}


