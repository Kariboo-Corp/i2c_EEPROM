#ifndef i2c_EEPROM_h
#define i2c_EEPROM_h

#include <Arduino.h>


//EEPROM size in kilobits. EEPROM part numbers are usually designated in k-bits.
enum eeprom_size_t {
    kbits_2 = 2,
    kbits_4 = 4,
    kbits_8 = 8,
    kbits_16 = 16,
    kbits_32 = 32,
    kbits_64 = 64,
    kbits_128 = 128,
    kbits_256 = 256,
    kbits_512 = 512,
    kbits_1024 = 1024,
    kbits_2048 = 2048
};

//EEPROM addressing error, returned by write() or read() if upper address bound is exceeded
const uint8_t EEPROM_ADDR_ERR = 9;

class i2c_EEPROM
{
    public:
        //I2C clock frequencies
        enum twiClockFreq_t { twiClock100kHz = 100000, twiClock400kHz = 400000 };
        i2c_EEPROM(eeprom_size_t deviceCapacity, byte nDevice, unsigned int pageSize, byte eepromAddr = 0x50);
        byte begin(twiClockFreq_t twiFreq = twiClock100kHz);
        byte write(unsigned long addr, byte *values, unsigned int nBytes);
        byte write(unsigned long addr, byte value);
        byte read(unsigned long addr, byte *values, unsigned int nBytes);
        int read(unsigned long addr);

    private:
        uint8_t _eepromAddr;            //eeprom i2c address
        uint16_t _dvcCapacity;          //capacity of one EEPROM device, in kbits
        uint8_t _nDevice;               //number of devices on the bus
        uint16_t _pageSize;             //page size in bytes
        uint8_t _csShift;               //number of bits to shift address for chip select bits in control byte
        uint16_t _nAddrBytes;           //number of address bytes (1 or 2)
        unsigned long _totalCapacity;   //capacity of all EEPROM devices on the bus, in bytes
};

#endif
