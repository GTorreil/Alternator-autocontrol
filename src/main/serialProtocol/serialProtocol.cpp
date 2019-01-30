
void serialProtocol_begin(){
    Serial.begin(SERIAL_BAUDRATE);
}

/*
  Process a line of serial command.
*/
void handleCommand(String command) {
  commandHandler_startCommandIfNeeded(command);
  switch (currentSerialCommand) {
    case NONE:
      //commandHandler_startCommandIfNeeded(command);
      break;

    case MAP32:
      commandHandler_handleMap32Command(command);
      break;

    case MAP32_INDEX:
      break;

    case DMP_MAP32:
      break;

    case DMP_MAP32_INDEX:
      break;

    case SAVE:
      break;

    case EEPROM_CLEAR:
      break;

    case HELP:
      commandHandler_handleHelpCommand();
      break;

    default :
      break; // do nothing
  }
      // clear the string
      inputString = "";
      stringComplete = false;
}

/*
  Called if a new Serial string was received while
  not running a command, which probably means the
  master wants to initiate a new Serial command.
*/
void commandHandler_startCommandIfNeeded(String command) {
  if (command.equalsIgnoreCase("MAP32"))
  {
    currentSerialCommand = MAP32;
  }

  else if (command.equalsIgnoreCase("MAP32_INDEX"))
  {
    currentSerialCommand = MAP32_INDEX;
  }

  else if (command.equalsIgnoreCase("DMP_MAP32"))
  {
    currentSerialCommand = DMP_MAP32;
  }

  else if (command.equalsIgnoreCase("DMP_MAP32_INDEX"))
  {
    currentSerialCommand = DMP_MAP32_INDEX;
  }

  else if (command.equalsIgnoreCase("SAVE"))
  {
    currentSerialCommand = SAVE;
  }

  else if (command.equalsIgnoreCase("EEPROM_CLEAR"))
  {
    currentSerialCommand = EEPROM_CLEAR;
  }

  else if (command.equalsIgnoreCase("HELP"))
  {
    currentSerialCommand = HELP;
  }

}

/*
  MAP32 Command
  received a new line of x32 map
*/
void sp_handleMap32Command(String command) {

}

/*
  HELP Command
  List available commands
*/
void sp_handleHelpCommand() {
  
  // Experimental new way of displaying help messages
  char helpMessage[] = "Available Commands : "
  
  Serial.println("-> Available commands : ");
  Serial.println("MAP32 Commands");
  Serial.println("X MAP32 ........... Start uploading a x32 map");
  Serial.println("X MAP32_INDEX ..... Start uploading a x32 map index");
  Serial.println("X DMP_MAP32 ....... Dump the onboard x32 map");
  Serial.println("X DMP_MAP32_INDEX . Dump the onboard x32 map index");
  Serial.println("EEPROM Commands");
  Serial.println("X SAVE ............ Save maps and config to EEPROM");
  Serial.println("X EEPROM_CLEAR .... Clear the EEPROM (Warning!)");
  Serial.println("Misc. Commands");
  Serial.println("O HELP ......... List available commands");
  currentSerialCommand = NONE;
}

/*
  End of commandHandler routines
*/

void serial_loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
  }
}