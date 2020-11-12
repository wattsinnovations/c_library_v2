#pragma once
// MESSAGE PRISM_VEHICLE_INFO PACKING

#define MAVLINK_MSG_ID_PRISM_VEHICLE_INFO 13006

MAVPACKED(
typedef struct __mavlink_prism_vehicle_info_t {
 uint64_t flight_time; /*<   Total recorded flight time */
 uint8_t target_system; /*<   System ID */
}) mavlink_prism_vehicle_info_t;

#define MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN 9
#define MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN 9
#define MAVLINK_MSG_ID_13006_LEN 9
#define MAVLINK_MSG_ID_13006_MIN_LEN 9

#define MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC 136
#define MAVLINK_MSG_ID_13006_CRC 136



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PRISM_VEHICLE_INFO { \
    13006, \
    "PRISM_VEHICLE_INFO", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_prism_vehicle_info_t, target_system) }, \
         { "flight_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_prism_vehicle_info_t, flight_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PRISM_VEHICLE_INFO { \
    "PRISM_VEHICLE_INFO", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_prism_vehicle_info_t, target_system) }, \
         { "flight_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_prism_vehicle_info_t, flight_time) }, \
         } \
}
#endif

/**
 * @brief Pack a prism_vehicle_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system   System ID 
 * @param flight_time   Total recorded flight time 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_vehicle_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint64_t flight_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN];
    _mav_put_uint64_t(buf, 0, flight_time);
    _mav_put_uint8_t(buf, 8, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN);
#else
    mavlink_prism_vehicle_info_t packet;
    packet.flight_time = flight_time;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_VEHICLE_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
}

/**
 * @brief Pack a prism_vehicle_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system   System ID 
 * @param flight_time   Total recorded flight time 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_vehicle_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint64_t flight_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN];
    _mav_put_uint64_t(buf, 0, flight_time);
    _mav_put_uint8_t(buf, 8, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN);
#else
    mavlink_prism_vehicle_info_t packet;
    packet.flight_time = flight_time;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_VEHICLE_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
}

/**
 * @brief Encode a prism_vehicle_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param prism_vehicle_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_vehicle_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_prism_vehicle_info_t* prism_vehicle_info)
{
    return mavlink_msg_prism_vehicle_info_pack(system_id, component_id, msg, prism_vehicle_info->target_system, prism_vehicle_info->flight_time);
}

/**
 * @brief Encode a prism_vehicle_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param prism_vehicle_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_vehicle_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_prism_vehicle_info_t* prism_vehicle_info)
{
    return mavlink_msg_prism_vehicle_info_pack_chan(system_id, component_id, chan, msg, prism_vehicle_info->target_system, prism_vehicle_info->flight_time);
}

/**
 * @brief Send a prism_vehicle_info message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system   System ID 
 * @param flight_time   Total recorded flight time 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_prism_vehicle_info_send(mavlink_channel_t chan, uint8_t target_system, uint64_t flight_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN];
    _mav_put_uint64_t(buf, 0, flight_time);
    _mav_put_uint8_t(buf, 8, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO, buf, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
#else
    mavlink_prism_vehicle_info_t packet;
    packet.flight_time = flight_time;
    packet.target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO, (const char *)&packet, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
#endif
}

/**
 * @brief Send a prism_vehicle_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_prism_vehicle_info_send_struct(mavlink_channel_t chan, const mavlink_prism_vehicle_info_t* prism_vehicle_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_prism_vehicle_info_send(chan, prism_vehicle_info->target_system, prism_vehicle_info->flight_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO, (const char *)prism_vehicle_info, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_prism_vehicle_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint64_t flight_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, flight_time);
    _mav_put_uint8_t(buf, 8, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO, buf, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
#else
    mavlink_prism_vehicle_info_t *packet = (mavlink_prism_vehicle_info_t *)msgbuf;
    packet->flight_time = flight_time;
    packet->target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO, (const char *)packet, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_MIN_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE PRISM_VEHICLE_INFO UNPACKING


/**
 * @brief Get field target_system from prism_vehicle_info message
 *
 * @return   System ID 
 */
static inline uint8_t mavlink_msg_prism_vehicle_info_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field flight_time from prism_vehicle_info message
 *
 * @return   Total recorded flight time 
 */
static inline uint64_t mavlink_msg_prism_vehicle_info_get_flight_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a prism_vehicle_info message into a struct
 *
 * @param msg The message to decode
 * @param prism_vehicle_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_prism_vehicle_info_decode(const mavlink_message_t* msg, mavlink_prism_vehicle_info_t* prism_vehicle_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    prism_vehicle_info->flight_time = mavlink_msg_prism_vehicle_info_get_flight_time(msg);
    prism_vehicle_info->target_system = mavlink_msg_prism_vehicle_info_get_target_system(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN? msg->len : MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN;
        memset(prism_vehicle_info, 0, MAVLINK_MSG_ID_PRISM_VEHICLE_INFO_LEN);
    memcpy(prism_vehicle_info, _MAV_PAYLOAD(msg), len);
#endif
}
