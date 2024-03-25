#ifndef SENSOR_H
#define SENSOR_H

// 1.1
class Sensor {
public:
    // Virtual function for data collection
    virtual void gatherData() = 0;

    // Virtual function for data processing
    virtual void processData() = 0;
};

#endif // SENSOR_H
