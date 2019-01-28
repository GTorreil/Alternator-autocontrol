#include <stdio.h>
#include <inttypes.h>

/* 
Commands definition 
====================

- Commands are sent as an u_int8_t, so the maximum possible command is 255. 

- UL/DL : 
   UL = PC to TARGET. DL = TARGET to PC. 

*/ 

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

u_int8_t table [32][32];
char message[1027];

/* 
This routine is a debug utility that prints a X32 map to the console. 
*/ 
void printX32Map(u_int8_t table[32][32]){
   for(int j = 0; j < 32; j++){
      for (int i = 0; i < 32; i++){
         u_int8_t a = table[i][j];
         printf("%" PRIu8,a & 0xff);
         printf(",");
      }
      printf("\n");
   }
}

/*
This routine is a debug utility that prints details about each byte of the blob. 
*/
void printDetailledBlobX32(char blobX32[1027]){
   for (int i = 0; i<1027; i++){
         printf("Byte : %i - Content : %u - Size : %lu \n",i, blobX32[i], sizeof(blobX32[i]));
      }
}

/*
This routine is a utility that outputs the raw binary blob to the console. 
*/
void dumpBlobX32(char blobX32[1027]){
   for (int i = 0; i<1027; i++){
      printf("%u",blobX32[i]);
   }
}

int main()
{
   message[0] = 2;

   int index = 1;
   
   for(int j = 0; j < 32; j++){
      for (int i = 0; i < 32; i++){
         message[index] = table[i][j];
         index ++ ;
      }
   }

   printDetailledBlobX32(message);
   dumpBlobX32(message);

   return 0;
}

