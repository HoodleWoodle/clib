#ifndef HW_COMMON_H
#define HW_COMMON_H

// types
typedef unsigned long size_t;

// join
#define JOIN(a, b) JOIN_AGAIN(a, b)
#define JOIN_AGAIN(a, b) a ## b

#define JOIN_3(a ,b, c) JOIN_3_AGAIN(a, b, c)
#define JOIN_3_AGAIN(a, b, c) a ## b ## c

#define JOIN_4(a, b, c, d) JOIN_4_AGAIN(a, b, c, d)
#define JOIN_4_AGAIN(a, b, c, d) a ## b ## c ## d

#define JOIN_5(a, b, c, d, e) JOIN_5_AGAIN(a, b, c, d, e)
#define JOIN_5_AGAIN(a, b, c, d, e)	a ## b ## c ## d ## e

// identifier
#define PREFIX_LIB hw_

// (prefixed) change identifier
#define CHI(ident) JOIN(PREFIX_LIB, ident)
#define PCHI(ident) JOIN_4(PREFIX_LIB, PREFIX, _, ident)

#endif // HW_COMMON_H