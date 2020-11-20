#pragma once
// MESSAGE PRISM_PROPULSION_ID PACKING

#define MAVLINK_MSG_ID_PRISM_PROPULSION_ID 13007

MAVPACKED(
typedef struct __mavlink_prism_propulsion_id_t {
 uint8_t target_system; /*<   System ID */
 uint8_t id; /*<   Propulsion ID */
}) mavlink_prism_propulsion_id_t;

#define MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN 2
#define MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN 2
#define MAVLINK_MSG_ID_13007_LEN 2
#define MAVLINK_MSG_ID_13007_MIN_LEN 2

#define MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC 5
#define MAVLINK_MSG_ID_13007_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PRISM_PROPULSION_ID { \
    13007, \
    "PRISM_PROPULSION_ID", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_prism_propulsion_id_t, target_system) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_prism_propulsion_id_t, id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PRISM_PROPULSION_ID { \
    "PRISM_PROPULSION_ID", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_prism_propulsion_id_t, target_system) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_prism_propulsion_id_t, id) }, \
         } \
}
#endif

/**
 * @brief Pack a prism_propulsion_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system   System ID 
 * @param id   Propulsion ID 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_propulsion_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN);
#else
    mavlink_prism_propulsion_id_t packet;
    packet.target_system = target_system;
    packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_PROPULSION_ID;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
}

/**
 * @brief Pack a prism_propulsion_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system   System ID 
 * @param id   Propulsion ID 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_prism_propulsion_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN);
#else
    mavlink_prism_propulsion_id_t packet;
    packet.target_system = target_system;
    packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRISM_PROPULSION_ID;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
}

/**
 * @brief Encode a prism_propulsion_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param prism_propulsion_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_propulsion_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_prism_propulsion_id_t* prism_propulsion_id)
{
    return mavlink_msg_prism_propulsion_id_pack(system_id, component_id, msg, prism_propulsion_id->target_system, prism_propulsion_id->id);
}

/**
 * @brief Encode a prism_propulsion_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param prism_propulsion_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_prism_propulsion_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_prism_propulsion_id_t* prism_propulsion_id)
{
    return mavlink_msg_prism_propulsion_id_pack_chan(system_id, component_id, chan, msg, prism_propulsion_id->target_system, prism_propulsion_id->id);
}

/**
 * @brief Send a prism_propulsion_id message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system   System ID 
 * @param id   Propulsion ID 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_prism_propulsion_id_send(mavlink_channel_t chan, uint8_t target_system, uint8_t id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID, buf, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
#else
    mavlink_prism_propulsion_id_t packet;
    packet.target_system = target_system;
    packet.id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID, (const char *)&packet, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
#endif
}

/**
 * @brief Send a prism_propulsion_id message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_prism_propulsion_id_send_struct(mavlink_channel_t chan, const mavlink_prism_propulsion_id_t* prism_propulsion_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_prism_propulsion_id_send(chan, prism_propulsion_id->target_system, prism_propulsion_id->id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID, (const char *)prism_propulsion_id, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
#endif
}

#if MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_prism_propulsion_id_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID, buf, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
#else
    mavlink_prism_propulsion_id_t *packet = (mavlink_prism_propulsion_id_t *)msgbuf;
    packet->target_system = target_system;
    packet->id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRISM_PROPULSION_ID, (const char *)packet, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_MIN_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_CRC);
#endif
}
#endif

#endif

// MESSAGE PRISM_PROPULSION_ID UNPACKING


/**
 * @brief Get field target_system from prism_propulsion_id message
 *
 * @return   System ID 
 */
static inline uint8_t mavlink_msg_prism_propulsion_id_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field id from prism_propulsion_id message
 *
 * @return   Propulsion ID 
 */
static inline uint8_t mavlink_msg_prism_propulsion_id_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a prism_propulsion_id message into a struct
 *
 * @param msg The message to decode
 * @param prism_propulsion_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_prism_propulsion_id_decode(const mavlink_message_t* msg, mavlink_prism_propulsion_id_t* prism_propulsion_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    prism_propulsion_id->target_system = mavlink_msg_prism_propulsion_id_get_target_system(msg);
    prism_propulsion_id->id = mavlink_msg_prism_propulsion_id_get_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN? msg->len : MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN;
        memset(prism_propulsion_id, 0, MAVLINK_MSG_ID_PRISM_PROPULSION_ID_LEN);
    memcpy(prism_propulsion_id, _MAV_PAYLOAD(msg), len);
#endif
}
