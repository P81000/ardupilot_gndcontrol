// ServoPackets.h was generated by ProtoGen version 3.2.a

/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Oliver Walters / Currawong Engineering Pty Ltd
 */

#ifndef _SERVOPACKETS_H
#define _SERVOPACKETS_H

// Language target is C, C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \file
 */

#include <stdbool.h>
#include "ServoProtocol.h"
#include "ServoDefines.h"

/*!
 * General servo configuration settings
 */
typedef struct
{
    Servo_ConfigBits_t options;        //!< Servo configuration parameters
    uint16_t           commandTimeout; //!< Servo command timeout
    int16_t            homePosition;   //!< Servo neutral position. Servo can be configured to return to this position at powerup, or after loss of communication
    uint8_t            reserved[2];    //!< Reserved for future use
}Servo_Config_t;

//! Create the Servo_Config packet
void encodeServo_ConfigPacketStructure(void* pkt, const Servo_Config_t* user);

//! Decode the Servo_Config packet
int decodeServo_ConfigPacketStructure(const void* pkt, Servo_Config_t* user);

//! Create the Servo_Config packet from parameters
void encodeServo_ConfigPacket(void* pkt, const Servo_ConfigBits_t* options, uint16_t commandTimeout, int16_t homePosition, const uint8_t reserved[2]);

//! Decode the Servo_Config packet to parameters
int decodeServo_ConfigPacket(const void* pkt, Servo_ConfigBits_t* options, uint16_t* commandTimeout, int16_t* homePosition, uint8_t reserved[2]);

//! Encode a Servo_Config_t into a byte array
void encodeServo_Config_t(uint8_t* data, int* bytecount, const Servo_Config_t* user);

//! Decode a Servo_Config_t from a byte array
int decodeServo_Config_t(const uint8_t* data, int* bytecount, Servo_Config_t* user);

//! return the packet ID for the Servo_Config packet
#define getServo_ConfigPacketID() (PKT_SERVO_CONFIG)

//! return the minimum encoded length for the Servo_Config packet
#define getServo_ConfigMinDataLength() (8)

//! return the maximum encoded length for the Servo_Config packet
#define getServo_ConfigMaxDataLength() (8)

/*!
 * This packet can be used to simultaneously command multiple servos which have
 * sequential CAN ID values. This packet must be sent as a broadcast packet
 * (address = 0xFF) such that all servos can receive it. These commands can be
 * sent to groups of servos with ID values up to 64, using different
 * PKT_SERVO_MULTI_COMMAND_x packet ID values.
 */
typedef struct
{
    int16_t commandA; //!< Servo command for servo with address offset 0
    int16_t commandB; //!< Servo command for servo with address offset 1
    int16_t commandC; //!< Servo command for servo with address offset 3
    int16_t commandD; //!< Servo command for servo with address offset 3
}Servo_MultiPositionCommand_t;

//! Create the Servo_MultiPositionCommand packet from parameters
void encodeServo_MultiPositionCommandPacket(void* pkt, int16_t commandA, int16_t commandB, int16_t commandC, int16_t commandD, uint32_t id);

//! Decode the Servo_MultiPositionCommand packet to parameters
int decodeServo_MultiPositionCommandPacket(const void* pkt, int16_t* commandA, int16_t* commandB, int16_t* commandC, int16_t* commandD);

//! return the minimum encoded length for the Servo_MultiPositionCommand packet
#define getServo_MultiPositionCommandMinDataLength() (8)

//! return the maximum encoded length for the Servo_MultiPositionCommand packet
#define getServo_MultiPositionCommandMaxDataLength() (8)

/*!
 * Send this command to move the servo(s) to the commanded position. Position
 * command units depend on the configuration of the servo. Send with the
 * broadcast ID (0xFF) to send the position command to *all* servos.
 */
typedef struct
{
    int16_t command; //!< Servo command
}Servo_PositionCommand_t;

//! Create the Servo_PositionCommand packet from parameters
void encodeServo_PositionCommandPacket(void* pkt, int16_t command);

//! Decode the Servo_PositionCommand packet to parameters
int decodeServo_PositionCommandPacket(const void* pkt, int16_t* command);

//! return the packet ID for the Servo_PositionCommand packet
#define getServo_PositionCommandPacketID() (PKT_SERVO_POSITION_COMMAND)

//! return the minimum encoded length for the Servo_PositionCommand packet
#define getServo_PositionCommandMinDataLength() (2)

//! return the maximum encoded length for the Servo_PositionCommand packet
#define getServo_PositionCommandMaxDataLength() (2)

