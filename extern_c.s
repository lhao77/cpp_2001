	.file	"extern_c.c"
	.section .rdata,"dr"
LC0:
	.ascii "In extern_c.c tc()\0"
	.text
.globl __Z2tcv
	.def	__Z2tcv;	.scl	2;	.type	32;	.endef
__Z2tcv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$LC0, (%esp)
	call	_puts
	leave
	ret
	.def	_puts;	.scl	2;	.type	32;	.endef
