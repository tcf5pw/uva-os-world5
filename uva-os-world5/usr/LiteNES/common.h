#include <stdbool.h>
#include <stdint.h>
// #include <stdio.h>       // we have our own (fxl)
#include <assert.h> // fxl

#ifndef COMMON_H
#define COMMON_H

#ifndef NULL
#define NULL 0   // fxl
#endif

// fxl: from xv6. TODO clean up
typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int  uint32;
typedef unsigned long uint64;
////////////////////////////////////

typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef uint64_t qword;

// Binary Operations
bool common_bit_set(long long value, byte position);

// Byte Bit Operations
void common_set_bitb(byte *variable, byte position);
void common_unset_bitb(byte *variable, byte position);
void common_toggle_bitb(byte *variable, byte position);
void common_modify_bitb(byte *variable, byte position, bool set);

// Word Bit Operations
void common_set_bitw(word *variable, byte position);
void common_unset_bitw(word *variable, byte position);
void common_toggle_bitw(word *variable, byte position);
void common_modify_bitw(word *variable, byte position, bool set);

// Double Word Bit Operations
void common_set_bitd(dword *variable, byte position);
void common_unset_bitd(dword *variable, byte position);
void common_toggle_bitd(dword *variable, byte position);
void common_modify_bitd(dword *variable, byte position, bool set);

// Quad Word Bit Operations
void common_set_bitq(qword *variable, byte position);
void common_unset_bitq(qword *variable, byte position);
void common_toggle_bitq(qword *variable, byte position);
void common_modify_bitq(qword *variable, byte position, bool set);

#endif
