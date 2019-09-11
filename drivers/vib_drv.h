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

#ifndef VIB_DRV_H
#define VIB_DRV_H

/* INCLUDES */

#include "prj_types.h"

/* DEFINES AND TYPES */

/* VARIABLES */

/* PROCEDURES */

void vib_drv_init(uint32 pin, uint32 port);

void vib_drv_set(uint32 pin, uint32 port);

void vib_drv_clear(uint32 pin, uint32 port);

#endif