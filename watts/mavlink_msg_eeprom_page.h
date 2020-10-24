#pragma once
// MESSAGE EEPROM_PAGE PACKING

#define MAVLINK_MSG_ID_EEPROM_PAGE 13001

MAVPACKED(
typedef struct __mavlink_eeprom_page_t {
 uint32_t index; /*<   The eeprom board index, 0 indexed */
 uint32_t page_num; /*<   Page number, 0 indexed */
 uint8_t target_system; /*<   System ID */
 char page_data[16]; /*<   Opaque page data */
}) mavlink_eeprom_page_t;

#define MAVLINK_MSG_ID_EEPROM_PAGE_LEN 25
#define MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN 25
#define MAVLINK_MSG_ID_13001_LEN 25
#define MAVLINK_MSG_ID_13001_MIN_LEN 25

#define MAVLINK_MSG_ID_EEPROM_PAGE_CRC 33
#define MAVLINK_MSG_ID_13001_CRC 33

#define MAVLINK_MSG_EEPROM_PAGE_FIELD_PAGE_DATA_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EEPROM_PAGE { \
    13001, \
    "EEPROM_PAGE", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_eeprom_page_t, target_system) }, \
         { "index", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_eeprom_page_t, index) }, \
         { "page_data", NULL, MAVLINK_TYPE_CHAR, 16, 9, offsetof(mavlink_eeprom_page_t, page_data) }, \
         { "page_num", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_eeprom_page_t, page_num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EEPROM_PAGE { \
    "EEPROM_PAGE", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_eeprom_page_t, target_system) }, \
         { "index", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_eeprom_page_t, index) }, \
         { "page_data", NULL, MAVLINK_TYPE_CHAR, 16, 9, offsetof(mavlink_eeprom_page_t, page_data) }, \
         { "page_num", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_eeprom_page_t, page_num) }, \
         } \
}
#endif

/**
 * @brief Pack a eeprom_page message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system   System ID 
 * @param index   The eeprom board index, 0 indexed 
 * @param page_data   Opaque page data 
 * @param page_num   Page number, 0 indexed 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eeprom_page_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint32_t index, const char *page_data, uint32_t page_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EEPROM_PAGE_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_uint32_t(buf, 4, page_num);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_char_array(buf, 9, page_data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EEPROM_PAGE_LEN);
#else
    mavlink_eeprom_page_t packet;
    packet.index = index;
    packet.page_num = page_num;
    packet.target_system = target_system;
    mav_array_memcpy(packet.page_data, page_data, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EEPROM_PAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EEPROM_PAGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
}

/**
 * @brief Pack a eeprom_page message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system   System ID 
 * @param index   The eeprom board index, 0 indexed 
 * @param page_data   Opaque page data 
 * @param page_num   Page number, 0 indexed 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eeprom_page_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint32_t index,const char *page_data,uint32_t page_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EEPROM_PAGE_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_uint32_t(buf, 4, page_num);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_char_array(buf, 9, page_data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EEPROM_PAGE_LEN);
#else
    mavlink_eeprom_page_t packet;
    packet.index = index;
    packet.page_num = page_num;
    packet.target_system = target_system;
    mav_array_memcpy(packet.page_data, page_data, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EEPROM_PAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EEPROM_PAGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
}

/**
 * @brief Encode a eeprom_page struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param eeprom_page C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eeprom_page_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_eeprom_page_t* eeprom_page)
{
    return mavlink_msg_eeprom_page_pack(system_id, component_id, msg, eeprom_page->target_system, eeprom_page->index, eeprom_page->page_data, eeprom_page->page_num);
}

/**
 * @brief Encode a eeprom_page struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param eeprom_page C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eeprom_page_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_eeprom_page_t* eeprom_page)
{
    return mavlink_msg_eeprom_page_pack_chan(system_id, component_id, chan, msg, eeprom_page->target_system, eeprom_page->index, eeprom_page->page_data, eeprom_page->page_num);
}

/**
 * @brief Send a eeprom_page message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system   System ID 
 * @param index   The eeprom board index, 0 indexed 
 * @param page_data   Opaque page data 
 * @param page_num   Page number, 0 indexed 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_eeprom_page_send(mavlink_channel_t chan, uint8_t target_system, uint32_t index, const char *page_data, uint32_t page_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EEPROM_PAGE_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_uint32_t(buf, 4, page_num);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_char_array(buf, 9, page_data, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EEPROM_PAGE, buf, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
#else
    mavlink_eeprom_page_t packet;
    packet.index = index;
    packet.page_num = page_num;
    packet.target_system = target_system;
    mav_array_memcpy(packet.page_data, page_data, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EEPROM_PAGE, (const char *)&packet, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
#endif
}

/**
 * @brief Send a eeprom_page message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_eeprom_page_send_struct(mavlink_channel_t chan, const mavlink_eeprom_page_t* eeprom_page)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_eeprom_page_send(chan, eeprom_page->target_system, eeprom_page->index, eeprom_page->page_data, eeprom_page->page_num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EEPROM_PAGE, (const char *)eeprom_page, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_EEPROM_PAGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_eeprom_page_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint32_t index, const char *page_data, uint32_t page_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_uint32_t(buf, 4, page_num);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_char_array(buf, 9, page_data, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EEPROM_PAGE, buf, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
#else
    mavlink_eeprom_page_t *packet = (mavlink_eeprom_page_t *)msgbuf;
    packet->index = index;
    packet->page_num = page_num;
    packet->target_system = target_system;
    mav_array_memcpy(packet->page_data, page_data, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EEPROM_PAGE, (const char *)packet, MAVLINK_MSG_ID_EEPROM_PAGE_MIN_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_LEN, MAVLINK_MSG_ID_EEPROM_PAGE_CRC);
#endif
}
#endif

#endif

// MESSAGE EEPROM_PAGE UNPACKING


/**
 * @brief Get field target_system from eeprom_page message
 *
 * @return   System ID 
 */
static inline uint8_t mavlink_msg_eeprom_page_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field index from eeprom_page message
 *
 * @return   The eeprom board index, 0 indexed 
 */
static inline uint32_t mavlink_msg_eeprom_page_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field page_data from eeprom_page message
 *
 * @return   Opaque page data 
 */
static inline uint16_t mavlink_msg_eeprom_page_get_page_data(const mavlink_message_t* msg, char *page_data)
{
    return _MAV_RETURN_char_array(msg, page_data, 16,  9);
}

/**
 * @brief Get field page_num from eeprom_page message
 *
 * @return   Page number, 0 indexed 
 */
static inline uint32_t mavlink_msg_eeprom_page_get_page_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a eeprom_page message into a struct
 *
 * @param msg The message to decode
 * @param eeprom_page C-struct to decode the message contents into
 */
static inline void mavlink_msg_eeprom_page_decode(const mavlink_message_t* msg, mavlink_eeprom_page_t* eeprom_page)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    eeprom_page->index = mavlink_msg_eeprom_page_get_index(msg);
    eeprom_page->page_num = mavlink_msg_eeprom_page_get_page_num(msg);
    eeprom_page->target_system = mavlink_msg_eeprom_page_get_target_system(msg);
    mavlink_msg_eeprom_page_get_page_data(msg, eeprom_page->page_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EEPROM_PAGE_LEN? msg->len : MAVLINK_MSG_ID_EEPROM_PAGE_LEN;
        memset(eeprom_page, 0, MAVLINK_MSG_ID_EEPROM_PAGE_LEN);
    memcpy(eeprom_page, _MAV_PAYLOAD(msg), len);
#endif
}
