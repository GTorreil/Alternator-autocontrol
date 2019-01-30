#ifndef SERIAL_PROTOCOL_H
#define SERIAL_PROTOCOL_H


#define SERIAL_BAUDRATE 115200

/* 
Commands definition 
====================

- Commands are sent as an u_int8_t, so the maximum possible command is 255. 

- UL/DL : 
   UL = PC to TARGET. DL = TARGET to PC. 

*/ 

const enum Serial_Command {
        NONE,
        MAP32_UL,
        MAP32_INDEX_UL,
        MAP32_DL,
        MAP32_INDEX_DL,
        EEPROM_SAVE,
        EEPROM_CLEAR,
        HELP,
} serialCommand = NONE ;

void serialProtocol_begin();

void serial_loop();


#endif