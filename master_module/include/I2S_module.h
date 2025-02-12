#ifndef I2S_MODULE_H
#define I2S_MODULE_H

class I2S_module
{
public:
    I2S_module(int address, Wire *wire);
    ~I2S_module();

    void askVoltage();
    void askTemperature();
    void askNumber();

private:
    // Add private members and methods here
    int _address;
    int _voltage;
    int _temperature;
    int _number;

    Wire *wire;
};

#endif // I2S_MODULE_H