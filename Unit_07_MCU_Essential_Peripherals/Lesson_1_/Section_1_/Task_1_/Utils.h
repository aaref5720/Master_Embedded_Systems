/*
 * MemMap.h
 *
 * Created: 12/24/2022 8:38:25 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(PORT,Bit)       PORT |=  (1<<Bit)
#define Reset_Bit(PORT,Bit)     PORT &= ~(1<<Bit)
#define Toggle_Bit(PORT,Bit)    PORT ^=  (1<<Bit)
#define Read_Bit(PORT,Bit)      ((PORT >> Bit) & 1)

#endif /* UTILS_H_ */