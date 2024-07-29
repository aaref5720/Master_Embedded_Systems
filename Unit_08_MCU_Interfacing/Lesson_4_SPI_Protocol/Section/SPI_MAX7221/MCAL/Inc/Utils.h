/*
 * MemMap.h
 *
 * Created: 12/24/2022 8:38:25 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(PORT,Bit)       PORT |=  (1<<Bit)		// Set pin
#define ReSet_Bit(PORT,Bit)     PORT &= ~(1<<Bit)		// Reset pin
#define Toggle_Bit(PORT,Bit)    PORT ^=  (1<<Bit)		// Toggle pin
#define Read_Bit(PORT,Bit)      ((PORT >> Bit) & 1)		// Read from pin

/***************************** @Ref Mechanism_define ***************************/
enum Mechanism{
	Polling_Mechanism_DIS=0,
	Polling_Mechanism_EN
};

#endif /* UTILS_H_ */