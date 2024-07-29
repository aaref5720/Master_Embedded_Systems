/*  linker script
	Copyrigt (C) Abdelrahman Aref
*/

MEMORY
{
	FLASH(RX) : ORIGIN =  0x08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN =  0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT_ = . ;
	}> FLASH

	.data :
	{
		_S_DATA_ = . ;
		*(.data*)
		. = ALIGN(4) ;
		_E_DATA_ = . ;
	}> SRAM AT> FLASH

	.bss :
	{
		_S_BSS_ = . ;
		*(.bss*)
		_E_BSS_ = . ;

		. = ALIGN(4) ;
		. = . + 0x1000 ;
		Stack_Top = . ;

	}> SRAM
}