The main purpose of this files is to add some new functions to the Repetier firmware so it can work better with my Homemade 3D printer

The new functions added are:

1-New M-codes:

  -M480 P(1,2,3) to store the current position with offset to eeprom so it will still saved even if the printer powered off.

  -M481 P(1.2.3) that prints the saved coordinates in position (1,2,3).

  -M482 P(1,2,3) F(feedrate) that moves the printer to the position (1,2,3) after setting the stored offset with a specific feedrate or       the default feedrate.  
  
2- Emergency power off print recovery  
    the printer will ask to continue a print when it is powered on if an emergency power off detected  
