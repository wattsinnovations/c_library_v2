#pragma once
// MESSAGE CUSTOM_MESSAGE_TEST PACKING

#define MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST 13001


typedef struct __mavlink_custom_message_test_t {
 int32_t lat; /*<   empty */
 int32_t lon; /*<   empty */
 int32_t alt; /*<   empty */
} mavlink_custom_message_test_t;

#define MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN 12
#define MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN 12
#define MAVLINK_MSG_ID_13001_LEN 12
#define MAVLINK_MSG_ID_13001_MIN_LEN 12

#define MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC 120
#define MAVLINK_MSG_ID_13001_CRC 120



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_MESSAGE_TEST { \
    13001, \
    "CUSTOM_MESSAGE_TEST", \
    3, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_custom_message_test_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_custom_message_test_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_custom_message_test_t, alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_MESSAGE_TEST { \
    "CUSTOM_MESSAGE_TEST", \
    3, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_custom_message_test_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_custom_message_test_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_custom_message_test_t, alt) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_message_test message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat   empty 
 * @param lon   empty 
 * @param alt   empty 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_message_test_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t lat, int32_t lon, int32_t alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_int32_t(buf, 8, alt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN);
#else
    mavlink_custom_message_test_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
}

/**
 * @brief Pack a custom_message_test message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat   empty 
 * @param lon   empty 
 * @param alt   empty 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_message_test_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t lat,int32_t lon,int32_t alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_int32_t(buf, 8, alt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN);
#else
    mavlink_custom_message_test_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
}

/**
 * @brief Encode a custom_message_test struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_message_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_message_test_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_message_test_t* custom_message_test)
{
    return mavlink_msg_custom_message_test_pack(system_id, component_id, msg, custom_message_test->lat, custom_message_test->lon, custom_message_test->alt);
}

/**
 * @brief Encode a custom_message_test struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_message_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_message_test_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_message_test_t* custom_message_test)
{
    return mavlink_msg_custom_message_test_pack_chan(system_id, component_id, chan, msg, custom_message_test->lat, custom_message_test->lon, custom_message_test->alt);
}

/**
 * @brief Send a custom_message_test message
 * @param chan MAVLink channel to send the message
 *
 * @param lat   empty 
 * @param lon   empty 
 * @param alt   empty 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_message_test_send(mavlink_channel_t chan, int32_t lat, int32_t lon, int32_t alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_int32_t(buf, 8, alt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST, buf, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
#else
    mavlink_custom_message_test_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
#endif
}

/**
 * @brief Send a custom_message_test message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_message_test_send_struct(mavlink_channel_t chan, const mavlink_custom_message_test_t* custom_message_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_message_test_send(chan, custom_message_test->lat, custom_message_test->lon, custom_message_test->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST, (const char *)custom_message_test, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_message_test_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lat, int32_t lon, int32_t alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_int32_t(buf, 8, alt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST, buf, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
#else
    mavlink_custom_message_test_t *packet = (mavlink_custom_message_test_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_MESSAGE_TEST UNPACKING


/**
 * @brief Get field lat from custom_message_test message
 *
 * @return   empty 
 */
static inline int32_t mavlink_msg_custom_message_test_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lon from custom_message_test message
 *
 * @return   empty 
 */
static inline int32_t mavlink_msg_custom_message_test_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field alt from custom_message_test message
 *
 * @return   empty 
 */
static inline int32_t mavlink_msg_custom_message_test_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Decode a custom_message_test message into a struct
 *
 * @param msg The message to decode
 * @param custom_message_test C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_message_test_decode(const mavlink_message_t* msg, mavlink_custom_message_test_t* custom_message_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_message_test->lat = mavlink_msg_custom_message_test_get_lat(msg);
    custom_message_test->lon = mavlink_msg_custom_message_test_get_lon(msg);
    custom_message_test->alt = mavlink_msg_custom_message_test_get_alt(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN;
        memset(custom_message_test, 0, MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_LEN);
    memcpy(custom_message_test, _MAV_PAYLOAD(msg), len);
#endif
}
