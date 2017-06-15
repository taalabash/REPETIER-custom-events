THe main purpose of this files is to add some new functions to the Repetier firmware so it can work better with my Homemade 3D printer

The new functions added are:

New M-codes:

-M480 P(1,2,3)  to store the current position to eeprom so it will still saved even if the printer powered off.

-M481 P(1.2.3) that prints the saved coordinates in position (1,2,3).

-M482 P(!,2,3) F(feedrate) that moves the printer to the position (1,2,3) in with a specific feedrate or the default feedrate.
