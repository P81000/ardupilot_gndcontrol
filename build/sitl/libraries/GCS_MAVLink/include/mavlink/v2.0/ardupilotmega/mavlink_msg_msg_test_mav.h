#pragma once
// MESSAGE MSG_TEST_MAV PACKING

#define MAVLINK_MSG_ID_MSG_TEST_MAV 112669


typedef struct __mavlink_msg_test_mav_t {
 float ex1; /*<  Sample value.*/
 char ex2[10]; /*<  Sample text.*/
} mavlink_msg_test_mav_t;

#define MAVLINK_MSG_ID_MSG_TEST_MAV_LEN 14
#define MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN 14
#define MAVLINK_MSG_ID_112669_LEN 14
#define MAVLINK_MSG_ID_112669_MIN_LEN 14

#define MAVLINK_MSG_ID_MSG_TEST_MAV_CRC 25
#define MAVLINK_MSG_ID_112669_CRC 25

#define MAVLINK_MSG_MSG_TEST_MAV_FIELD_EX2_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MSG_TEST_MAV { \
    112669, \
    "MSG_TEST_MAV", \
    2, \
    {  { "ex1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_msg_test_mav_t, ex1) }, \
         { "ex2", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_msg_test_mav_t, ex2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MSG_TEST_MAV { \
    "MSG_TEST_MAV", \
    2, \
    {  { "ex1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_msg_test_mav_t, ex1) }, \
         { "ex2", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_msg_test_mav_t, ex2) }, \
         } \
}
#endif

/**
 * @brief Pack a msg_test_mav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ex1  Sample value.
 * @param ex2  Sample text.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_msg_test_mav_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float ex1, const char *ex2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MSG_TEST_MAV_LEN];
    _mav_put_float(buf, 0, ex1);
    _mav_put_char_array(buf, 4, ex2, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN);
#else
    mavlink_msg_test_mav_t packet;
    packet.ex1 = ex1;
    mav_array_memcpy(packet.ex2, ex2, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MSG_TEST_MAV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
}

/**
 * @brief Pack a msg_test_mav message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ex1  Sample value.
 * @param ex2  Sample text.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_msg_test_mav_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float ex1,const char *ex2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MSG_TEST_MAV_LEN];
    _mav_put_float(buf, 0, ex1);
    _mav_put_char_array(buf, 4, ex2, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN);
#else
    mavlink_msg_test_mav_t packet;
    packet.ex1 = ex1;
    mav_array_memcpy(packet.ex2, ex2, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MSG_TEST_MAV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
}

/**
 * @brief Encode a msg_test_mav struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param msg_test_mav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_msg_test_mav_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_msg_test_mav_t* msg_test_mav)
{
    return mavlink_msg_msg_test_mav_pack(system_id, component_id, msg, msg_test_mav->ex1, msg_test_mav->ex2);
}

/**
 * @brief Encode a msg_test_mav struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param msg_test_mav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_msg_test_mav_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_msg_test_mav_t* msg_test_mav)
{
    return mavlink_msg_msg_test_mav_pack_chan(system_id, component_id, chan, msg, msg_test_mav->ex1, msg_test_mav->ex2);
}

/**
 * @brief Send a msg_test_mav message
 * @param chan MAVLink channel to send the message
 *
 * @param ex1  Sample value.
 * @param ex2  Sample text.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_msg_test_mav_send(mavlink_channel_t chan, float ex1, const char *ex2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MSG_TEST_MAV_LEN];
    _mav_put_float(buf, 0, ex1);
    _mav_put_char_array(buf, 4, ex2, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MSG_TEST_MAV, buf, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
#else
    mavlink_msg_test_mav_t packet;
    packet.ex1 = ex1;
    mav_array_memcpy(packet.ex2, ex2, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MSG_TEST_MAV, (const char *)&packet, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
#endif
}

/**
 * @brief Send a msg_test_mav message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_msg_test_mav_send_struct(mavlink_channel_t chan, const mavlink_msg_test_mav_t* msg_test_mav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_msg_test_mav_send(chan, msg_test_mav->ex1, msg_test_mav->ex2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MSG_TEST_MAV, (const char *)msg_test_mav, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
#endif
}

#if MAVLINK_MSG_ID_MSG_TEST_MAV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_msg_test_mav_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float ex1, const char *ex2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, ex1);
    _mav_put_char_array(buf, 4, ex2, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MSG_TEST_MAV, buf, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
#else
    mavlink_msg_test_mav_t *packet = (mavlink_msg_test_mav_t *)msgbuf;
    packet->ex1 = ex1;
    mav_array_memcpy(packet->ex2, ex2, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MSG_TEST_MAV, (const char *)packet, MAVLINK_MSG_ID_MSG_TEST_MAV_MIN_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN, MAVLINK_MSG_ID_MSG_TEST_MAV_CRC);
#endif
}
#endif

#endif

// MESSAGE MSG_TEST_MAV UNPACKING


/**
 * @brief Get field ex1 from msg_test_mav message
 *
 * @return  Sample value.
 */
static inline float mavlink_msg_msg_test_mav_get_ex1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ex2 from msg_test_mav message
 *
 * @return  Sample text.
 */
static inline uint16_t mavlink_msg_msg_test_mav_get_ex2(const mavlink_message_t* msg, char *ex2)
{
    return _MAV_RETURN_char_array(msg, ex2, 10,  4);
}

/**
 * @brief Decode a msg_test_mav message into a struct
 *
 * @param msg The message to decode
 * @param msg_test_mav C-struct to decode the message contents into
 */
static inline void mavlink_msg_msg_test_mav_decode(const mavlink_message_t* msg, mavlink_msg_test_mav_t* msg_test_mav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    msg_test_mav->ex1 = mavlink_msg_msg_test_mav_get_ex1(msg);
    mavlink_msg_msg_test_mav_get_ex2(msg, msg_test_mav->ex2);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MSG_TEST_MAV_LEN? msg->len : MAVLINK_MSG_ID_MSG_TEST_MAV_LEN;
        memset(msg_test_mav, 0, MAVLINK_MSG_ID_MSG_TEST_MAV_LEN);
    memcpy(msg_test_mav, _MAV_PAYLOAD(msg), len);
#endif
}
