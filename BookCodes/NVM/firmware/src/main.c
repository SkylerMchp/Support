/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#define READ_WRITE_SIZE         (NVM_FLASH_PAGESIZE)
#define BUFFER_SIZE             (READ_WRITE_SIZE / sizeof(uint32_t))
#define APP_FLASH_ADDRESS       (NVM_FLASH_START_ADDRESS + (NVM_FLASH_SIZE / 2))



#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

static volatile bool xferDone = false;

static void eventHandler(uintptr_t context)
{
    xferDone = true;
}
int arr[10] = {55};
uint32_t  writeData[BUFFER_SIZE]={0xFFFFFFFF};
uint32_t readData[BUFFER_SIZE]={0x00};
int main ( void )
{volatile unsigned char ch[]="HelloWorld!";
 volatile unsigned char chout[BUFFER_SIZE];

    uint32_t i,address = APP_FLASH_ADDRESS;
    uint8_t *writePtr = (uint8_t *)writeData;
    memcpy(writeData,ch,sizeof(ch));
    for(i=0;i<BUFFER_SIZE;i++)
    {readData[i]  = 0xFF;}
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    NVM_CallbackRegister(eventHandler, (uintptr_t)NULL);
    while(NVM_IsBusy() == true);
    NVM_PageErase(address);
    while(xferDone == false);
    xferDone = false;
    for (i = 0; i < READ_WRITE_SIZE; i+= NVM_FLASH_ROWSIZE)
    {   /* Program a row of data */
        NVM_RowWrite((uint32_t *)writePtr, address);
        while(xferDone == false);
        xferDone = false;
        writePtr += NVM_FLASH_ROWSIZE;
        address  += NVM_FLASH_ROWSIZE;
    }
    NVM_Read(readData, sizeof(writeData), APP_FLASH_ADDRESS);
    memcpy(chout, writeData,sizeof(ch));
    while ( true )
    {static volatile int i=0;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

