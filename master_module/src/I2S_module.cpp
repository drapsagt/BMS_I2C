#include <wire.h>
#include "I2S_module.h"

I2S_module::I2S_module(int address, Wire *wire)
{
    this->_address = address;
    this->wire = wire;
}

I2S_module::~I2S_module()
{
    // Add your implementation here
}

void I2S_module::askVoltage()
{
    int voltage = 0;
    wire->beginTransmission(this->_address);
    wire->write(0x01); // Command to ask for voltage
    wire->endTransmission();
    wire->requestFrom(this->_address, 2); // Request 2 bytes from the device

    if (wire->available() == 2)
    {
        voltage = wire->read() << 8 | wire->read();
    }

    this->_voltage = voltage;
}

void I2S_module::askTemperature()
{
    // Add your implementation here
}

void I2S_module::askNumber()
{
    // Add your implementation here
}