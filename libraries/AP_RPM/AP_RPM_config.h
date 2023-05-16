#pragma once

#include <AP_HAL/AP_HAL_Boards.h>

#include <AP_EFI/AP_EFI_config.h>
#include <AP_Generator/AP_Generator.h>

#ifndef AP_RPM_ENABLED
#define AP_RPM_ENABLED 1
#endif

#ifndef AP_RPM_BACKEND_DEFAULT_ENABLED
#define AP_RPM_BACKEND_DEFAULT_ENABLED AP_RPM_ENABLED
#endif

#ifndef AP_RPM_EFI_ENABLED
#define AP_RPM_EFI_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED && HAL_EFI_ENABLED
#endif

#ifndef AP_RPM_ESC_TELEM_ENABLED
#define AP_RPM_ESC_TELEM_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED
#endif

#ifndef AP_RPM_HARMONICNOTCH_ENABLED
#define AP_RPM_HARMONICNOTCH_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED
#endif

#ifndef AP_RPM_PIN_ENABLED
#define AP_RPM_PIN_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED
#endif

#ifndef AP_RPM_SIM_ENABLED
#define AP_RPM_SIM_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED && AP_SIM_ENABLED
#endif

#ifndef AP_RPM_GENERATOR_ENABLED
#define AP_RPM_GENERATOR_ENABLED AP_RPM_BACKEND_DEFAULT_ENABLED && HAL_GENERATOR_ENABLED
#endif