//! Create the Servo_NeutralPositionCommand packet from parameters
void encodeServo_NeutralPositionCommandPacket(void* pkt);

//! Decode the Servo_NeutralPositionCommand packet to parameters
int decodeServo_NeutralPositionCommandPacket(const void* pkt);

//! return the packet ID for the Servo_NeutralPositionCommand packet
#define getServo_NeutralPositionCommandPacketID() (PKT_SERVO_NEUTRAL_COMMAND)

//! return the minimum encoded length for the Servo_NeutralPositionCommand packet
#define getServo_NeutralPositionCommandMinDataLength() 0

//! return the maximum encoded length for the Servo_NeutralPositionCommand packet
#define getServo_NeutralPositionCommandMaxDataLength() 0

//! Create the Servo_Disable packet from parameters
void encodeServo_DisablePacket(void* pkt);

//! Decode the Servo_Disable packet to parameters
int decodeServo_DisablePacket(const void* pkt);

//! return the packet ID for the Servo_Disable packet
#define getServo_DisablePacketID() (PKT_SERVO_DISABLE)

//! return the minimum encoded length for the Servo_Disable packet
#define getServo_DisableMinDataLength() 0

//! return the maximum encoded length for the Servo_Disable packet
#define getServo_DisableMaxDataLength() 0

//! Create the Servo_Enable packet from parameters
void encodeServo_EnablePacket(void* pkt);

//! Decode the Servo_Enable packet to parameters
int decodeServo_EnablePacket(const void* pkt);

//! return the packet ID for the Servo_Enable packet
#define getServo_EnablePacketID() (PKT_SERVO_ENABLE)

//! return the minimum encoded length for the Servo_Enable packet
#define getServo_EnableMinDataLength() 0

//! return the maximum encoded length for the Servo_Enable packet
#define getServo_EnableMaxDataLength() 0

/*!
 * Set the human-readable description of this servo
 */
typedef struct
{
    uint8_t title[8];
}Servo_SetTitle_t;

//! Create the Servo_SetTitle packet from parameters
void encodeServo_SetTitlePacket(void* pkt, const uint8_t title[8]);

//! Decode the Servo_SetTitle packet to parameters
int decodeServo_SetTitlePacket(const void* pkt, uint8_t title[8]);

//! return the packet ID for the Servo_SetTitle packet
#define getServo_SetTitlePacketID() (PKT_SERVO_SET_TITLE)

//! return the minimum encoded length for the Servo_SetTitle packet
#define getServo_SetTitleMinDataLength() (8)

//! return the maximum encoded length for the Servo_SetTitle packet
#define getServo_SetTitleMaxDataLength() (8)

/*!
 * The *SERVO_STATUS_A* packet contains status, warning and error information,
 * in addition to the servo position
 */
typedef struct
{
    Servo_StatusBits_t  status;   //!< Status bits contain information on servo operation
    Servo_WarningBits_t warnings; //!< Warning bits indicate servo is operation outside of desired range
    Servo_ErrorBits_t   errors;   //!< These bits indicate critical system error information
    int16_t             position; //!< Servo position, mapped to input units
    int16_t             command;  //!< Servo commanded position
}Servo_StatusA_t;

//! Create the Servo_StatusA packet
void encodeServo_StatusAPacketStructure(void* pkt, const Servo_StatusA_t* user);

//! Decode the Servo_StatusA packet
int decodeServo_StatusAPacketStructure(const void* pkt, Servo_StatusA_t* user);

//! Create the Servo_StatusA packet from parameters
void encodeServo_StatusAPacket(void* pkt, const Servo_StatusBits_t* status, const Servo_WarningBits_t* warnings, const Servo_ErrorBits_t* errors, int16_t position, int16_t command);

//! Decode the Servo_StatusA packet to parameters
int decodeServo_StatusAPacket(const void* pkt, Servo_StatusBits_t* status, Servo_WarningBits_t* warnings, Servo_ErrorBits_t* errors, int16_t* position, int16_t* command);

//! return the packet ID for the Servo_StatusA packet
#define getServo_StatusAPacketID() (PKT_SERVO_STATUS_A)

//! return the minimum encoded length for the Servo_StatusA packet
#define getServo_StatusAMinDataLength() (8)

//! return the maximum encoded length for the Servo_StatusA packet
#define getServo_StatusAMaxDataLength() (8)

/*!
 * The *SERVO_STATUS_B* packet contains various servo feedback data
 */
