/*  linker script
	Copyrigt (C) Abdelrahman Aref
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	}>flash

	.data : {
		_S_Data = . ;
		*(.data*)
		. = ALIGN(4) ;
		_E_Data = . ;
	}>sram AT>flash
	
	.bss : {
		_S_bss = . ;
		*(.bss*)
		_E_bss = . ;

		. = ALIGN(4) ;
		. = . + 0x1000 ;
		Stack_top = . ;
	}>sram
}

