/*
    This file is additional to Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

    This firmware is a nearly complete rewrite of the sprinter firmware
    by kliment (https://github.com/kliment/Sprinter)
    which based on Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.

    author of this additional File : RAyWB / Robert Ayrenschmalz

*/
#ifndef CustomEvents_H
#define CustomEvents_H

extern bool Custom_GCode(GCode *com);
extern bool Custom_MCode(GCode *com); 


//static float memoryX1;
//static float memoryX2;
//static float memoryX3;
//
//static float memoryY1;
//static float memoryY2;
//static float memoryY3;
//
//static float memoryZ1;
//static float memoryZ2;
//static float memoryZ3;

#define epr_memoryX1        400
#define epr_memoryX2        401
#define epr_memoryX3        402

#define epr_memoryY1        403
#define epr_memoryY2        404
#define epr_memoryY3        405

#define epr_memoryZ1        406
#define epr_memoryZ2        407
#define epr_memoryZ3        408



//G and M code replacements and /or additional
//#undef EVENT_UNHANDLED_G_CODE(c)
//#define EVENT_UNHANDLED_G_CODE(c) Custom_GCode(c)

#undef EVENT_UNHANDLED_M_CODE(c)
#define EVENT_UNHANDLED_M_CODE(c) Custom_MCode(c)


#endif
