/** @file
 *    @brief MAVLink comm protocol testsuite generated from watts.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef WATTS_TESTSUITE_H
#define WATTS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_uAvionix(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_icarous(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_watts(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_uAvionix(system_id, component_id, last_msg);
    mavlink_test_icarous(system_id, component_id, last_msg);
    mavlink_test_watts(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"
#include "../ardupilotmega/testsuite.h"
#include "../uAvionix/testsuite.h"
#include "../icarous/testsuite.h"


static void mavlink_test_custom_message_test(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_custom_message_test_t packet_in = {
        963497464,963497672,963497880
    };
    mavlink_custom_message_test_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CUSTOM_MESSAGE_TEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_message_test_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_custom_message_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_message_test_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.alt );
    mavlink_msg_custom_message_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_message_test_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.alt );
    mavlink_msg_custom_message_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_custom_message_test_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_message_test_send(MAVLINK_COMM_1 , packet1.lat , packet1.lon , packet1.alt );
    mavlink_msg_custom_message_test_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_watts(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_custom_message_test(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // WATTS_TESTSUITE_H
