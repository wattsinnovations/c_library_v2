#pragma once
// MESSAGE SOFTWARE_UPDATE_REQUEST PACKING

#define MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST 13005

MAVPACKED(
typedef struct __mavlink_software_update_request_t {
 uint8_t target_system; /*<   System ID */
 char release_string[32]; /*<   Name of release to update to */
}) mavlink_software_update_request_t;

#define MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN 33
#define MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN 33
#define MAVLINK_MSG_ID_13005_LEN 33
#define MAVLINK_MSG_ID_13005_MIN_LEN 33

#define MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC 107
#define MAVLINK_MSG_ID_13005_CRC 107

#define MAVLINK_MSG_SOFTWARE_UPDATE_REQUEST_FIELD_RELEASE_STRING_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOFTWARE_UPDATE_REQUEST { \
    13005, \
    "SOFTWARE_UPDATE_REQUEST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_software_update_request_t, target_system) }, \
         { "release_string", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_software_update_request_t, release_string) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOFTWARE_UPDATE_REQUEST { \
    "SOFTWARE_UPDATE_REQUEST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_software_update_request_t, target_system) }, \
         { "release_string", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_software_update_request_t, release_string) }, \
         } \
}
#endif

/**
 * @brief Pack a software_update_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system   System ID 
 * @param release_string   Name of release to update to 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_software_update_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, const char *release_string)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, release_string, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN);
#else
    mavlink_software_update_request_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.release_string, release_string, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
}

/**
 * @brief Pack a software_update_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system   System ID 
 * @param release_string   Name of release to update to 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_software_update_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,const char *release_string)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, release_string, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN);
#else
    mavlink_software_update_request_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.release_string, release_string, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
}

/**
 * @brief Encode a software_update_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param software_update_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_software_update_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_software_update_request_t* software_update_request)
{
    return mavlink_msg_software_update_request_pack(system_id, component_id, msg, software_update_request->target_system, software_update_request->release_string);
}

/**
 * @brief Encode a software_update_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param software_update_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_software_update_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_software_update_request_t* software_update_request)
{
    return mavlink_msg_software_update_request_pack_chan(system_id, component_id, chan, msg, software_update_request->target_system, software_update_request->release_string);
}

/**
 * @brief Send a software_update_request message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system   System ID 
 * @param release_string   Name of release to update to 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_software_update_request_send(mavlink_channel_t chan, uint8_t target_system, const char *release_string)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, release_string, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST, buf, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
#else
    mavlink_software_update_request_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.release_string, release_string, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
#endif
}

/**
 * @brief Send a software_update_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_software_update_request_send_struct(mavlink_channel_t chan, const mavlink_software_update_request_t* software_update_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_software_update_request_send(chan, software_update_request->target_system, software_update_request->release_string);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST, (const char *)software_update_request, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_software_update_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, const char *release_string)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, release_string, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST, buf, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
#else
    mavlink_software_update_request_t *packet = (mavlink_software_update_request_t *)msgbuf;
    packet->target_system = target_system;
    mav_array_memcpy(packet->release_string, release_string, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST, (const char *)packet, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE SOFTWARE_UPDATE_REQUEST UNPACKING


/**
 * @brief Get field target_system from software_update_request message
 *
 * @return   System ID 
 */
static inline uint8_t mavlink_msg_software_update_request_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field release_string from software_update_request message
 *
 * @return   Name of release to update to 
 */
static inline uint16_t mavlink_msg_software_update_request_get_release_string(const mavlink_message_t* msg, char *release_string)
{
    return _MAV_RETURN_char_array(msg, release_string, 32,  1);
}

/**
 * @brief Decode a software_update_request message into a struct
 *
 * @param msg The message to decode
 * @param software_update_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_software_update_request_decode(const mavlink_message_t* msg, mavlink_software_update_request_t* software_update_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    software_update_request->target_system = mavlink_msg_software_update_request_get_target_system(msg);
    mavlink_msg_software_update_request_get_release_string(msg, software_update_request->release_string);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN;
        memset(software_update_request, 0, MAVLINK_MSG_ID_SOFTWARE_UPDATE_REQUEST_LEN);
    memcpy(software_update_request, _MAV_PAYLOAD(msg), len);
#endif
}
