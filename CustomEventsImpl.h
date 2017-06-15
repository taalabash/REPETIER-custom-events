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
#ifndef CustomEventsImpl_H
#define CustomEventsImpl_H

//#########################################################################################
//#### GCode addition/replacement
//#########################################################################################

 bool Custom_GCode(GCode *com)
 {

    switch(com->G) {
        //XXXX is the number you want to generate
//		case XXXX:

//		break;

  default:
     return false;
  }
  return true;
}

//#########################################################################################
//#### MCode addition/replacement
//#########################################################################################
float memoryX1 = IGNORE_COORDINATE;
float memoryY1 = IGNORE_COORDINATE;
float memoryZ1 = IGNORE_COORDINATE;




bool Custom_MCode(GCode *com)
{

  switch(com->M) {


    case 480:   // M480
      #if EEPROM_MODE !=0
       if(com->hasP()){
        switch(com->P){
         
		     case 1:
          Commands::waitUntilEndOfAllMoves();
          Printer::updateCurrentPosition(false);
          Printer::realPosition(memoryX1, memoryY1, memoryZ1);

          HAL::eprSetFloat(epr_memoryX1,memoryX1);
          HAL::eprSetFloat(epr_memoryY1,memoryY1);
          HAL::eprSetFloat(epr_memoryZ1,memoryZ1);

          Com::printF(PSTR("Ram Saved to position 1: X:"),HAL::eprGetFloat(memoryX1));
          Com::printF(PSTR("  Y:"),HAL::eprGetFloat(memoryY1));
          Com::printFLN(PSTR("  Z:"),HAL::eprGetFloat(memoryZ1));   
          
          Com::printF(PSTR("EEPROM Saved to position 1: X:"),HAL::eprGetFloat(epr_memoryX1));
          Com::printF(PSTR("  Y:"),HAL::eprGetFloat(epr_memoryY1));
          Com::printFLN(PSTR("  Z:"),HAL::eprGetFloat(epr_memoryZ1));   
        
         break;

              }
         }
         #else Com::printErrorF(Com::tNoEEPROMSupport);
         #endif

    break; //end  480

//  --------------------------------------------------------------------

     case 481:  //M481
      #if EEPROM_MODE !=0
       if(com->hasP()){
        switch(com->P){
         case 1:
            Com::printF(PSTR("Position 1: X1:"),HAL::eprGetFloat(epr_memoryX1));
            Com::printF(PSTR("  Y1:"),HAL::eprGetFloat(epr_memoryY1));
            Com::printFLN(PSTR("  Z1:"),HAL::eprGetFloat(epr_memoryZ1));

         break;

            }
         }
         #else Com::printErrorF(Com::tNoEEPROMSupport);
         #endif

    break;  //end 481

//  -------------------------------------------------------------------
    case 482:   //M482
    #if EEPROM_MODE !=0
       if(com->hasP()){
        switch(com->P){
         case 1:
         
            Printer::moveToReal(HAL::eprGetFloat(epr_memoryX1)
                                ,HAL::eprGetFloat(epr_memoryY1)
                                ,HAL::eprGetFloat(epr_memoryZ1)
                                ,IGNORE_COORDINATE
                                ,(com->hasF() ? com->F : Printer::feedrate));

         break;

            }
         }
         #else Com::printErrorF(Com::tNoEEPROMSupport);
         #endif
      break;  //end 482
  
  default:
     return false;
  }
  
  
  return true;
}

#endif
