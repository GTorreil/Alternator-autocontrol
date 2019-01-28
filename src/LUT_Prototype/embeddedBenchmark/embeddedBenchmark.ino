/*

  DRAFT on Serial Manager State System

  commandManagerState :
    - enum CurrentCommand = MAP32 or MAP32_INDEX or ...

*/



enum CurrentSerialCommand
{
  NONE, // 0
  MAP32,
  MAP32_INDEX,
  DMP_MAP32,
  DMP_MAP32_INDEX,
  SAVE,
  EEPROM_CLEAR,
  HELP
} currentSerialCommand = NONE ;

struct Map32 {
  int map32[32][32];
  int index32[2][32];
} map32 ;

/*
  int map32[32][32];
  int map32_index[2][32];
*/

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {

  Serial.begin(SERIAL_BAUDRATE);
  inputString.reserve(MAX_COMMAND_SIZE);
}


void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    handleCommand(inputString);
  }
}

/*
  commandHandler routines
*/

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
void commandHandler_handleMap32Command(String command) {
 
  if (!command.equalsIgnoreCase("MAP32")){
   
    if (!command.equalsIgnoreCase("END")) {

      // Parse the line
      char commandChars[command.length()];
      command.toCharArray(commandChars,command.length()+1);
      Serial.println(commandChars);
      
      int line[32];
      
      int beginIndex = 0; 
      int i;
      for (i = 0; i < command.length(); i++){
        if (commandChars[i] == ','){
          char number[4];
          int a;
          for (a = beginIndex; a < i; a++){
            number[a-beginIndex] = commandChars[a];
          }
          Serial.println(number);
          beginIndex = i+1;
        }
      }

    } else {

      currentSerialCommand = NONE;

    }
  
  }

}

/*
  HELP Command
  List available commands
*/
void commandHandler_handleHelpCommand() {
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

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
