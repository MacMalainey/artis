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

/* DEFINES */

/* CONSTANTS */

/* VARIABLES */

/* PROCEDURES */

/* FUNCTION DEFINITIONS */

#include <stdbool.h>
#include "nrfx_gpiote.h"
#include "nrf_gpiote.h"

#include "app_simple_timer.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

static void toggle_red(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
static void nrf_init(void);

int main(void)
{
    nrf_init();

    const uint32_t LED_PIN = NRF_GPIO_PIN_MAP(1, 10);
    nrfx_gpiote_in_config_t in_event_config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(false);
    in_event_config.pull = NRF_GPIO_PIN_PULLUP;

    nrf_gpio_cfg_output(LED_PIN);

    nrfx_gpiote_in_init(31, &in_event_config, &toggle_red);

    nrfx_gpiote_in_event_enable(31, true);

}

static void toggle_red(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    if( pin == 31 && NRF_GPIOTE_POLARITY_HITOLO == action )
    {
        const uint32_t LED_PIN = NRF_GPIO_PIN_MAP(1, 10);
        nrf_gpio_pin_set(LED_PIN);
    }
}

static void nrf_init()
{
    // Enable Logging
    NRF_LOG_INIT(NULL);
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    NRF_LOG_INFO("INITIALIZING SDK");

    nrfx_gpiote_init();

    NRF_LOG_PROCESS();
}
