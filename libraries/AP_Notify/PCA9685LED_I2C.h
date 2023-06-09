/*
   PCA9685LED I2C driver

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <AP_HAL/I2CDevice.h>
#include "RGBLed.h"

#if AP_NOTIFY_PCA9685_ENABLED

class PCA9685LED_I2C : public RGBLed
{
public:
    PCA9685LED_I2C(void);
    bool init(void) override;
protected:
    bool hw_set_rgb(uint8_t r, uint8_t g, uint8_t b) override;

private:
    AP_HAL::OwnPtr<AP_HAL::I2CDevice> _dev;
    void _timer(void);
    struct {
        uint8_t r, g, b;
    } rgb;
    bool _need_update;
};

#endif  // AP_NOTIFY_PCA9685_ENABLED
