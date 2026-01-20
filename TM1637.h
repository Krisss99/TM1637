/**
  ******************************************************************************
  * @file     tm1637_t.h
  * @author   Krzysztof Cajler
  * @version  V0.1
  * @date     19/01/2026
  * @brief    Default under dev library file.
  ******************************************************************************
*/

#include <stdint.h>

typedef struct tm1637_t {
    GPIO_TypeDef *clk_port;
	GPIO_TypeDef *dio_port;
	uint16_t clk_pin;
	uint16_t dio_pin;
	uint8_t brightness;
} tm1637_t;

/* Initialization of the display with all zeros,
 * mode = 0 -> tm1637_t initialized and zeros are shown
 * mode = 1 -> tm1638 initialized and dashes are shown
 *  */
int tm1637_init(tm1637_t *p, uint8_t mode);

/* Turn segments on, brightness = 0 -> default value passed in struct
 * brightness 1-8 -> turns on and changes default as well
 */
int tm1637_on(tm1637_t *p, uint8_t brighness);

/* Turns all segments off */
int tm1637_off(tm1637_t *p);

/* Update screen with new time in seconds, it will be converted to mm:ss */
int tm1637_update_time(tm1637_t *p, uint16_t seconds);

