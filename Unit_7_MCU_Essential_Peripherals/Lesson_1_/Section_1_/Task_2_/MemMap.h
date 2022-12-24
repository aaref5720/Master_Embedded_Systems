/*
 * MemMap.h
 *
 * Created: 12/24/2022 8:38:25 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define DDRA    *((volatile unsigned char *) 0x3A)
#define PORTA   *((volatile unsigned char *) 0x3B)
#define PINA    *((volatile unsigned char *) 0x39)

#define DDRC    *((volatile unsigned char *) 0x34)
#define PORTC   *((volatile unsigned char *) 0x35)
#define PINC    *((volatile unsigned char *) 0x33)



#endif /* MEMMAP_H_ */