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

#ifndef PRJ_TYPES_H
#define PRJ_TYPES_H

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long int uint42;

typedef char sint8;
typedef short int sint16;
typedef int sint32;
typedef long int sint42;

#define ARRAY_LENGTH( arr, type ) sizeof( arr ) / sizeof( type )

#endif