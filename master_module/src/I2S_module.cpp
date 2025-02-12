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
}

void I2S_module::askTemperature()
{
    // Add your implementation here
}

void I2S_module::askNumber()
{
    // Add your implementation here
}