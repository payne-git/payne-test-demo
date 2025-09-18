
a.out:     file format elf64-littleaarch64


Disassembly of section .init:

00000000004003b0 <_init>:
  4003b0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  4003b4:	910003fd 	mov	x29, sp
  4003b8:	9400002c 	bl	400468 <call_weak_fn>
  4003bc:	a8c17bfd 	ldp	x29, x30, [sp], #16
  4003c0:	d65f03c0 	ret

Disassembly of section .plt:

00000000004003d0 <.plt>:
  4003d0:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
  4003d4:	90000090 	adrp	x16, 410000 <__FRAME_END__+0xf998>
  4003d8:	f947fe11 	ldr	x17, [x16, #4088]
  4003dc:	913fe210 	add	x16, x16, #0xff8
  4003e0:	d61f0220 	br	x17
  4003e4:	d503201f 	nop
  4003e8:	d503201f 	nop
  4003ec:	d503201f 	nop

00000000004003f0 <__libc_start_main@plt>:
  4003f0:	b0000090 	adrp	x16, 411000 <__libc_start_main@GLIBC_2.17>
  4003f4:	f9400211 	ldr	x17, [x16]
  4003f8:	91000210 	add	x16, x16, #0x0
  4003fc:	d61f0220 	br	x17

0000000000400400 <__gmon_start__@plt>:
  400400:	b0000090 	adrp	x16, 411000 <__libc_start_main@GLIBC_2.17>
  400404:	f9400611 	ldr	x17, [x16, #8]
  400408:	91002210 	add	x16, x16, #0x8
  40040c:	d61f0220 	br	x17

0000000000400410 <abort@plt>:
  400410:	b0000090 	adrp	x16, 411000 <__libc_start_main@GLIBC_2.17>
  400414:	f9400a11 	ldr	x17, [x16, #16]
  400418:	91004210 	add	x16, x16, #0x10
  40041c:	d61f0220 	br	x17

Disassembly of section .text:

0000000000400420 <_start>:
  400420:	d280001d 	mov	x29, #0x0                   	// #0
  400424:	d280001e 	mov	x30, #0x0                   	// #0
  400428:	aa0003e5 	mov	x5, x0
  40042c:	f94003e1 	ldr	x1, [sp]
  400430:	910023e2 	add	x2, sp, #0x8
  400434:	910003e6 	mov	x6, sp
  400438:	580000c0 	ldr	x0, 400450 <_start+0x30>
  40043c:	580000e3 	ldr	x3, 400458 <_start+0x38>
  400440:	58000104 	ldr	x4, 400460 <_start+0x40>
  400444:	97ffffeb 	bl	4003f0 <__libc_start_main@plt>
  400448:	97fffff2 	bl	400410 <abort@plt>
  40044c:	00000000 	.inst	0x00000000 ; undefined
  400450:	00400580 	.word	0x00400580
  400454:	00000000 	.word	0x00000000
  400458:	004005b8 	.word	0x004005b8
  40045c:	00000000 	.word	0x00000000
  400460:	00400638 	.word	0x00400638
  400464:	00000000 	.word	0x00000000

0000000000400468 <call_weak_fn>:
  400468:	90000080 	adrp	x0, 410000 <__FRAME_END__+0xf998>
  40046c:	f947f000 	ldr	x0, [x0, #4064]
  400470:	b4000040 	cbz	x0, 400478 <call_weak_fn+0x10>
  400474:	17ffffe3 	b	400400 <__gmon_start__@plt>
  400478:	d65f03c0 	ret
  40047c:	00000000 	.inst	0x00000000 ; undefined

0000000000400480 <deregister_tm_clones>:
  400480:	b0000080 	adrp	x0, 411000 <__libc_start_main@GLIBC_2.17>
  400484:	9100a000 	add	x0, x0, #0x28
  400488:	b0000081 	adrp	x1, 411000 <__libc_start_main@GLIBC_2.17>
  40048c:	9100a021 	add	x1, x1, #0x28
  400490:	eb00003f 	cmp	x1, x0
  400494:	540000a0 	b.eq	4004a8 <deregister_tm_clones+0x28>  // b.none
  400498:	90000001 	adrp	x1, 400000 <_init-0x3b0>
  40049c:	f9432c21 	ldr	x1, [x1, #1624]
  4004a0:	b4000041 	cbz	x1, 4004a8 <deregister_tm_clones+0x28>
  4004a4:	d61f0020 	br	x1
  4004a8:	d65f03c0 	ret
  4004ac:	d503201f 	nop

00000000004004b0 <register_tm_clones>:
  4004b0:	b0000080 	adrp	x0, 411000 <__libc_start_main@GLIBC_2.17>
  4004b4:	9100a000 	add	x0, x0, #0x28
  4004b8:	b0000081 	adrp	x1, 411000 <__libc_start_main@GLIBC_2.17>
  4004bc:	9100a021 	add	x1, x1, #0x28
  4004c0:	cb000021 	sub	x1, x1, x0
  4004c4:	9343fc21 	asr	x1, x1, #3
  4004c8:	8b41fc21 	add	x1, x1, x1, lsr #63
  4004cc:	9341fc21 	asr	x1, x1, #1
  4004d0:	b40000a1 	cbz	x1, 4004e4 <register_tm_clones+0x34>
  4004d4:	90000002 	adrp	x2, 400000 <_init-0x3b0>
  4004d8:	f9433042 	ldr	x2, [x2, #1632]
  4004dc:	b4000042 	cbz	x2, 4004e4 <register_tm_clones+0x34>
  4004e0:	d61f0040 	br	x2
  4004e4:	d65f03c0 	ret

00000000004004e8 <__do_global_dtors_aux>:
  4004e8:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
  4004ec:	910003fd 	mov	x29, sp
  4004f0:	f9000bf3 	str	x19, [sp, #16]
  4004f4:	b0000093 	adrp	x19, 411000 <__libc_start_main@GLIBC_2.17>
  4004f8:	3940a260 	ldrb	w0, [x19, #40]
  4004fc:	35000080 	cbnz	w0, 40050c <__do_global_dtors_aux+0x24>
  400500:	97ffffe0 	bl	400480 <deregister_tm_clones>
  400504:	52800020 	mov	w0, #0x1                   	// #1
  400508:	3900a260 	strb	w0, [x19, #40]
  40050c:	f9400bf3 	ldr	x19, [sp, #16]
  400510:	a8c27bfd 	ldp	x29, x30, [sp], #32
  400514:	d65f03c0 	ret

0000000000400518 <frame_dummy>:
  400518:	17ffffe6 	b	4004b0 <register_tm_clones>

000000000040051c <function2>:
  40051c:	d10083ff 	sub	sp, sp, #0x20
  400520:	b9000fe0 	str	w0, [sp, #12]
  400524:	b9000be1 	str	w1, [sp, #8]
  400528:	b9400fe1 	ldr	w1, [sp, #12]
  40052c:	b9400be0 	ldr	w0, [sp, #8]
  400530:	0b000020 	add	w0, w1, w0
  400534:	b9001fe0 	str	w0, [sp, #28]
  400538:	b9401fe0 	ldr	w0, [sp, #28]
  40053c:	910083ff 	add	sp, sp, #0x20
  400540:	d65f03c0 	ret

0000000000400544 <function1>:
  400544:	a9bd7bfd 	stp	x29, x30, [sp, #-48]!
  400548:	910003fd 	mov	x29, sp
  40054c:	b9001fa0 	str	w0, [x29, #28]
  400550:	b9001ba1 	str	w1, [x29, #24]
  400554:	b9401fa1 	ldr	w1, [x29, #28]
  400558:	b9401ba0 	ldr	w0, [x29, #24]
  40055c:	4b000020 	sub	w0, w1, w0
  400560:	b9002fa0 	str	w0, [x29, #44]
  400564:	b9402fa1 	ldr	w1, [x29, #44]
  400568:	b9401fa0 	ldr	w0, [x29, #28]
  40056c:	97ffffec 	bl	40051c <function2>
  400570:	b9002fa0 	str	w0, [x29, #44]
  400574:	b9402fa0 	ldr	w0, [x29, #44]
  400578:	a8c37bfd 	ldp	x29, x30, [sp], #48
  40057c:	d65f03c0 	ret

0000000000400580 <main>:
  400580:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
  400584:	910003fd 	mov	x29, sp
  400588:	52800060 	mov	w0, #0x3                   	// #3
  40058c:	b9001fa0 	str	w0, [x29, #28]
  400590:	52800020 	mov	w0, #0x1                   	// #1
  400594:	b9001ba0 	str	w0, [x29, #24]
  400598:	b9401ba1 	ldr	w1, [x29, #24]
  40059c:	b9401fa0 	ldr	w0, [x29, #28]
  4005a0:	97ffffe9 	bl	400544 <function1>
  4005a4:	b90017a0 	str	w0, [x29, #20]
  4005a8:	52800000 	mov	w0, #0x0                   	// #0
  4005ac:	a8c27bfd 	ldp	x29, x30, [sp], #32
  4005b0:	d65f03c0 	ret
  4005b4:	00000000 	.inst	0x00000000 ; undefined

00000000004005b8 <__libc_csu_init>:
  4005b8:	a9bc7bfd 	stp	x29, x30, [sp, #-64]!
  4005bc:	910003fd 	mov	x29, sp
  4005c0:	a901d7f4 	stp	x20, x21, [sp, #24]
  4005c4:	90000094 	adrp	x20, 410000 <__FRAME_END__+0xf998>
  4005c8:	90000095 	adrp	x21, 410000 <__FRAME_END__+0xf998>
  4005cc:	91380294 	add	x20, x20, #0xe00
  4005d0:	9137e2b5 	add	x21, x21, #0xdf8
  4005d4:	a902dff6 	stp	x22, x23, [sp, #40]
  4005d8:	cb150294 	sub	x20, x20, x21
  4005dc:	f9001ff8 	str	x24, [sp, #56]
  4005e0:	2a0003f6 	mov	w22, w0
  4005e4:	aa0103f7 	mov	x23, x1
  4005e8:	9343fe94 	asr	x20, x20, #3
  4005ec:	aa0203f8 	mov	x24, x2
  4005f0:	97ffff70 	bl	4003b0 <_init>
  4005f4:	b4000194 	cbz	x20, 400624 <__libc_csu_init+0x6c>
  4005f8:	f9000bb3 	str	x19, [x29, #16]
  4005fc:	d2800013 	mov	x19, #0x0                   	// #0
  400600:	f8737aa3 	ldr	x3, [x21, x19, lsl #3]
  400604:	aa1803e2 	mov	x2, x24
  400608:	aa1703e1 	mov	x1, x23
  40060c:	2a1603e0 	mov	w0, w22
  400610:	91000673 	add	x19, x19, #0x1
  400614:	d63f0060 	blr	x3
  400618:	eb13029f 	cmp	x20, x19
  40061c:	54ffff21 	b.ne	400600 <__libc_csu_init+0x48>  // b.any
  400620:	f9400bb3 	ldr	x19, [x29, #16]
  400624:	a941d7f4 	ldp	x20, x21, [sp, #24]
  400628:	a942dff6 	ldp	x22, x23, [sp, #40]
  40062c:	f9401ff8 	ldr	x24, [sp, #56]
  400630:	a8c47bfd 	ldp	x29, x30, [sp], #64
  400634:	d65f03c0 	ret

0000000000400638 <__libc_csu_fini>:
  400638:	d65f03c0 	ret

Disassembly of section .fini:

000000000040063c <_fini>:
  40063c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  400640:	910003fd 	mov	x29, sp
  400644:	a8c17bfd 	ldp	x29, x30, [sp], #16
  400648:	d65f03c0 	ret