typedef struct
{
    uint16_t current;     //!< Servo current
    uint16_t voltage;     //!< Servo supply voltage
    int8_t   temperature; //!< Servo temperature
    int8_t   dutyCycle;   //!< Motor duty cycle
    int16_t  speed;       //!< Servo output shaft speed
}Servo_StatusB_t;

//! Create the Servo_StatusB packet
void encodeServo_StatusBPacketStructure(void* pkt, const Servo_StatusB_t* user);

//! Decode the Servo_StatusB packet
int decodeServo_StatusBPacketStructure(const void* pkt, Servo_StatusB_t* user);

//! Create the Servo_StatusB packet from parameters
void encodeServo_StatusBPacket(void* pkt, uint16_t current, uint16_t voltage, int8_t temperature, int8_t dutyCycle, int16_t speed);

//! Decode the Servo_StatusB packet to parameters
int decodeServo_StatusBPacket(const void* pkt, uint16_t* current, uint16_t* voltage, int8_t* temperature, int8_t* dutyCycle, int16_t* speed);

//! return the packet ID for the Servo_StatusB packet
#define getServo_StatusBPacketID() (PKT_SERVO_STATUS_B)

//! return the minimum encoded length for the Servo_StatusB packet
#define getServo_StatusBMinDataLength() (5)

//! return the maximum encoded length for the Servo_StatusB packet
#define getServo_StatusBMaxDataLength() (8)

/*!
 * The *SERVO_STATUS_C* packet contains servo position data. It is a cut-down
 * packet to allow high-speed feedback on servo position
 */
typedef struct
{
    int16_t position; //!< Servo position, mapped to input units
}Servo_StatusC_t;

//! Create the Servo_StatusC packet
void encodeServo_StatusCPacketStructure(void* pkt, const Servo_StatusC_t* user);

//! Decode the Servo_StatusC packet
int decodeServo_StatusCPacketStructure(const void* pkt, Servo_StatusC_t* user);

//! Create the Servo_StatusC packet from parameters
void encodeServo_StatusCPacket(void* pkt, int16_t position);

//! Decode the Servo_StatusC packet to parameters
int decodeServo_StatusCPacket(const void* pkt, int16_t* position);

//! return the packet ID for the Servo_StatusC packet
#define getServo_StatusCPacketID() (PKT_SERVO_STATUS_C)

//! return the minimum encoded length for the Servo_StatusC packet
#define getServo_StatusCMinDataLength() (2)

//! return the maximum encoded length for the Servo_StatusC packet
#define getServo_StatusCMaxDataLength() (2)

/*!
 * Raw accelerometer data. To convert these raw readings to 'real' units, use
 * the formula acc = 0.5 * raw * fullscale / (2^resolution)
 */
typedef struct
{
    int16_t xAcc;       //!< X axis acceleration value
    int16_t yAcc;       //!< Y axis acceleration value
    int16_t zAcc;       //!< Z axis acceleration value
    uint8_t fullscale;  //!< Accelerometer full-scale range
    uint8_t resolution; //!< Accelerometer measurement resolution, in 'bits'.
}Servo_Accelerometer_t;

//! Create the Servo_Accelerometer packet from parameters
void encodeServo_AccelerometerPacket(void* pkt, int16_t xAcc, int16_t yAcc, int16_t zAcc, uint8_t fullscale, uint8_t resolution);

//! Decode the Servo_Accelerometer packet to parameters
int decodeServo_AccelerometerPacket(const void* pkt, int16_t* xAcc, int16_t* yAcc, int16_t* zAcc, uint8_t* fullscale, uint8_t* resolution);

//! return the packet ID for the Servo_Accelerometer packet
#define getServo_AccelerometerPacketID() (PKT_SERVO_ACCELEROMETER)

//! return the minimum encoded length for the Servo_Accelerometer packet
#define getServo_AccelerometerMinDataLength() (8)

//! return the maximum encoded length for the Servo_Accelerometer packet
#define getServo_AccelerometerMaxDataLength() (8)

/*!
 * Servo address information
 */
typedef struct
{
    uint8_t  hwRev;        //!< Hardware revision
    uint32_t serialNumber; //!< Servo serial number
    uint16_t userIDA;      //!< Programmable User ID value 1/2
    uint16_t userIDB;      //!< Programmable User ID value 2/2
}Servo_Address_t;

//! Create the Servo_Address packet
void encodeServo_AddressPacketStructure(void* pkt, const Servo_Address_t* user);

//! Decode the Servo_Address packet
int decodeServo_AddressPacketStructure(const void* pkt, Servo_Address_t* user);

