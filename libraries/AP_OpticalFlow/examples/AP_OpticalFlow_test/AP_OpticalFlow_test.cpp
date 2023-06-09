/*
 *  Example of AP_OpticalFlow library.
 *  Code by Randy Mackay. DIYDrones.com
 */

#include <AP_AHRS/AP_AHRS.h>
#include <AP_Baro/AP_Baro.h>
#include <AP_Compass/AP_Compass.h>
#include <AP_GPS/AP_GPS.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_InertialSensor/AP_InertialSensor.h>
#include <AP_NavEKF2/AP_NavEKF2.h>
#include <AP_NavEKF3/AP_NavEKF3.h>
#include <AP_OpticalFlow/AP_OpticalFlow.h>
#include <AP_RangeFinder/AP_RangeFinder.h>
#include <AP_SerialManager/AP_SerialManager.h>

void setup();
void loop();

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

class DummyVehicle {
public:
    AP_GPS gps;
    AP_Baro barometer;
    Compass compass;
    AP_InertialSensor ins;
    AP_SerialManager serial_manager;
    RangeFinder sonar;
    AP_AHRS ahrs{AP_AHRS::FLAG_ALWAYS_USE_EKF};
};

static DummyVehicle vehicle;
#if AP_OPTICALFLOW_ENABLED
static AP_OpticalFlow optflow;
#endif

void setup()
{
    hal.console->printf("OpticalFlow library test ver 1.6\n");

    hal.scheduler->delay(1000);

#if AP_OPTICALFLOW_ENABLED
    // flowSensor initialization
    optflow.init(-1);

    if (!optflow.healthy()) {
        hal.console->printf("Failed to initialise OpticalFlow");
    }
#else
    hal.console->printf("OpticalFlow compiled out");
#endif

    hal.scheduler->delay(1000);
}

void loop()
{
    hal.console->printf("this only tests compilation succeeds\n");

    hal.scheduler->delay(5000);
}

AP_HAL_MAIN();
