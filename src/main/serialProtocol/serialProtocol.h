#ifndef SERIAL_PROTOCOL_H
#define SERIAL_PROTOCOL_H


#define SERIAL_BAUDRATE 115200

/* 
Commands definition 
====================

- Commands are sent as an u_int8_t, so the maximum possible command is 255. 

- UL/DL : 
   UL = PC to TARGET. DL = TARGET to PC. 

        !!!!

!! MAKE AN ENUM WITH TIS !! 
#defines may lead to conflicts? 

        !!!!

*/ 

const enum Serial_Command {
        // Make that enum
} serialCommand ;

// MAP32 Commands. 
#define MAP32_UL 2
#define MAP32_INDEX_UL 3
#define MAP32_DL 4
#define MAP32_INDEX_DL 5

// EEPROM Commands. 
#define EEPROM_SAVE 10
#define EEPROM_CLEAR 11

// Misc Commands
#define HELP 21


#endif