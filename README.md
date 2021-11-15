# lsm6dsm-Nucleo_L073
IMU lsm6dsm project with Nucleo L073

# Configuration

SPI: 3MHz, 8 bits data size, sofeware NSS signal

When button is pressed pin BUTTON signal toggles, a timer TIM2 initiates and increment counter hndr_ms_cnt by 1 every 100ms. When button is released hndr_ms_cnt stops counting and determines power on action based on the previous pwr_on state. Pin POWER_ON is used to change the ON/OFF state, high -> ON, low -> OFF.

Accelerometer: Set ODR to 833Hz, range to +-16g using register CTRL1_XL

Gyro: Set ODR to 833Hz, range to +-2000dps using register CTRL2_G

Enable Gyro and Accelerometer data interrupt on INT1 using register INT1_CTRL

When device is ON && INT1 is triggered, gyro and accerlerometer data will be read using registers OUTX/Y/Z_H/L_G/XL and display on terminal screen if needed.

Debug printf can be enabled with DEBUG mode on.

# MCU PINOUTs

PC_1[POWER_ON]: Output, Push pull, no pull-up&pull-down, initial output level low.

PC_4: IMU INT1 interrupt pin, external interrupt mode, rising edge trigger dection

PC_13[BUTTON]: BUTTON interrupt pin, external interrupt mode, rising&falling edge trigger detection

PA_5[LD2]: LED pin, output, push pull, no pull-up&pull-down, initial output level low.

PA_2: USART_TX

PA_3: USART_RX

PA_4: SPI1_NSS

PB_3: SPI_SCK

PA_6: SPI1_MISO

PA_7: SPI1_MOSI

