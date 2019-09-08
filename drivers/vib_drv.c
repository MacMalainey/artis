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
void vib_drv_cfg( unsigned char pin )
{
    nrf_gpio_cfg_output( pin );
}

// Set the vibrator pin to HIGH
void vib_drv_set( unsigned char pin )
{
    nrf_gpio_pin_set( pin );
}

// Clear the vibrator pin to LOW
void vib_drv_clear( unsigned char pin )
{
    nrf_gpio_pin_clear( pin );
}


