#@ Copyright (C) 2022 Abdelrahman Aref.

CC			 =arm-none-eabi-
CFLAGS 		 =-mcpu=cortex-m3 -gdwarf-2 -mthumb
INCS		 =-I .
LIBS		 =
SRC			 =$(wildcard *.c)
OBJ			 =$(SRC:.c=.o)
ASM    		 =$(wildcard *.s)
ASMOBJ 		 =$(ASM:.s=.o)
LINKER 		 =$(wildcard *.ld)
Project_Name =HighPressureDetection


ALL : $(Project_Name).bin
	@echo "Build is Done ... "

%.o : %.s
	$(CC)as.exe -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_Name).elf : $(OBJ) $(ASMOBJ)
	$(CC)ld.exe -T $(LINKER) $(OBJ) $(ASMOBJ) $(LIBS) -Map=Map_File.map -o $@ 

$(Project_Name).bin : $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *elf *.bin *.map
	@echo "Everything is Cleaned..."

clean:
	rm *.elf *.bin *.map