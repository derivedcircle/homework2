#ifndef SENSOR_H // include guard
#define SENSOR_H

// 1.1 code
class Sensor { // implimenting a base virtual class with all virtual functions for gather and proces data
public:
    // Virtual function for data collection
    virtual void gatherData() = 0;

    // Virtual function for data processing
    virtual void processData() = 0;
};

#endif // SENSOR_H
