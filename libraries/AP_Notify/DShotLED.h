/*
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

#include "RGBLed.h"
#include "DShotLED.h"
#include <AP_Common/AP_Common.h>

class DShotLED : public RGBLed {
public:
    DShotLED() : RGBLed(0, 1, 1, 1) {}

    bool init(void) override { return true; }

protected:
    bool hw_set_rgb(uint8_t r, uint8_t g, uint8_t b) override;
};
