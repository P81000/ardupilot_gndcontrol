#pragma once

#include <AP_Common/AP_Common.h>
#include <AC_PID/AP_PIDInfo.h>

class AP_SteerController {
public:
    AP_SteerController()
    {
        AP_Param::setup_object_defaults(this, var_info);
    }

    /* Do not allow copies */
    CLASS_NO_COPY(AP_SteerController);

    /*
      return a steering servo output from -4500 to 4500 given a
      desired lateral acceleration rate in m/s/s. Positive lateral
      acceleration is to the right.
     */
	int32_t get_steering_out_lat_accel(float desired_accel);

    /*
      return a steering servo output from -4500 to 4500 given a
      desired yaw rate in degrees/sec. Positive yaw is to the right.
     */
	int32_t get_steering_out_rate(float desired_rate);

    /*
      return a steering servo output from -4500 to 4500 given a
      yaw error in centi-degrees
     */
	int32_t get_steering_out_angle_error(int32_t angle_err);

    /*
      return the steering radius (half diameter). Assumed to be half
      the P value.
     */
    float get_turn_radius(void) const { return _K_P * 0.5f; }

	void reset_I();

	static const struct AP_Param::GroupInfo var_info[];

    const class AP_PIDInfo& get_pid_info(void) const { return _pid_info; }

    void set_reverse(bool reverse) {
        _reverse = reverse;
    }

    // Returns true if controller has been run recently
    bool active() const;

private:
    AP_Float _tau;
	AP_Float _K_FF;
	AP_Float _K_P;
	AP_Float _K_I;
	AP_Float _K_D;
	AP_Float _minspeed;
    AP_Int16  _imax;
	uint32_t _last_t;
	float _last_out;

	AP_Float _deratespeed;
	AP_Float _deratefactor;
	AP_Float _mindegree;

    AP_PIDInfo _pid_info {};

    bool _reverse;
};
