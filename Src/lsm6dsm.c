/**
  ******************************************************************************
  * File Name          : lsm6dsm.c
  * Description        : This file provides code for the configuration
  *                      of IMU sensor LSM6DSM. Part# LSM6DSMTR
  ******************************************************************************
  */
	
	
#include "lsm6dsm.h"

uint8_t txData;

void ls6dsm_spi_write( uint8_t addr, uint8_t data )
{
	uint8_t rxData;
	
	//NSS=0
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	
	txData = SPI_WRITE | addr ;
	HAL_SPI_TransmitReceive( &hspi1, (uint8_t *) &txData, (uint8_t *) &rxData, 1, HAL_MAX_DELAY );
	txData = SPI_WRITE | data ;
	HAL_SPI_TransmitReceive( &hspi1, (uint8_t *) &txData, (uint8_t *) &rxData, 1, HAL_MAX_DELAY );
	
	//NSS=1
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	
	HAL_Delay(5);
}

uint8_t ls6dsm_spi_read( uint8_t addr )
{
	uint8_t rxData;
	
	//NSS=0
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	
	txData = SPI_READ | addr ;
	HAL_SPI_TransmitReceive( &hspi1, (uint8_t *) &txData, (uint8_t *) &rxData, 1, HAL_MAX_DELAY );
	rxData = 0;
	txData = SPI_READ | 0 ;
	HAL_SPI_TransmitReceive( &hspi1, (uint8_t *) &txData, (uint8_t *) &rxData, 1, HAL_MAX_DELAY );
	
	//NSS=1
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	
	HAL_Delay(5);
	
	return rxData;
}


void lsm6dsm_init(void)
{
	//ls6dsm_spi_write(FIFO_CTRL5, 0x3E); // Data: 0 0111 110
	ls6dsm_spi_write(CTRL1_XL, 0x7C); // Data: 0111 11xx
	ls6dsm_spi_write(CTRL2_G, 0x7C); // Data: 0111 11x0
	ls6dsm_spi_write(INT1_CTRL, 0x03); // Data: 0000 0011
}


