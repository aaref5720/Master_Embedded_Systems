
learn-in-depth.elf:     file format elf32-littlearm


Disassembly of section .startup:

00010000 <reset>:
   10000:	e3a0da11 	mov	sp, #69632	; 0x11000
   10004:	eb000000 	bl	1000c <main>

00010008 <stop>:
   10008:	eafffffe 	b	10008 <stop>

Disassembly of section .text:

0001000c <main>:
   1000c:	e92d4800 	push	{fp, lr}
   10010:	e28db004 	add	fp, sp, #4
   10014:	e59f0004 	ldr	r0, [pc, #4]	; 10020 <main+0x14>
   10018:	eb000001 	bl	10024 <Uart_Send_String>
   1001c:	e8bd8800 	pop	{fp, pc}
   10020:	000100d8 	ldrdeq	r0, [r1], -r8

00010024 <Uart_Send_String>:
   10024:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   10028:	e28db000 	add	fp, sp, #0
   1002c:	e24dd00c 	sub	sp, sp, #12
   10030:	e50b0008 	str	r0, [fp, #-8]
   10034:	ea000006 	b	10054 <Uart_Send_String+0x30>
   10038:	e59f3030 	ldr	r3, [pc, #48]	; 10070 <Uart_Send_String+0x4c>
   1003c:	e51b2008 	ldr	r2, [fp, #-8]
   10040:	e5d22000 	ldrb	r2, [r2]
   10044:	e5832000 	str	r2, [r3]
   10048:	e51b3008 	ldr	r3, [fp, #-8]
   1004c:	e2833001 	add	r3, r3, #1
   10050:	e50b3008 	str	r3, [fp, #-8]
   10054:	e51b3008 	ldr	r3, [fp, #-8]
   10058:	e5d33000 	ldrb	r3, [r3]
   1005c:	e3530000 	cmp	r3, #0
   10060:	1afffff4 	bne	10038 <Uart_Send_String+0x14>
   10064:	e28bd000 	add	sp, fp, #0
   10068:	e8bd0800 	ldmfd	sp!, {fp}
   1006c:	e12fff1e 	bx	lr
   10070:	101f1000 	andsne	r1, pc, r0

Disassembly of section .rodata:

00010074 <string_buffer2>:
   10074:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   10078:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   1007c:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   10080:	413a6874 	teqmi	sl, r4, ror r8
   10084:	6c656462 	cfstrdvs	mvd6, [r5], #-392	; 0xfffffe78
   10088:	6d686172 	stfvse	f6, [r8, #-456]!	; 0xfffffe38
   1008c:	00006e61 	andeq	r6, r0, r1, ror #28
	...

Disassembly of section .data:

000100d8 <string_buffer1>:
   100d8:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   100dc:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   100e0:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   100e4:	413a6874 	teqmi	sl, r4, ror r8
   100e8:	6c656462 	cfstrdvs	mvd6, [r5], #-392	; 0xfffffe78
   100ec:	6d686172 	stfvse	f6, [r8, #-456]!	; 0xfffffe38
   100f0:	00006e61 	andeq	r6, r0, r1, ror #28
	...

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002d41 	andeq	r2, r0, r1, asr #26
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000023 	andeq	r0, r0, r3, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	Address 0x0000002c is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <stack_top+0x10bfbe8>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	34202955 	strtcc	r2, [r0], #-2389	; 0x955
   c:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
	...
