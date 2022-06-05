	.file	"program.cpp"
# GNU C++14 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE program.cpp
# -mtune=generic -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexceptions -ffp-int-builtin-inexact
# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fipa-stack-alignment -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-clash-protection
# -fstack-protector-strong -fstdarg-opt -fstrict-volatile-bitfields
# -fsync-libcalls -ftrapping-math -ftree-cselim -ftree-forwprop
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z3fooi
	.type	_Z3fooi, @function
_Z3fooi:
.LFB1522:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)	# var1, var1
# program.cpp:7:     int var3 = var1;
	movl	-20(%rbp), %eax	# var1, tmp84
	movl	%eax, -4(%rbp)	# tmp84, var3
# program.cpp:9:     asm("addl $20, -0x4(%rbp)");
#APP
# 9 "program.cpp" 1
	addl $20, -0x4(%rbp)
# 0 "" 2
# program.cpp:10:     return var3;
#NO_APP
	movl	-4(%rbp), %eax	# var3, _5
# program.cpp:11: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1522:
	.size	_Z3fooi, .-_Z3fooi
	.globl	main
	.type	main, @function
main:
.LFB1523:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# program.cpp:14:     int x = 9;
	movl	$9, -12(%rbp)	#, x
# program.cpp:15:     int y = x * 30;
	movl	-12(%rbp), %eax	# x, tmp86
	imull	$30, %eax, %eax	#, tmp86, tmp85
	movl	%eax, -8(%rbp)	# tmp85, y
# program.cpp:16:     int var = foo(x);
	movl	-12(%rbp), %eax	# x, tmp87
	movl	%eax, %edi	# tmp87,
	call	_Z3fooi	#
	movl	%eax, -4(%rbp)	# tmp88, var
# program.cpp:17:     cout << var << endl;
	movl	-4(%rbp), %eax	# var, tmp89
	movl	%eax, %esi	# tmp89,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZNSolsEi@PLT	#
	movq	%rax, %rdx	#, _1
# program.cpp:17:     cout << var << endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp90
	movq	%rax, %rsi	# tmp90,
	movq	%rdx, %rdi	# _1,
	call	_ZNSolsEPFRSoS_E@PLT	#
# program.cpp:19:     return 0;
	movl	$0, %eax	#, _10
# program.cpp:20: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1523:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2009:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# __initialize_p, __initialize_p
	movl	%esi, -8(%rbp)	# __priority, __priority
# program.cpp:20: }
	cmpl	$1, -4(%rbp)	#, __initialize_p
	jne	.L7	#,
# program.cpp:20: }
	cmpl	$65535, -8(%rbp)	#, __priority
	jne	.L7	#,
# /usr/include/c++/9/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rdi	#,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	leaq	__dso_handle(%rip), %rdx	#,
	leaq	_ZStL8__ioinit(%rip), %rsi	#,
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax	#, tmp82
	movq	%rax, %rdi	# tmp82,
	call	__cxa_atexit@PLT	#
.L7:
# program.cpp:20: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2009:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3fooi, @function
_GLOBAL__sub_I__Z3fooi:
.LFB2010:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# program.cpp:20: }
	movl	$65535, %esi	#,
	movl	$1, %edi	#,
	call	_Z41__static_initialization_and_destruction_0ii	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2010:
	.size	_GLOBAL__sub_I__Z3fooi, .-_GLOBAL__sub_I__Z3fooi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3fooi
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
