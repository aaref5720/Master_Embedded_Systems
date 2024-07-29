/*
 * AUTOSAR_Platforms_Types.h
 *
 * Created on : Oct 13, 2022
 *     Author : Abdelrahman Aref
 */

#ifndef AUTOSAR_PLATFORM_TYPES_H_
#define AUTOSAR_PLATFORM_TYPES_H_


/**********************************************************************************/
/*                                 Typedefs                                       */
/**********************************************************************************/

// boolean
typedef unsigned char   boolean;

// non-volatile and signed
typedef char                                sint8;
typedef short                               sint16;
typedef int                                 sint32;
typedef signed long long int                sint64;

// non-volatile and unsigned 
typedef unsigned char                       uint8;
typedef unsigned short                      uint16;
typedef unsigned int                        uint32;
typedef unsigned long long int              uint64;

// volatile and signed 
typedef volatile signed char                vsint8;
typedef volatile signed short               vsint16;
typedef volatile signed int                 vsint32;
typedef volatile signed long long int       vsint64;

// volatile and unsigned 
typedef volatile unsigned char              vuint8;
typedef volatile unsigned short             vuint16;
typedef volatile unsigned int               vuint32;
typedef volatile unsigned long long int     vuint64;

// non-volatile real 
typedef float                               float32;
typedef double                              float64;

// volatile real
typedef volatile float                      vfloat32;
typedef volatile double                     vfloat64;


/**********************************************************************************/
/*                                 Definitions                                    */
/**********************************************************************************/

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#endif