# i2c_EEPROM

This is a simple lib to communicate with i2c EEPROM chips (ex. M24M01). FreeRTOS + STM32Duino.

## Usage

```cpp
i2c_EEPROM eep(kbits_1024, 1, 256, 0x56);
...
uint32_t addr = 0;
byte err = eep.write(addr, 25);
Serial << F("HEX : ") << _HEX(err) << endl;

int value = eep.read(addr);
Serial << F("Value read = ") << value << endl;
```