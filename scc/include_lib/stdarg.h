#ifndef _STDARG_H//{
#define _STDARG_H

#if defined(__SAOCC__)//{

#if defined(__x86_64__)//{

#if defined(_WIN64) //{

typedef char *va_list;
#define va_start(ap,last) __builtin_va_start(ap,last)
#define va_arg(ap, t) ((sizeof(t) > 8 || (sizeof(t) & (sizeof(t) - 1))) ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#define va_copy(dest, src) ((dest) = (src))
#define va_end(ap)

#elif defined(__APPLE__) //{

//TODO ...
#define _scc_alignof(type) ((int)&((struct {char c;type x;} *)0)->x)
#define _scc_align(addr,type) (((unsigned)addr + _scc_alignof(type) - 1) \
                               & ~(_scc_alignof(type) - 1))
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap = (void *) ((_scc_align(ap,type)+sizeof(type)+3) \
                        &~3), *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)

#else//}_WIN64{

typedef struct {
	unsigned int gp_offset;
	unsigned int fp_offset;
	union {
		unsigned int overflow_offset;
		char *overflow_arg_area;
	};
	char *reg_save_area;
} __va_list_struct;
typedef __va_list_struct va_list[1];

enum __va_arg_type {
	__va_gen_reg, __va_float_reg, __va_stack
};

static inline void __va_start(__va_list_struct *ap, void *fp)
{
	SCC(memset)(ap, 0, sizeof(__va_list_struct));
	*ap = *(__va_list_struct *)((char *)fp - 16);
	ap->overflow_arg_area = (char *)fp + ap->overflow_offset;
	ap->reg_save_area = (char *)fp - 176 - 16;
}

static inline void *__va_arg(__va_list_struct *ap,
		enum __va_arg_type arg_type,
		int size, int align)
{
	size = (size + 7) & ~7;
	align = (align + 7) & ~7;
	switch (arg_type) {
		case __va_gen_reg:
			if (ap->gp_offset + size <= 48) {
				ap->gp_offset += size;
				return ap->reg_save_area + ap->gp_offset - size;
			}
			goto use_overflow_area;

		case __va_float_reg:
			if (ap->fp_offset < 128 + 48) {
				ap->fp_offset += 16;
				return ap->reg_save_area + ap->fp_offset - 16;
			}
			size = 8;
			goto use_overflow_area;

		case __va_stack:
use_overflow_area:
			ap->overflow_arg_area += size;
			ap->overflow_arg_area = (char*)((long long)(ap->overflow_arg_area + align - 1) & -align);
			return ap->overflow_arg_area - size;

		default: /* should never happen */
			SCC(abort)();
	}
}

#define va_start(ap, last) __va_start(ap, __builtin_frame_address(0))
#define va_arg(ap, type) (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type), __alignof__(type))))
#define va_copy(dest, src) (*(dest) = *(src))
#define va_end(ap)

#endif//}

#elif defined(__arm__)//}{

typedef char *va_list;
#define _scc_alignof(type) ((int)&((struct {char c;type x;} *)0)->x)
#define _scc_align(addr,type) (((unsigned)addr + _scc_alignof(type) - 1) \
                               & ~(_scc_alignof(type) - 1))
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap = (void *) ((_scc_align(ap,type)+sizeof(type)+3) \
                        &~3), *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)

#elif defined(__aarch64__)
typedef struct {
    void *__stack;
    void *__gr_top;
    void *__vr_top;
    int   __gr_offs;
    int   __vr_offs;
} va_list;
#define va_start(ap, last) __va_start(ap, last)
#define va_arg(ap, type) __va_arg(ap, type)
#define va_end(ap)
#define va_copy(dest, src) ((dest) = (src))

#else //}:{

typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)

#endif //}

//close up for clang...
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif

#elif defined(__SMALLER_PP__)//}:{

typedef char* va_list;
#define va_start(vl, last)      { (vl) = (char*)&(last) + ((sizeof(last) + sizeof(int) - 1) & -sizeof(int)); }
#define va_arg(vl, type)        (*(type*)(((vl) += ((sizeof(type) + sizeof(int) - 1) & -sizeof(int))) - ((sizeof(type) + sizeof(int) - 1) & -sizeof(int))))
#define va_end(vl)

#else//}:{

//TODO
//TMP assume other compiler have __builtin_va_list ?

//TESTED: clang@osx, gcc@osx, gcc@docker_alpine

typedef __builtin_va_list	va_list;
#define va_start(ap,last) __builtin_va_start(ap,last)
#define va_end(ap)          __builtin_va_end(ap)
#define va_arg(ap, type)    __builtin_va_arg(ap, type)
//#define va_arg(ap, t) ((sizeof(t) > 8 || (sizeof(t) & (sizeof(t) - 1))) ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#define va_copy(dest, src) ((dest) = (src))

#endif//}__SAOCC__

#endif//}//_STDARG_H
