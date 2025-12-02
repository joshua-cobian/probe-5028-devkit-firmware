/*******************************************************************************
 * @file eeprom_wrapper.h
 * @author Copeland Cold Chain LP
 * 
 * @date 20 November, 2025
 * @brief Helper functions to help make writing to EEPROM easier
 ******************************************************************************/

#ifndef EEPROM_WRAPPER_H
#define EEPROM_WRAPPER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "mcc_generated_files/nvm/nvm.h"
 /******************************************************************************/

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define Testing_EEPROM_START_ADDR 0x1400
#define Testing_EEPROM_MAX_SIZE 256

/******************************************************************************/

/*******************************************************************************
 * Public Function Delcarations
 ******************************************************************************/

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
                        uint16_t num_bytes);
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
                       eeprom_data_t *bytes);

/**
 * @brief - Erases all contents from the EEPROM
 * 
 */
void testing_eeprom_erase();

/******************************************************************************/

#endif // EEPROM_WRAPPER_H
/*** end of file ***/
