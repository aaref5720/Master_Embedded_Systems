#@ Copyright (C) 2022 Abdelrahman Aref.
#@ Description : This is the generic makefile for arm32 projects.

CC     =arm-none-eabi-
CFLAGS =-mcpu=arm926ej-s -g
INCS   =-I .
LIBS   =
SRC    =$(wildcard *.c)
OBJ    =$(SRC:.c=.o)
ASM    =$(wildcard *.s)
ASMOBJ =$(ASM:.s=.o)
Project_Name = Learn-in-depth


All: $(Project_Name).bin
	@echo "Build is Done ..."

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_Name).elf: $(OBJ) $(ASMOBJ) 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASMOBJ) -Map=Map_File.map -o $@

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@


clean_all:
	rm *.o *elf *.bin
	@echo "Everything Cleaned ..."

clean:
	rm *.elf *.bin