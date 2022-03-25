	.file	"test.cpp"
	.text
	.globl	_Z12make_pointerRPc
	.type	_Z12make_pointerRPc, @function
_Z12make_pointerRPc:
.LFB56:
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movl	$40, %eax
	movq	%fs:(%rax), %rcx
	movq	%rcx, 24(%rsp)
	xorl	%ecx, %ecx
	movq	%rsp, %rdx
	movq	%rdx, (%rdi)
	movq	24(%rsp), %rsi
	xorq	%fs:(%rax), %rsi
	jne	.L4
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE56:
	.size	_Z12make_pointerRPc, .-_Z12make_pointerRPc
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"name = %s\n Allocated address: %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB55:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movl	$40, %ebx
	movq	%fs:(%rbx), %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	$20, %edi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	%rax, (%rsp)
	movq	%rax, %rcx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rsp, %rdi
	call	_Z12make_pointerRPc
	movq	(%rsp), %rdx
	movq	%rdx, %rcx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	8(%rsp), %rax
	xorq	%fs:(%rbx), %rax
	jne	.L8
	movl	$0, %eax
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE55:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
