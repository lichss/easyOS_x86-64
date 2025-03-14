#ifndef __CPU_INSTR_H__
#define __CPU_INSTR_H__

#include "types.h"

#if 0
#define cli() \
    __asm__ __volatile__("cli")

#define sti() \
    __asm__ __volatile__("sti")


#else
static inline void cli() {
	__asm__ __volatile__("cli");
}

static inline void sti() {
	__asm__ __volatile__("sti");
}

#endif

static inline uint8_t inb(uint16_t  port) {
	uint8_t rv;
	__asm__ __volatile__("inb %[p], %[v]" : [v]"=a" (rv) : [p]"d"(port));
	return rv;
}

static inline void outb(uint16_t port, uint8_t data) {
	__asm__ __volatile__("outb %[v], %[p]" : : [p]"d" (port), [v]"a" (data));
}

static inline void lgdt(uint32_t start, uint32_t size) {
	struct {
		uint16_t limit;
		uint16_t start15_0;    // 视频中这里写成了32位
		uint16_t start31_16;    // 视频中这里写成了32位
	} gdt;

	gdt.start31_16 = start >> 16;
	gdt.start15_0 = start & 0xFFFF;
	gdt.limit = size - 1;

	__asm__ __volatile__("lgdt %[g]"::[g]"m"(gdt));
}



#endif