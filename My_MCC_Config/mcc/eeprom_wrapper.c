
/*******************************************************************************
 * @file eeprom_wrapper.c
 * @author Copeland Cold Chain LP
 * 
 * @date 20 November, 2025
 * @brief 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "eeprom_wrapper.h"
#include "mcc_generated_files/system/ccp.h"
#include <avr/io.h>

/******************************************************************************/

/*******************************************************************************
 * Defines
 ******************************************************************************/
/******************************************************************************/

/*******************************************************************************
 * Constants
 ******************************************************************************/
/******************************************************************************/

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
/******************************************************************************/

/*******************************************************************************
 * Private Function Declarations
 ******************************************************************************/
/******************************************************************************/

/*******************************************************************************
 * Public Function Definitions
 ******************************************************************************/
/******************************************************************************/

/**
  * @brief Writes multiple bytes to the eeprom. 
  * 
  * @param starting_address - Starting EEPROM address for the first write 
  * @param bytes - All bytes to be written
  * @param num_bytes - Number of bytes to be written
  * @return true  - write was sucessful
  * @return false - write failed
  */
bool testing_eeprom_write_bytes(eeprom_address_t starting_address, eeprom_data_t *bytes,
                        uint16_t num_bytes)
{
    eeprom_address_t ending_address = starting_address + num_bytes;
    if(ending_address > Testing_EEPROM_MAX_SIZE) 
    {
        ending_address = Testing_EEPROM_MAX_SIZE;
    }
    for (eeprom_address_t i = starting_address; i < ending_address; i++)
    {
        EEPROM_Write(Testing_EEPROM_START_ADDR + i, bytes[i - starting_address]);
        while (EEPROM_IsBusy())
        {
        };
        //Checking to see if EEPROM wrote properly.
        if (NVM_StatusGet() != NVM_OK)
        {
            NVM_StatusClear();
            //Return if we fail once
            return false;
        }
    }
    return true;
}

/**
 * @brief - Reads EEPROM starting at a given address. Will continue to read 
            accending EEPROM addresses given by the num_bytes
            Ex, if starting_address = 128 and num_bytes_to_read is 4 then it will
            read addresses, 128 - 131 inclusive. 
 * @warning it is assumed that *bytes will be big enough to hold requested data.
 * @param starting_address  - Starting EEPROM address for the first read
 * @param num_bytes_to_read - number of total bytes to read
 * @param bytes - all read bytes

 */
void testing_eeprom_read_bytes(eeprom_address_t starting_address, uint16_t num_bytes_to_read,
                       eeprom_data_t *bytes)
{
    eeprom_address_t ending_address = starting_address + num_bytes_to_read;
    if(ending_address > Testing_EEPROM_MAX_SIZE) 
    {
        ending_address = Testing_EEPROM_MAX_SIZE;
    }
    for (eeprom_address_t i = starting_address; i < ending_address; i++)
    {
        eeprom_data_t read_data     = EEPROM_Read(Testing_EEPROM_START_ADDR + i);
        bytes[i - starting_address] = read_data;
    }
}

void eeprom_erase()
{
    //Erase entire EEPROM
    ccp_write_spm((void *) &NVMCTRL.CTRLA, NVMCTRL_CMD_EECHER_gc);

    //Clear the current command
    ccp_write_spm((void *) &NVMCTRL.CTRLA, NVMCTRL_CMD_NONE_gc);
}

/*******************************************************************************
 * Private Function Definitions
 ******************************************************************************/
/******************************************************************************/

/*** end of file ***/
