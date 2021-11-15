#ifndef __LSM6DSM_H
#define __LSM6DSM_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
#include "spi.h"	
	
#define SPI_WRITE   0x00U
#define SPI_READ		0x80U

#define FIFO_CTRL5  0x0AU
#define INT1_CTRL		0x0DU
#define CTRL1_XL    0x10U
#define CTRL2_G     0x11U
//default is already in big endian, 4-wire SPI
#define CTRL3_C     0x12U

#define OUTX_L_G  0x22U
#define OUTX_H_G  0x23U
#define OUTY_L_G  0x24U
#define OUTY_H_G  0x25U
#define OUTZ_L_G  0x26U
#define OUTZ_H_G  0x27U
#define OUTX_L_XL  0x28U
#define OUTX_H_XL  0x29U
#define OUTY_L_XL  0x2AU
#define OUTY_H_XL  0x2BU
#define OUTZ_L_XL  0x2CU
#define OUTZ_H_XL  0x2DU

void ls6dsm_spi_write( uint8_t addr, uint8_t data );
uint8_t ls6dsm_spi_read( uint8_t addr );
void lsm6dsm_init(void);

	
#ifdef __cplusplus
}
#endif

#endif /* __LSM6DSM_H */
