#pragma once
// MESSAGE NETWORK_STATUS PACKING

#define MAVLINK_MSG_ID_NETWORK_STATUS 13002

MAVPACKED(
typedef struct __mavlink_network_status_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t connected; /*<   Boolean indcator to determine connection to internet */
 char ssid[32]; /*<   SSID name -- 802.11 standard 32 characters max */
}) mavlink_network_status_t;

#define MAVLINK_MSG_ID_NETWORK_STATUS_LEN 34
#define MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN 34
#define MAVLINK_MSG_ID_13002_LEN 34
#define MAVLINK_MSG_ID_13002_MIN_LEN 34

#define MAVLINK_MSG_ID_NETWORK_STATUS_CRC 97
#define MAVLINK_MSG_ID_13002_CRC 97

#define MAVLINK_MSG_NETWORK_STATUS_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NETWORK_STATUS { \
    13002, \
    "NETWORK_STATUS", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_network_status_t, target_system) }, \
         { "connected", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_network_status_t, connected) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_network_status_t, ssid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NETWORK_STATUS { \
    "NETWORK_STATUS", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_network_status_t, target_system) }, \
         { "connected", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_network_status_t, connected) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_network_status_t, ssid) }, \
         } \
}
#endif

/**
 * @brief Pack a network_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param connected   Boolean indcator to determine connection to internet 
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_network_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t connected, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, connected);
    _mav_put_char_array(buf, 2, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#else
    mavlink_network_status_t packet;
    packet.target_system = target_system;
    packet.connected = connected;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NETWORK_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
}

/**
 * @brief Pack a network_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param connected   Boolean indcator to determine connection to internet 
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_network_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t connected,const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, connected);
    _mav_put_char_array(buf, 2, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#else
    mavlink_network_status_t packet;
    packet.target_system = target_system;
    packet.connected = connected;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NETWORK_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
}

/**
 * @brief Encode a network_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param network_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_network_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_network_status_t* network_status)
{
    return mavlink_msg_network_status_pack(system_id, component_id, msg, network_status->target_system, network_status->connected, network_status->ssid);
}

/**
 * @brief Encode a network_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param network_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_network_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_network_status_t* network_status)
{
    return mavlink_msg_network_status_pack_chan(system_id, component_id, chan, msg, network_status->target_system, network_status->connected, network_status->ssid);
}

/**
 * @brief Send a network_status message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param connected   Boolean indcator to determine connection to internet 
 * @param ssid   SSID name -- 802.11 standard 32 characters max 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_network_status_send(mavlink_channel_t chan, uint8_t target_system, uint8_t connected, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, connected);
    _mav_put_char_array(buf, 2, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, buf, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#else
    mavlink_network_status_t packet;
    packet.target_system = target_system;
    packet.connected = connected;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)&packet, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}

/**
 * @brief Send a network_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_network_status_send_struct(mavlink_channel_t chan, const mavlink_network_status_t* network_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_network_status_send(chan, network_status->target_system, network_status->connected, network_status->ssid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)network_status, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_NETWORK_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_network_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t connected, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, connected);
    _mav_put_char_array(buf, 2, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, buf, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#else
    mavlink_network_status_t *packet = (mavlink_network_status_t *)msgbuf;
    packet->target_system = target_system;
    packet->connected = connected;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)packet, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE NETWORK_STATUS UNPACKING


/**
 * @brief Get field target_system from network_status message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_network_status_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field connected from network_status message
 *
 * @return   Boolean indcator to determine connection to internet 
 */
static inline uint8_t mavlink_msg_network_status_get_connected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field ssid from network_status message
 *
 * @return   SSID name -- 802.11 standard 32 characters max 
 */
static inline uint16_t mavlink_msg_network_status_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  2);
}

/**
 * @brief Decode a network_status message into a struct
 *
 * @param msg The message to decode
 * @param network_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_network_status_decode(const mavlink_message_t* msg, mavlink_network_status_t* network_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    network_status->target_system = mavlink_msg_network_status_get_target_system(msg);
    network_status->connected = mavlink_msg_network_status_get_connected(msg);
    mavlink_msg_network_status_get_ssid(msg, network_status->ssid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NETWORK_STATUS_LEN? msg->len : MAVLINK_MSG_ID_NETWORK_STATUS_LEN;
        memset(network_status, 0, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
    memcpy(network_status, _MAV_PAYLOAD(msg), len);
#endif
}
