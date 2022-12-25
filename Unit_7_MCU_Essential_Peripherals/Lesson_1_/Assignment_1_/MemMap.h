/*
 * MemMap.h
 *
 * Created: 12/24/2022 8:38:25 PM
 *  Author: kinge
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define DDRD	*((volatile unsigned char *) 0x31)
#define PORTD	*((volatile unsigned char *) 0x32)
#define PIND	*((volatile unsigned char *) 0x30)

#endif /* MEMMAP_H_ */