//! Create the Servo_Address packet from parameters
void encodeServo_AddressPacket(void* pkt, uint8_t hwRev, uint32_t serialNumber, uint16_t userIDA, uint16_t userIDB);

//! Decode the Servo_Address packet to parameters
int decodeServo_AddressPacket(const void* pkt, uint8_t* hwRev, uint32_t* serialNumber, uint16_t* userIDA, uint16_t* userIDB);

//! return the packet ID for the Servo_Address packet
#define getServo_AddressPacketID() (PKT_SERVO_ADDRESS)

//! return the minimum encoded length for the Servo_Address packet
#define getServo_AddressMinDataLength() (8)

//! return the maximum encoded length for the Servo_Address packet
#define getServo_AddressMaxDataLength() (8)

/*!
 * Servo title information
 */
typedef struct
{
    uint8_t title[8]; //!< Human readable description string for the servo
}Servo_Title_t;

//! Create the Servo_Title packet from parameters
void encodeServo_TitlePacket(void* pkt, const uint8_t title[8]);

//! Decode the Servo_Title packet to parameters
int decodeServo_TitlePacket(const void* pkt, uint8_t title[8]);

//! return the packet ID for the Servo_Title packet
#define getServo_TitlePacketID() (PKT_SERVO_TITLE)

//! return the minimum encoded length for the Servo_Title packet
#define getServo_TitleMinDataLength() (8)

//! return the maximum encoded length for the Servo_Title packet
#define getServo_TitleMaxDataLength() (8)

/*!
 * Servo firmware information
 */
typedef struct
{
    uint8_t  major;    //!< Firmware version, major number
    uint8_t  minor;    //!< Firmware version, minor number
    uint8_t  day;      //!< Firmware release date, day-of-month
    uint8_t  month;    //!< Firmware release date, month-of-year
    uint16_t year;     //!< Firmware release date, year
    uint16_t checksum; //!< Firmware checksum, 16-bit
}Servo_Firmware_t;

//! Create the Servo_Firmware packet
void encodeServo_FirmwarePacketStructure(void* pkt, const Servo_Firmware_t* user);

//! Decode the Servo_Firmware packet
int decodeServo_FirmwarePacketStructure(const void* pkt, Servo_Firmware_t* user);

//! Create the Servo_Firmware packet from parameters
void encodeServo_FirmwarePacket(void* pkt, uint8_t major, uint8_t minor, uint8_t day, uint8_t month, uint16_t year, uint16_t checksum);

//! Decode the Servo_Firmware packet to parameters
int decodeServo_FirmwarePacket(const void* pkt, uint8_t* major, uint8_t* minor, uint8_t* day, uint8_t* month, uint16_t* year, uint16_t* checksum);

//! return the packet ID for the Servo_Firmware packet
#define getServo_FirmwarePacketID() (PKT_SERVO_FIRMWARE)

//! return the minimum encoded length for the Servo_Firmware packet
#define getServo_FirmwareMinDataLength() (8)

//! return the maximum encoded length for the Servo_Firmware packet
#define getServo_FirmwareMaxDataLength() (8)

/*!
 * Servo system info (uptime, etc)
 */
typedef struct
{
    uint32_t msSinceReset; //!< Time since last power cycle (milliseconds)
    uint16_t powerCycles;  //!< Number of recorded power cycles
    uint8_t  resetCode;    //!< Processor code indicating cause of most recent reset event
    uint8_t  cpuOccupancy;
}Servo_SystemInfo_t;

//! Create the Servo_SystemInfo packet
void encodeServo_SystemInfoPacketStructure(void* pkt, const Servo_SystemInfo_t* user);

//! Decode the Servo_SystemInfo packet
int decodeServo_SystemInfoPacketStructure(const void* pkt, Servo_SystemInfo_t* user);

//! Create the Servo_SystemInfo packet from parameters
void encodeServo_SystemInfoPacket(void* pkt, uint32_t msSinceReset, uint16_t powerCycles, uint8_t resetCode, uint8_t cpuOccupancy);

//! Decode the Servo_SystemInfo packet to parameters
int decodeServo_SystemInfoPacket(const void* pkt, uint32_t* msSinceReset, uint16_t* powerCycles, uint8_t* resetCode, uint8_t* cpuOccupancy);

//! return the packet ID for the Servo_SystemInfo packet
#define getServo_SystemInfoPacketID() (PKT_SERVO_SYSTEM_INFO)

//! return the minimum encoded length for the Servo_SystemInfo packet
#define getServo_SystemInfoMinDataLength() (8)

