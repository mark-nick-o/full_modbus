#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* @file crc.h  :   * @brief Compact CRC library for embedded systems for CRC-CCITT, CRC-16, CRC-32.  *  * @par
 */
/* COPYRIGHT NOTICE: (c) 2000, 2018 Michael Barr.  This software is placed in the
 */
/* public domain and may be used for any purpose.
 */
/* However, this notice must not  * be changed or removed.  No warranty is expressed or implied by the publication
 */
/* or distribution of this source code.
 */
/* Ported for mikroE C Copyright (C) 2020 A C P Avaiation Walkerburn Scotland
 */
/*
 */
#include <stdint.h>

#define CRC_32                                                                  /* Define the 32 bit CRC computation (used for Receive filtering)
 */

/* Compile-time selection of the desired CRC algorithm. // 
 */
#if defined(CRC_CCITT)

#define CRC_NAME "CRC-CCITT" 
typedef uint16_t crc_t;

#elif defined(CRC_16)

#define CRC_NAME "CRC-16" 
typedef uint16_t crc_t;

#elif defined(CRC_32)

#define CRC_NAME "CRC-32" 
typedef uint32_t crc_t;

#else

#error "One of CRC_CCITT, CRC_16, or CRC_32 must be #define'd."

#endif

extern void crc16_arc_update(uint16_t length, uint8_t const * const p_message, uint8_t crc[2]); /* New CRC for SimpleBGC version 2.68b0 or greater
 */
/*void crc16_arc_calculate(uint16_t length, uint8_t *dataX, uint8_t crc[2]);
 */
extern uint16_t crc16_arc_calculate(uint16_t length, uint8_t const * const p_message); /* CRC16 ARC calculation */

/* Public API functions provided by the Compact CRC library.
 */
extern void crc_init(void);
extern crc_t crc_slow(uint8_t const * const p_message, uint8_t n_bytes);        /* Compute the CRC chosen above  (either CRC-CCITT CRC-16 CRC-32) slowly we are using CRC32 */
extern crc_t crc_fast(uint8_t const * const p_message, uint8_t n_bytes);        /* Compute the CRC chosen above  (either CRC-CCITT CRC-16 CRC-32) fast we are using CRC32 */
extern void compute_hashtable_fast32( unsigned char *addData );                 /* Compute the hash table for the network */
extern uint8_t crc8(uint8_t const * dataX, int32_t length);                     /* Compute the CRC8 */
extern uint8_t crc8_dvb_s2(uint8_t crc, unsigned char a);                       /* Run Cam CRC CRC8_DVB_S2 */
extern uint8_t crc8_dvb_s2_update(uint8_t crc, const void *dataX, uint32_t length);    /* Run Cam CRC iteration */
extern uint16_t crc16_arc_calculate(uint16_t length, uint8_t const * const p_message); /* CRC16 ARC calculation slow */
extern uint16_t crc16_arc_fast(uint16_t crc, unsigned char const *buffer, uint16_t len); /* CRC16 ARC fast */
extern uint16_t usMBCRC16( unsigned char * pucFrame, uint16_t usLen );          /* modbus rtu CRC */
extern uint8_t usMBAsciiLRC(unsigned char *auchMsg, uint16_t usLen);            /* modbus ascii LRC */
extern void crc_ccit16_init(void);                                             /* ccit16 crc for uavcan */
extern uint16_t crc_ccit16_fast(uint8_t const * const p_message, uint8_t n_bytes); /* ccit16 crc for uavcan */
extern uint16_t RobotisServo_crc(uint16_t crc_accum, uint8_t *data_blk_ptr, uint16_t data_blk_size); /* crc for robotis servo */
/* define the bit shift for the 32 bit to byte hash table locator
 */
#define INT32_TO_BYTE_MASK 0xFC0000
#define INT32_TO_BYTE_MOVE 23

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CRC_H */

/*** end of file ***/
