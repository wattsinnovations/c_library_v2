#pragma once
// MESSAGE PRISM_VERSION_INFO PACKING

#define MAVLINK_MSG_ID_PRISM_VERSION_INFO 13004

MAVPACKED(
typedef struct __mavlink_prism_version_info_t {
 uint8_t target_system; /*<  System ID*/
 char ssid[32]; /*<   SSID name -- 802.11 standard 32 characters max */
 char password[64]; /*<   Network password -- WPA2 up to 63 characters */
}) mavlink_prism_version_info_t;

#define MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN 97
#define MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN 97
#define MAVLINK_MSG_ID_13004_LEN 97
#define MAVLINK_MSG_ID_13004_MIN_LEN 97

#define MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC 81
#define MAVLINK_MSG_ID_13004_CRC 81

#define MAVLINK_MSG_PRISM_VERSION_INFO_FIELD_SSID_LEN 32
#define MAVLINK_MSG_PRISM_VERSION_INFO_FIELD_PASSWORD_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PRISM_VERSION_INFO { \
    13004, \
    "PRISM_VERSION_INFO", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_prism_version_info_t, target_system) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_prism_version_info_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_prism_version_info_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PRISM_VERSION_INFO { \
    "PRISM_VERSION_INFO", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_prism_version_info_t, target_system) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_prism_version_info_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_prism_version_info_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a prism_version_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 * @param password   Network password -- WPA2 up to 63 characters 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_version_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, const char *ssid, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN);
#else
    mavlink_prism_version_info_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_VERSION_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
}

/**
 * @brief Pack a prism_version_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 * @param password   Network password -- WPA2 up to 63 characters 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_version_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,const char *ssid,const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN);
#else
    mavlink_prism_version_info_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_VERSION_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
}

/**
 * @brief Encode a prism_version_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param prism_version_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_version_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_prism_version_info_t* prism_version_info)
{
    return mavlink_msg_prism_version_info_pack(system_id, component_id, msg, prism_version_info->target_system, prism_version_info->ssid, prism_version_info->password);
}

/**
 * @brief Encode a prism_version_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param prism_version_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_version_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_prism_version_info_t* prism_version_info)
{
    return mavlink_msg_prism_version_info_pack_chan(system_id, component_id, chan, msg, prism_version_info->target_system, prism_version_info->ssid, prism_version_info->password);
}

/**
 * @brief Send a prism_version_info message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 * @param password   Network password -- WPA2 up to 63 characters 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_prism_version_info_send(mavlink_channel_t chan, uint8_t target_system, const char *ssid, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO, buf, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
#else
    mavlink_prism_version_info_t packet;
    packet.target_system = target_system;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO, (const char *)&packet, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
#endif
}

/**
 * @brief Send a prism_version_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_prism_version_info_send_struct(mavlink_channel_t chan, const mavlink_prism_version_info_t* prism_version_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_prism_version_info_send(chan, prism_version_info->target_system, prism_version_info->ssid, prism_version_info->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO, (const char *)prism_version_info, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_prism_version_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, const char *ssid, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO, buf, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
#else
    mavlink_prism_version_info_t *packet = (mavlink_prism_version_info_t *)msgbuf;
    packet->target_system = target_system;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet->password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VERSION_INFO, (const char *)packet, MAVLINK_MSG_ID_PRISM_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN, MAVLINK_MSG_ID_PRISM_VERSION_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE PRISM_VERSION_INFO UNPACKING


/**
 * @brief Get field target_system from prism_version_info message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_prism_version_info_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ssid from prism_version_info message
 *
 * @return   SSID name -- 802.11 standard 32 characters max 
 */
static inline uint16_t mavlink_msg_prism_version_info_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  1);
}

/**
 * @brief Get field password from prism_version_info message
 *
 * @return   Network password -- WPA2 up to 63 characters 
 */
static inline uint16_t mavlink_msg_prism_version_info_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 64,  33);
}

/**
 * @brief Decode a prism_version_info message into a struct
 *
 * @param msg The message to decode
 * @param prism_version_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_prism_version_info_decode(const mavlink_message_t* msg, mavlink_prism_version_info_t* prism_version_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    prism_version_info->target_system = mavlink_msg_prism_version_info_get_target_system(msg);
    mavlink_msg_prism_version_info_get_ssid(msg, prism_version_info->ssid);
    mavlink_msg_prism_version_info_get_password(msg, prism_version_info->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN? msg->len : MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN;
        memset(prism_version_info, 0, MAVLINK_MSG_ID_PRISM_VERSION_INFO_LEN);
    memcpy(prism_version_info, _MAV_PAYLOAD(msg), len);
#endif
}
