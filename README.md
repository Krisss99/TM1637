# TM1637 Driver for STM32 (HAL)

A lightweight C library for interfacing the TM1637 4-digit 7-segment display with STM32 microcontrollers. This driver uses direct register manipulation (BSRR) for high-speed bit-banging while maintaining compatibility with the STM32 HAL environment.

# 🛠 Features

- Flexible GPIO Mapping: Supports any GPIO pins across different ports.
- Clock Mode: Specialized function to convert seconds into MM:SS format.
- Initialization Modes: Start the display with zeros (0000) or dashes (----).
- Brightness Control: 8 levels of intensity that can be adjusted at setup or at dynamically when needed.
- Developed using L432KC: Developed for stm32l4xx, but easily portable to other series.

# ⚙️ Hardware Configuration
STM32CubeMX Setup
- Configure two pins (e.g., PB10 for CLK and PB11 for DIO) as GPIO_Output.
- Set Output Speed to Low.
- Set GPIO Mode to Output Open Drain with Pull-up resistors (DIO needs to be open-drain, otherwise won't work).

# 🚀 How to Use

In your main.c, after importing ```TM1637.h``` create a configuration struct of type tm1637_t for your display:
```
  tm1637_t tm1637 = {
    .clk_port = TM1637_CLK_GPIO_Port,
    .dio_port = TM1637_DIO_GPIO_Port,
    .clk_pin  = TM1637_CLK_Pin,
    .dio_pin  = TM1637_DIO_Pin,
    .brightness = 2,
    .colon_on = 1
  };
```

As you can see above, you can set brightness to a specific value from 0 to 7, or if you want or don't want to use a colon.

# 📚 API Reference

```int tm1637_init(tm1637_t *p, uint8_t mode)```

Initializes the display with two starting modes:
- Mode 0: Displays 0000 after init.
- Mode 1: Displays ---- after init.

```int tm1637_update_time(tm1637_t *p, uint16_t seconds)```

Automatically converts seconds into a four-digit time format and sends it to TM1637 IC.

```int tm1637_on(tm1637_t *p, uint8_t brightness)```

Turns the display on and sets brightness (1–7). If 0 is passed, it uses the default brightness stored in the struct.

```int tm1637_off(tm1637_t *p)```

Turns off all segments and the display backlight.

🔧 Porting to other STM32 Series

This library includes #include "stm32l4xx.h". To use it on an F1, F4, or other series:

- Change the include in tm1637.h to your specific series (e.g., #include "stm32f4xx.h").
- Ensure the BSRR register logic remains the same (standard across most STM32s).
- You can use it without ST's official headers, but you will need to take care of defining GPIO and BSRR yourself and look for correct adresses in the documentation.

***
[link-repo]: https://github.com/Krisss99/board-game-timer
With progression of another [project][link-repo], this library could be updated.