//! return the maximum encoded length for the Servo_SystemInfo packet
#define getServo_SystemInfoMaxDataLength() (8)

/*!
 * Telemetry settings configuration packet
 */
typedef struct
{
    Servo_TelemetrySettings_t settings;   //!< Servo telemetry settings
    uint8_t                   icdVersion; //!< Servo ICD revision. Field is encoded constant.
}Servo_TelemetryConfig_t;

//! Create the Servo_TelemetryConfig packet
void encodeServo_TelemetryConfigPacketStructure(void* pkt, const Servo_TelemetryConfig_t* user);

//! Decode the Servo_TelemetryConfig packet
int decodeServo_TelemetryConfigPacketStructure(const void* pkt, Servo_TelemetryConfig_t* user);

//! Create the Servo_TelemetryConfig packet from parameters
void encodeServo_TelemetryConfigPacket(void* pkt, const Servo_TelemetrySettings_t* settings);

//! Decode the Servo_TelemetryConfig packet to parameters
int decodeServo_TelemetryConfigPacket(const void* pkt, Servo_TelemetrySettings_t* settings, uint8_t* icdVersion);

//! return the packet ID for the Servo_TelemetryConfig packet
#define getServo_TelemetryConfigPacketID() (PKT_SERVO_TELEMETRY_CONFIG)

//! return the minimum encoded length for the Servo_TelemetryConfig packet
#define getServo_TelemetryConfigMinDataLength() (8)

//! return the maximum encoded length for the Servo_TelemetryConfig packet
#define getServo_TelemetryConfigMaxDataLength() (8)

/*!
 * Non-volatile settings configuration information
 */
typedef struct
{
    unsigned eeUnlocked : 1; //!< Set if the servo is unlocked and ready to receive settings updates
    unsigned eeVersion : 7;  //!< Version of non-volatile settings configuration
    uint16_t eeSize;         //!< Size of non-volatile settings data
    uint16_t eeChecksum;     //!< NV settings checksum
    uint8_t  mramVersion;   
    uint16_t mramSize;      
}Servo_SettingsInfo_t;

//! Create the Servo_SettingsInfo packet
void encodeServo_SettingsInfoPacketStructure(void* pkt, const Servo_SettingsInfo_t* user);

//! Decode the Servo_SettingsInfo packet
int decodeServo_SettingsInfoPacketStructure(const void* pkt, Servo_SettingsInfo_t* user);

//! Create the Servo_SettingsInfo packet from parameters
void encodeServo_SettingsInfoPacket(void* pkt, unsigned eeUnlocked, unsigned eeVersion, uint16_t eeSize, uint16_t eeChecksum, uint8_t mramVersion, uint16_t mramSize);

//! Decode the Servo_SettingsInfo packet to parameters
int decodeServo_SettingsInfoPacket(const void* pkt, unsigned* eeUnlocked, unsigned* eeVersion, uint16_t* eeSize, uint16_t* eeChecksum, uint8_t* mramVersion, uint16_t* mramSize);

//! return the packet ID for the Servo_SettingsInfo packet
#define getServo_SettingsInfoPacketID() (PKT_SERVO_SETTINGS_INFO)

//! return the minimum encoded length for the Servo_SettingsInfo packet
#define getServo_SettingsInfoMinDataLength() (8)

//! return the maximum encoded length for the Servo_SettingsInfo packet
#define getServo_SettingsInfoMaxDataLength() (8)

/*!
 * Servo telltale data
 */
typedef struct
{
    int8_t minTemperature; //!< Minimum temperature seen by the servo
    int8_t maxTemperature; //!< Maximum temperature seen by the servo
}Servo_TelltaleA_t;

//! Create the Servo_TelltaleA packet from parameters
void encodeServo_TelltaleAPacket(void* pkt, int8_t minTemperature, int8_t maxTemperature);

//! Decode the Servo_TelltaleA packet to parameters
int decodeServo_TelltaleAPacket(const void* pkt, int8_t* minTemperature, int8_t* maxTemperature);

//! return the packet ID for the Servo_TelltaleA packet
#define getServo_TelltaleAPacketID() (PKT_SERVO_TELLTALE_A)

//! return the minimum encoded length for the Servo_TelltaleA packet
#define getServo_TelltaleAMinDataLength() (2)

//! return the maximum encoded length for the Servo_TelltaleA packet
#define getServo_TelltaleAMaxDataLength() (2)

#ifdef __cplusplus
}
#endif
#endif // _SERVOPACKETS_H
