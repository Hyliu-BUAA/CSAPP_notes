	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	__Z7multipyRlS_S_               ## -- Begin function _Z7multipyRlS_S_
	.p2align	4, 0x90
__Z7multipyRlS_S_:                      ## @_Z7multipyRlS_S_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rsi), %rax
	imulq	(%rdi), %rax
	movq	%rax, (%rdx)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
