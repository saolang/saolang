
typedef char			__int8_t;
typedef unsigned char		__uint8_t;
typedef	short			__int16_t;
typedef	unsigned short		__uint16_t;
typedef int			__int32_t;
typedef unsigned int		__uint32_t;
typedef long long		__int64_t;
typedef unsigned long long	__uint64_t;
typedef long			__darwin_intptr_t;
typedef unsigned int		__darwin_natural_t;
typedef int			__darwin_ct_rune_t;
typedef union {
	char		__mbstate8[128];
	long long	_mbstateL;
} __mbstate_t;
typedef __mbstate_t		__darwin_mbstate_t;
typedef long	__darwin_ptrdiff_t;
typedef unsigned long		__darwin_size_t;
typedef void *			__darwin_va_list;
typedef int		__darwin_wchar_t;
typedef __darwin_wchar_t	__darwin_rune_t;
typedef unsigned int		__darwin_wint_t;
typedef unsigned long		__darwin_clock_t;
typedef __uint32_t		__darwin_socklen_t;
typedef long			__darwin_ssize_t;
typedef long			__darwin_time_t;
typedef	__int64_t	__darwin_blkcnt_t;
typedef	__int32_t	__darwin_blksize_t;
typedef __int32_t	__darwin_dev_t;
typedef unsigned int	__darwin_fsblkcnt_t;
typedef unsigned int	__darwin_fsfilcnt_t;
typedef __uint32_t	__darwin_gid_t;
typedef __uint32_t	__darwin_id_t;
typedef __uint64_t	__darwin_ino64_t;
typedef __darwin_ino64_t __darwin_ino_t;
typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t	__darwin_mode_t;
typedef __int64_t	__darwin_off_t;
typedef __int32_t	__darwin_pid_t;
typedef __uint32_t	__darwin_sigset_t;
typedef __int32_t	__darwin_suseconds_t;
typedef __uint32_t	__darwin_uid_t;
typedef __uint32_t	__darwin_useconds_t;
typedef	unsigned char	__darwin_uuid_t[16];
typedef	char	__darwin_uuid_string_t[37];
struct __darwin_pthread_handler_rec {
	void (*__routine)(void *);
	void *__arg;
	struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t {
	long __sig;
	char __opaque[56];
};
struct _opaque_pthread_cond_t {
	long __sig;
	char __opaque[40];
};
struct _opaque_pthread_condattr_t {
	long __sig;
	char __opaque[8];
};
struct _opaque_pthread_mutex_t {
	long __sig;
	char __opaque[56];
};
struct _opaque_pthread_mutexattr_t {
	long __sig;
	char __opaque[8];
};
struct _opaque_pthread_once_t {
	long __sig;
	char __opaque[8];
};
struct _opaque_pthread_rwlock_t {
	long __sig;
	char __opaque[192];
};
struct _opaque_pthread_rwlockattr_t {
	long __sig;
	char __opaque[16];
};
struct _opaque_pthread_t {
	long __sig;
	struct __darwin_pthread_handler_rec  *__cleanup_stack;
	char __opaque[8176];
};
typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
typedef	int		__darwin_nl_item;
typedef	int		__darwin_wctrans_t;
typedef	__uint32_t	__darwin_wctype_t;
typedef	signed char		int8_t;
typedef	short			int16_t;
typedef	int			int32_t;
typedef	long long		int64_t;
typedef	unsigned char		u_int8_t;
typedef	unsigned short			u_int16_t;
typedef	unsigned int		u_int32_t;
typedef	unsigned long long	u_int64_t;
typedef int64_t			register_t;
typedef __darwin_intptr_t	intptr_t;
typedef unsigned long		uintptr_t;
typedef u_int64_t		user_addr_t;
typedef u_int64_t		user_size_t;
typedef int64_t			user_ssize_t;
typedef int64_t			user_long_t;
typedef u_int64_t		user_ulong_t;
typedef int64_t			user_time_t;
typedef int64_t			user_off_t;
typedef u_int64_t		syscall_arg_t;
typedef __darwin_va_list va_list;
typedef __darwin_size_t        size_t;
int	renameat(int, const char *, int, const char *) ;
int renamex_np(const char *, const char *, unsigned int)    ;
int renameatx_np(int, const char *, int, const char *, unsigned int)    ;
typedef __darwin_off_t		fpos_t;
struct __sbuf {
	unsigned char	*_base;
	int		_size;
};
struct __sFILEX;
typedef	struct __sFILE {
	unsigned char *_p;
	int	_r;
	int	_w;
	short	_flags;
	short	_file;
	struct	__sbuf _bf;
	int	_lbfsize;
	void	*_cookie;
	int	(*  _close)(void *);
	int	(*  _read) (void *, char *, int);
	fpos_t	(*  _seek) (void *, fpos_t, int);
	int	(*  _write)(void *, const char *, int);
	struct	__sbuf _ub;
	struct __sFILEX *_extra;
	int	_ur;
	unsigned char _ubuf[3];
	unsigned char _nbuf[1];
	struct	__sbuf _lb;
	int	_blksize;
	fpos_t	_offset;
} FILE;
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
void	 clearerr(FILE *);
int	 fclose(FILE *);
int	 feof(FILE *);
int	 ferror(FILE *);
int	 fflush(FILE *);
int	 fgetc(FILE *);
int	 fgetpos(FILE * restrict, fpos_t *);
char	*fgets(char * restrict, int, FILE *);
FILE	*fopen(const char * restrict __filename, const char * restrict __mode) __asm("_" "fopen" );
int	 fprintf(FILE * restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
int	 fputc(int, FILE *);
int	 fputs(const char * restrict, FILE * restrict) __asm("_" "fputs" );
size_t	 fread(void * restrict __ptr, size_t __size, size_t __nitems, FILE * restrict __stream);
FILE	*freopen(const char * restrict, const char * restrict,
                 FILE * restrict) __asm("_" "freopen" );
int	 fscanf(FILE * restrict, const char * restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
int	 fseek(FILE *, long, int);
int	 fsetpos(FILE *, const fpos_t *);
long	 ftell(FILE *);
size_t	 fwrite(const void * restrict __ptr, size_t __size, size_t __nitems, FILE * restrict __stream) __asm("_" "fwrite" );
int	 getc(FILE *);
int	 getchar(void);
char	*gets(char *);
void	 perror(const char *);
int	 printf(const char * restrict, ...) __attribute__((__format__ (__printf__, 1, 2)));
int	 putc(int, FILE *);
int	 putchar(int);
int	 puts(const char *);
int	 remove(const char *);
int	 rename (const char *__old, const char *__new);
void	 rewind(FILE *);
int	 scanf(const char * restrict, ...) __attribute__((__format__ (__scanf__, 1, 2)));
void	 setbuf(FILE * restrict, char * restrict);
int	 setvbuf(FILE * restrict, char * restrict, int, size_t);
int	 sprintf(char * restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) ;
int	 sscanf(const char * restrict, const char * restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE	*tmpfile(void);
__attribute__((deprecated))
char	*tmpnam(char *);
int	 ungetc(int, FILE *);
int	 vfprintf(FILE * restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
int	 vprintf(const char * restrict, va_list) __attribute__((__format__ (__printf__, 1, 0)));
int	 vsprintf(char * restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) ;
char	*ctermid(char *);
FILE	*fdopen(int, const char *) __asm("_" "fdopen" );
int	 fileno(FILE *);
int	 pclose(FILE *) ;
FILE	*popen(const char *, const char *) __asm("_" "popen" ) ;
int	__srget(FILE *);
int	__svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int	__swbuf(int, FILE *);
void	 flockfile(FILE *);
int	 ftrylockfile(FILE *);
void	 funlockfile(FILE *);
int	 getc_unlocked(FILE *);
int	 getchar_unlocked(void);
int	 putc_unlocked(int, FILE *);
int	 putchar_unlocked(int);
int	 getw(FILE *);
int	 putw(int, FILE *);
__attribute__((deprecated))
char	*tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam" );
typedef __darwin_off_t		off_t;
int	 fseeko(FILE * __stream, off_t __offset, int __whence);
off_t	 ftello(FILE * __stream);
int	 snprintf(char * restrict __str, size_t __size, const char * restrict __format, ...) __attribute__((__format__ (__printf__, 3, 4)));
int	 vfscanf(FILE * restrict __stream, const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int	 vscanf(const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int	 vsnprintf(char * restrict __str, size_t __size, const char * restrict __format, va_list) __attribute__((__format__ (__printf__, 3, 0)));
int	 vsscanf(const char * restrict __str, const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
typedef __darwin_ssize_t        ssize_t;
int	dprintf(int, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) ;
int	vdprintf(int, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) ;
ssize_t getdelim(char ** restrict __linep, size_t * restrict __linecapp, int __delimiter, FILE * restrict __stream) ;
ssize_t getline(char ** restrict __linep, size_t * restrict __linecapp, FILE * restrict __stream) ;
FILE *fmemopen(void * restrict __buf, size_t __size, const char * restrict __mode) ;
FILE *open_memstream(char **__bufp, size_t *__sizep) ;
extern const int sys_nerr;
extern const char *const sys_errlist[];
int	 asprintf(char ** restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
char	*ctermid_r(char *);
char	*fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int	 fpurge(FILE *);
void	 setbuffer(FILE *, char *, int);
int	 setlinebuf(FILE *);
int	 vasprintf(char ** restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE	*zopen(const char *, const char *, int);
FILE	*funopen(const void *,
                 int (* )(void *, char *, int),
                 int (* )(void *, const char *, int),
                 fpos_t (* )(void *, fpos_t, int),
                 int (* )(void *));
typedef enum {
	P_ALL,
	P_PID,
	P_PGID
} idtype_t;
typedef __darwin_pid_t        pid_t;
typedef __darwin_id_t	id_t;
typedef int sig_atomic_t;
struct __darwin_i386_thread_state
{
    unsigned int	__eax;
    unsigned int	__ebx;
    unsigned int	__ecx;
    unsigned int	__edx;
    unsigned int	__edi;
    unsigned int	__esi;
    unsigned int	__ebp;
    unsigned int	__esp;
    unsigned int	__ss;
    unsigned int	__eflags;
    unsigned int	__eip;
    unsigned int	__cs;
    unsigned int	__ds;
    unsigned int	__es;
    unsigned int	__fs;
    unsigned int	__gs;
};
struct __darwin_fp_control
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
						:2,
				__pc		:2,
				__rc		:2,
					 	:1,
						:3;
};
typedef struct __darwin_fp_control	__darwin_fp_control_t;
struct __darwin_fp_status
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
				__stkflt	:1,
				__errsumm	:1,
				__c0		:1,
				__c1		:1,
				__c2		:1,
				__tos		:3,
				__c3		:1,
				__busy		:1;
};
typedef struct __darwin_fp_status	__darwin_fp_status_t;
struct __darwin_mmst_reg
{
	char	__mmst_reg[10];
	char	__mmst_rsrv[6];
};
struct __darwin_xmm_reg
{
	char		__xmm_reg[16];
};
struct __darwin_ymm_reg
{
	char		__ymm_reg[32];
};
struct __darwin_zmm_reg
{
	char		__zmm_reg[64];
};
struct __darwin_opmask_reg
{
	char		__opmask_reg[8];
};
struct __darwin_i386_float_state
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	char			__fpu_rsrv4[14*16];
	int 			__fpu_reserved1;
};
struct __darwin_i386_avx_state
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	char			__fpu_rsrv4[14*16];
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;
	struct __darwin_xmm_reg		__fpu_ymmh1;
	struct __darwin_xmm_reg		__fpu_ymmh2;
	struct __darwin_xmm_reg		__fpu_ymmh3;
	struct __darwin_xmm_reg		__fpu_ymmh4;
	struct __darwin_xmm_reg		__fpu_ymmh5;
	struct __darwin_xmm_reg		__fpu_ymmh6;
	struct __darwin_xmm_reg		__fpu_ymmh7;
};
struct __darwin_i386_avx512_state
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	char			__fpu_rsrv4[14*16];
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;
	struct __darwin_xmm_reg		__fpu_ymmh1;
	struct __darwin_xmm_reg		__fpu_ymmh2;
	struct __darwin_xmm_reg		__fpu_ymmh3;
	struct __darwin_xmm_reg		__fpu_ymmh4;
	struct __darwin_xmm_reg		__fpu_ymmh5;
	struct __darwin_xmm_reg		__fpu_ymmh6;
	struct __darwin_xmm_reg		__fpu_ymmh7;
	struct __darwin_opmask_reg	__fpu_k0;
	struct __darwin_opmask_reg	__fpu_k1;
	struct __darwin_opmask_reg	__fpu_k2;
	struct __darwin_opmask_reg	__fpu_k3;
	struct __darwin_opmask_reg	__fpu_k4;
	struct __darwin_opmask_reg	__fpu_k5;
	struct __darwin_opmask_reg	__fpu_k6;
	struct __darwin_opmask_reg	__fpu_k7;
	struct __darwin_ymm_reg		__fpu_zmmh0;
	struct __darwin_ymm_reg		__fpu_zmmh1;
	struct __darwin_ymm_reg		__fpu_zmmh2;
	struct __darwin_ymm_reg		__fpu_zmmh3;
	struct __darwin_ymm_reg		__fpu_zmmh4;
	struct __darwin_ymm_reg		__fpu_zmmh5;
	struct __darwin_ymm_reg		__fpu_zmmh6;
	struct __darwin_ymm_reg		__fpu_zmmh7;
};
struct __darwin_i386_exception_state
{
	__uint16_t	__trapno;
	__uint16_t	__cpu;
	__uint32_t	__err;
	__uint32_t	__faultvaddr;
};
struct __darwin_x86_debug_state32
{
	unsigned int	__dr0;
	unsigned int	__dr1;
	unsigned int	__dr2;
	unsigned int	__dr3;
	unsigned int	__dr4;
	unsigned int	__dr5;
	unsigned int	__dr6;
	unsigned int	__dr7;
};
struct __darwin_x86_thread_state64
{
	__uint64_t	__rax;
	__uint64_t	__rbx;
	__uint64_t	__rcx;
	__uint64_t	__rdx;
	__uint64_t	__rdi;
	__uint64_t	__rsi;
	__uint64_t	__rbp;
	__uint64_t	__rsp;
	__uint64_t	__r8;
	__uint64_t	__r9;
	__uint64_t	__r10;
	__uint64_t	__r11;
	__uint64_t	__r12;
	__uint64_t	__r13;
	__uint64_t	__r14;
	__uint64_t	__r15;
	__uint64_t	__rip;
	__uint64_t	__rflags;
	__uint64_t	__cs;
	__uint64_t	__fs;
	__uint64_t	__gs;
};
struct __darwin_x86_float_state64
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	struct __darwin_xmm_reg		__fpu_xmm8;
	struct __darwin_xmm_reg		__fpu_xmm9;
	struct __darwin_xmm_reg		__fpu_xmm10;
	struct __darwin_xmm_reg		__fpu_xmm11;
	struct __darwin_xmm_reg		__fpu_xmm12;
	struct __darwin_xmm_reg		__fpu_xmm13;
	struct __darwin_xmm_reg		__fpu_xmm14;
	struct __darwin_xmm_reg		__fpu_xmm15;
	char			__fpu_rsrv4[6*16];
	int 			__fpu_reserved1;
};
struct __darwin_x86_avx_state64
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	struct __darwin_xmm_reg		__fpu_xmm8;
	struct __darwin_xmm_reg		__fpu_xmm9;
	struct __darwin_xmm_reg		__fpu_xmm10;
	struct __darwin_xmm_reg		__fpu_xmm11;
	struct __darwin_xmm_reg		__fpu_xmm12;
	struct __darwin_xmm_reg		__fpu_xmm13;
	struct __darwin_xmm_reg		__fpu_xmm14;
	struct __darwin_xmm_reg		__fpu_xmm15;
	char			__fpu_rsrv4[6*16];
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;
	struct __darwin_xmm_reg		__fpu_ymmh1;
	struct __darwin_xmm_reg		__fpu_ymmh2;
	struct __darwin_xmm_reg		__fpu_ymmh3;
	struct __darwin_xmm_reg		__fpu_ymmh4;
	struct __darwin_xmm_reg		__fpu_ymmh5;
	struct __darwin_xmm_reg		__fpu_ymmh6;
	struct __darwin_xmm_reg		__fpu_ymmh7;
	struct __darwin_xmm_reg		__fpu_ymmh8;
	struct __darwin_xmm_reg		__fpu_ymmh9;
	struct __darwin_xmm_reg		__fpu_ymmh10;
	struct __darwin_xmm_reg		__fpu_ymmh11;
	struct __darwin_xmm_reg		__fpu_ymmh12;
	struct __darwin_xmm_reg		__fpu_ymmh13;
	struct __darwin_xmm_reg		__fpu_ymmh14;
	struct __darwin_xmm_reg		__fpu_ymmh15;
};
struct __darwin_x86_avx512_state64
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;
	struct __darwin_fp_status	__fpu_fsw;
	__uint8_t		__fpu_ftw;
	__uint8_t		__fpu_rsrv1;
	__uint16_t		__fpu_fop;
	__uint32_t		__fpu_ip;
	__uint16_t		__fpu_cs;
	__uint16_t		__fpu_rsrv2;
	__uint32_t		__fpu_dp;
	__uint16_t		__fpu_ds;
	__uint16_t		__fpu_rsrv3;
	__uint32_t		__fpu_mxcsr;
	__uint32_t		__fpu_mxcsrmask;
	struct __darwin_mmst_reg	__fpu_stmm0;
	struct __darwin_mmst_reg	__fpu_stmm1;
	struct __darwin_mmst_reg	__fpu_stmm2;
	struct __darwin_mmst_reg	__fpu_stmm3;
	struct __darwin_mmst_reg	__fpu_stmm4;
	struct __darwin_mmst_reg	__fpu_stmm5;
	struct __darwin_mmst_reg	__fpu_stmm6;
	struct __darwin_mmst_reg	__fpu_stmm7;
	struct __darwin_xmm_reg		__fpu_xmm0;
	struct __darwin_xmm_reg		__fpu_xmm1;
	struct __darwin_xmm_reg		__fpu_xmm2;
	struct __darwin_xmm_reg		__fpu_xmm3;
	struct __darwin_xmm_reg		__fpu_xmm4;
	struct __darwin_xmm_reg		__fpu_xmm5;
	struct __darwin_xmm_reg		__fpu_xmm6;
	struct __darwin_xmm_reg		__fpu_xmm7;
	struct __darwin_xmm_reg		__fpu_xmm8;
	struct __darwin_xmm_reg		__fpu_xmm9;
	struct __darwin_xmm_reg		__fpu_xmm10;
	struct __darwin_xmm_reg		__fpu_xmm11;
	struct __darwin_xmm_reg		__fpu_xmm12;
	struct __darwin_xmm_reg		__fpu_xmm13;
	struct __darwin_xmm_reg		__fpu_xmm14;
	struct __darwin_xmm_reg		__fpu_xmm15;
	char			__fpu_rsrv4[6*16];
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;
	struct __darwin_xmm_reg		__fpu_ymmh1;
	struct __darwin_xmm_reg		__fpu_ymmh2;
	struct __darwin_xmm_reg		__fpu_ymmh3;
	struct __darwin_xmm_reg		__fpu_ymmh4;
	struct __darwin_xmm_reg		__fpu_ymmh5;
	struct __darwin_xmm_reg		__fpu_ymmh6;
	struct __darwin_xmm_reg		__fpu_ymmh7;
	struct __darwin_xmm_reg		__fpu_ymmh8;
	struct __darwin_xmm_reg		__fpu_ymmh9;
	struct __darwin_xmm_reg		__fpu_ymmh10;
	struct __darwin_xmm_reg		__fpu_ymmh11;
	struct __darwin_xmm_reg		__fpu_ymmh12;
	struct __darwin_xmm_reg		__fpu_ymmh13;
	struct __darwin_xmm_reg		__fpu_ymmh14;
	struct __darwin_xmm_reg		__fpu_ymmh15;
	struct __darwin_opmask_reg	__fpu_k0;
	struct __darwin_opmask_reg	__fpu_k1;
	struct __darwin_opmask_reg	__fpu_k2;
	struct __darwin_opmask_reg	__fpu_k3;
	struct __darwin_opmask_reg	__fpu_k4;
	struct __darwin_opmask_reg	__fpu_k5;
	struct __darwin_opmask_reg	__fpu_k6;
	struct __darwin_opmask_reg	__fpu_k7;
	struct __darwin_ymm_reg		__fpu_zmmh0;
	struct __darwin_ymm_reg		__fpu_zmmh1;
	struct __darwin_ymm_reg		__fpu_zmmh2;
	struct __darwin_ymm_reg		__fpu_zmmh3;
	struct __darwin_ymm_reg		__fpu_zmmh4;
	struct __darwin_ymm_reg		__fpu_zmmh5;
	struct __darwin_ymm_reg		__fpu_zmmh6;
	struct __darwin_ymm_reg		__fpu_zmmh7;
	struct __darwin_ymm_reg		__fpu_zmmh8;
	struct __darwin_ymm_reg		__fpu_zmmh9;
	struct __darwin_ymm_reg		__fpu_zmmh10;
	struct __darwin_ymm_reg		__fpu_zmmh11;
	struct __darwin_ymm_reg		__fpu_zmmh12;
	struct __darwin_ymm_reg		__fpu_zmmh13;
	struct __darwin_ymm_reg		__fpu_zmmh14;
	struct __darwin_ymm_reg		__fpu_zmmh15;
	struct __darwin_zmm_reg		__fpu_zmm16;
	struct __darwin_zmm_reg		__fpu_zmm17;
	struct __darwin_zmm_reg		__fpu_zmm18;
	struct __darwin_zmm_reg		__fpu_zmm19;
	struct __darwin_zmm_reg		__fpu_zmm20;
	struct __darwin_zmm_reg		__fpu_zmm21;
	struct __darwin_zmm_reg		__fpu_zmm22;
	struct __darwin_zmm_reg		__fpu_zmm23;
	struct __darwin_zmm_reg		__fpu_zmm24;
	struct __darwin_zmm_reg		__fpu_zmm25;
	struct __darwin_zmm_reg		__fpu_zmm26;
	struct __darwin_zmm_reg		__fpu_zmm27;
	struct __darwin_zmm_reg		__fpu_zmm28;
	struct __darwin_zmm_reg		__fpu_zmm29;
	struct __darwin_zmm_reg		__fpu_zmm30;
	struct __darwin_zmm_reg		__fpu_zmm31;
};
struct __darwin_x86_exception_state64
{
    __uint16_t	__trapno;
    __uint16_t	__cpu;
    __uint32_t	__err;
    __uint64_t	__faultvaddr;
};
struct __darwin_x86_debug_state64
{
	__uint64_t	__dr0;
	__uint64_t	__dr1;
	__uint64_t	__dr2;
	__uint64_t	__dr3;
	__uint64_t	__dr4;
	__uint64_t	__dr5;
	__uint64_t	__dr6;
	__uint64_t	__dr7;
};
struct __darwin_x86_cpmu_state64
{
	__uint64_t __ctrs[16];
};
struct __darwin_mcontext32
{
	struct __darwin_i386_exception_state	__es;
	struct __darwin_i386_thread_state	__ss;
	struct __darwin_i386_float_state	__fs;
};
struct __darwin_mcontext_avx32
{
	struct __darwin_i386_exception_state	__es;
	struct __darwin_i386_thread_state	__ss;
	struct __darwin_i386_avx_state		__fs;
};
struct __darwin_mcontext_avx512_32
{
	struct __darwin_i386_exception_state	__es;
	struct __darwin_i386_thread_state	__ss;
	struct __darwin_i386_avx512_state	__fs;
};
struct __darwin_mcontext64
{
	struct __darwin_x86_exception_state64	__es;
	struct __darwin_x86_thread_state64	__ss;
	struct __darwin_x86_float_state64	__fs;
};
struct __darwin_mcontext_avx64
{
	struct __darwin_x86_exception_state64	__es;
	struct __darwin_x86_thread_state64	__ss;
	struct __darwin_x86_avx_state64		__fs;
};
struct __darwin_mcontext_avx512_64
{
	struct __darwin_x86_exception_state64	__es;
	struct __darwin_x86_thread_state64	__ss;
	struct __darwin_x86_avx512_state64	__fs;
};
typedef struct __darwin_mcontext64	*mcontext_t;
typedef __darwin_pthread_attr_t pthread_attr_t;
struct __darwin_sigaltstack
{
	void            *ss_sp;
	__darwin_size_t ss_size;
	int             ss_flags;
};
typedef struct __darwin_sigaltstack	stack_t;
struct __darwin_ucontext
{
	int                     uc_onstack;
	__darwin_sigset_t       uc_sigmask;
	struct __darwin_sigaltstack     uc_stack;
	struct __darwin_ucontext        *uc_link;
	__darwin_size_t	        uc_mcsize;
	struct __darwin_mcontext64        *uc_mcontext;
};
typedef struct __darwin_ucontext	ucontext_t;
typedef __darwin_sigset_t		sigset_t;
typedef __darwin_uid_t        uid_t;
union sigval {
	int	sival_int;
	void	*sival_ptr;
};
struct sigevent {
	int				sigev_notify;
	int				sigev_signo;
	union sigval	sigev_value;
	void			(*sigev_notify_function)(union sigval);
	pthread_attr_t	*sigev_notify_attributes;
};
typedef struct __siginfo {
	int	si_signo;
	int	si_errno;
	int	si_code;
	pid_t	si_pid;
	uid_t	si_uid;
	int	si_status;
	void	*si_addr;
	union sigval si_value;
	long	si_band;
	unsigned long	__pad[7];
} siginfo_t;
union __sigaction_u {
	void    (*__sa_handler)(int);
	void    (*__sa_sigaction)(int, struct __siginfo *,
		       void *);
};
struct	__sigaction {
	union __sigaction_u __sigaction_u;
	void    (*sa_tramp)(void *, int, int, siginfo_t *, void *);
	sigset_t sa_mask;
	int	sa_flags;
};
struct	sigaction {
	union __sigaction_u __sigaction_u;
	sigset_t sa_mask;
	int	sa_flags;
};
typedef	void (*sig_t)(int);
struct	sigvec {
	void	(*sv_handler)(int);
	int	sv_mask;
	int	sv_flags;
};
struct	sigstack {
	char	*ss_sp;
	int	ss_onstack;
};
void	(*signal(int, void (*)(int)))(int);
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef int8_t           int_least8_t;
typedef int16_t         int_least16_t;
typedef int32_t         int_least32_t;
typedef int64_t         int_least64_t;
typedef uint8_t         uint_least8_t;
typedef uint16_t       uint_least16_t;
typedef uint32_t       uint_least32_t;
typedef uint64_t       uint_least64_t;
typedef int8_t            int_fast8_t;
typedef int16_t          int_fast16_t;
typedef int32_t          int_fast32_t;
typedef int64_t          int_fast64_t;
typedef uint8_t          uint_fast8_t;
typedef uint16_t        uint_fast16_t;
typedef uint32_t        uint_fast32_t;
typedef uint64_t        uint_fast64_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;
struct timeval
{
	__darwin_time_t	        tv_sec;
	__darwin_suseconds_t    tv_usec;
};
typedef __uint64_t	rlim_t;
struct	rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
	long	ru_maxrss;
	long	ru_ixrss;
	long	ru_idrss;
	long	ru_isrss;
	long	ru_minflt;
	long	ru_majflt;
	long	ru_nswap;
	long	ru_inblock;
	long	ru_oublock;
	long	ru_msgsnd;
	long	ru_msgrcv;
	long	ru_nsignals;
	long	ru_nvcsw;
	long	ru_nivcsw;
};
typedef void *rusage_info_t;
struct rusage_info_v0 {
	uint8_t  ri_uuid[16];
	uint64_t ri_user_time;
	uint64_t ri_system_time;
	uint64_t ri_pkg_idle_wkups;
	uint64_t ri_interrupt_wkups;
	uint64_t ri_pageins;
	uint64_t ri_wired_size;
	uint64_t ri_resident_size;
	uint64_t ri_phys_footprint;
	uint64_t ri_proc_start_abstime;
	uint64_t ri_proc_exit_abstime;
};
struct rusage_info_v1 {
	uint8_t  ri_uuid[16];
	uint64_t ri_user_time;
	uint64_t ri_system_time;
	uint64_t ri_pkg_idle_wkups;
	uint64_t ri_interrupt_wkups;
	uint64_t ri_pageins;
	uint64_t ri_wired_size;
	uint64_t ri_resident_size;
	uint64_t ri_phys_footprint;
	uint64_t ri_proc_start_abstime;
	uint64_t ri_proc_exit_abstime;
	uint64_t ri_child_user_time;
	uint64_t ri_child_system_time;
	uint64_t ri_child_pkg_idle_wkups;
	uint64_t ri_child_interrupt_wkups;
	uint64_t ri_child_pageins;
	uint64_t ri_child_elapsed_abstime;
};
struct rusage_info_v2 {
	uint8_t  ri_uuid[16];
	uint64_t ri_user_time;
	uint64_t ri_system_time;
	uint64_t ri_pkg_idle_wkups;
	uint64_t ri_interrupt_wkups;
	uint64_t ri_pageins;
	uint64_t ri_wired_size;
	uint64_t ri_resident_size;
	uint64_t ri_phys_footprint;
	uint64_t ri_proc_start_abstime;
	uint64_t ri_proc_exit_abstime;
	uint64_t ri_child_user_time;
	uint64_t ri_child_system_time;
	uint64_t ri_child_pkg_idle_wkups;
	uint64_t ri_child_interrupt_wkups;
	uint64_t ri_child_pageins;
	uint64_t ri_child_elapsed_abstime;
	uint64_t ri_diskio_bytesread;
	uint64_t ri_diskio_byteswritten;
};
struct rusage_info_v3 {
	uint8_t  ri_uuid[16];
	uint64_t ri_user_time;
	uint64_t ri_system_time;
	uint64_t ri_pkg_idle_wkups;
	uint64_t ri_interrupt_wkups;
	uint64_t ri_pageins;
	uint64_t ri_wired_size;
	uint64_t ri_resident_size;
	uint64_t ri_phys_footprint;
	uint64_t ri_proc_start_abstime;
	uint64_t ri_proc_exit_abstime;
	uint64_t ri_child_user_time;
	uint64_t ri_child_system_time;
	uint64_t ri_child_pkg_idle_wkups;
	uint64_t ri_child_interrupt_wkups;
	uint64_t ri_child_pageins;
	uint64_t ri_child_elapsed_abstime;
	uint64_t ri_diskio_bytesread;
	uint64_t ri_diskio_byteswritten;
	uint64_t ri_cpu_time_qos_default;
	uint64_t ri_cpu_time_qos_maintenance;
	uint64_t ri_cpu_time_qos_background;
	uint64_t ri_cpu_time_qos_utility;
	uint64_t ri_cpu_time_qos_legacy;
	uint64_t ri_cpu_time_qos_user_initiated;
	uint64_t ri_cpu_time_qos_user_interactive;
	uint64_t ri_billed_system_time;
	uint64_t ri_serviced_system_time;
};
struct rusage_info_v4 {
	uint8_t  ri_uuid[16];
	uint64_t ri_user_time;
	uint64_t ri_system_time;
	uint64_t ri_pkg_idle_wkups;
	uint64_t ri_interrupt_wkups;
	uint64_t ri_pageins;
	uint64_t ri_wired_size;
	uint64_t ri_resident_size;
	uint64_t ri_phys_footprint;
	uint64_t ri_proc_start_abstime;
	uint64_t ri_proc_exit_abstime;
	uint64_t ri_child_user_time;
	uint64_t ri_child_system_time;
	uint64_t ri_child_pkg_idle_wkups;
	uint64_t ri_child_interrupt_wkups;
	uint64_t ri_child_pageins;
	uint64_t ri_child_elapsed_abstime;
	uint64_t ri_diskio_bytesread;
	uint64_t ri_diskio_byteswritten;
	uint64_t ri_cpu_time_qos_default;
	uint64_t ri_cpu_time_qos_maintenance;
	uint64_t ri_cpu_time_qos_background;
	uint64_t ri_cpu_time_qos_utility;
	uint64_t ri_cpu_time_qos_legacy;
	uint64_t ri_cpu_time_qos_user_initiated;
	uint64_t ri_cpu_time_qos_user_interactive;
	uint64_t ri_billed_system_time;
	uint64_t ri_serviced_system_time;
	uint64_t ri_logical_writes;
	uint64_t ri_lifetime_max_phys_footprint;
	uint64_t ri_instructions;
	uint64_t ri_cycles;
	uint64_t ri_billed_energy;
	uint64_t ri_serviced_energy;
	uint64_t ri_unused[2];
};
typedef struct rusage_info_v4 rusage_info_current;
struct rlimit {
	rlim_t	rlim_cur;
	rlim_t	rlim_max;
};
struct proc_rlimit_control_wakeupmon {
	uint32_t wm_flags;
	int32_t wm_rate;
};
int	getpriority(int, id_t);
int	getiopolicy_np(int, int) ;
int	getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int	getrusage(int, struct rusage *);
int	setpriority(int, id_t, int);
int	setiopolicy_np(int, int, int) ;
int	setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
static inline
uint16_t
_OSSwapInt16(
    uint16_t			data
)
{
    return ((__uint16_t)((((__uint16_t)(data) & 0xff00) >> 8) | (((__uint16_t)(data) & 0x00ff) << 8)));
}
static inline
uint32_t
_OSSwapInt32(
    uint32_t			data
)
{
    return ((__uint32_t)((((__uint32_t)(data) & 0xff000000) >> 24) | (((__uint32_t)(data) & 0x00ff0000) >> 8) | (((__uint32_t)(data) & 0x0000ff00) << 8) | (((__uint32_t)(data) & 0x000000ff) << 24)));
}
static inline
uint64_t
_OSSwapInt64(
    uint64_t			data
)
{
    return ((__uint64_t)((((__uint64_t)(data) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(data) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(data) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(data) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(data) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(data) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(data) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(data) & 0x00000000000000ffULL) << 56)));
}
union wait {
	int	w_status;
	struct {
		unsigned int	w_Termsig:7,
				w_Coredump:1,
				w_Retcode:8,
				w_Filler:16;
	} w_T;
	struct {
		unsigned int	w_Stopval:8,
				w_Stopsig:8,
				w_Filler:16;
	} w_S;
};
pid_t	wait(int *) __asm("_" "wait" );
pid_t	waitpid(pid_t, int *, int) __asm("_" "waitpid" );
int	waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );
pid_t	wait3(int *, int, struct rusage *);
pid_t	wait4(pid_t, int *, int, struct rusage *);
void	*alloca(size_t);
typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;
typedef __darwin_wchar_t wchar_t;
typedef struct {
	int quot;
	int rem;
} div_t;
typedef struct {
	long quot;
	long rem;
} ldiv_t;
typedef struct {
	long long quot;
	long long rem;
} lldiv_t;
extern int __mb_cur_max;
void	 abort(void) __attribute__((noreturn));
int	 abs(int) __attribute__((const));
int	 atexit(void (* )(void));
double	 atof(const char *);
int	 atoi(const char *);
long	 atol(const char *);
long long
	 atoll(const char *);
void	*bsearch(const void *__key, const void *__base, size_t __nel,
	    size_t __width, int (*  __compar)(const void *, const void *));
void	*calloc(size_t __count, size_t __size)  ;
div_t	 div(int, int) __attribute__((const));
void	 exit(int) __attribute__((noreturn));
void	 free(void *);
char	*getenv(const char *);
long	 labs(long) __attribute__((const));
ldiv_t	 ldiv(long, long) __attribute__((const));
long long
	 llabs(long long);
lldiv_t	 lldiv(long long, long long);
void	*malloc(size_t __size)  ;
int	 mblen(const char *__s, size_t __n);
size_t	 mbstowcs(wchar_t * restrict , const char * restrict, size_t);
int	 mbtowc(wchar_t * restrict, const char * restrict, size_t);
int 	 posix_memalign(void **__memptr, size_t __alignment, size_t __size) ;
void	 qsort(void *__base, size_t __nel, size_t __width,
	    int (*  __compar)(const void *, const void *));
int	 rand(void) ;
void	*realloc(void *__ptr, size_t __size)  ;
void	 srand(unsigned) ;
double	 strtod(const char *, char **) __asm("_" "strtod" );
float	 strtof(const char *, char **) __asm("_" "strtof" );
long	 strtol(const char *__str, char **__endptr, int __base);
long double
	 strtold(const char *, char **);
long long
	 strtoll(const char *__str, char **__endptr, int __base);
unsigned long
	 strtoul(const char *__str, char **__endptr, int __base);
unsigned long long
	 strtoull(const char *__str, char **__endptr, int __base);
int	 system(const char *) __asm("_" "system" );
size_t	 wcstombs(char * restrict, const wchar_t * restrict, size_t);
int	 wctomb(char *, wchar_t);
void	_Exit(int) __attribute__((noreturn));
long	 a64l(const char *);
double	 drand48(void);
char	*ecvt(double, int, int *restrict, int *restrict);
double	 erand48(unsigned short[3]);
char	*fcvt(double, int, int *restrict, int *restrict);
char	*gcvt(double, int, char *);
int	 getsubopt(char **, char * const *, char **);
int	 grantpt(int);
char	*initstate(unsigned, char *, size_t);
long	 jrand48(unsigned short[3]) ;
char	*l64a(long);
void	 lcong48(unsigned short[7]);
long	 lrand48(void) ;
char	*mktemp(char *);
int	 mkstemp(char *);
long	 mrand48(void) ;
long	 nrand48(unsigned short[3]) ;
int	 posix_openpt(int);
char	*ptsname(int);
int ptsname_r(int fildes, char *buffer, size_t buflen) ;
int	 putenv(char *) __asm("_" "putenv" );
long	 random(void) ;
int	 rand_r(unsigned *) ;
char	*realpath(const char * restrict, char * restrict) __asm("_" "realpath" "$DARWIN_EXTSN");
unsigned short
	*seed48(unsigned short[3]);
int	 setenv(const char * __name, const char * __value, int __overwrite) __asm("_" "setenv" );
void	 setkey(const char *) __asm("_" "setkey" );
char	*setstate(const char *);
void	 srand48(long);
void	 srandom(unsigned);
int	 unlockpt(int);
int	 unsetenv(const char *) __asm("_" "unsetenv" );
typedef __darwin_dev_t        dev_t;
typedef	__darwin_mode_t		mode_t;
uint32_t arc4random(void);
void	 arc4random_addrandom(unsigned char *  , int  )
    ;
void	 arc4random_buf(void * __buf, size_t __nbytes) ;
void	 arc4random_stir(void);
uint32_t
	 arc4random_uniform(uint32_t __upper_bound) ;
char	*cgetcap(char *, const char *, int);
int	 cgetclose(void);
int	 cgetent(char **, char **, const char *);
int	 cgetfirst(char **, char **);
int	 cgetmatch(const char *, const char *);
int	 cgetnext(char **, char **);
int	 cgetnum(char *, const char *, long *);
int	 cgetset(const char *);
int	 cgetstr(char *, const char *, char **);
int	 cgetustr(char *, const char *, char **);
int	 daemon(int, int) __asm("_" "daemon" "$1050")   ;
char	*devname(dev_t, mode_t);
char	*devname_r(dev_t, mode_t, char *buf, int len);
char	*getbsize(int *, long *);
int	 getloadavg(double [], int);
const char
	*getprogname(void);
int	 heapsort(void *__base, size_t __nel, size_t __width,
	    int (*  __compar)(const void *, const void *));
int	 mergesort(void *__base, size_t __nel, size_t __width,
	    int (*  __compar)(const void *, const void *));
void	 psort(void *__base, size_t __nel, size_t __width,
	    int (*  __compar)(const void *, const void *)) ;
void	 psort_r(void *__base, size_t __nel, size_t __width, void *,
	    int (*  __compar)(void *, const void *, const void *))  ;
void	 qsort_r(void *__base, size_t __nel, size_t __width, void *,
	    int (*  __compar)(void *, const void *, const void *));
int	 radixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
	    unsigned __endbyte);
void	 setprogname(const char *);
int	 sradixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
	    unsigned __endbyte);
void	 sranddev(void);
void	 srandomdev(void);
void	*reallocf(void *__ptr, size_t __size) ;
long long
	 strtoq(const char *__str, char **__endptr, int __base);
unsigned long long
	 strtouq(const char *__str, char **__endptr, int __base);
extern char *suboptarg;
void	*valloc(size_t) ;
void	*memchr(const void *__s, int __c, size_t __n);
int	 memcmp(const void *__s1, const void *__s2, size_t __n);
void	*memcpy(void *__dst, const void *__src, size_t __n);
void	*memmove(void *__dst, const void *__src, size_t __len);
void	*memset(void *__b, int __c, size_t __len);
char	*strcat(char *__s1, const char *__s2);
char	*strchr(const char *__s, int __c);
int	 strcmp(const char *__s1, const char *__s2);
int	 strcoll(const char *__s1, const char *__s2);
char	*strcpy(char *__dst, const char *__src);
size_t	 strcspn(const char *__s, const char *__charset);
char	*strerror(int __errnum) __asm("_" "strerror" );
size_t	 strlen(const char *__s);
char	*strncat(char *__s1, const char *__s2, size_t __n);
int	 strncmp(const char *__s1, const char *__s2, size_t __n);
char	*strncpy(char *__dst, const char *__src, size_t __n);
char	*strpbrk(const char *__s, const char *__charset);
char	*strrchr(const char *__s, int __c);
size_t	 strspn(const char *__s, const char *__charset);
char	*strstr(const char *__big, const char *__little);
char	*strtok(char *__str, const char *__sep);
size_t	 strxfrm(char *__s1, const char *__s2, size_t __n);
char	*strtok_r(char *__str, const char *__sep, char **__lasts);
int	 strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char	*strdup(const char *__s1);
void	*memccpy(void *__dst, const void *__src, int __c, size_t __n);
char	*stpcpy(char *__dst, const char *__src);
char    *stpncpy(char *__dst, const char *__src, size_t __n) ;
char	*strndup(const char *__s1, size_t __n) ;
size_t   strnlen(const char *__s1, size_t __n) ;
char	*strsignal(int __sig);
typedef __darwin_size_t        rsize_t;
typedef int                    errno_t;
errno_t	memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) ;
void	*memmem(const void *__big, size_t __big_len, const void *__little, size_t __little_len) ;
void     memset_pattern4(void *__b, const void *__pattern4, size_t __len) ;
void     memset_pattern8(void *__b, const void *__pattern8, size_t __len) ;
void     memset_pattern16(void *__b, const void *__pattern16, size_t __len) ;
char	*strcasestr(const char *__big, const char *__little);
char	*strnstr(const char *__big, const char *__little, size_t __len);
size_t	 strlcat(char *__dst, const char *__source, size_t __size);
size_t	 strlcpy(char *__dst, const char *__source, size_t __size);
void	 strmode(int __mode, char *__bp);
char	*strsep(char **__stringp, const char *__delim);
void	 swab(const void * restrict, void * restrict, ssize_t);
int	timingsafe_bcmp(const void *__b1, const void *__b2, size_t __len);
int	 bcmp(const void *, const void *, size_t) ;
void	 bcopy(const void *, void *, size_t) ;
void	 bzero(void *, size_t) ;
char	*index(const char *, int) ;
char	*rindex(const char *, int) ;
int	 ffs(int);
int	 strcasecmp(const char *, const char *);
int	 strncasecmp(const char *, const char *, size_t);
int	 ffsl(long) ;
int	 ffsll(long long) ;
int	 fls(int) ;
int	 flsl(long) ;
int	 flsll(long long) ;
extern intmax_t
imaxabs(intmax_t j);
typedef struct {
	intmax_t quot;
	intmax_t rem;
} imaxdiv_t;
extern imaxdiv_t
imaxdiv(intmax_t __numer, intmax_t __denom);
extern intmax_t
strtoimax(const char * restrict __nptr,
	  char ** restrict __endptr,
	  int __base);
extern uintmax_t
strtoumax(const char * restrict __nptr,
	  char ** restrict __endptr,
	  int __base);
extern intmax_t
wcstoimax(const wchar_t * restrict __nptr,
	  wchar_t ** restrict __endptr,
	  int __base);
extern uintmax_t
wcstoumax(const wchar_t * restrict __nptr,
	  wchar_t ** restrict __endptr,
	  int __base);
typedef int jmp_buf[((9 * 2) + 3 + 16)];
typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
extern int	setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((noreturn));
int	_setjmp(jmp_buf);
void	_longjmp(jmp_buf, int) __attribute__((noreturn));
int	sigsetjmp(sigjmp_buf, int);
void	siglongjmp(sigjmp_buf, int) __attribute__((noreturn));
void	longjmperror(void);
typedef enum
{
  ERR_OUT_OF_MEMORY = 10,
  ERR_SYSCALL = 11,
  ERR_REF_COUNT_LIMIT = 12,
  ERR_DISABLED_BYTE_CODE = 13,
  ERR_FAILED_INTERNAL_ASSERTION = 120
} jerry_fatal_code_t;
void  jerry_port_fatal (jerry_fatal_code_t code);
typedef enum
{
  JERRY_LOG_LEVEL_ERROR,
  JERRY_LOG_LEVEL_WARNING,
  JERRY_LOG_LEVEL_DEBUG,
  JERRY_LOG_LEVEL_TRACE
} jerry_log_level_t;
void  jerry_port_log (jerry_log_level_t level, const char *format, ...);
double jerry_port_get_local_time_zone_adjustment (double unix_ms, _Bool is_utc);
double jerry_port_get_current_time (void);
struct jerry_context_t *jerry_port_get_current_context (void);
void jerry_port_sleep (uint32_t sleep_time);
typedef __darwin_ptrdiff_t ptrdiff_t;
typedef __darwin_wint_t wint_t;
void
jerry_assert_fail (const char *assertion, const char *file, const char *function, const uint32_t line);
void
jerry_unreachable (const char *file, const char *function, const uint32_t line);
void  jerry_fatal (jerry_fatal_code_t code);
typedef uint16_t ecma_char_t;
typedef uint32_t ecma_length_t;
typedef uint8_t lit_utf8_byte_t;
typedef uint32_t lit_utf8_size_t;
typedef uint8_t lit_magic_size_t;
typedef uint32_t lit_code_point_t;
typedef uint16_t lit_string_hash_t;
typedef enum
{
LIT_MAGIC_STRING__EMPTY,
LIT_MAGIC_STRING_SPACE_CHAR,
LIT_MAGIC_STRING_COMMA_CHAR,
LIT_MAGIC_STRING_SLASH_CHAR,
LIT_MAGIC_STRING_COLON_CHAR,
LIT_MAGIC_STRING_E_U,
LIT_MAGIC_STRING_LEFT_SQUARE_CHAR,
LIT_MAGIC_STRING_RIGHT_SQUARE_CHAR,
LIT_MAGIC_STRING_PI_U,
LIT_MAGIC_STRING_OF,
LIT_MAGIC_STRING_LN2_U,
LIT_MAGIC_STRING_MAP_UL,
LIT_MAGIC_STRING_NAN,
LIT_MAGIC_STRING_UTC_U,
LIT_MAGIC_STRING_ABS,
LIT_MAGIC_STRING_ALL,
LIT_MAGIC_STRING_COS,
LIT_MAGIC_STRING_EXP,
LIT_MAGIC_STRING_GET,
LIT_MAGIC_STRING_HAS,
LIT_MAGIC_STRING_LOG,
LIT_MAGIC_STRING_MAP,
LIT_MAGIC_STRING_MAX,
LIT_MAGIC_STRING_MIN,
LIT_MAGIC_STRING_NOW,
LIT_MAGIC_STRING_POP,
LIT_MAGIC_STRING_POW,
LIT_MAGIC_STRING_SET,
LIT_MAGIC_STRING_SIN,
LIT_MAGIC_STRING_TAN,
LIT_MAGIC_STRING_EMPTY_NON_CAPTURE_GROUP,
LIT_MAGIC_STRING_DATE_UL,
LIT_MAGIC_STRING_JSON_U,
LIT_MAGIC_STRING_LN10_U,
LIT_MAGIC_STRING_MATH_UL,
LIT_MAGIC_STRING_NULL_UL,
LIT_MAGIC_STRING_ACOS,
LIT_MAGIC_STRING_ASIN,
LIT_MAGIC_STRING_ATAN,
LIT_MAGIC_STRING_BIND,
LIT_MAGIC_STRING_CALL,
LIT_MAGIC_STRING_CEIL,
LIT_MAGIC_STRING_EVAL,
LIT_MAGIC_STRING_EXEC,
LIT_MAGIC_STRING_FILL,
LIT_MAGIC_STRING_FROM,
LIT_MAGIC_STRING_JOIN,
LIT_MAGIC_STRING_KEYS,
LIT_MAGIC_STRING_NAME,
LIT_MAGIC_STRING_NULL,
LIT_MAGIC_STRING_PUSH,
LIT_MAGIC_STRING_RACE,
LIT_MAGIC_STRING_SEAL,
LIT_MAGIC_STRING_SIZE,
LIT_MAGIC_STRING_SOME,
LIT_MAGIC_STRING_SORT,
LIT_MAGIC_STRING_SQRT,
LIT_MAGIC_STRING_TEST,
LIT_MAGIC_STRING_THEN,
LIT_MAGIC_STRING_TRIM,
LIT_MAGIC_STRING_TRUE,
LIT_MAGIC_STRING_ARRAY_UL,
LIT_MAGIC_STRING_ERROR_UL,
LIT_MAGIC_STRING_LOG2E_U,
LIT_MAGIC_STRING_SQRT2_U,
LIT_MAGIC_STRING_APPLY,
LIT_MAGIC_STRING_ATAN2,
LIT_MAGIC_STRING_CATCH,
LIT_MAGIC_STRING_CLEAR,
LIT_MAGIC_STRING_EVERY,
LIT_MAGIC_STRING_FALSE,
LIT_MAGIC_STRING_FLOOR,
LIT_MAGIC_STRING_INDEX,
LIT_MAGIC_STRING_INPUT,
LIT_MAGIC_STRING_IS_NAN,
LIT_MAGIC_STRING_MATCH,
LIT_MAGIC_STRING_PARSE,
LIT_MAGIC_STRING_ROUND,
LIT_MAGIC_STRING_SHIFT,
LIT_MAGIC_STRING_SLICE,
LIT_MAGIC_STRING_SPLIT,
LIT_MAGIC_STRING_VALUE,
LIT_MAGIC_STRING_LOG10E_U,
LIT_MAGIC_STRING_NUMBER_UL,
LIT_MAGIC_STRING_OBJECT_UL,
LIT_MAGIC_STRING_REGEXP_UL,
LIT_MAGIC_STRING_STRING_UL,
LIT_MAGIC_STRING_BUFFER,
LIT_MAGIC_STRING_CALLEE,
LIT_MAGIC_STRING_CALLER,
LIT_MAGIC_STRING_CHAR_AT_UL,
LIT_MAGIC_STRING_CONCAT,
LIT_MAGIC_STRING_CREATE,
LIT_MAGIC_STRING_DELETE,
LIT_MAGIC_STRING_ESCAPE,
LIT_MAGIC_STRING_FILTER,
LIT_MAGIC_STRING_FREEZE,
LIT_MAGIC_STRING_GET_DAY_UL,
LIT_MAGIC_STRING_GLOBAL,
LIT_MAGIC_STRING_IS_VIEW_UL,
LIT_MAGIC_STRING_LENGTH,
LIT_MAGIC_STRING_NUMBER,
LIT_MAGIC_STRING_OBJECT,
LIT_MAGIC_STRING_RANDOM,
LIT_MAGIC_STRING_REDUCE,
LIT_MAGIC_STRING_REJECT,
LIT_MAGIC_STRING_SEARCH,
LIT_MAGIC_STRING_SOURCE,
LIT_MAGIC_STRING_SPLICE,
LIT_MAGIC_STRING_STRING,
LIT_MAGIC_STRING_SUBSTR,
LIT_MAGIC_STRING_TO_JSON_UL,
LIT_MAGIC_STRING_BOOLEAN_UL,
LIT_MAGIC_STRING_PROMISE_UL,
LIT_MAGIC_STRING_SQRT1_2_U,
LIT_MAGIC_STRING_BOOLEAN,
LIT_MAGIC_STRING_COMPILE,
LIT_MAGIC_STRING_FOR_EACH_UL,
LIT_MAGIC_STRING_GET_DATE_UL,
LIT_MAGIC_STRING_GET_TIME_UL,
LIT_MAGIC_STRING_GET_YEAR_UL,
LIT_MAGIC_STRING_INDEX_OF_UL,
LIT_MAGIC_STRING_IS_ARRAY_UL,
LIT_MAGIC_STRING_MESSAGE,
LIT_MAGIC_STRING_REPLACE,
LIT_MAGIC_STRING_RESOLVE,
LIT_MAGIC_STRING_REVERSE,
LIT_MAGIC_STRING_SET_DATE_UL,
LIT_MAGIC_STRING_SET_TIME_UL,
LIT_MAGIC_STRING_SET_YEAR_UL,
LIT_MAGIC_STRING_TO_FIXED_UL,
LIT_MAGIC_STRING_UNSHIFT,
LIT_MAGIC_STRING_VALUE_OF_UL,
LIT_MAGIC_STRING_FUNCTION_UL,
LIT_MAGIC_STRING_INFINITY_UL,
LIT_MAGIC_STRING_URI_ERROR_UL,
LIT_MAGIC_STRING_FUNCTION,
LIT_MAGIC_STRING_GET_HOURS_UL,
LIT_MAGIC_STRING_GET_MONTH_UL,
LIT_MAGIC_STRING_IS_FINITE,
LIT_MAGIC_STRING_IS_FROZEN_UL,
LIT_MAGIC_STRING_IS_SEALED_UL,
LIT_MAGIC_STRING_PARSE_INT,
LIT_MAGIC_STRING_SET_HOURS_UL,
LIT_MAGIC_STRING_SET_MONTH_UL,
LIT_MAGIC_STRING_SUBARRAY,
LIT_MAGIC_STRING_TO_STRING_UL,
LIT_MAGIC_STRING_UNESCAPE,
LIT_MAGIC_STRING_WRITABLE,
LIT_MAGIC_STRING_NEGATIVE_INFINITY_UL,
LIT_MAGIC_STRING_ARGUMENTS_UL,
LIT_MAGIC_STRING_EVAL_ERROR_UL,
LIT_MAGIC_STRING_INT8_ARRAY_UL,
LIT_MAGIC_STRING_MAX_VALUE_U,
LIT_MAGIC_STRING_MIN_VALUE_U,
LIT_MAGIC_STRING_TYPE_ERROR_UL,
LIT_MAGIC_STRING_UNDEFINED_UL,
LIT_MAGIC_STRING_ARGUMENTS,
LIT_MAGIC_STRING_DECODE_URI,
LIT_MAGIC_STRING_ENCODE_URI,
LIT_MAGIC_STRING_GET_UTC_DAY_UL,
LIT_MAGIC_STRING_LASTINDEX_UL,
LIT_MAGIC_STRING_MULTILINE,
LIT_MAGIC_STRING_PROTOTYPE,
LIT_MAGIC_STRING_STRINGIFY,
LIT_MAGIC_STRING_SUBSTRING,
LIT_MAGIC_STRING_UNDEFINED,
LIT_MAGIC_STRING_INT16_ARRAY_UL,
LIT_MAGIC_STRING_INT32_ARRAY_UL,
LIT_MAGIC_STRING_RANGE_ERROR_UL,
LIT_MAGIC_STRING_TYPED_ARRAY_UL,
LIT_MAGIC_STRING_UINT8_ARRAY_UL,
LIT_MAGIC_STRING_BYTE_LENGTH_UL,
LIT_MAGIC_STRING_BYTE_OFFSET_UL,
LIT_MAGIC_STRING_CHAR_CODE_AT_UL,
LIT_MAGIC_STRING_ENUMERABLE,
LIT_MAGIC_STRING_GET_MINUTES_UL,
LIT_MAGIC_STRING_GET_SECONDS_UL,
LIT_MAGIC_STRING_GET_UTC_DATE_UL,
LIT_MAGIC_STRING_IGNORECASE_UL,
LIT_MAGIC_STRING_PARSE_FLOAT,
LIT_MAGIC_STRING_SET_MINUTES_UL,
LIT_MAGIC_STRING_SET_SECONDS_UL,
LIT_MAGIC_STRING_SET_UTC_DATE_UL,
LIT_MAGIC_STRING_ARRAY_BUFFER_UL,
LIT_MAGIC_STRING_SYNTAX_ERROR_UL,
LIT_MAGIC_STRING_UINT16_ARRAY_UL,
LIT_MAGIC_STRING_UINT32_ARRAY_UL,
LIT_MAGIC_STRING_CONSTRUCTOR,
LIT_MAGIC_STRING_GET_FULL_YEAR_UL,
LIT_MAGIC_STRING_GET_UTC_HOURS_UL,
LIT_MAGIC_STRING_GET_UTC_MONTH_UL,
LIT_MAGIC_STRING_LAST_INDEX_OF_UL,
LIT_MAGIC_STRING_REDUCE_RIGHT_UL,
LIT_MAGIC_STRING_SET_FULL_YEAR_UL,
LIT_MAGIC_STRING_SET_UTC_HOURS_UL,
LIT_MAGIC_STRING_SET_UTC_MONTH_UL,
LIT_MAGIC_STRING_TO_GMT_STRING_UL,
LIT_MAGIC_STRING_TO_ISO_STRING_UL,
LIT_MAGIC_STRING_TO_LOWER_CASE_UL,
LIT_MAGIC_STRING_TO_PRECISION_UL,
LIT_MAGIC_STRING_TO_UTC_STRING_UL,
LIT_MAGIC_STRING_TO_UPPER_CASE_UL,
LIT_MAGIC_STRING_FLOAT32_ARRAY_UL,
LIT_MAGIC_STRING_FLOAT64_ARRAY_UL,
LIT_MAGIC_STRING_INVALID_DATE_UL,
LIT_MAGIC_STRING_CONFIGURABLE,
LIT_MAGIC_STRING_FROM_CHAR_CODE_UL,
LIT_MAGIC_STRING_IS_EXTENSIBLE,
LIT_MAGIC_STRING_TO_DATE_STRING_UL,
LIT_MAGIC_STRING_TO_TIME_STRING_UL,
LIT_MAGIC_STRING_GET_UTC_MINUTES_UL,
LIT_MAGIC_STRING_GET_UTC_SECONDS_UL,
LIT_MAGIC_STRING_IS_PROTOTYPE_OF_UL,
LIT_MAGIC_STRING_LOCALE_COMPARE_UL,
LIT_MAGIC_STRING_SET_UTC_MINUTES_UL,
LIT_MAGIC_STRING_SET_UTC_SECONDS_UL,
LIT_MAGIC_STRING_TO_EXPONENTIAL_UL,
LIT_MAGIC_STRING_REFERENCE_ERROR_UL,
LIT_MAGIC_STRING_DEFINE_PROPERTY_UL,
LIT_MAGIC_STRING_GET_PROTOTYPE_OF_UL,
LIT_MAGIC_STRING_GET_UTC_FULL_YEAR_UL,
LIT_MAGIC_STRING_HAS_OWN_PROPERTY_UL,
LIT_MAGIC_STRING_SET_PROTOTYPE_OF_UL,
LIT_MAGIC_STRING_SET_UTC_FULL_YEAR_UL,
LIT_MAGIC_STRING_TO_LOCALE_STRING_UL,
LIT_MAGIC_STRING_GET_MILLISECONDS_UL,
LIT_MAGIC_STRING_SET_MILLISECONDS_UL,
LIT_MAGIC_STRING_DEFINE_PROPERTIES_UL,
LIT_MAGIC_STRING_BYTES_PER_ELEMENT_U,
LIT_MAGIC_STRING_NEGATIVE_INFINITY_U,
LIT_MAGIC_STRING_POSITIVE_INFINITY_U,
LIT_MAGIC_STRING_UINT8_CLAMPED_ARRAY_UL,
LIT_MAGIC_STRING_GET_TIMEZONE_OFFSET_UL,
LIT_MAGIC_STRING_PREVENT_EXTENSIONS_UL,
LIT_MAGIC_STRING_TO_LOCALE_LOWER_CASE_UL,
LIT_MAGIC_STRING_TO_LOCALE_UPPER_CASE_UL,
LIT_MAGIC_STRING_DECODE_URI_COMPONENT,
LIT_MAGIC_STRING_ENCODE_URI_COMPONENT,
LIT_MAGIC_STRING_GET_UTC_MILLISECONDS_UL,
LIT_MAGIC_STRING_SET_UTC_MILLISECONDS_UL,
LIT_MAGIC_STRING_TO_LOCALE_DATE_STRING_UL,
LIT_MAGIC_STRING_TO_LOCALE_TIME_STRING_UL,
LIT_MAGIC_STRING_GET_OWN_PROPERTY_NAMES_UL,
LIT_MAGIC_STRING_PROPERTY_IS_ENUMERABLE_UL,
LIT_MAGIC_STRING_GET_OWN_PROPERTY_DESCRIPTOR_UL,
LIT_MAGIC_STRING__FUNCTION_TO_STRING,
  LIT_NON_INTERNAL_MAGIC_STRING__COUNT,
  LIT_INTERNAL_MAGIC_STRING_PROMISE = LIT_NON_INTERNAL_MAGIC_STRING__COUNT,
  LIT_INTERNAL_MAGIC_STRING_ALREADY_RESOLVED,
  LIT_INTERNAL_MAGIC_STRING_RESOLVE_FUNCTION,
  LIT_INTERNAL_MAGIC_STRING_REJECT_FUNCTION,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_PROMISE,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_RESOLVE,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_REJECT,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_CAPABILITY,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_HANDLER,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_ALREADY_CALLED,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_INDEX,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_VALUE,
  LIT_INTERNAL_MAGIC_STRING_PROMISE_PROPERTY_REMAINING_ELEMENT,
  LIT_GC_MARK_REQUIRED_MAGIC_STRING__COUNT,
  LIT_INTERNAL_MAGIC_STRING_DELETED = LIT_GC_MARK_REQUIRED_MAGIC_STRING__COUNT,
  LIT_INTERNAL_MAGIC_STRING_NATIVE_POINTER,
  LIT_FIRST_INTERNAL_MAGIC_STRING = LIT_INTERNAL_MAGIC_STRING_NATIVE_POINTER,
  LIT_INTERNAL_MAGIC_STRING_CLASS_THIS_BINDING,
  LIT_MAGIC_STRING__COUNT
} lit_magic_string_id_t;
typedef uint32_t lit_magic_string_ex_id_t;
uint32_t lit_get_magic_string_ex_count (void);
const lit_utf8_byte_t *lit_get_magic_string_utf8 (lit_magic_string_id_t id);
lit_utf8_size_t lit_get_magic_string_size (lit_magic_string_id_t id);
const lit_utf8_byte_t *lit_get_magic_string_ex_utf8 (lit_magic_string_ex_id_t id);
lit_utf8_size_t lit_get_magic_string_ex_size (lit_magic_string_ex_id_t id);
void lit_magic_strings_ex_set (const lit_utf8_byte_t * const *ex_str_items,
                               uint32_t count,
                               const lit_utf8_size_t *ex_str_sizes);
lit_magic_string_id_t lit_is_utf8_string_magic (const lit_utf8_byte_t *string_p, lit_utf8_size_t string_size);
lit_magic_string_id_t lit_is_utf8_string_pair_magic (const lit_utf8_byte_t *string1_p, lit_utf8_size_t string1_size,
                                                     const lit_utf8_byte_t *string2_p, lit_utf8_size_t string2_size);
lit_magic_string_ex_id_t lit_is_ex_utf8_string_magic (const lit_utf8_byte_t *string_p, lit_utf8_size_t string_size);
lit_magic_string_ex_id_t lit_is_ex_utf8_string_pair_magic (const lit_utf8_byte_t *string1_p,
                                                           lit_utf8_size_t string1_size,
                                                           const lit_utf8_byte_t *string2_p,
                                                           lit_utf8_size_t string2_size);
lit_utf8_byte_t *lit_copy_magic_string_to_buffer (lit_magic_string_id_t id, lit_utf8_byte_t *buffer_p,
                                                  lit_utf8_size_t buffer_size);
typedef uint16_t jmem_cpointer_t;
typedef enum
{
  JMEM_FREE_UNUSED_MEMORY_SEVERITY_LOW,
  JMEM_FREE_UNUSED_MEMORY_SEVERITY_HIGH,
} jmem_free_unused_memory_severity_t;
typedef struct jmem_pools_chunk_t
{
  struct jmem_pools_chunk_t *next_p;
} jmem_pools_chunk_t;
typedef struct
{
  uint32_t next_offset;
  uint32_t size;
} jmem_heap_free_t;
void jmem_init (void);
void jmem_finalize (void);
void *jmem_heap_alloc_block (const size_t size);
void *jmem_heap_alloc_block_null_on_error (const size_t size);
void jmem_heap_free_block (void *ptr, const size_t size);
jmem_cpointer_t  jmem_compress_pointer (const void *pointer_p);
void *  jmem_decompress_pointer (uintptr_t compressed_pointer);
typedef void (*jmem_free_unused_memory_callback_t) (jmem_free_unused_memory_severity_t);
void jmem_register_free_unused_memory_callback (jmem_free_unused_memory_callback_t callback);
void jmem_unregister_free_unused_memory_callback (jmem_free_unused_memory_callback_t callback);
void jmem_run_free_unused_memory_callbacks (jmem_free_unused_memory_severity_t severity);
void *jmem_pools_alloc (size_t size);
void jmem_pools_free (void *chunk_p, size_t size);
typedef enum
{
  ECMA_INIT_EMPTY               = (0u),
  ECMA_INIT_SHOW_OPCODES        = (1u << 0),
  ECMA_INIT_SHOW_REGEXP_OPCODES = (1u << 1),
  ECMA_INIT_MEM_STATS           = (1u << 2),
} ecma_init_flag_t;
typedef enum
{
  ECMA_STATUS_API_AVAILABLE     = (1u << 0),
  ECMA_STATUS_DIRECT_EVAL       = (1u << 1),
  ECMA_STATUS_HIGH_SEV_GC       = (1u << 2),
  ECMA_STATUS_EXCEPTION         = (1u << 3),
} ecma_status_flag_t;
typedef enum
{
  ECMA_TYPE_DIRECT = 0,
  ECMA_TYPE_STRING = 1,
  ECMA_TYPE_FLOAT = 2,
  ECMA_TYPE_OBJECT = 3,
  ECMA_TYPE_DIRECT_STRING = 5,
  ECMA_TYPE_ERROR = 7,
  ECMA_TYPE_POINTER = ECMA_TYPE_ERROR,
  ECMA_TYPE_SNAPSHOT_OFFSET = ECMA_TYPE_ERROR,
  ECMA_TYPE___MAX = ECMA_TYPE_ERROR
} ecma_type_t;
typedef enum
{
  ECMA_PARSE_NO_OPTS = 0,
  ECMA_PARSE_STRICT_MODE = (1u << 0),
  ECMA_PARSE_DIRECT_EVAL = (1u << 1),
  ECMA_PARSE_CLASS_CONSTRUCTOR = (1u << 2),
  ECMA_PARSE_HAS_SUPER = (1u << 3),
  ECMA_PARSE_HAS_STATIC_SUPER = (1u << 4),
} ecma_parse_opts_t;
typedef uint32_t ecma_value_t;
typedef int32_t ecma_integer_value_t;
enum
{
  ECMA_VALUE_EMPTY = ((((ecma_value_t) (0)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_ERROR = ((((ecma_value_t) (1)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_FALSE = ((((ecma_value_t) (2)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_TRUE = ((((ecma_value_t) (3)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_UNDEFINED = ((((ecma_value_t) (4)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_NULL = ((((ecma_value_t) (5)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_ARRAY_HOLE = ((((ecma_value_t) (6)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_NOT_FOUND = ((((ecma_value_t) (7)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_REGISTER_REF = ((((ecma_value_t) (8)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
  ECMA_VALUE_IMPLICIT_CONSTRUCTOR = ((((ecma_value_t) (9)) << 4) | ((1u << 3) | ECMA_TYPE_DIRECT)),
};
typedef uintptr_t ecma_external_pointer_t;
typedef ecma_value_t (*ecma_vm_exec_stop_callback_t) (void *user_p);
typedef void (*ecma_user_context_deinit_t) (void *user_context_p);
typedef ecma_value_t (*ecma_external_handler_t) (const ecma_value_t function_obj,
                                                 const ecma_value_t this_val,
                                                 const ecma_value_t args_p[],
                                                 const ecma_length_t args_count);
typedef void (*ecma_object_native_free_callback_t) (void *native_p);
typedef struct
{
  ecma_object_native_free_callback_t free_cb;
} ecma_object_native_info_t;
typedef struct
{
  void *data_p;
  ecma_object_native_info_t *info_p;
} ecma_native_pointer_t;
typedef enum
{
  ECMA_PROPERTY_NOT_WRITABLE,
  ECMA_PROPERTY_WRITABLE
} ecma_property_writable_value_t;
typedef enum
{
  ECMA_PROPERTY_NOT_ENUMERABLE,
  ECMA_PROPERTY_ENUMERABLE
} ecma_property_enumerable_value_t;
typedef enum
{
  ECMA_PROPERTY_NOT_CONFIGURABLE,
  ECMA_PROPERTY_CONFIGURABLE
} ecma_property_configurable_value_t;
typedef enum
{
  ECMA_PROPERTY_TYPE_SPECIAL,
  ECMA_PROPERTY_TYPE_NAMEDDATA,
  ECMA_PROPERTY_TYPE_NAMEDACCESSOR,
  ECMA_PROPERTY_TYPE_INTERNAL,
  ECMA_PROPERTY_TYPE_VIRTUAL = ECMA_PROPERTY_TYPE_INTERNAL,
  ECMA_PROPERTY_TYPE__MAX = ECMA_PROPERTY_TYPE_VIRTUAL,
} ecma_property_types_t;
typedef enum
{
  ECMA_LIST_NO_OPTS = (0),
  ECMA_LIST_ARRAY_INDICES = (1 << 0),
  ECMA_LIST_ENUMERABLE = (1 << 1),
  ECMA_LIST_PROTOTYPE = (1 << 2),
} ecma_list_properties_options_t;
typedef enum
{
  ECMA_PROPERTY_FLAG_CONFIGURABLE = 1u << (2 + 0),
  ECMA_PROPERTY_FLAG_ENUMERABLE = 1u << (2 + 1),
  ECMA_PROPERTY_FLAG_WRITABLE = 1u << (2 + 2),
  ECMA_PROPERTY_FLAG_LCACHED = 1u << (2 + 3),
} ecma_property_flags_t;
typedef enum
{
  ECMA_SPECIAL_PROPERTY_HASHMAP,
  ECMA_SPECIAL_PROPERTY_DELETED,
  ECMA_SPECIAL_PROPERTY__COUNT
} ecma_special_property_id_t;
typedef uint8_t ecma_property_t;
typedef struct
{
  ecma_property_t types[2];
  jmem_cpointer_t next_property_cp;
} ecma_property_header_t;
typedef struct
{
  jmem_cpointer_t getter_p;
  jmem_cpointer_t setter_p;
} ecma_getter_setter_pointers_t;
typedef union
{
  ecma_value_t value;
  ecma_getter_setter_pointers_t getter_setter_pair;
} ecma_property_value_t;
typedef struct
{
  ecma_property_header_t header;
  ecma_property_value_t values[2];
  jmem_cpointer_t names_cp[2];
} ecma_property_pair_t;
typedef union
{
  ecma_property_value_t *value_p;
  ecma_value_t virtual_value;
} ecma_property_ref_t;
typedef struct
{
  ecma_property_ref_t property_ref;
  ecma_property_t *property_p;
} ecma_extended_property_ref_t;
typedef enum
{
  ECMA_PROPERTY_GET_NO_OPTIONS = 0,
  ECMA_PROPERTY_GET_VALUE = 1u << 0,
  ECMA_PROPERTY_GET_EXT_REFERENCE = 1u << 1,
} ecma_property_get_option_bits_t;
typedef enum
{
  ECMA_OBJECT_TYPE_GENERAL = 0,
  ECMA_OBJECT_TYPE_CLASS = 1,
  ECMA_OBJECT_TYPE_FUNCTION = 2,
  ECMA_OBJECT_TYPE_EXTERNAL_FUNCTION = 3,
  ECMA_OBJECT_TYPE_ARRAY = 4,
  ECMA_OBJECT_TYPE_BOUND_FUNCTION = 5,
  ECMA_OBJECT_TYPE_PSEUDO_ARRAY  = 6,
  ECMA_OBJECT_TYPE_ARROW_FUNCTION = 7,
  ECMA_OBJECT_TYPE__MAX
} ecma_object_type_t;
typedef enum
{
  ECMA_PSEUDO_ARRAY_ARGUMENTS = 0,
  ECMA_PSEUDO_ARRAY_TYPEDARRAY = 1,
  ECMA_PSEUDO_ARRAY_TYPEDARRAY_WITH_INFO = 2,
  ECMA_PSEUDO_ARRAY__MAX = ECMA_PSEUDO_ARRAY_TYPEDARRAY_WITH_INFO
} ecma_pseudo_array_type_t;
typedef enum
{
  ECMA_LEXICAL_ENVIRONMENT_DECLARATIVE = 13,
  ECMA_LEXICAL_ENVIRONMENT_THIS_OBJECT_BOUND = 14,
  ECMA_LEXICAL_ENVIRONMENT_SUPER_OBJECT_BOUND = 15,
  ECMA_LEXICAL_ENVIRONMENT_TYPE_START = ECMA_LEXICAL_ENVIRONMENT_DECLARATIVE,
  ECMA_LEXICAL_ENVIRONMENT_TYPE__MAX = ECMA_LEXICAL_ENVIRONMENT_SUPER_OBJECT_BOUND
} ecma_lexical_environment_type_t;
typedef struct
{
  uint16_t type_flags_refs;
  jmem_cpointer_t gc_next_cp;
  jmem_cpointer_t property_list_or_bound_object_cp;
  jmem_cpointer_t prototype_or_outer_reference_cp;
} ecma_object_t;
typedef struct
{
  uint8_t id;
  uint8_t length_and_bitset_size;
  uint16_t routine_id;
  uint32_t instantiated_bitset[1];
} ecma_built_in_props_t;
typedef struct
{
  ecma_object_t object;
  union
  {
    ecma_built_in_props_t built_in;
    struct
    {
      uint16_t class_id;
      uint16_t extra_info;
      union
      {
        ecma_value_t value;
        uint32_t length;
      } u;
    } class_prop;
    struct
    {
      ecma_value_t scope_cp;
      ecma_value_t bytecode_cp;
    } function;
    struct
    {
      uint32_t length;
      ecma_property_t length_prop;
    } array;
    struct
    {
      uint8_t type;
      uint8_t extra_info;
      union
      {
        uint16_t length;
        uint16_t class_id;
      } u1;
      union
      {
        ecma_value_t lex_env_cp;
        ecma_value_t arraybuffer;
      } u2;
    } pseudo_array;
    struct
    {
      ecma_value_t target_function;
      ecma_value_t args_len_or_this;
    } bound_function;
    ecma_external_handler_t external_handler_cb;
  } u;
} ecma_extended_object_t;
typedef struct
{
  ecma_extended_object_t extended_object;
  ecma_built_in_props_t built_in;
} ecma_extended_built_in_object_t;
typedef struct
{
  uint16_t size;
  uint16_t refs;
  uint16_t status_flags;
} ecma_compiled_code_t;
typedef struct
{
  ecma_object_t object;
  ecma_value_t this_binding;
  jmem_cpointer_t scope_cp;
  jmem_cpointer_t bytecode_cp;
} ecma_arrow_function_t;
typedef struct
{
  ecma_extended_object_t header;
  jmem_cpointer_t first_chunk_cp;
  jmem_cpointer_t last_chunk_cp;
} ecma_map_object_t;
typedef struct
{
  ecma_value_t items[3 + 1];
} ecma_map_object_chunk_t;
typedef struct
{
  unsigned int is_value_defined : 1;
  unsigned int is_get_defined : 1;
  unsigned int is_set_defined : 1;
  unsigned int is_writable_defined : 1;
  unsigned int is_writable : 1;
  unsigned int is_enumerable_defined : 1;
  unsigned int is_enumerable : 1;
  unsigned int is_configurable_defined : 1;
  unsigned int is_configurable : 1;
  ecma_value_t value;
  ecma_object_t *get_p;
  ecma_object_t *set_p;
} ecma_property_descriptor_t;
typedef double ecma_number_t;
typedef enum
{
  ECMA_COLLECTION_NO_REF_OBJECTS = (1u << 0),
  ECMA_COLLECTION_NO_COPY = (1u << 1),
} ecma_collection_flag_t;
typedef struct
{
  jmem_cpointer_t first_chunk_cp;
  jmem_cpointer_t last_chunk_cp;
  ecma_length_t item_count;
} ecma_collection_header_t;
typedef struct
{
  ecma_value_t items[5 + 1];
} ecma_collection_chunk_t;
typedef enum
{
  ECMA_DIRECT_STRING_PTR = 0,
  ECMA_DIRECT_STRING_MAGIC = 1,
  ECMA_DIRECT_STRING_UINT = 2,
  ECMA_DIRECT_STRING_MAGIC_EX = 3,
} ecma_direct_string_type_t;
typedef enum
{
  ECMA_STRING_CONTAINER_HEAP_UTF8_STRING,
  ECMA_STRING_CONTAINER_HEAP_LONG_UTF8_STRING,
  ECMA_STRING_CONTAINER_UINT32_IN_DESC,
  ECMA_STRING_CONTAINER_MAGIC_STRING_EX,
  ECMA_STRING_LITERAL_NUMBER,
  ECMA_STRING_CONTAINER__MAX = ECMA_STRING_LITERAL_NUMBER
} ecma_string_container_t;
typedef struct
{
  uint16_t refs_and_container;
  lit_string_hash_t hash;
  union
  {
    struct
    {
      uint16_t size;
      uint16_t length;
    } utf8_string;
    lit_utf8_size_t long_utf8_string_size;
    uint32_t uint32_number;
    uint32_t magic_string_ex_id;
    ecma_value_t lit_number;
    uint32_t common_uint32_field;
  } u;
} ecma_string_t;
typedef struct
{
  ecma_string_t header;
  lit_utf8_size_t long_utf8_string_length;
} ecma_long_string_t;
typedef struct
{
  uint32_t refs_and_flags;
  ecma_value_t value;
} ecma_error_reference_t;
typedef struct
{
  jmem_cpointer_t next_cp;
  jmem_cpointer_t values[3];
} ecma_lit_storage_item_t;
typedef struct
{
  ecma_property_t *prop_p;
  jmem_cpointer_t object_cp;
  jmem_cpointer_t prop_name_cp;
} ecma_lcache_hash_entry_t;
typedef enum
{
  ECMA_ARRAYBUFFER_INTERNAL_MEMORY = 0u,
  ECMA_ARRAYBUFFER_EXTERNAL_MEMORY = (1u << 0),
} ecma_arraybuffer_extra_flag_t;
typedef struct
{
  ecma_extended_object_t extended_object;
  void *buffer_p;
  ecma_object_native_free_callback_t free_cb;
} ecma_arraybuffer_external_info;
typedef struct
{
  ecma_extended_object_t extended_object;
  ecma_length_t byte_offset;
  ecma_length_t array_length;
} ecma_extended_typedarray_object_t;
typedef enum
{
  RE_OP_EOF,
  RE_OP_CAPTURE_GROUP_START,
  RE_OP_CAPTURE_GREEDY_ZERO_GROUP_START,
  RE_OP_CAPTURE_NON_GREEDY_ZERO_GROUP_START,
  RE_OP_CAPTURE_GREEDY_GROUP_END,
  RE_OP_CAPTURE_NON_GREEDY_GROUP_END,
  RE_OP_NON_CAPTURE_GROUP_START,
  RE_OP_NON_CAPTURE_GREEDY_ZERO_GROUP_START,
  RE_OP_NON_CAPTURE_NON_GREEDY_ZERO_GROUP_START,
  RE_OP_NON_CAPTURE_GREEDY_GROUP_END,
  RE_OP_NON_CAPTURE_NON_GREEDY_GROUP_END,
  RE_OP_MATCH,
  RE_OP_CHAR,
  RE_OP_SAVE_AT_START,
  RE_OP_SAVE_AND_MATCH,
  RE_OP_PERIOD,
  RE_OP_ALTERNATIVE,
  RE_OP_GREEDY_ITERATOR,
  RE_OP_NON_GREEDY_ITERATOR,
  RE_OP_ASSERT_START,
  RE_OP_ASSERT_END,
  RE_OP_ASSERT_WORD_BOUNDARY,
  RE_OP_ASSERT_NOT_WORD_BOUNDARY,
  RE_OP_LOOKAHEAD_POS,
  RE_OP_LOOKAHEAD_NEG,
  RE_OP_BACKREFERENCE,
  RE_OP_CHAR_CLASS,
  RE_OP_INV_CHAR_CLASS
} re_opcode_t;
typedef struct
{
  ecma_compiled_code_t header;
  ecma_value_t pattern;
  uint32_t num_of_captures;
  uint32_t num_of_non_captures;
} re_compiled_code_t;
typedef struct
{
  uint8_t *block_start_p;
  uint8_t *block_end_p;
  uint8_t *current_p;
} re_bytecode_ctx_t;
re_opcode_t re_get_opcode (uint8_t **bc_p);
ecma_char_t re_get_char (uint8_t **bc_p);
uint32_t re_get_value (uint8_t **bc_p);
uint32_t  re_get_bytecode_length (re_bytecode_ctx_t *bc_ctx_p);
void re_append_opcode (re_bytecode_ctx_t *bc_ctx_p, re_opcode_t opcode);
void re_append_u32 (re_bytecode_ctx_t *bc_ctx_p, uint32_t value);
void re_append_char (re_bytecode_ctx_t *bc_ctx_p, ecma_char_t input_char);
void re_append_jump_offset (re_bytecode_ctx_t *bc_ctx_p, uint32_t value);
void re_insert_opcode (re_bytecode_ctx_t *bc_ctx_p, uint32_t offset, re_opcode_t opcode);
void re_insert_u32 (re_bytecode_ctx_t *bc_ctx_p, uint32_t offset, uint32_t value);
void re_bytecode_list_insert (re_bytecode_ctx_t *bc_ctx_p, size_t offset, uint8_t *bytecode_p, size_t length);
typedef enum
{
  RE_TOK_EOF,
  RE_TOK_BACKREFERENCE,
  RE_TOK_CHAR,
  RE_TOK_ALTERNATIVE,
  RE_TOK_ASSERT_START,
  RE_TOK_ASSERT_END,
  RE_TOK_PERIOD,
  RE_TOK_START_CAPTURE_GROUP,
  RE_TOK_START_NON_CAPTURE_GROUP,
  RE_TOK_END_GROUP,
  RE_TOK_ASSERT_START_POS_LOOKAHEAD,
  RE_TOK_ASSERT_START_NEG_LOOKAHEAD,
  RE_TOK_ASSERT_WORD_BOUNDARY,
  RE_TOK_ASSERT_NOT_WORD_BOUNDARY,
  RE_TOK_DIGIT,
  RE_TOK_NOT_DIGIT,
  RE_TOK_WHITE,
  RE_TOK_NOT_WHITE,
  RE_TOK_WORD_CHAR,
  RE_TOK_NOT_WORD_CHAR,
  RE_TOK_START_CHAR_CLASS,
  RE_TOK_START_INV_CHAR_CLASS,
} re_token_type_t;
typedef struct
{
  re_token_type_t type;
  uint32_t value;
  uint32_t qmin;
  uint32_t qmax;
  _Bool greedy;
} re_token_t;
typedef struct
{
  const lit_utf8_byte_t *input_start_p;
  const lit_utf8_byte_t *input_curr_p;
  const lit_utf8_byte_t *input_end_p;
  int num_of_groups;
  uint32_t num_of_classes;
} re_parser_ctx_t;
typedef void (*re_char_class_callback) (void *re_ctx_p, ecma_char_t start, ecma_char_t end);
ecma_value_t
re_parse_char_class (re_parser_ctx_t *parser_ctx_p, re_char_class_callback append_char_class, void *re_ctx_p,
                     re_token_t *out_token_p);
ecma_value_t
re_parse_next_token (re_parser_ctx_t *parser_ctx_p, re_token_t *out_token_p);
typedef struct
{
  uint16_t flags;
  uint32_t num_of_captures;
  uint32_t num_of_non_captures;
  uint32_t highest_backref;
  re_bytecode_ctx_t *bytecode_ctx_p;
  re_token_t current_token;
  re_parser_ctx_t *parser_ctx_p;
} re_compiler_ctx_t;
ecma_value_t
re_compile_bytecode (const re_compiled_code_t **out_bytecode_p, ecma_string_t *pattern_str_p, uint16_t flags);
void re_cache_gc_run (void);
typedef enum
{
  RE_FLAG_GLOBAL = (1u << 1),
  RE_FLAG_IGNORE_CASE = (1u << 2),
  RE_FLAG_MULTILINE = (1u << 3)
} re_flags_t;
typedef struct
{
  const lit_utf8_byte_t **saved_p;
  const lit_utf8_byte_t *input_start_p;
  const lit_utf8_byte_t *input_end_p;
  uint32_t num_of_captures;
  uint32_t num_of_non_captures;
  uint32_t *num_of_iterations_p;
  uint16_t flags;
} re_matcher_ctx_t;
ecma_value_t ecma_op_create_regexp_object_from_bytecode (re_compiled_code_t *bytecode_p);
ecma_value_t ecma_op_create_regexp_object (ecma_string_t *pattern_p, uint16_t flags);
ecma_value_t ecma_regexp_exec_helper (ecma_value_t regexp_value, ecma_value_t input_string, _Bool ignore_global);
ecma_value_t ecma_regexp_read_pattern_str_helper (ecma_value_t pattern_arg, ecma_string_t **pattern_string_p);
ecma_char_t re_canonicalize (ecma_char_t ch, _Bool is_ignorecase);
void re_set_result_array_properties (ecma_object_t *array_obj_p, ecma_string_t *input_str_p, uint32_t num_of_elements,
                                     int32_t index);
ecma_value_t re_parse_regexp_flags (ecma_string_t *flags_str_p, uint16_t *flags_p);
void re_initialize_props (ecma_object_t *re_obj_p, ecma_string_t *source_p, uint16_t flags);
typedef enum
{
  LEXER_IDENT_LITERAL = 0,
  LEXER_STRING_LITERAL = 1,
  LEXER_NUMBER_LITERAL = 2,
  LEXER_FUNCTION_LITERAL = 3,
  LEXER_REGEXP_LITERAL = 4,
  LEXER_UNUSED_LITERAL = 5,
} lexer_literal_type_t;
typedef enum
{
  LEXER_FLAG_VAR = (1 << 0),
  LEXER_FLAG_NO_REG_STORE = (1 << 1),
  LEXER_FLAG_INITIALIZED = (1 << 2),
  LEXER_FLAG_FUNCTION_NAME = (1 << 3),
  LEXER_FLAG_FUNCTION_ARGUMENT = (1 << 4),
  LEXER_FLAG_UNUSED_IDENT = (1 << 5),
  LEXER_FLAG_SOURCE_PTR = (1 << 6),
  LEXER_FLAG_LATE_INIT = (1 << 7),
} lexer_literal_status_flags_t;
typedef uint16_t prop_length_t;
typedef struct
{
  union
  {
    ecma_value_t value;
    const uint8_t *char_p;
    ecma_compiled_code_t *bytecode_p;
    uint32_t source_data;
  } u;
  union
  {
    prop_length_t length;
    uint16_t index;
  } prop;
  uint8_t type;
  uint8_t status_flags;
} lexer_literal_t;
void util_free_literal (lexer_literal_t *literal_p);
ecma_object_t *ecma_alloc_object (void);
void ecma_dealloc_object (ecma_object_t *object_p);
ecma_extended_object_t *ecma_alloc_extended_object (size_t size);
void ecma_dealloc_extended_object (ecma_object_t *object_p, size_t size);
ecma_number_t *ecma_alloc_number (void);
void ecma_dealloc_number (ecma_number_t *number_p);
ecma_string_t *ecma_alloc_string (void);
void ecma_dealloc_string (ecma_string_t *string_p);
ecma_string_t *ecma_alloc_string_buffer (size_t size);
void ecma_dealloc_string_buffer (ecma_string_t *string_p, size_t size);
ecma_property_pair_t *ecma_alloc_property_pair (void);
void ecma_dealloc_property_pair (ecma_property_pair_t *property_pair_p);
typedef enum
{
  ECMA_ARRAY_OBJECT_SET_LENGTH_FLAG_IS_THROW = 1u << 0,
  ECMA_ARRAY_OBJECT_SET_LENGTH_FLAG_REJECT = 1u << 1,
  ECMA_ARRAY_OBJECT_SET_LENGTH_FLAG_WRITABLE_DEFINED = 1u << 2,
  ECMA_ARRAY_OBJECT_SET_LENGTH_FLAG_WRITABLE = 1u << 3,
} ecma_array_object_set_length_flags_t;
ecma_value_t
ecma_op_create_array_object (const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len,
                             _Bool is_treat_single_arg_as_length);
ecma_value_t
ecma_op_create_array_object_by_constructor (const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len,
                                            _Bool is_treat_single_arg_as_length, ecma_object_t *object_p);
ecma_value_t
ecma_op_array_object_set_length (ecma_object_t *object_p, ecma_value_t new_value, uint32_t flags);
ecma_value_t
ecma_op_array_object_define_own_property (ecma_object_t *object_p, ecma_string_t *property_name_p,
                                          const ecma_property_descriptor_t *property_desc_p, _Bool is_throw);
void
ecma_op_array_list_lazy_property_names (ecma_object_t *obj_p, _Bool separate_enumerable,
                                        ecma_collection_header_t *main_collection_p,
                                        ecma_collection_header_t *non_enum_collection_p);
typedef enum
{
ECMA_BUILTIN_ID_OBJECT,
ECMA_BUILTIN_ID_ARRAY,
ECMA_BUILTIN_ID_STRING,
ECMA_BUILTIN_ID_BOOLEAN,
ECMA_BUILTIN_ID_NUMBER,
ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
ECMA_BUILTIN_ID_FUNCTION,
ECMA_BUILTIN_ID_DATE,
ECMA_BUILTIN_ID_REGEXP,
ECMA_BUILTIN_ID_ERROR,
ECMA_BUILTIN_ID_EVAL_ERROR,
ECMA_BUILTIN_ID_RANGE_ERROR,
ECMA_BUILTIN_ID_REFERENCE_ERROR,
ECMA_BUILTIN_ID_SYNTAX_ERROR,
ECMA_BUILTIN_ID_TYPE_ERROR,
ECMA_BUILTIN_ID_URI_ERROR,
ECMA_BUILTIN_ID_TYPE_ERROR_THROWER,
ECMA_BUILTIN_ID_ARRAYBUFFER,
ECMA_BUILTIN_ID_TYPEDARRAY,
ECMA_BUILTIN_ID_INT8ARRAY,
ECMA_BUILTIN_ID_UINT8ARRAY,
ECMA_BUILTIN_ID_INT16ARRAY,
ECMA_BUILTIN_ID_UINT16ARRAY,
ECMA_BUILTIN_ID_INT32ARRAY,
ECMA_BUILTIN_ID_UINT32ARRAY,
ECMA_BUILTIN_ID_FLOAT32ARRAY,
ECMA_BUILTIN_ID_FLOAT64ARRAY,
ECMA_BUILTIN_ID_UINT8CLAMPEDARRAY,
ECMA_BUILTIN_ID_PROMISE,
ECMA_BUILTIN_ID_MAP,
ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
ECMA_BUILTIN_ID_ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_STRING_PROTOTYPE,
ECMA_BUILTIN_ID_BOOLEAN_PROTOTYPE,
ECMA_BUILTIN_ID_NUMBER_PROTOTYPE,
ECMA_BUILTIN_ID_MATH,
ECMA_BUILTIN_ID_JSON,
ECMA_BUILTIN_ID_DATE_PROTOTYPE,
ECMA_BUILTIN_ID_REGEXP_PROTOTYPE,
ECMA_BUILTIN_ID_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_EVAL_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_RANGE_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_REFERENCE_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_SYNTAX_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_TYPE_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_URI_ERROR_PROTOTYPE,
ECMA_BUILTIN_ID_ARRAYBUFFER_PROTOTYPE,
ECMA_BUILTIN_ID_TYPEDARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_INT8ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_UINT8ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_INT16ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_UINT16ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_INT32ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_UINT32ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_FLOAT32ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_FLOAT64ARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_UINT8CLAMPEDARRAY_PROTOTYPE,
ECMA_BUILTIN_ID_PROMISE_PROTOTYPE,
ECMA_BUILTIN_ID_MAP_PROTOTYPE,
ECMA_BUILTIN_ID_GLOBAL,
  ECMA_BUILTIN_ID__COUNT
} ecma_builtin_id_t;
void ecma_finalize_builtins (void);
ecma_value_t
ecma_builtin_dispatch_call (ecma_object_t *obj_p, ecma_value_t this_arg_value,
                            const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_value_t
ecma_builtin_dispatch_construct (ecma_object_t *obj_p,
                                 const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_property_t *
ecma_builtin_try_to_instantiate_property (ecma_object_t *object_p, ecma_string_t *string_p);
void
ecma_builtin_list_lazy_property_names (ecma_object_t *object_p,
                                       _Bool separate_enumerable,
                                       ecma_collection_header_t *main_collection_p,
                                       ecma_collection_header_t *non_enum_collection_p);
_Bool
ecma_builtin_is (ecma_object_t *obj_p, ecma_builtin_id_t builtin_id);
ecma_object_t *
ecma_builtin_get (ecma_builtin_id_t builtin_id);
ecma_object_t *
ecma_builtin_get_global (void);
_Bool
ecma_builtin_function_is_routine (ecma_object_t *func_obj_p);
_Bool lit_is_valid_utf8_string (const lit_utf8_byte_t *utf8_buf_p, lit_utf8_size_t buf_size);
_Bool lit_is_valid_cesu8_string (const lit_utf8_byte_t *cesu8_buf_p, lit_utf8_size_t buf_size);
_Bool lit_is_code_point_utf16_low_surrogate (lit_code_point_t code_point);
_Bool lit_is_code_point_utf16_high_surrogate (lit_code_point_t code_point);
lit_utf8_size_t lit_zt_utf8_string_size (const lit_utf8_byte_t *utf8_str_p);
lit_utf8_size_t lit_get_utf8_size_of_cesu8_string (const lit_utf8_byte_t *cesu8_buf_p, lit_utf8_size_t cesu8_buf_size);
ecma_length_t lit_utf8_string_length (const lit_utf8_byte_t *utf8_buf_p, lit_utf8_size_t utf8_buf_size);
ecma_length_t lit_get_utf8_length_of_cesu8_string (const lit_utf8_byte_t *cesu8_buf_p, lit_utf8_size_t cesu8_buf_size);
lit_string_hash_t lit_utf8_string_calc_hash (const lit_utf8_byte_t *utf8_buf_p, lit_utf8_size_t utf8_buf_size);
lit_string_hash_t lit_utf8_string_hash_combine (lit_string_hash_t hash_basis, const lit_utf8_byte_t *utf8_buf_p,
                                                lit_utf8_size_t utf8_buf_size);
ecma_char_t lit_utf8_string_code_unit_at (const lit_utf8_byte_t *utf8_buf_p, lit_utf8_size_t utf8_buf_size,
                                          ecma_length_t code_unit_offset);
lit_utf8_size_t lit_get_unicode_char_size_by_utf8_first_byte (const lit_utf8_byte_t first_byte);
lit_utf8_size_t lit_code_unit_to_utf8 (ecma_char_t code_unit, lit_utf8_byte_t *buf_p);
lit_utf8_size_t lit_code_point_to_utf8 (lit_code_point_t code_point, lit_utf8_byte_t *buf);
lit_utf8_size_t lit_code_point_to_cesu8 (lit_code_point_t code_point, lit_utf8_byte_t *buf);
lit_utf8_size_t lit_convert_cesu8_string_to_utf8_string (const lit_utf8_byte_t *cesu8_string,
                                                         lit_utf8_size_t cesu8_size,
                                                         lit_utf8_byte_t *utf8_string,
                                                         lit_utf8_size_t utf8_size);
lit_code_point_t lit_convert_surrogate_pair_to_code_point (ecma_char_t high_surrogate, ecma_char_t low_surrogate);
_Bool lit_compare_utf8_strings_relational (const lit_utf8_byte_t *string1_p, lit_utf8_size_t string1_size,
                                          const lit_utf8_byte_t *string2_p, lit_utf8_size_t string2_size);
lit_utf8_size_t lit_read_code_point_from_utf8 (const lit_utf8_byte_t *buf_p, lit_utf8_size_t buf_size,
                                               lit_code_point_t *code_point);
lit_utf8_size_t lit_read_code_unit_from_utf8 (const lit_utf8_byte_t *buf_p,
                                              ecma_char_t *code_point);
lit_utf8_size_t lit_read_prev_code_unit_from_utf8 (const lit_utf8_byte_t *buf_p,
                                                   ecma_char_t *code_point);
ecma_char_t lit_utf8_read_next (const lit_utf8_byte_t **buf_p);
ecma_char_t lit_utf8_read_prev (const lit_utf8_byte_t **buf_p);
ecma_char_t lit_utf8_peek_next (const lit_utf8_byte_t *buf_p);
ecma_char_t lit_utf8_peek_prev (const lit_utf8_byte_t *buf_p);
void lit_utf8_incr (const lit_utf8_byte_t **buf_p);
void lit_utf8_decr (const lit_utf8_byte_t **buf_p);
typedef enum
{
  ECMA_STRING_FLAG_EMPTY = 0,
  ECMA_STRING_FLAG_IS_ASCII,
  ECMA_STRING_FLAG_MUST_BE_FREED
} ecma_string_flag_t;
_Bool  ecma_is_value_direct (ecma_value_t value);
_Bool  ecma_is_value_simple (ecma_value_t value);
_Bool  ecma_is_value_empty (ecma_value_t value);
_Bool  ecma_is_value_undefined (ecma_value_t value);
_Bool  ecma_is_value_null (ecma_value_t value);
_Bool  ecma_is_value_boolean (ecma_value_t value);
_Bool  ecma_is_value_true (ecma_value_t value);
_Bool  ecma_is_value_false (ecma_value_t value);
_Bool  ecma_is_value_found (ecma_value_t value);
_Bool  ecma_is_value_array_hole (ecma_value_t value);
_Bool  ecma_is_value_integer_number (ecma_value_t value);
_Bool  ecma_are_values_integer_numbers (ecma_value_t first_value, ecma_value_t second_value);
_Bool  ecma_is_value_float_number (ecma_value_t value);
_Bool  ecma_is_value_number (ecma_value_t value);
_Bool  ecma_is_value_string (ecma_value_t value);
_Bool  ecma_is_value_direct_string (ecma_value_t value);
_Bool  ecma_is_value_non_direct_string (ecma_value_t value);
_Bool  ecma_is_value_object (ecma_value_t value);
_Bool  ecma_is_value_error_reference (ecma_value_t value);
_Bool  ecma_is_value_pointer (ecma_value_t value);
void ecma_check_value_type_is_spec_defined (ecma_value_t value);
ecma_value_t  ecma_make_boolean_value (_Bool boolean_value);
ecma_value_t  ecma_make_integer_value (ecma_integer_value_t integer_value);
ecma_value_t ecma_make_nan_value (void);
ecma_value_t ecma_make_number_value (ecma_number_t ecma_number);
ecma_value_t ecma_make_int32_value (int32_t int32_number);
ecma_value_t ecma_make_uint32_value (uint32_t uint32_number);
ecma_value_t  ecma_make_string_value (const ecma_string_t *ecma_string_p);
ecma_value_t  ecma_make_magic_string_value (lit_magic_string_id_t id);
ecma_value_t  ecma_make_object_value (const ecma_object_t *object_p);
ecma_value_t  ecma_make_error_reference_value (const ecma_error_reference_t *error_ref_p);
ecma_value_t  ecma_make_pointer_value (const void *any_p);
ecma_integer_value_t  ecma_get_integer_from_value (ecma_value_t value);
ecma_number_t  ecma_get_float_from_value (ecma_value_t value);
ecma_number_t  ecma_get_number_from_value (ecma_value_t value);
ecma_string_t  *ecma_get_string_from_value (ecma_value_t value);
ecma_object_t  *ecma_get_object_from_value (ecma_value_t value);
ecma_error_reference_t  *ecma_get_error_reference_from_value (ecma_value_t value);
void *  ecma_get_pointer_from_value (ecma_value_t value);
ecma_value_t  ecma_invert_boolean_value (ecma_value_t value);
ecma_value_t ecma_copy_value (ecma_value_t value);
ecma_value_t ecma_fast_copy_value (ecma_value_t value);
ecma_value_t ecma_copy_value_if_not_object (ecma_value_t value);
ecma_value_t ecma_update_float_number (ecma_value_t float_value, ecma_number_t new_number);
void ecma_value_assign_value (ecma_value_t *value_p, ecma_value_t ecma_value);
void ecma_value_assign_number (ecma_value_t *value_p, ecma_number_t ecma_number);
void ecma_free_value (ecma_value_t value);
void ecma_fast_free_value (ecma_value_t value);
void ecma_free_value_if_not_object (ecma_value_t value);
lit_magic_string_id_t ecma_get_typeof_lit_id (ecma_value_t value);
ecma_string_t *ecma_new_ecma_string_from_utf8 (const lit_utf8_byte_t *string_p, lit_utf8_size_t string_size);
ecma_string_t *ecma_new_ecma_string_from_utf8_converted_to_cesu8 (const lit_utf8_byte_t *string_p,
                                                                  lit_utf8_size_t string_size);
ecma_string_t *ecma_new_ecma_string_from_code_unit (ecma_char_t code_unit);
ecma_string_t *ecma_new_ecma_string_from_uint32 (uint32_t uint32_number);
ecma_string_t *ecma_get_ecma_string_from_uint32 (uint32_t uint32_number);
ecma_string_t *ecma_new_ecma_string_from_number (ecma_number_t num);
ecma_string_t *ecma_get_magic_string (lit_magic_string_id_t id);
ecma_string_t *ecma_append_chars_to_string (ecma_string_t *string1_p,
                                            const lit_utf8_byte_t *cesu8_string2_p,
                                            lit_utf8_size_t cesu8_string2_size,
                                            lit_utf8_size_t cesu8_string2_length);
ecma_string_t *ecma_concat_ecma_strings (ecma_string_t *string1_p, ecma_string_t *string2_p);
ecma_string_t *ecma_append_magic_string_to_string (ecma_string_t *string1_p, lit_magic_string_id_t string2_id);
void ecma_ref_ecma_string (ecma_string_t *string_p);
void ecma_deref_ecma_string (ecma_string_t *string_p);
ecma_number_t ecma_string_to_number (const ecma_string_t *str_p);
uint32_t ecma_string_get_array_index (const ecma_string_t *str_p);
lit_utf8_size_t
ecma_string_copy_to_cesu8_buffer (const ecma_string_t *string_desc_p,
                                  lit_utf8_byte_t *buffer_p,
                                  lit_utf8_size_t buffer_size);
lit_utf8_size_t
ecma_string_copy_to_utf8_buffer (const ecma_string_t *string_desc_p,
                                 lit_utf8_byte_t *buffer_p,
                                 lit_utf8_size_t buffer_size);
lit_utf8_size_t
ecma_substring_copy_to_cesu8_buffer (const ecma_string_t *string_desc_p,
                                     ecma_length_t start_pos,
                                     ecma_length_t end_pos,
                                     lit_utf8_byte_t *buffer_p,
                                     lit_utf8_size_t buffer_size);
lit_utf8_size_t
ecma_substring_copy_to_utf8_buffer (const ecma_string_t *string_desc_p,
                                    ecma_length_t start_pos,
                                    ecma_length_t end_pos,
                                    lit_utf8_byte_t *buffer_p,
                                    lit_utf8_size_t buffer_size);
void ecma_string_to_utf8_bytes (const ecma_string_t *string_desc_p, lit_utf8_byte_t *buffer_p,
                                lit_utf8_size_t buffer_size);
const lit_utf8_byte_t *ecma_string_get_chars (const ecma_string_t *string_p, lit_utf8_size_t *size_p, uint8_t *flags_p);
_Bool ecma_compare_ecma_string_to_magic_id (const ecma_string_t *string_p, lit_magic_string_id_t id);
_Bool ecma_string_is_empty (const ecma_string_t *string_p);
_Bool ecma_string_is_length (const ecma_string_t *string_p);
jmem_cpointer_t ecma_string_to_property_name (ecma_string_t *prop_name_p, ecma_property_t *name_type_p);
ecma_string_t *ecma_string_from_property_name (ecma_property_t property, jmem_cpointer_t prop_name_cp);
lit_string_hash_t ecma_string_get_property_name_hash (ecma_property_t property, jmem_cpointer_t prop_name_cp);
uint32_t ecma_string_get_property_index (ecma_property_t property, jmem_cpointer_t prop_name_cp);
_Bool ecma_string_compare_to_property_name (ecma_property_t property, jmem_cpointer_t prop_name_cp,
                                           const ecma_string_t *string_p);
_Bool ecma_compare_ecma_strings (const ecma_string_t *string1_p, const ecma_string_t *string2_p);
_Bool ecma_compare_ecma_non_direct_strings (const ecma_string_t *string1_p, const ecma_string_t *string2_p);
_Bool ecma_compare_ecma_strings_relational (const ecma_string_t *string1_p, const ecma_string_t *string2_p);
ecma_length_t ecma_string_get_length (const ecma_string_t *string_p);
ecma_length_t ecma_string_get_utf8_length (const ecma_string_t *string_p);
lit_utf8_size_t ecma_string_get_size (const ecma_string_t *string_p);
lit_utf8_size_t ecma_string_get_utf8_size (const ecma_string_t *string_p);
ecma_char_t ecma_string_get_char_at_pos (const ecma_string_t *string_p, ecma_length_t index);
lit_magic_string_id_t ecma_get_string_magic (const ecma_string_t *string_p);
lit_string_hash_t ecma_string_hash (const ecma_string_t *string_p);
ecma_string_t *ecma_string_substr (const ecma_string_t *string_p, ecma_length_t start_pos, ecma_length_t end_pos);
ecma_string_t *ecma_string_trim (const ecma_string_t *string_p);
ecma_number_t ecma_number_make_nan (void);
ecma_number_t ecma_number_make_infinity (_Bool sign);
_Bool ecma_number_is_nan (ecma_number_t num);
_Bool ecma_number_is_negative (ecma_number_t num);
_Bool ecma_number_is_zero (ecma_number_t num);
_Bool ecma_number_is_infinity (ecma_number_t num);
ecma_number_t
ecma_number_make_from_sign_mantissa_and_exponent (_Bool sign, uint64_t mantissa, int32_t exponent);
ecma_number_t ecma_number_get_prev (ecma_number_t num);
ecma_number_t ecma_number_get_next (ecma_number_t num);
ecma_number_t ecma_number_trunc (ecma_number_t num);
ecma_number_t ecma_number_calc_remainder (ecma_number_t left_num, ecma_number_t right_num);
ecma_value_t ecma_integer_multiply (ecma_integer_value_t left_integer, ecma_integer_value_t right_integer);
lit_utf8_size_t ecma_number_to_decimal (ecma_number_t num, lit_utf8_byte_t *out_digits_p, int32_t *out_decimal_exp_p);
lit_utf8_size_t ecma_number_to_binary_floating_point_number (ecma_number_t num,
                                                             lit_utf8_byte_t *out_digits_p,
                                                             int32_t *out_decimal_exp_p);
ecma_collection_header_t *ecma_new_values_collection (void);
void ecma_free_values_collection (ecma_collection_header_t *header_p, uint32_t flags);
void ecma_append_to_values_collection (ecma_collection_header_t *header_p, ecma_value_t v, uint32_t flags);
ecma_value_t *
ecma_collection_iterator_init (ecma_collection_header_t *header_p);
ecma_value_t *
ecma_collection_iterator_next (ecma_value_t *iterator_p);
ecma_object_t *ecma_create_object (ecma_object_t *prototype_object_p, size_t ext_object_size, ecma_object_type_t type);
ecma_object_t *ecma_create_decl_lex_env (ecma_object_t *outer_lexical_environment_p);
ecma_object_t *ecma_create_object_lex_env (ecma_object_t *outer_lexical_environment_p, ecma_object_t *binding_obj_p,
                                           ecma_lexical_environment_type_t type);
_Bool  ecma_is_lexical_environment (const ecma_object_t *object_p);
_Bool  ecma_get_object_extensible (const ecma_object_t *object_p);
void ecma_set_object_extensible (ecma_object_t *object_p, _Bool is_extensible);
ecma_object_type_t  ecma_get_object_type (const ecma_object_t *object_p);
ecma_object_t  *ecma_get_object_prototype (const ecma_object_t *object_p);
_Bool  ecma_get_object_is_builtin (const ecma_object_t *object_p);
void ecma_set_object_is_builtin (ecma_object_t *object_p);
uint8_t ecma_get_object_builtin_id (ecma_object_t *object_p);
ecma_lexical_environment_type_t  ecma_get_lex_env_type (const ecma_object_t *object_p);
ecma_object_t  *ecma_get_lex_env_outer_reference (const ecma_object_t *object_p);
ecma_property_header_t  *ecma_get_property_list (const ecma_object_t *object_p);
ecma_object_t  *ecma_get_lex_env_binding_object (const ecma_object_t *object_p);
ecma_property_value_t *
ecma_create_named_data_property (ecma_object_t *object_p, ecma_string_t *name_p, uint8_t prop_attributes,
                                 ecma_property_t **out_prop_p);
ecma_property_value_t *
ecma_create_named_accessor_property (ecma_object_t *object_p, ecma_string_t *name_p, ecma_object_t *get_p,
                                     ecma_object_t *set_p, uint8_t prop_attributes, ecma_property_t **out_prop_p);
ecma_property_t *
ecma_find_named_property (ecma_object_t *obj_p, ecma_string_t *name_p);
ecma_property_value_t *
ecma_get_named_data_property (ecma_object_t *obj_p, ecma_string_t *name_p);
void ecma_free_property (ecma_object_t *object_p, jmem_cpointer_t name_cp, ecma_property_t *property_p);
void ecma_delete_property (ecma_object_t *object_p, ecma_property_value_t *prop_value_p);
uint32_t ecma_delete_array_properties (ecma_object_t *object_p, uint32_t new_length, uint32_t old_length);
void ecma_named_data_property_assign_value (ecma_object_t *obj_p, ecma_property_value_t *prop_value_p,
                                            ecma_value_t value);
ecma_object_t *ecma_get_named_accessor_property_getter (const ecma_property_value_t *prop_value_p);
ecma_object_t *ecma_get_named_accessor_property_setter (const ecma_property_value_t *prop_value_p);
void ecma_set_named_accessor_property_getter (ecma_object_t *object_p, ecma_property_value_t *prop_value_p,
                                              ecma_object_t *getter_p);
void ecma_set_named_accessor_property_setter (ecma_object_t *object_p, ecma_property_value_t *prop_value_p,
                                              ecma_object_t *setter_p);
_Bool ecma_is_property_writable (ecma_property_t property);
void ecma_set_property_writable_attr (ecma_property_t *property_p, _Bool is_writable);
_Bool ecma_is_property_enumerable (ecma_property_t property);
void ecma_set_property_enumerable_attr (ecma_property_t *property_p, _Bool is_enumerable);
_Bool ecma_is_property_configurable (ecma_property_t property);
void ecma_set_property_configurable_attr (ecma_property_t *property_p, _Bool is_configurable);
_Bool ecma_is_property_lcached (ecma_property_t *property_p);
void ecma_set_property_lcached (ecma_property_t *property_p, _Bool is_lcached);
ecma_property_descriptor_t ecma_make_empty_property_descriptor (void);
void ecma_free_property_descriptor (ecma_property_descriptor_t *prop_desc_p);
ecma_value_t ecma_create_error_reference (ecma_value_t value, _Bool is_exception);
ecma_value_t ecma_create_error_reference_from_context (void);
ecma_value_t ecma_create_error_object_reference (ecma_object_t *object_p);
void ecma_ref_error_reference (ecma_error_reference_t *error_ref_p);
void ecma_deref_error_reference (ecma_error_reference_t *error_ref_p);
ecma_value_t ecma_clear_error_reference (ecma_value_t value, _Bool set_abort_flag);
void ecma_bytecode_ref (ecma_compiled_code_t *bytecode_p);
void ecma_bytecode_deref (ecma_compiled_code_t *bytecode_p);
_Bool ecma_create_native_pointer_property (ecma_object_t *obj_p, void *native_p, void *info_p);
ecma_native_pointer_t *ecma_get_native_pointer_value (ecma_object_t *obj_p);
ecma_number_t ecma_utf8_string_to_number (const lit_utf8_byte_t *str_p, lit_utf8_size_t str_size);
lit_utf8_size_t ecma_uint32_to_utf8_string (uint32_t value, lit_utf8_byte_t *out_buffer_p, lit_utf8_size_t buffer_size);
uint32_t ecma_number_to_uint32 (ecma_number_t num);
int32_t ecma_number_to_int32 (ecma_number_t num);
lit_utf8_size_t ecma_number_to_utf8_string (ecma_number_t num, lit_utf8_byte_t *buffer_p, lit_utf8_size_t buffer_size);
lit_utf8_size_t ecma_errol0_dtoa (double val, lit_utf8_byte_t *buffer_p, int32_t *exp_p);
ecma_value_t ecma_op_abstract_equality_compare (ecma_value_t x, ecma_value_t y);
_Bool ecma_op_strict_equality_compare (ecma_value_t x, ecma_value_t y);
ecma_value_t ecma_op_abstract_relational_compare (ecma_value_t x, ecma_value_t y, _Bool left_first);
typedef enum
{
  ECMA_PREFERRED_TYPE_NO,
  ECMA_PREFERRED_TYPE_NUMBER,
  ECMA_PREFERRED_TYPE_STRING
} ecma_preferred_type_hint_t;
ecma_value_t ecma_op_check_object_coercible (ecma_value_t value);
_Bool ecma_op_same_value (ecma_value_t x, ecma_value_t y);
ecma_value_t ecma_op_to_primitive (ecma_value_t value, ecma_preferred_type_hint_t preferred_type);
_Bool ecma_op_to_boolean (ecma_value_t value);
ecma_value_t ecma_op_to_number (ecma_value_t value);
ecma_value_t ecma_get_number (ecma_value_t value, ecma_number_t *number_p);
ecma_value_t ecma_op_to_string (ecma_value_t value);
ecma_value_t ecma_op_to_object (ecma_value_t value);
ecma_object_t *ecma_op_from_property_descriptor (const ecma_property_descriptor_t *src_prop_desc_p);
ecma_value_t ecma_op_to_property_descriptor (ecma_value_t obj_value, ecma_property_descriptor_t *out_prop_desc_p);
typedef enum
{
  ECMA_ERROR_NONE,
  ECMA_ERROR_COMMON,
  ECMA_ERROR_EVAL,
  ECMA_ERROR_RANGE,
  ECMA_ERROR_REFERENCE,
  ECMA_ERROR_SYNTAX,
  ECMA_ERROR_TYPE,
  ECMA_ERROR_URI
} ecma_standard_error_t;
ecma_standard_error_t ecma_get_error_type (ecma_object_t *error_object);
ecma_object_t *ecma_new_standard_error (ecma_standard_error_t error_type);
ecma_object_t *ecma_new_standard_error_with_message (ecma_standard_error_t error_type, ecma_string_t *message_string_p);
ecma_value_t ecma_raise_common_error (const char *msg_p);
ecma_value_t ecma_raise_range_error (const char *msg_p);
ecma_value_t ecma_raise_reference_error (const char *msg_p);
ecma_value_t ecma_raise_syntax_error (const char *msg_p);
ecma_value_t ecma_raise_type_error (const char *msg_p);
ecma_value_t ecma_raise_uri_error (const char *msg_p);
typedef struct
{
  ecma_compiled_code_t header;
  uint8_t stack_limit;
  uint8_t argument_end;
  uint8_t register_end;
  uint8_t ident_end;
  uint8_t const_literal_end;
  uint8_t literal_end;
} cbc_uint8_arguments_t;
typedef struct
{
  ecma_compiled_code_t header;
  uint16_t stack_limit;
  uint16_t argument_end;
  uint16_t register_end;
  uint16_t ident_end;
  uint16_t const_literal_end;
  uint16_t literal_end;
  uint16_t padding;
} cbc_uint16_arguments_t;
typedef enum
{
  CBC_CODE_FLAGS_FUNCTION = (1u << 0),
  CBC_CODE_FLAGS_FULL_LITERAL_ENCODING = (1u << 1),
  CBC_CODE_FLAGS_UINT16_ARGUMENTS = (1u << 2),
  CBC_CODE_FLAGS_STRICT_MODE = (1u << 3),
  CBC_CODE_FLAGS_ARGUMENTS_NEEDED = (1u << 4),
  CBC_CODE_FLAGS_LEXICAL_ENV_NOT_NEEDED = (1u << 5),
  CBC_CODE_FLAGS_ARROW_FUNCTION = (1u << 6),
  CBC_CODE_FLAGS_STATIC_FUNCTION = (1u << 7),
  CBC_CODE_FLAGS_DEBUGGER_IGNORE = (1u << 8),
  CBC_CODE_FLAGS_CONSTRUCTOR = (1u << 9),
} cbc_code_flags;
typedef enum
{
  CBC_EXT_OPCODE, CBC_JUMP_FORWARD, CBC_JUMP_FORWARD_2, CBC_JUMP_FORWARD_3, CBC_POP, CBC_JUMP_BACKWARD, CBC_JUMP_BACKWARD_2, CBC_JUMP_BACKWARD_3, CBC_POP_BLOCK, CBC_BRANCH_IF_TRUE_FORWARD, CBC_BRANCH_IF_TRUE_FORWARD_2, CBC_BRANCH_IF_TRUE_FORWARD_3, CBC_THROW, CBC_BRANCH_IF_TRUE_BACKWARD, CBC_BRANCH_IF_TRUE_BACKWARD_2, CBC_BRANCH_IF_TRUE_BACKWARD_3, CBC_CONTEXT_END, CBC_BRANCH_IF_FALSE_FORWARD, CBC_BRANCH_IF_FALSE_FORWARD_2, CBC_BRANCH_IF_FALSE_FORWARD_3, CBC_CREATE_OBJECT, CBC_BRANCH_IF_FALSE_BACKWARD, CBC_BRANCH_IF_FALSE_BACKWARD_2, CBC_BRANCH_IF_FALSE_BACKWARD_3, CBC_SET_PROPERTY, CBC_JUMP_FORWARD_EXIT_CONTEXT, CBC_JUMP_FORWARD_EXIT_CONTEXT_2, CBC_JUMP_FORWARD_EXIT_CONTEXT_3, CBC_CREATE_ARRAY, CBC_BRANCH_IF_LOGICAL_TRUE, CBC_BRANCH_IF_LOGICAL_TRUE_2, CBC_BRANCH_IF_LOGICAL_TRUE_3, CBC_ARRAY_APPEND, CBC_BRANCH_IF_LOGICAL_FALSE, CBC_BRANCH_IF_LOGICAL_FALSE_2, CBC_BRANCH_IF_LOGICAL_FALSE_3, CBC_PUSH_ELISION, CBC_BRANCH_IF_STRICT_EQUAL, CBC_BRANCH_IF_STRICT_EQUAL_2, CBC_BRANCH_IF_STRICT_EQUAL_3, CBC_PUSH_LITERAL, CBC_PUSH_TWO_LITERALS, CBC_PUSH_THREE_LITERALS, CBC_PUSH_UNDEFINED, CBC_PUSH_TRUE, CBC_PUSH_FALSE, CBC_PUSH_NULL, CBC_PUSH_THIS, CBC_PUSH_THIS_LITERAL, CBC_PUSH_NUMBER_0, CBC_PUSH_NUMBER_POS_BYTE, CBC_PUSH_NUMBER_NEG_BYTE, CBC_PUSH_PROP, CBC_PUSH_PROP_LITERAL, CBC_PUSH_PROP_LITERAL_LITERAL, CBC_PUSH_PROP_THIS_LITERAL, CBC_PUSH_IDENT_REFERENCE, CBC_PUSH_PROP_REFERENCE, CBC_PUSH_PROP_LITERAL_REFERENCE, CBC_PUSH_PROP_LITERAL_LITERAL_REFERENCE, CBC_PUSH_PROP_THIS_LITERAL_REFERENCE, CBC_NEW, CBC_NEW0, CBC_NEW1, CBC_EVAL, CBC_DEFINE_VARS, CBC_INITIALIZE_VAR, CBC_INITIALIZE_VARS, CBC_SET_BYTECODE_PTR, CBC_RETURN, CBC_RETURN_WITH_BLOCK, CBC_RETURN_WITH_LITERAL, CBC_SET_LITERAL_PROPERTY, CBC_BREAKPOINT_ENABLED, CBC_BREAKPOINT_DISABLED, CBC_PLUS, CBC_PLUS_LITERAL, CBC_NEGATE, CBC_NEGATE_LITERAL, CBC_LOGICAL_NOT, CBC_LOGICAL_NOT_LITERAL, CBC_BIT_NOT, CBC_BIT_NOT_LITERAL, CBC_VOID, CBC_VOID_LITERAL, CBC_TYPEOF, CBC_TYPEOF_IDENT, CBC_BIT_OR, CBC_BIT_OR_RIGHT_LITERAL, CBC_BIT_OR_TWO_LITERALS, CBC_BIT_XOR, CBC_BIT_XOR_RIGHT_LITERAL, CBC_BIT_XOR_TWO_LITERALS, CBC_BIT_AND, CBC_BIT_AND_RIGHT_LITERAL, CBC_BIT_AND_TWO_LITERALS, CBC_EQUAL, CBC_EQUAL_RIGHT_LITERAL, CBC_EQUAL_TWO_LITERALS, CBC_NOT_EQUAL, CBC_NOT_EQUAL_RIGHT_LITERAL, CBC_NOT_EQUAL_TWO_LITERALS, CBC_STRICT_EQUAL, CBC_STRICT_EQUAL_RIGHT_LITERAL, CBC_STRICT_EQUAL_TWO_LITERALS, CBC_STRICT_NOT_EQUAL, CBC_STRICT_NOT_EQUAL_RIGHT_LITERAL, CBC_STRICT_NOT_EQUAL_TWO_LITERALS, CBC_LESS, CBC_LESS_RIGHT_LITERAL, CBC_LESS_TWO_LITERALS, CBC_GREATER, CBC_GREATER_RIGHT_LITERAL, CBC_GREATER_TWO_LITERALS, CBC_LESS_EQUAL, CBC_LESS_EQUAL_RIGHT_LITERAL, CBC_LESS_EQUAL_TWO_LITERALS, CBC_GREATER_EQUAL, CBC_GREATER_EQUAL_RIGHT_LITERAL, CBC_GREATER_EQUAL_TWO_LITERALS, CBC_IN, CBC_IN_RIGHT_LITERAL, CBC_IN_TWO_LITERALS, CBC_INSTANCEOF, CBC_INSTANCEOF_RIGHT_LITERAL, CBC_INSTANCEOF_TWO_LITERALS, CBC_LEFT_SHIFT, CBC_LEFT_SHIFT_RIGHT_LITERAL, CBC_LEFT_SHIFT_TWO_LITERALS, CBC_RIGHT_SHIFT, CBC_RIGHT_SHIFT_RIGHT_LITERAL, CBC_RIGHT_SHIFT_TWO_LITERALS, CBC_UNS_RIGHT_SHIFT, CBC_UNS_RIGHT_SHIFT_RIGHT_LITERAL, CBC_UNS_RIGHT_SHIFT_TWO_LITERALS, CBC_ADD, CBC_ADD_RIGHT_LITERAL, CBC_ADD_TWO_LITERALS, CBC_SUBTRACT, CBC_SUBTRACT_RIGHT_LITERAL, CBC_SUBTRACT_TWO_LITERALS, CBC_MULTIPLY, CBC_MULTIPLY_RIGHT_LITERAL, CBC_MULTIPLY_TWO_LITERALS, CBC_DIVIDE, CBC_DIVIDE_RIGHT_LITERAL, CBC_DIVIDE_TWO_LITERALS, CBC_MODULO, CBC_MODULO_RIGHT_LITERAL, CBC_MODULO_TWO_LITERALS, CBC_DELETE_PUSH_RESULT, CBC_DELETE_IDENT_PUSH_RESULT, CBC_PRE_INCR, CBC_PRE_INCR_PUSH_RESULT, CBC_PRE_INCR_BLOCK, CBC_PRE_INCR_IDENT, CBC_PRE_INCR_IDENT_PUSH_RESULT, CBC_PRE_INCR_IDENT_BLOCK, CBC_PRE_DECR, CBC_PRE_DECR_PUSH_RESULT, CBC_PRE_DECR_BLOCK, CBC_PRE_DECR_IDENT, CBC_PRE_DECR_IDENT_PUSH_RESULT, CBC_PRE_DECR_IDENT_BLOCK, CBC_POST_INCR, CBC_POST_INCR_PUSH_RESULT, CBC_POST_INCR_BLOCK, CBC_POST_INCR_IDENT, CBC_POST_INCR_IDENT_PUSH_RESULT, CBC_POST_INCR_IDENT_BLOCK, CBC_POST_DECR, CBC_POST_DECR_PUSH_RESULT, CBC_POST_DECR_BLOCK, CBC_POST_DECR_IDENT, CBC_POST_DECR_IDENT_PUSH_RESULT, CBC_POST_DECR_IDENT_BLOCK, CBC_CALL, CBC_CALL_PUSH_RESULT, CBC_CALL_BLOCK, CBC_CALL_PROP, CBC_CALL_PROP_PUSH_RESULT, CBC_CALL_PROP_BLOCK, CBC_CALL0, CBC_CALL0_PUSH_RESULT, CBC_CALL0_BLOCK, CBC_CALL0_PROP, CBC_CALL0_PROP_PUSH_RESULT, CBC_CALL0_PROP_BLOCK, CBC_CALL1, CBC_CALL1_PUSH_RESULT, CBC_CALL1_BLOCK, CBC_CALL1_PROP, CBC_CALL1_PROP_PUSH_RESULT, CBC_CALL1_PROP_BLOCK, CBC_CALL2, CBC_CALL2_PUSH_RESULT, CBC_CALL2_BLOCK, CBC_CALL2_PROP, CBC_CALL2_PROP_PUSH_RESULT, CBC_CALL2_PROP_BLOCK, CBC_ASSIGN, CBC_ASSIGN_PUSH_RESULT, CBC_ASSIGN_BLOCK, CBC_ASSIGN_SET_IDENT, CBC_ASSIGN_SET_IDENT_PUSH_RESULT, CBC_ASSIGN_SET_IDENT_BLOCK, CBC_ASSIGN_LITERAL_SET_IDENT, CBC_ASSIGN_LITERAL_SET_IDENT_PUSH_RESULT, CBC_ASSIGN_LITERAL_SET_IDENT_BLOCK, CBC_ASSIGN_PROP_LITERAL, CBC_ASSIGN_PROP_LITERAL_PUSH_RESULT, CBC_ASSIGN_PROP_LITERAL_BLOCK, CBC_ASSIGN_PROP_THIS_LITERAL, CBC_ASSIGN_PROP_THIS_LITERAL_PUSH_RESULT, CBC_ASSIGN_PROP_THIS_LITERAL_BLOCK, CBC_ASSIGN_ADD, CBC_ASSIGN_ADD_LITERAL, CBC_ASSIGN_SUBTRACT, CBC_ASSIGN_SUBTRACT_LITERAL, CBC_ASSIGN_MULTIPLY, CBC_ASSIGN_MULTIPLY_LITERAL, CBC_ASSIGN_DIVIDE, CBC_ASSIGN_DIVIDE_LITERAL, CBC_ASSIGN_MODULO, CBC_ASSIGN_MODULO_LITERAL, CBC_ASSIGN_LEFT_SHIFT, CBC_ASSIGN_LEFT_SHIFT_LITERAL, CBC_ASSIGN_RIGHT_SHIFT, CBC_ASSIGN_RIGHT_SHIFT_LITERAL, CBC_ASSIGN_UNS_RIGHT_SHIFT, CBC_ASSIGN_UNS_RIGHT_SHIFT_LITERAL, CBC_ASSIGN_BIT_AND, CBC_ASSIGN_BIT_AND_LITERAL, CBC_ASSIGN_BIT_OR, CBC_ASSIGN_BIT_OR_LITERAL, CBC_ASSIGN_BIT_XOR, CBC_ASSIGN_BIT_XOR_LITERAL, CBC_END,
} cbc_opcode_t;
typedef enum
{
  CBC_EXT_NOP, CBC_EXT_WITH_CREATE_CONTEXT, CBC_EXT_WITH_CREATE_CONTEXT_2, CBC_EXT_WITH_CREATE_CONTEXT_3, CBC_EXT_FOR_IN_GET_NEXT, CBC_EXT_FOR_IN_CREATE_CONTEXT, CBC_EXT_FOR_IN_CREATE_CONTEXT_2, CBC_EXT_FOR_IN_CREATE_CONTEXT_3, CBC_EXT_SET_GETTER, CBC_EXT_BRANCH_IF_FOR_IN_HAS_NEXT, CBC_EXT_BRANCH_IF_FOR_IN_HAS_NEXT_2, CBC_EXT_BRANCH_IF_FOR_IN_HAS_NEXT_3, CBC_EXT_SET_SETTER, CBC_EXT_TRY_CREATE_CONTEXT, CBC_EXT_TRY_CREATE_CONTEXT_2, CBC_EXT_TRY_CREATE_CONTEXT_3, CBC_EXT_THROW_REFERENCE_ERROR, CBC_EXT_CATCH, CBC_EXT_CATCH_2, CBC_EXT_CATCH_3, CBC_EXT_PUSH_UNDEFINED_BASE, CBC_EXT_FINALLY, CBC_EXT_FINALLY_2, CBC_EXT_FINALLY_3, CBC_EXT_CLASS_EXPR_CONTEXT_END, CBC_EXT_SUPER_CLASS_CREATE_CONTEXT, CBC_EXT_SUPER_CLASS_CREATE_CONTEXT_2, CBC_EXT_SUPER_CLASS_CREATE_CONTEXT_3, CBC_EXT_PUSH_LITERAL_PUSH_NUMBER_0, CBC_EXT_PUSH_LITERAL_PUSH_NUMBER_POS_BYTE, CBC_EXT_PUSH_LITERAL_PUSH_NUMBER_NEG_BYTE, CBC_EXT_RESOURCE_NAME, CBC_EXT_LINE, CBC_EXT_SET_COMPUTED_PROPERTY, CBC_EXT_SET_COMPUTED_PROPERTY_LITERAL, CBC_EXT_SET_COMPUTED_GETTER, CBC_EXT_SET_COMPUTED_SETTER, CBC_EXT_SET_STATIC_PROPERTY_LITERAL, CBC_EXT_SET_STATIC_COMPUTED_PROPERTY_LITERAL, CBC_EXT_SET_STATIC_GETTER, CBC_EXT_SET_STATIC_SETTER, CBC_EXT_SET_STATIC_COMPUTED_GETTER, CBC_EXT_SET_STATIC_COMPUTED_SETTER, CBC_EXT_INHERIT_AND_SET_CONSTRUCTOR, CBC_EXT_PUSH_CLASS_CONSTRUCTOR, CBC_EXT_IMPLICIT_CONSTRUCTOR_CALL, CBC_EXT_SET_CLASS_LITERAL, CBC_EXT_CLASS_EVAL, CBC_EXT_SUPER_CALL, CBC_EXT_SUPER_CALL_PUSH_RESULT, CBC_EXT_SUPER_CALL_BLOCK, CBC_EXT_PUSH_CONSTRUCTOR_SUPER, CBC_EXT_PUSH_CONSTRUCTOR_SUPER_PROP, CBC_EXT_PUSH_SUPER, CBC_EXT_PUSH_STATIC_SUPER, CBC_EXT_PUSH_CONSTRUCTOR_THIS, CBC_EXT_SUPER_PROP_CALL, CBC_EXT_SUPER_PROP_ASSIGN, CBC_EXT_CONSTRUCTOR_RETURN, CBC_EXT_ASSIGN_ADD_PUSH_RESULT, CBC_EXT_ASSIGN_ADD_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_SUBTRACT_PUSH_RESULT, CBC_EXT_ASSIGN_SUBTRACT_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_MULTIPLY_PUSH_RESULT, CBC_EXT_ASSIGN_MULTIPLY_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_DIVIDE_PUSH_RESULT, CBC_EXT_ASSIGN_DIVIDE_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_MODULO_PUSH_RESULT, CBC_EXT_ASSIGN_MODULO_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_LEFT_SHIFT_PUSH_RESULT, CBC_EXT_ASSIGN_LEFT_SHIFT_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_RIGHT_SHIFT_PUSH_RESULT, CBC_EXT_ASSIGN_RIGHT_SHIFT_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_UNS_RIGHT_SHIFT_PUSH_RESULT, CBC_EXT_ASSIGN_UNS_RIGHT_SHIFT_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_AND_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_AND_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_OR_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_OR_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_XOR_PUSH_RESULT, CBC_EXT_ASSIGN_BIT_XOR_LITERAL_PUSH_RESULT, CBC_EXT_ASSIGN_ADD_BLOCK, CBC_EXT_ASSIGN_ADD_LITERAL_BLOCK, CBC_EXT_ASSIGN_SUBTRACT_BLOCK, CBC_EXT_ASSIGN_SUBTRACT_LITERAL_BLOCK, CBC_EXT_ASSIGN_MULTIPLY_BLOCK, CBC_EXT_ASSIGN_MULTIPLY_LITERAL_BLOCK, CBC_EXT_ASSIGN_DIVIDE_BLOCK, CBC_EXT_ASSIGN_DIVIDE_LITERAL_BLOCK, CBC_EXT_ASSIGN_MODULO_BLOCK, CBC_EXT_ASSIGN_MODULO_LITERAL_BLOCK, CBC_EXT_ASSIGN_LEFT_SHIFT_BLOCK, CBC_EXT_ASSIGN_LEFT_SHIFT_LITERAL_BLOCK, CBC_EXT_ASSIGN_RIGHT_SHIFT_BLOCK, CBC_EXT_ASSIGN_RIGHT_SHIFT_LITERAL_BLOCK, CBC_EXT_ASSIGN_UNS_RIGHT_SHIFT_BLOCK, CBC_EXT_ASSIGN_UNS_RIGHT_SHIFT_LITERAL_BLOCK, CBC_EXT_ASSIGN_BIT_AND_BLOCK, CBC_EXT_ASSIGN_BIT_AND_LITERAL_BLOCK, CBC_EXT_ASSIGN_BIT_OR_BLOCK, CBC_EXT_ASSIGN_BIT_OR_LITERAL_BLOCK, CBC_EXT_ASSIGN_BIT_XOR_BLOCK, CBC_EXT_ASSIGN_BIT_XOR_LITERAL_BLOCK, CBC_EXT_END,
} cbc_ext_opcode_t;
extern const uint8_t cbc_flags[];
extern const uint8_t cbc_ext_flags[];
typedef const uint8_t *vm_instr_counter_t;
typedef struct vm_frame_ctx_t
{
  const ecma_compiled_code_t *bytecode_header_p;
  uint8_t *byte_code_p;
  uint8_t *byte_code_start_p;
  ecma_value_t *registers_p;
  ecma_value_t *stack_top_p;
  ecma_value_t *literal_start_p;
  ecma_object_t *lex_env_p;
  struct vm_frame_ctx_t *prev_context_p;
  ecma_value_t this_binding;
  ecma_value_t call_block_result;
  uint16_t context_depth;
  uint8_t is_eval_code;
  uint8_t call_operation;
} vm_frame_ctx_t;
typedef enum
{
  VM_OC_GET_NONE = (((0) & 0x7) << 7),
  VM_OC_GET_BRANCH = (((1) & 0x7) << 7),
  VM_OC_GET_STACK = (((2) & 0x7) << 7),
  VM_OC_GET_STACK_STACK = (((3) & 0x7) << 7),
  VM_OC_GET_LITERAL = (((4) & 0x7) << 7),
  VM_OC_GET_LITERAL_LITERAL = (((5) & 0x7) << 7),
  VM_OC_GET_STACK_LITERAL = (((6) & 0x7) << 7),
  VM_OC_GET_THIS_LITERAL = (((7) & 0x7) << 7),
} vm_oc_get_types;
typedef enum
{
  VM_OC_POP,
  VM_OC_POP_BLOCK,
  VM_OC_PUSH,
  VM_OC_PUSH_TWO,
  VM_OC_PUSH_THREE,
  VM_OC_PUSH_UNDEFINED,
  VM_OC_PUSH_TRUE,
  VM_OC_PUSH_FALSE,
  VM_OC_PUSH_NULL,
  VM_OC_PUSH_THIS,
  VM_OC_PUSH_0,
  VM_OC_PUSH_POS_BYTE,
  VM_OC_PUSH_NEG_BYTE,
  VM_OC_PUSH_LIT_0,
  VM_OC_PUSH_LIT_POS_BYTE,
  VM_OC_PUSH_LIT_NEG_BYTE,
  VM_OC_PUSH_OBJECT,
  VM_OC_SET_PROPERTY,
  VM_OC_SET_COMPUTED_PROPERTY,
  VM_OC_SET_GETTER,
  VM_OC_SET_SETTER,
  VM_OC_PUSH_UNDEFINED_BASE,
  VM_OC_PUSH_ARRAY,
  VM_OC_PUSH_ELISON,
  VM_OC_APPEND_ARRAY,
  VM_OC_IDENT_REFERENCE,
  VM_OC_PROP_REFERENCE,
  VM_OC_PROP_GET,
  VM_OC_PROP_PRE_INCR,
  VM_OC_PROP_PRE_DECR,
  VM_OC_PROP_POST_INCR,
  VM_OC_PROP_POST_DECR,
  VM_OC_PRE_INCR,
  VM_OC_PRE_DECR,
  VM_OC_POST_INCR,
  VM_OC_POST_DECR,
  VM_OC_PROP_DELETE,
  VM_OC_DELETE,
  VM_OC_ASSIGN,
  VM_OC_ASSIGN_PROP,
  VM_OC_ASSIGN_PROP_THIS,
  VM_OC_RET,
  VM_OC_THROW,
  VM_OC_THROW_REFERENCE_ERROR,
  VM_OC_EVAL,
  VM_OC_CALL,
  VM_OC_NEW,
  VM_OC_JUMP,
  VM_OC_BRANCH_IF_STRICT_EQUAL,
  VM_OC_BRANCH_IF_TRUE,
  VM_OC_BRANCH_IF_FALSE,
  VM_OC_BRANCH_IF_LOGICAL_TRUE,
  VM_OC_BRANCH_IF_LOGICAL_FALSE,
  VM_OC_PLUS,
  VM_OC_MINUS,
  VM_OC_NOT,
  VM_OC_BIT_NOT,
  VM_OC_VOID,
  VM_OC_TYPEOF_IDENT,
  VM_OC_TYPEOF,
  VM_OC_ADD,
  VM_OC_SUB,
  VM_OC_MUL,
  VM_OC_DIV,
  VM_OC_MOD,
  VM_OC_EQUAL,
  VM_OC_NOT_EQUAL,
  VM_OC_STRICT_EQUAL,
  VM_OC_STRICT_NOT_EQUAL,
  VM_OC_LESS,
  VM_OC_GREATER,
  VM_OC_LESS_EQUAL,
  VM_OC_GREATER_EQUAL,
  VM_OC_IN,
  VM_OC_INSTANCEOF,
  VM_OC_BIT_OR,
  VM_OC_BIT_XOR,
  VM_OC_BIT_AND,
  VM_OC_LEFT_SHIFT,
  VM_OC_RIGHT_SHIFT,
  VM_OC_UNS_RIGHT_SHIFT,
  VM_OC_WITH,
  VM_OC_FOR_IN_CREATE_CONTEXT,
  VM_OC_FOR_IN_GET_NEXT,
  VM_OC_FOR_IN_HAS_NEXT,
  VM_OC_TRY,
  VM_OC_CATCH,
  VM_OC_FINALLY,
  VM_OC_CONTEXT_END,
  VM_OC_JUMP_AND_EXIT_CONTEXT,
  VM_OC_CLASS_HERITAGE,
  VM_OC_CLASS_INHERITANCE,
  VM_OC_PUSH_CLASS_CONSTRUCTOR,
  VM_OC_SET_CLASS_CONSTRUCTOR,
  VM_OC_PUSH_IMPL_CONSTRUCTOR,
  VM_OC_CLASS_EXPR_CONTEXT_END,
  VM_OC_CLASS_EVAL,
  VM_OC_SUPER_CALL,
  VM_OC_SUPER_PROP_REFERENCE,
  VM_OC_PUSH_SUPER,
  VM_OC_PUSH_CONSTRUCTOR_SUPER,
  VM_OC_PUSH_CONSTRUCTOR_THIS,
  VM_OC_CONSTRUCTOR_RET,
  VM_OC_NONE,
} vm_oc_types;
typedef enum
{
  VM_OC_BREAKPOINT_ENABLED = VM_OC_NONE,
  VM_OC_BREAKPOINT_DISABLED = VM_OC_NONE,
  VM_OC_RESOURCE_NAME = VM_OC_NONE,
  VM_OC_LINE = VM_OC_NONE,
  VM_OC_UNUSED = VM_OC_NONE
} vm_oc_unused_types;
typedef enum
{
  VM_OC_PUT_IDENT = (((0x1) & 0xf) << 10),
  VM_OC_PUT_REFERENCE = (((0x2) & 0xf) << 10),
  VM_OC_PUT_STACK = (((0x4) & 0xf) << 10),
  VM_OC_PUT_BLOCK = (((0x8) & 0xf) << 10),
} vm_oc_put_types;
typedef enum
{
  VM_NO_EXEC_OP,
  VM_EXEC_CALL,
  VM_EXEC_SUPER_CALL,
  VM_EXEC_CONSTRUCT,
} vm_call_operation;
ecma_value_t vm_run_global (const ecma_compiled_code_t *bytecode_p);
ecma_value_t vm_run_eval (ecma_compiled_code_t *bytecode_data_p, uint32_t parse_opts);
ecma_value_t vm_run (const ecma_compiled_code_t *bytecode_header_p, ecma_value_t this_binding_value,
                     ecma_object_t *lex_env_p, uint32_t parse_opts, const ecma_value_t *arg_list_p,
                     ecma_length_t arg_list_len);
_Bool vm_is_strict_mode (void);
_Bool vm_is_direct_eval_form_call (void);
ecma_value_t vm_get_backtrace (uint32_t max_depth);
_Bool ecma_is_normal_or_arrow_function (ecma_object_type_t type);
_Bool ecma_op_is_callable (ecma_value_t value);
_Bool ecma_is_constructor (ecma_value_t value);
ecma_object_t *
ecma_op_create_function_object (ecma_object_t *scope_p, const ecma_compiled_code_t *bytecode_data_p);
ecma_object_t *
ecma_op_create_arrow_function_object (ecma_object_t *scope_p, const ecma_compiled_code_t *bytecode_data_p,
                                      ecma_value_t this_binding);
ecma_object_t *
ecma_op_create_external_function_object (ecma_external_handler_t handler_cb);
const ecma_compiled_code_t *
ecma_op_function_get_compiled_code (ecma_extended_object_t *function_p);
void
ecma_op_set_super_called (ecma_object_t *lex_env_p);
_Bool
ecma_op_is_super_called (ecma_object_t *lex_env_p);
void
ecma_op_set_class_this_binding (ecma_object_t *lex_env_p, ecma_value_t this_binding);
ecma_value_t
ecma_op_get_class_this_binding (ecma_object_t *lex_env_p);
ecma_value_t
ecma_op_function_implicit_constructor_handler_cb (const ecma_value_t function_obj,
                                                  const ecma_value_t this_val,
                                                  const ecma_value_t args_p[],
                                                  const ecma_length_t args_count);
void
ecma_op_set_class_prototype (ecma_value_t completion_value, ecma_value_t this_arg);
const ecma_compiled_code_t *
ecma_op_arrow_function_get_compiled_code (ecma_arrow_function_t *arrow_function_p);
ecma_value_t
ecma_op_function_has_instance (ecma_object_t *func_obj_p, ecma_value_t value);
ecma_value_t
ecma_op_function_call (ecma_object_t *func_obj_p, ecma_value_t this_arg_value,
                       const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_value_t
ecma_op_function_construct (ecma_object_t *func_obj_p, ecma_value_t this_arg_value,
                            const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_property_t *
ecma_op_function_try_to_lazy_instantiate_property (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_property_t *
ecma_op_external_function_try_to_lazy_instantiate_property (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_property_t *
ecma_op_bound_function_try_to_lazy_instantiate_property (ecma_object_t *object_p, ecma_string_t *property_name_p);
void
ecma_op_function_list_lazy_property_names (ecma_object_t *object_p,
                                           _Bool separate_enumerable,
                                           ecma_collection_header_t *main_collection_p,
                                           ecma_collection_header_t *non_enum_collection_p);
void
ecma_op_external_function_list_lazy_property_names (_Bool separate_enumerable,
                                                    ecma_collection_header_t *main_collection_p,
                                                    ecma_collection_header_t *non_enum_collection_p);
void
ecma_op_bound_function_list_lazy_property_names (_Bool separate_enumerable,
                                                 ecma_collection_header_t *main_collection_p,
                                                 ecma_collection_header_t *non_enum_collection_p);
void ecma_init_gc_info (ecma_object_t *object_p);
void ecma_ref_object (ecma_object_t *object_p);
void ecma_deref_object (ecma_object_t *object_p);
void ecma_gc_run (jmem_free_unused_memory_severity_t severity);
void ecma_free_unused_memory (jmem_free_unused_memory_severity_t severity);
void ecma_lcache_insert (ecma_object_t *object_p, jmem_cpointer_t name_cp, ecma_property_t *prop_p);
ecma_property_t *ecma_lcache_lookup (ecma_object_t *object_p, const ecma_string_t *prop_name_p);
void ecma_lcache_invalidate (ecma_object_t *object_p, jmem_cpointer_t name_cp, ecma_property_t *prop_p);
ecma_object_t *ecma_op_resolve_reference_base (ecma_object_t *lex_env_p, ecma_string_t *name_p);
ecma_value_t ecma_op_resolve_reference_value (ecma_object_t *lex_env_p, ecma_string_t *name_p);
ecma_object_t *ecma_op_resolve_super_reference_value (ecma_object_t *lex_env_p);
void ecma_init_global_lex_env (void);
void ecma_finalize_global_lex_env (void);
ecma_object_t *ecma_get_global_environment (void);
ecma_value_t ecma_op_get_value_lex_env_base (ecma_object_t *ref_base_lex_env_p, ecma_string_t *var_name_string_p,
                                             _Bool is_strict);
ecma_value_t ecma_op_get_value_object_base (ecma_value_t base_value, ecma_string_t *property_name_p);
ecma_value_t ecma_op_put_value_lex_env_base (ecma_object_t *ref_base_lex_env_p, ecma_string_t *var_name_string_p,
                                             _Bool is_strict, ecma_value_t value);
_Bool ecma_op_has_binding (ecma_object_t *lex_env_p, ecma_string_t *name_p);
ecma_value_t ecma_op_create_mutable_binding (ecma_object_t *lex_env_p, ecma_string_t *name_p, _Bool is_deletable);
ecma_value_t ecma_op_set_mutable_binding (ecma_object_t *lex_env_p, ecma_string_t *name_p, ecma_value_t value,
                                          _Bool is_strict);
ecma_value_t ecma_op_get_binding_value (ecma_object_t *lex_env_p, ecma_string_t *name_p, _Bool is_strict);
ecma_value_t ecma_op_delete_binding (ecma_object_t *lex_env_p, ecma_string_t *name_p);
ecma_value_t ecma_op_implicit_this_value (ecma_object_t *lex_env_p);
void ecma_op_create_immutable_binding (ecma_object_t *lex_env_p, ecma_string_t *name_p, ecma_value_t value);
ecma_property_t ecma_op_object_get_own_property (ecma_object_t *object_p, ecma_string_t *property_name_p,
                                                 ecma_property_ref_t *property_ref_p, uint32_t options);
_Bool ecma_op_object_has_own_property (ecma_object_t *object_p, ecma_string_t *property_name_p);
_Bool ecma_op_object_has_property (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_value_t ecma_op_object_find_own (ecma_value_t base_value, ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_value_t ecma_op_object_find (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_value_t ecma_op_object_get_own_data_prop (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_value_t ecma_op_object_get (ecma_object_t *object_p, ecma_string_t *property_name_p);
ecma_value_t ecma_op_object_get_by_magic_id (ecma_object_t *object_p, lit_magic_string_id_t property_id);
ecma_value_t ecma_op_object_put (ecma_object_t *object_p, ecma_string_t *property_name_p, ecma_value_t value,
                                 _Bool is_throw);
ecma_value_t ecma_op_object_delete (ecma_object_t *obj_p, ecma_string_t *property_name_p, _Bool is_throw);
ecma_value_t ecma_op_object_default_value (ecma_object_t *obj_p, ecma_preferred_type_hint_t hint);
ecma_value_t ecma_op_object_define_own_property (ecma_object_t *obj_p, ecma_string_t *property_name_p,
                                                 const ecma_property_descriptor_t *property_desc_p, _Bool is_throw);
_Bool ecma_op_object_get_own_property_descriptor (ecma_object_t *object_p, ecma_string_t *property_name_p,
                                                 ecma_property_descriptor_t *prop_desc_p);
ecma_value_t ecma_op_object_has_instance (ecma_object_t *obj_p, ecma_value_t value);
_Bool ecma_op_object_is_prototype_of (ecma_object_t *base_p, ecma_object_t *target_p);
ecma_collection_header_t * ecma_op_object_get_property_names (ecma_object_t *obj_p, uint32_t opts);
lit_magic_string_id_t ecma_object_get_class_name (ecma_object_t *obj_p);
_Bool ecma_object_class_is (ecma_object_t *object_p, uint32_t class_id);
ecma_value_t ecma_reject (_Bool is_throw);
ecma_object_t *ecma_op_create_object_object_noarg (void);
ecma_value_t ecma_op_create_object_object_arg (ecma_value_t value);
ecma_object_t *ecma_op_create_object_object_noarg_and_set_prototype (ecma_object_t *object_prototype_p);
ecma_value_t ecma_op_general_object_delete (ecma_object_t *obj_p, ecma_string_t *property_name_p, _Bool is_throw);
ecma_value_t ecma_op_general_object_default_value (ecma_object_t *obj_p, ecma_preferred_type_hint_t hint);
ecma_value_t ecma_op_general_object_define_own_property (ecma_object_t *object_p, ecma_string_t *property_name_p,
                                                         const ecma_property_descriptor_t *property_desc_p,
                                                         _Bool is_throw);
typedef struct
{
  uint8_t *buffer_p;
  size_t received_length;
  uint8_t *message_p;
  size_t message_length;
  size_t message_total_length;
} jerry_debugger_transport_receive_context_t;
struct jerry_debugger_transport_interface_t;
typedef void (*jerry_debugger_transport_close_t) (struct jerry_debugger_transport_interface_t *header_p);
typedef _Bool (*jerry_debugger_transport_send_t) (struct jerry_debugger_transport_interface_t *header_p,
                                                 uint8_t *message_p, size_t message_length);
typedef _Bool (*jerry_debugger_transport_receive_t) (struct jerry_debugger_transport_interface_t *header_p,
                                                    jerry_debugger_transport_receive_context_t *context_p);
typedef struct jerry_debugger_transport_interface_t
{
  jerry_debugger_transport_close_t close;
  jerry_debugger_transport_send_t send;
  jerry_debugger_transport_receive_t receive;
  struct jerry_debugger_transport_interface_t *next_p;
} jerry_debugger_transport_header_t;
void jerry_debugger_transport_add (jerry_debugger_transport_header_t *header_p,
                                   size_t send_message_header_size, size_t max_send_message_size,
                                   size_t receive_message_header_size, size_t max_receive_message_size);
void jerry_debugger_transport_start (void);
_Bool jerry_debugger_transport_is_connected (void);
void jerry_debugger_transport_close (void);
_Bool jerry_debugger_transport_send (const uint8_t *message_p, size_t message_length);
_Bool jerry_debugger_transport_receive (jerry_debugger_transport_receive_context_t *context_p);
void jerry_debugger_transport_receive_completed (jerry_debugger_transport_receive_context_t *context_p);
void jerry_debugger_transport_sleep (void);
typedef ecma_value_t (*ecma_job_handler_t) (void *job_p);
typedef struct ecma_job_queueitem_t
{
  struct ecma_job_queueitem_t *next_p;
  ecma_job_handler_t handler;
  void *job_p;
} ecma_job_queueitem_t;
void ecma_job_queue_init (void);
void ecma_enqueue_promise_reaction_job (ecma_value_t reaction, ecma_value_t argument);
void ecma_enqueue_promise_resolve_thenable_job (ecma_value_t promise, ecma_value_t thenable, ecma_value_t then);
void ecma_free_all_enqueued_jobs (void);
ecma_value_t ecma_process_all_enqueued_jobs (void);
typedef enum
{
  JERRY_INIT_EMPTY               = (0u),
  JERRY_INIT_SHOW_OPCODES        = (1u << 0),
  JERRY_INIT_SHOW_REGEXP_OPCODES = (1u << 1),
  JERRY_INIT_MEM_STATS           = (1u << 2),
  JERRY_INIT_MEM_STATS_SEPARATE  = (1u << 3),
  JERRY_INIT_DEBUGGER            = (1u << 4),
} jerry_init_flag_t;
typedef enum
{
  JERRY_ERROR_NONE = 0,
  JERRY_ERROR_COMMON,
  JERRY_ERROR_EVAL,
  JERRY_ERROR_RANGE,
  JERRY_ERROR_REFERENCE,
  JERRY_ERROR_SYNTAX,
  JERRY_ERROR_TYPE,
  JERRY_ERROR_URI
} jerry_error_t;
typedef enum
{
  JERRY_FEATURE_CPOINTER_32_BIT,
  JERRY_FEATURE_ERROR_MESSAGES,
  JERRY_FEATURE_JS_PARSER,
  JERRY_FEATURE_MEM_STATS,
  JERRY_FEATURE_PARSER_DUMP,
  JERRY_FEATURE_REGEXP_DUMP,
  JERRY_FEATURE_SNAPSHOT_SAVE,
  JERRY_FEATURE_SNAPSHOT_EXEC,
  JERRY_FEATURE_DEBUGGER,
  JERRY_FEATURE_VM_EXEC_STOP,
  JERRY_FEATURE_JSON,
  JERRY_FEATURE_PROMISE,
  JERRY_FEATURE_TYPEDARRAY,
  JERRY_FEATURE_DATE,
  JERRY_FEATURE_REGEXP,
  JERRY_FEATURE_LINE_INFO,
  JERRY_FEATURE_LOGGING,
  JERRY_FEATURE__COUNT
} jerry_feature_t;
typedef enum
{
  JERRY_PARSE_NO_OPTS = 0,
  JERRY_PARSE_STRICT_MODE = (1 << 0)
} jerry_parse_opts_t;
typedef enum
{
  JERRY_GC_SEVERITY_LOW,
  JERRY_GC_SEVERITY_HIGH
} jerry_gc_mode_t;
typedef enum
{
  JERRY_REGEXP_FLAG_GLOBAL = (1u << 1),
  JERRY_REGEXP_FLAG_IGNORE_CASE = (1u << 2),
  JERRY_REGEXP_FLAG_MULTILINE = (1u << 3)
} jerry_regexp_flags_t;
typedef uint8_t jerry_char_t;
typedef uint32_t jerry_size_t;
typedef uint32_t jerry_length_t;
typedef uint32_t jerry_value_t;
typedef struct
{
  _Bool is_value_defined;
  _Bool is_get_defined;
  _Bool is_set_defined;
  _Bool is_writable_defined;
  _Bool is_writable;
  _Bool is_enumerable_defined;
  _Bool is_enumerable;
  _Bool is_configurable_defined;
  _Bool is_configurable;
  jerry_value_t value;
  jerry_value_t getter;
  jerry_value_t setter;
} jerry_property_descriptor_t;
typedef struct
{
  size_t version;
  size_t size;
  size_t allocated_bytes;
  size_t peak_allocated_bytes;
  size_t reserved[4];
} jerry_heap_stats_t;
typedef jerry_value_t (*jerry_external_handler_t) (const jerry_value_t function_obj,
                                                   const jerry_value_t this_val,
                                                   const jerry_value_t args_p[],
                                                   const jerry_length_t args_count);
typedef void (*jerry_object_native_free_callback_t) (void *native_p);
typedef jerry_value_t (*jerry_vm_exec_stop_callback_t) (void *user_p);
typedef _Bool (*jerry_object_property_foreach_t) (const jerry_value_t property_name,
                                                 const jerry_value_t property_value,
                                                 void *user_data_p);
typedef _Bool (*jerry_objects_foreach_t) (const jerry_value_t object,
                                         void *user_data_p);
typedef _Bool (*jerry_objects_foreach_by_native_info_t) (const jerry_value_t object,
                                                        void *object_data_p,
                                                        void *user_data_p);
typedef struct
{
  void (*init_cb) (void *data);
  void (*deinit_cb) (void *data);
  void (*finalize_cb) (void *data);
  size_t bytes_needed;
} jerry_context_data_manager_t;
typedef void *(*jerry_context_alloc_t) (size_t size, void *cb_data_p);
typedef struct
{
  jerry_object_native_free_callback_t free_cb;
} jerry_object_native_info_t;
typedef struct jerry_context_t jerry_context_t;
void jerry_init (jerry_init_flag_t flags);
void jerry_cleanup (void);
void jerry_register_magic_strings (const jerry_char_t * const *ex_str_items_p,
                                   uint32_t count,
                                   const jerry_length_t *str_lengths_p);
void jerry_gc (jerry_gc_mode_t mode);
void *jerry_get_context_data (const jerry_context_data_manager_t *manager_p);
_Bool jerry_get_memory_stats (jerry_heap_stats_t *out_stats_p);
_Bool jerry_run_simple (const jerry_char_t *script_source_p, size_t script_source_size, jerry_init_flag_t flags);
jerry_value_t jerry_parse (const jerry_char_t *resource_name_p, size_t resource_name_length,
                           const jerry_char_t *source_p, size_t source_size, uint32_t parse_opts);
jerry_value_t jerry_parse_function (const jerry_char_t *resource_name_p, size_t resource_name_length,
                                    const jerry_char_t *arg_list_p, size_t arg_list_size,
                                    const jerry_char_t *source_p, size_t source_size, uint32_t parse_opts);
jerry_value_t jerry_run (const jerry_value_t func_val);
jerry_value_t jerry_eval (const jerry_char_t *source_p, size_t source_size, uint32_t parse_opts);
jerry_value_t jerry_run_all_enqueued_jobs (void);
jerry_value_t jerry_get_global_object (void);
_Bool jerry_value_is_abort (const jerry_value_t value);
_Bool jerry_value_is_array (const jerry_value_t value);
_Bool jerry_value_is_boolean (const jerry_value_t value);
_Bool jerry_value_is_constructor (const jerry_value_t value);
_Bool jerry_value_is_error (const jerry_value_t value);
_Bool jerry_value_is_function (const jerry_value_t value);
_Bool jerry_value_is_number (const jerry_value_t value);
_Bool jerry_value_is_null (const jerry_value_t value);
_Bool jerry_value_is_object (const jerry_value_t value);
_Bool jerry_value_is_promise (const jerry_value_t value);
_Bool jerry_value_is_string (const jerry_value_t value);
_Bool jerry_value_is_undefined (const jerry_value_t value);
typedef enum
{
  JERRY_TYPE_NONE = 0u,
  JERRY_TYPE_UNDEFINED,
  JERRY_TYPE_NULL,
  JERRY_TYPE_BOOLEAN,
  JERRY_TYPE_NUMBER,
  JERRY_TYPE_STRING,
  JERRY_TYPE_OBJECT,
  JERRY_TYPE_FUNCTION,
  JERRY_TYPE_ERROR,
} jerry_type_t;
jerry_type_t jerry_value_get_type (const jerry_value_t value);
_Bool jerry_is_feature_enabled (const jerry_feature_t feature);
jerry_value_t jerry_create_abort_from_value (jerry_value_t value, _Bool release);
jerry_value_t jerry_create_error_from_value (jerry_value_t value, _Bool release);
jerry_value_t jerry_get_value_from_error (jerry_value_t value, _Bool release);
jerry_error_t jerry_get_error_type (jerry_value_t value);
_Bool jerry_get_boolean_value (const jerry_value_t value);
double jerry_get_number_value (const jerry_value_t value);
jerry_size_t jerry_get_string_size (const jerry_value_t value);
jerry_size_t jerry_get_utf8_string_size (const jerry_value_t value);
jerry_length_t jerry_get_string_length (const jerry_value_t value);
jerry_length_t jerry_get_utf8_string_length (const jerry_value_t value);
jerry_size_t jerry_string_to_char_buffer (const jerry_value_t value, jerry_char_t *buffer_p, jerry_size_t buffer_size);
jerry_size_t jerry_string_to_utf8_char_buffer (const jerry_value_t value,
                                               jerry_char_t *buffer_p,
                                               jerry_size_t buffer_size);
jerry_size_t jerry_substring_to_char_buffer (const jerry_value_t value,
                                             jerry_length_t start_pos,
                                             jerry_length_t end_pos,
                                             jerry_char_t *buffer_p,
                                             jerry_size_t buffer_size);
jerry_size_t jerry_substring_to_utf8_char_buffer (const jerry_value_t value,
                                                  jerry_length_t start_pos,
                                                  jerry_length_t end_pos,
                                                  jerry_char_t *buffer_p,
                                                  jerry_size_t buffer_size);
uint32_t jerry_get_array_length (const jerry_value_t value);
_Bool jerry_value_to_boolean (const jerry_value_t value);
jerry_value_t jerry_value_to_number (const jerry_value_t value);
jerry_value_t jerry_value_to_object (const jerry_value_t value);
jerry_value_t jerry_value_to_primitive (const jerry_value_t value);
jerry_value_t jerry_value_to_string (const jerry_value_t value);
jerry_value_t jerry_acquire_value (jerry_value_t value);
void jerry_release_value (jerry_value_t value);
jerry_value_t jerry_create_array (uint32_t size);
jerry_value_t jerry_create_boolean (_Bool value);
jerry_value_t jerry_create_error (jerry_error_t error_type, const jerry_char_t *message_p);
jerry_value_t jerry_create_error_sz (jerry_error_t error_type, const jerry_char_t *message_p,
                                     jerry_size_t message_size);
jerry_value_t jerry_create_external_function (jerry_external_handler_t handler_p);
jerry_value_t jerry_create_number (double value);
jerry_value_t jerry_create_number_infinity (_Bool sign);
jerry_value_t jerry_create_number_nan (void);
jerry_value_t jerry_create_null (void);
jerry_value_t jerry_create_object (void);
jerry_value_t jerry_create_promise (void);
jerry_value_t jerry_create_regexp (const jerry_char_t *pattern, jerry_regexp_flags_t flags);
jerry_value_t jerry_create_regexp_sz (const jerry_char_t *pattern, jerry_size_t pattern_size,
                                      jerry_regexp_flags_t flags);
jerry_value_t jerry_create_string_from_utf8 (const jerry_char_t *str_p);
jerry_value_t jerry_create_string_sz_from_utf8 (const jerry_char_t *str_p, jerry_size_t str_size);
jerry_value_t jerry_create_string (const jerry_char_t *str_p);
jerry_value_t jerry_create_string_sz (const jerry_char_t *str_p, jerry_size_t str_size);
jerry_value_t jerry_create_undefined (void);
jerry_value_t jerry_has_property (const jerry_value_t obj_val, const jerry_value_t prop_name_val);
jerry_value_t jerry_has_own_property (const jerry_value_t obj_val, const jerry_value_t prop_name_val);
_Bool jerry_delete_property (const jerry_value_t obj_val, const jerry_value_t prop_name_val);
_Bool jerry_delete_property_by_index (const jerry_value_t obj_val, uint32_t index);
jerry_value_t jerry_get_property (const jerry_value_t obj_val, const jerry_value_t prop_name_val);
jerry_value_t jerry_get_property_by_index (const jerry_value_t obj_val, uint32_t index);
jerry_value_t jerry_set_property (const jerry_value_t obj_val, const jerry_value_t prop_name_val,
                                  const jerry_value_t value_to_set);
jerry_value_t jerry_set_property_by_index (const jerry_value_t obj_val, uint32_t index,
                                           const jerry_value_t value_to_set);
void jerry_init_property_descriptor_fields (jerry_property_descriptor_t *prop_desc_p);
jerry_value_t jerry_define_own_property (const jerry_value_t obj_val,
                                         const jerry_value_t prop_name_val,
                                         const jerry_property_descriptor_t *prop_desc_p);
_Bool jerry_get_own_property_descriptor (const jerry_value_t obj_val,
                                        const jerry_value_t prop_name_val,
                                        jerry_property_descriptor_t *prop_desc_p);
void jerry_free_property_descriptor_fields (const jerry_property_descriptor_t *prop_desc_p);
jerry_value_t jerry_call_function (const jerry_value_t func_obj_val, const jerry_value_t this_val,
                                   const jerry_value_t args_p[], jerry_size_t args_count);
jerry_value_t jerry_construct_object (const jerry_value_t func_obj_val, const jerry_value_t args_p[],
                                      jerry_size_t args_count);
jerry_value_t jerry_get_object_keys (const jerry_value_t obj_val);
jerry_value_t jerry_get_prototype (const jerry_value_t obj_val);
jerry_value_t jerry_set_prototype (const jerry_value_t obj_val, const jerry_value_t proto_obj_val);
_Bool jerry_get_object_native_pointer (const jerry_value_t obj_val,
                                      void **out_native_pointer_p,
                                      const jerry_object_native_info_t **out_pointer_info_p);
void jerry_set_object_native_pointer (const jerry_value_t obj_val,
                                      void *native_pointer_p,
                                      const jerry_object_native_info_t *native_info_p);
_Bool jerry_objects_foreach (jerry_objects_foreach_t foreach_p,
                            void *user_data);
_Bool jerry_objects_foreach_by_native_info (const jerry_object_native_info_t *native_info_p,
                                           jerry_objects_foreach_by_native_info_t foreach_p,
                                           void *user_data_p);
_Bool jerry_foreach_object_property (const jerry_value_t obj_val, jerry_object_property_foreach_t foreach_p,
                                    void *user_data_p);
jerry_value_t jerry_resolve_or_reject_promise (jerry_value_t promise, jerry_value_t argument, _Bool is_resolve);
_Bool jerry_is_valid_utf8_string (const jerry_char_t *utf8_buf_p, jerry_size_t buf_size);
_Bool jerry_is_valid_cesu8_string (const jerry_char_t *cesu8_buf_p, jerry_size_t buf_size);
void *jerry_heap_alloc (size_t size);
void jerry_heap_free (void *mem_p, size_t size);
jerry_context_t *jerry_create_context (uint32_t heap_size, jerry_context_alloc_t alloc, void *cb_data_p);
void jerry_set_vm_exec_stop_callback (jerry_vm_exec_stop_callback_t stop_cb, void *user_p, uint32_t frequency);
jerry_value_t jerry_get_backtrace (uint32_t max_depth);
_Bool jerry_value_is_arraybuffer (const jerry_value_t value);
jerry_value_t jerry_create_arraybuffer (const jerry_length_t size);
jerry_value_t jerry_create_arraybuffer_external (const jerry_length_t size,
                                                 uint8_t *buffer_p,
                                                 jerry_object_native_free_callback_t free_cb);
jerry_length_t jerry_arraybuffer_write (const jerry_value_t value,
                                        jerry_length_t offset,
                                        const uint8_t *buf_p,
                                        jerry_length_t buf_size);
jerry_length_t jerry_arraybuffer_read (const jerry_value_t value,
                                       jerry_length_t offset,
                                       uint8_t *buf_p,
                                       jerry_length_t buf_size);
jerry_length_t jerry_get_arraybuffer_byte_length (const jerry_value_t value);
uint8_t *jerry_get_arraybuffer_pointer (const jerry_value_t value);
typedef enum
{
  JERRY_TYPEDARRAY_INVALID = 0,
  JERRY_TYPEDARRAY_UINT8,
  JERRY_TYPEDARRAY_UINT8CLAMPED,
  JERRY_TYPEDARRAY_INT8,
  JERRY_TYPEDARRAY_UINT16,
  JERRY_TYPEDARRAY_INT16,
  JERRY_TYPEDARRAY_UINT32,
  JERRY_TYPEDARRAY_INT32,
  JERRY_TYPEDARRAY_FLOAT32,
  JERRY_TYPEDARRAY_FLOAT64,
} jerry_typedarray_type_t;
_Bool jerry_value_is_typedarray (jerry_value_t value);
jerry_value_t jerry_create_typedarray (jerry_typedarray_type_t type_name, jerry_length_t length);
jerry_value_t jerry_create_typedarray_for_arraybuffer_sz (jerry_typedarray_type_t type_name,
                                                          const jerry_value_t arraybuffer,
                                                          jerry_length_t byte_offset,
                                                          jerry_length_t length);
jerry_value_t jerry_create_typedarray_for_arraybuffer (jerry_typedarray_type_t type_name,
                                                       const jerry_value_t arraybuffer);
jerry_typedarray_type_t jerry_get_typedarray_type (jerry_value_t value);
jerry_length_t jerry_get_typedarray_length (jerry_value_t value);
jerry_value_t jerry_get_typedarray_buffer (jerry_value_t value,
                                           jerry_length_t *byte_offset,
                                           jerry_length_t *byte_length);
jerry_value_t jerry_json_parse (const jerry_char_t *string_p, jerry_size_t string_size);
jerry_value_t jerry_json_stringify (const jerry_value_t object_to_stringify);
typedef enum
{
  JERRY_DEBUGGER_SOURCE_RECEIVE_FAILED = 0,
  JERRY_DEBUGGER_SOURCE_RECEIVED = 1,
  JERRY_DEBUGGER_SOURCE_END = 2,
  JERRY_DEBUGGER_CONTEXT_RESET_RECEIVED,
} jerry_debugger_wait_for_source_status_t;
typedef jerry_value_t (*jerry_debugger_wait_for_source_callback_t) (const jerry_char_t *resource_name_p,
                                                                    size_t resource_name_size,
                                                                    const jerry_char_t *source_p,
                                                                    size_t source_size, void *user_p);
_Bool jerry_debugger_is_connected (void);
void jerry_debugger_stop (void);
void jerry_debugger_continue (void);
void jerry_debugger_stop_at_breakpoint (_Bool enable_stop_at_breakpoint);
jerry_debugger_wait_for_source_status_t
jerry_debugger_wait_for_client_source (jerry_debugger_wait_for_source_callback_t callback_p,
                                       void *user_p, jerry_value_t *return_value);
void jerry_debugger_send_output (const jerry_char_t *buffer, jerry_size_t str_size);
void jerry_debugger_send_log (jerry_log_level_t level, const jerry_char_t *buffer, jerry_size_t str_size);
typedef enum
{
  JERRY_SNAPSHOT_SAVE_STATIC = (1u << 0),
  JERRY_SNAPSHOT_SAVE_STRICT = (1u << 1),
} jerry_generate_snapshot_opts_t;
typedef enum
{
  JERRY_SNAPSHOT_EXEC_COPY_DATA = (1u << 0),
  JERRY_SNAPSHOT_EXEC_ALLOW_STATIC = (1u << 1),
} jerry_exec_snapshot_opts_t;
jerry_value_t jerry_generate_snapshot (const jerry_char_t *resource_name_p, size_t resource_name_length,
                                       const jerry_char_t *source_p, size_t source_size,
                                       uint32_t generate_snapshot_opts, uint32_t *buffer_p, size_t buffer_size);
jerry_value_t jerry_generate_function_snapshot (const jerry_char_t *resource_name_p, size_t resource_name_length,
                                                const jerry_char_t *source_p, size_t source_size,
                                                const jerry_char_t *args_p, size_t args_size,
                                                uint32_t generate_snapshot_opts, uint32_t *buffer_p,
                                                size_t buffer_size);
jerry_value_t jerry_exec_snapshot (const uint32_t *snapshot_p, size_t snapshot_size,
                                   size_t func_index, uint32_t exec_snapshot_opts);
jerry_value_t jerry_load_function_snapshot (const uint32_t *function_snapshot_p,
                                            const size_t function_snapshot_size,
                                            size_t func_index, uint32_t exec_snapshot_opts);
size_t jerry_merge_snapshots (const uint32_t **inp_buffers_p, size_t *inp_buffer_sizes_p, size_t number_of_snapshots,
                              uint32_t *out_buffer_p, size_t out_buffer_size, const char **error_p);
size_t jerry_get_literals_from_snapshot (const uint32_t *snapshot_p, size_t snapshot_size,
                                         jerry_char_t *lit_buf_p, size_t lit_buf_size, _Bool is_c_format);
typedef struct jmem_heap_t jmem_heap_t;
typedef struct jerry_context_data_header
{
  struct jerry_context_data_header *next_p;
  const jerry_context_data_manager_t *manager_p;
} jerry_context_data_header_t;
struct jerry_context_t
{
  ecma_object_t *ecma_builtin_objects[ECMA_BUILTIN_ID__COUNT];
  const re_compiled_code_t *re_cache[8u];
  ecma_object_t *ecma_gc_objects_p;
  jmem_heap_free_t *jmem_heap_list_skip_p;
  jmem_pools_chunk_t *jmem_free_8_byte_chunk_p;
  jmem_free_unused_memory_callback_t jmem_free_unused_memory_callback;
  const lit_utf8_byte_t * const *lit_magic_string_ex_array;
  const lit_utf8_size_t *lit_magic_string_ex_sizes;
  ecma_lit_storage_item_t *string_list_first_p;
  ecma_lit_storage_item_t *number_list_first_p;
  ecma_object_t *ecma_global_lex_env_p;
  vm_frame_ctx_t *vm_top_context_p;
  jerry_context_data_header_t *context_data_p;
  size_t ecma_gc_objects_number;
  size_t ecma_gc_new_objects;
  size_t jmem_heap_allocated_size;
  size_t jmem_heap_limit;
  ecma_value_t error_value;
  uint32_t lit_magic_string_ex_count;
  uint32_t jerry_init_flags;
  uint32_t status_flags;
  uint8_t ecma_prop_hashmap_alloc_state;
  uint8_t re_cache_idx;
  ecma_job_queueitem_t *job_queue_head_p;
  ecma_job_queueitem_t *job_queue_tail_p;
  ecma_lcache_hash_entry_t lcache[128][2];
};
extern jerry_context_t jerry_global_context;
struct jmem_heap_t
{
  jmem_heap_free_t first;
  uint8_t area[(((size_t) ((512 * 1024))) - (1u << 3))];
};
extern jmem_heap_t jerry_global_heap;
typedef enum
{
  NUMBER_ARITHMETIC_SUBSTRACTION,
  NUMBER_ARITHMETIC_MULTIPLICATION,
  NUMBER_ARITHMETIC_DIVISION,
  NUMBER_ARITHMETIC_REMAINDER,
} number_arithmetic_op;
typedef enum
{
  NUMBER_BITWISE_LOGIC_AND,
  NUMBER_BITWISE_LOGIC_OR,
  NUMBER_BITWISE_LOGIC_XOR,
  NUMBER_BITWISE_SHIFT_LEFT,
  NUMBER_BITWISE_SHIFT_RIGHT,
  NUMBER_BITWISE_SHIFT_URIGHT,
  NUMBER_BITWISE_NOT,
} number_bitwise_logic_op;
ecma_value_t
vm_var_decl (vm_frame_ctx_t *frame_ctx_p, ecma_string_t *var_name_str_p);
ecma_value_t
opfunc_equality (ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
do_number_arithmetic (number_arithmetic_op op, ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
opfunc_unary_operation (ecma_value_t left_value, _Bool is_plus);
ecma_value_t
do_number_bitwise_logic (number_bitwise_logic_op op, ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
opfunc_addition (ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
opfunc_relation (ecma_value_t left_value, ecma_value_t right_value, _Bool left_first, _Bool is_invert);
ecma_value_t
opfunc_in (ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
opfunc_instanceof (ecma_value_t left_value, ecma_value_t right_value);
ecma_value_t
opfunc_logical_not (ecma_value_t left_value);
ecma_value_t
opfunc_typeof (ecma_value_t left_value);
void
opfunc_set_accessor (_Bool is_getter, ecma_value_t object, ecma_string_t *accessor_name_p, ecma_value_t accessor);
ecma_value_t
vm_op_delete_prop (ecma_value_t object, ecma_value_t property, _Bool is_strict);
ecma_value_t
vm_op_delete_var (ecma_value_t name_literal, ecma_object_t *lex_env_p);
ecma_collection_chunk_t *
opfunc_for_in (ecma_value_t left_value, ecma_value_t *result_obj_p);
typedef struct
{
  uint16_t prev_chunk_p;
} vm_stack_chunk_header_t;
typedef struct vm_stack_frame_t
{
  struct vm_stack_frame_t *prev_frame_p;
  uint32_t regs_number;
} vm_stack_frame_t;
typedef enum
{
  VM_CONTEXT_FINALLY_JUMP,
  VM_CONTEXT_FINALLY_THROW,
  VM_CONTEXT_FINALLY_RETURN,
  VM_CONTEXT_TRY,
  VM_CONTEXT_CATCH,
  VM_CONTEXT_WITH,
  VM_CONTEXT_SUPER_CLASS,
  VM_CONTEXT_FOR_IN,
} vm_stack_context_type_t;
ecma_value_t *vm_stack_context_abort (vm_frame_ctx_t *frame_ctx_p, ecma_value_t *vm_stack_top_p);
_Bool vm_stack_find_finally (vm_frame_ctx_t *frame_ctx_p, ecma_value_t **vm_stack_top_ref_p,
                            vm_stack_context_type_t finally_type, uint32_t search_limit);
	static ecma_value_t
vm_op_get_value (ecma_value_t object,
		ecma_value_t property)
{
	if (ecma_is_value_object (object))
	{
		ecma_string_t *property_name_p = ((void *)0);
		if (ecma_is_value_integer_number (property))
		{
			ecma_integer_value_t int_value = ecma_get_integer_from_value (property);
			if (int_value >= 0 && int_value <= 0x0000ffff)
			{
				property_name_p = (ecma_string_t *) ((uintptr_t) (ECMA_TYPE_DIRECT_STRING | ((ECMA_DIRECT_STRING_UINT) << 3) | ((uintptr_t) int_value) << (3 + 2)));
			}
		}
		else if (ecma_is_value_string (property))
		{
			property_name_p = ecma_get_string_from_value (property);
		}
		if (property_name_p != ((void *)0))
		{
			ecma_object_t *object_p = ecma_get_object_from_value (object);
			ecma_property_t *property_p = ecma_lcache_lookup (object_p, property_name_p);
			if (property_p != ((void *)0) &&
					((ecma_property_types_t) ((*property_p) & 0x3)) == ECMA_PROPERTY_TYPE_NAMEDDATA)
			{
				return ecma_fast_copy_value (((ecma_property_value_t *) (((uintptr_t) ((((uint8_t *) (property_p)) + (sizeof (ecma_property_value_t) * 2 - 1)))) & ~(sizeof (ecma_property_value_t) - 1)))->value);
			}
			return ecma_op_object_get (ecma_get_object_from_value (object), property_name_p);
		}
	}
	if ((ecma_is_value_undefined (object) || ecma_is_value_null (object)))
	{
		ecma_value_t error_value = ecma_raise_type_error (((void *)0));
		return error_value;
	}
	ecma_value_t prop_to_string_result = ecma_op_to_string (property);
	if ((((prop_to_string_result) == ECMA_VALUE_ERROR)))
	{
		return prop_to_string_result;
	}
	ecma_string_t *property_name_p = ecma_get_string_from_value (prop_to_string_result);
	ecma_value_t get_value_result = ecma_op_get_value_object_base (object, property_name_p);
	ecma_deref_ecma_string (property_name_p);
	return get_value_result;
}
	static ecma_value_t
vm_op_set_value (ecma_value_t object,
		ecma_value_t property,
		ecma_value_t value,
		_Bool is_strict)
{
	if ((!ecma_is_value_object (object)))
	{
		ecma_value_t to_object = ecma_op_to_object (object);
		ecma_free_value (object);
		if ((((to_object) == ECMA_VALUE_ERROR)))
		{
			ecma_free_value (property);
			return to_object;
		}
		object = to_object;
	}
	if (!ecma_is_value_string (property))
	{
		ecma_value_t to_string = ecma_op_to_string (property);
		ecma_fast_free_value (property);
		if ((((to_string) == ECMA_VALUE_ERROR)))
		{
			ecma_free_value (object);
			return to_string;
		}
		property = to_string;
	}
	ecma_object_t *object_p = ecma_get_object_from_value (object);
	ecma_string_t *property_p = ecma_get_string_from_value (property);
	ecma_value_t completion_value = ECMA_VALUE_EMPTY;
	if (!ecma_is_lexical_environment (object_p))
	{
		completion_value = ecma_op_object_put (object_p,
				property_p,
				value,
				is_strict);
	}
	else
	{
		completion_value = ecma_op_set_mutable_binding (object_p,
				property_p,
				value,
				is_strict);
	}
	ecma_free_value (object);
	ecma_free_value (property);
	return completion_value;
}
static const uint16_t vm_decode_table[]  =
{
	VM_OC_NONE, (VM_OC_JUMP) | VM_OC_GET_BRANCH, (VM_OC_JUMP) | VM_OC_GET_BRANCH, (VM_OC_JUMP) | VM_OC_GET_BRANCH, VM_OC_POP, (VM_OC_JUMP) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_JUMP) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_JUMP) | VM_OC_GET_BRANCH | 0x4000, VM_OC_POP_BLOCK | VM_OC_PUT_BLOCK, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH, VM_OC_THROW | VM_OC_GET_STACK, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_BRANCH_IF_TRUE) | VM_OC_GET_BRANCH | 0x4000, VM_OC_CONTEXT_END, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH, VM_OC_PUSH_OBJECT | VM_OC_PUT_STACK, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_BRANCH_IF_FALSE) | VM_OC_GET_BRANCH | 0x4000, VM_OC_SET_PROPERTY | (0x1 << 14) | VM_OC_GET_STACK_LITERAL, (VM_OC_JUMP_AND_EXIT_CONTEXT) | VM_OC_GET_BRANCH, (VM_OC_JUMP_AND_EXIT_CONTEXT) | VM_OC_GET_BRANCH, (VM_OC_JUMP_AND_EXIT_CONTEXT) | VM_OC_GET_BRANCH, VM_OC_PUSH_ARRAY | VM_OC_PUT_STACK, (VM_OC_BRANCH_IF_LOGICAL_TRUE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_LOGICAL_TRUE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_LOGICAL_TRUE) | VM_OC_GET_BRANCH, VM_OC_APPEND_ARRAY, (VM_OC_BRANCH_IF_LOGICAL_FALSE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_LOGICAL_FALSE) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_LOGICAL_FALSE) | VM_OC_GET_BRANCH, VM_OC_PUSH_ELISON | VM_OC_PUT_STACK, (VM_OC_BRANCH_IF_STRICT_EQUAL) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_STRICT_EQUAL) | VM_OC_GET_BRANCH, (VM_OC_BRANCH_IF_STRICT_EQUAL) | VM_OC_GET_BRANCH, VM_OC_PUSH | VM_OC_GET_LITERAL, VM_OC_PUSH_TWO | VM_OC_GET_LITERAL_LITERAL, VM_OC_PUSH_THREE | VM_OC_GET_LITERAL_LITERAL, VM_OC_PUSH_UNDEFINED | VM_OC_PUT_STACK, VM_OC_PUSH_TRUE | VM_OC_PUT_STACK, VM_OC_PUSH_FALSE | VM_OC_PUT_STACK, VM_OC_PUSH_NULL | VM_OC_PUT_STACK, VM_OC_PUSH_THIS | VM_OC_PUT_STACK, VM_OC_PUSH_TWO | VM_OC_GET_THIS_LITERAL, VM_OC_PUSH_0 | VM_OC_PUT_STACK, VM_OC_PUSH_POS_BYTE | VM_OC_PUT_STACK, VM_OC_PUSH_NEG_BYTE | VM_OC_PUT_STACK, VM_OC_PROP_GET | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, VM_OC_PROP_GET | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, VM_OC_PROP_GET | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, VM_OC_PROP_GET | VM_OC_GET_THIS_LITERAL | VM_OC_PUT_STACK, VM_OC_IDENT_REFERENCE | VM_OC_PUT_STACK, VM_OC_PROP_REFERENCE | VM_OC_PUT_STACK, VM_OC_PROP_REFERENCE | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, VM_OC_PROP_REFERENCE | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, VM_OC_PROP_REFERENCE | VM_OC_GET_THIS_LITERAL | VM_OC_PUT_STACK, VM_OC_NEW | VM_OC_PUT_STACK, VM_OC_NEW | VM_OC_PUT_STACK, VM_OC_NEW | VM_OC_PUT_STACK, VM_OC_EVAL, VM_OC_NONE, VM_OC_NONE, VM_OC_NONE, VM_OC_NONE, VM_OC_RET | VM_OC_GET_STACK, VM_OC_RET, VM_OC_RET | VM_OC_GET_LITERAL, VM_OC_SET_PROPERTY | (0x1 << 14) | VM_OC_GET_LITERAL_LITERAL, VM_OC_BREAKPOINT_ENABLED, VM_OC_BREAKPOINT_DISABLED, (VM_OC_PLUS) | VM_OC_GET_STACK | VM_OC_PUT_STACK, (VM_OC_PLUS) | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, (VM_OC_MINUS) | VM_OC_GET_STACK | VM_OC_PUT_STACK, (VM_OC_MINUS) | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, (VM_OC_NOT) | VM_OC_GET_STACK | VM_OC_PUT_STACK, (VM_OC_NOT) | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_NOT) | VM_OC_GET_STACK | VM_OC_PUT_STACK, (VM_OC_BIT_NOT) | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, (VM_OC_VOID) | VM_OC_GET_STACK | VM_OC_PUT_STACK, (VM_OC_VOID) | VM_OC_GET_LITERAL | VM_OC_PUT_STACK, VM_OC_TYPEOF | VM_OC_GET_STACK | VM_OC_PUT_STACK, VM_OC_TYPEOF_IDENT | VM_OC_PUT_STACK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_OR) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_XOR) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_BIT_AND) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_NOT_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_NOT_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_NOT_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_STRICT_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_STRICT_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_STRICT_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_STRICT_NOT_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_STRICT_NOT_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_STRICT_NOT_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_LESS) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_LESS) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_LESS) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_GREATER) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_GREATER) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_GREATER) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_LESS_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_LESS_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_LESS_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_GREATER_EQUAL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_GREATER_EQUAL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_GREATER_EQUAL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_IN) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_IN) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_IN) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_INSTANCEOF) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_INSTANCEOF) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_INSTANCEOF) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_ADD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_ADD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_ADD) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_SUB) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_SUB) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_SUB) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_MUL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_MUL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_MUL) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_DIV) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_DIV) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_DIV) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, (VM_OC_MOD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, (VM_OC_MOD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_STACK, (VM_OC_MOD) | VM_OC_GET_LITERAL_LITERAL | VM_OC_PUT_STACK, VM_OC_PROP_DELETE | VM_OC_GET_STACK_STACK | VM_OC_PUT_STACK, VM_OC_DELETE | VM_OC_PUT_STACK, (VM_OC_PROP_PRE_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_PROP_PRE_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_PROP_PRE_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_PRE_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT, (VM_OC_PRE_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, (VM_OC_PRE_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, (VM_OC_PROP_PRE_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_PROP_PRE_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_PROP_PRE_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_PRE_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT, (VM_OC_PRE_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, (VM_OC_PRE_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, (VM_OC_PROP_POST_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_PROP_POST_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_PROP_POST_INCR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_POST_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT, (VM_OC_POST_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, (VM_OC_POST_INCR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, (VM_OC_PROP_POST_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_PROP_POST_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_PROP_POST_DECR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_POST_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT, (VM_OC_POST_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, (VM_OC_POST_DECR) | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_CALL, VM_OC_CALL | VM_OC_PUT_STACK, VM_OC_CALL | VM_OC_PUT_BLOCK, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_REFERENCE, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_IDENT, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, VM_OC_ASSIGN | VM_OC_GET_STACK | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, VM_OC_ASSIGN | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT, VM_OC_ASSIGN | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_STACK, VM_OC_ASSIGN | VM_OC_GET_LITERAL | VM_OC_PUT_IDENT | VM_OC_PUT_BLOCK, VM_OC_ASSIGN_PROP | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE, VM_OC_ASSIGN_PROP | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, VM_OC_ASSIGN_PROP | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, VM_OC_ASSIGN_PROP_THIS | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE, VM_OC_ASSIGN_PROP_THIS | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, VM_OC_ASSIGN_PROP_THIS | VM_OC_GET_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_ADD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_ADD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_SUB) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_SUB) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_MUL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_MUL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_DIV) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_DIV) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_MOD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_MOD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_BIT_AND) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_BIT_AND) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_BIT_OR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_BIT_OR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE, VM_OC_NONE,
		VM_OC_NONE, (VM_OC_WITH) | VM_OC_GET_BRANCH, (VM_OC_WITH) | VM_OC_GET_BRANCH, (VM_OC_WITH) | VM_OC_GET_BRANCH, VM_OC_FOR_IN_GET_NEXT | VM_OC_PUT_STACK, (VM_OC_FOR_IN_CREATE_CONTEXT) | VM_OC_GET_BRANCH, (VM_OC_FOR_IN_CREATE_CONTEXT) | VM_OC_GET_BRANCH, (VM_OC_FOR_IN_CREATE_CONTEXT) | VM_OC_GET_BRANCH, VM_OC_SET_GETTER | (0x1 << 14) | VM_OC_GET_LITERAL_LITERAL, (VM_OC_FOR_IN_HAS_NEXT) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_FOR_IN_HAS_NEXT) | VM_OC_GET_BRANCH | 0x4000, (VM_OC_FOR_IN_HAS_NEXT) | VM_OC_GET_BRANCH | 0x4000, VM_OC_SET_SETTER | (0x1 << 14) | VM_OC_GET_LITERAL_LITERAL, (VM_OC_TRY) | VM_OC_GET_BRANCH, (VM_OC_TRY) | VM_OC_GET_BRANCH, (VM_OC_TRY) | VM_OC_GET_BRANCH, VM_OC_THROW_REFERENCE_ERROR, (VM_OC_CATCH) | VM_OC_GET_BRANCH, (VM_OC_CATCH) | VM_OC_GET_BRANCH, (VM_OC_CATCH) | VM_OC_GET_BRANCH, VM_OC_PUSH_UNDEFINED_BASE | VM_OC_PUT_STACK, (VM_OC_FINALLY) | VM_OC_GET_BRANCH, (VM_OC_FINALLY) | VM_OC_GET_BRANCH, (VM_OC_FINALLY) | VM_OC_GET_BRANCH, VM_OC_CLASS_EXPR_CONTEXT_END, (VM_OC_CLASS_HERITAGE) | VM_OC_GET_BRANCH, (VM_OC_CLASS_HERITAGE) | VM_OC_GET_BRANCH, (VM_OC_CLASS_HERITAGE) | VM_OC_GET_BRANCH, VM_OC_PUSH_LIT_0 | VM_OC_GET_LITERAL, VM_OC_PUSH_LIT_POS_BYTE | VM_OC_GET_LITERAL, VM_OC_PUSH_LIT_NEG_BYTE | VM_OC_GET_LITERAL, VM_OC_RESOURCE_NAME, VM_OC_LINE, VM_OC_SET_COMPUTED_PROPERTY | (0x1 << 14) | VM_OC_GET_STACK_STACK, VM_OC_SET_COMPUTED_PROPERTY | (0x1 << 14) | VM_OC_GET_STACK_LITERAL, VM_OC_SET_GETTER | (0x1 << 14) | VM_OC_GET_STACK_LITERAL, VM_OC_SET_SETTER | (0x1 << 14) | VM_OC_GET_STACK_LITERAL, VM_OC_SET_PROPERTY | VM_OC_GET_LITERAL_LITERAL, VM_OC_SET_COMPUTED_PROPERTY | VM_OC_GET_STACK_LITERAL, VM_OC_SET_GETTER | VM_OC_GET_LITERAL_LITERAL, VM_OC_SET_SETTER | VM_OC_GET_LITERAL_LITERAL, VM_OC_SET_GETTER | VM_OC_GET_STACK_LITERAL, VM_OC_SET_SETTER | VM_OC_GET_STACK_LITERAL, VM_OC_CLASS_INHERITANCE, VM_OC_PUSH_CLASS_CONSTRUCTOR | VM_OC_PUT_STACK, VM_OC_PUSH_IMPL_CONSTRUCTOR, VM_OC_SET_CLASS_CONSTRUCTOR | VM_OC_GET_LITERAL, VM_OC_CLASS_EVAL, VM_OC_SUPER_CALL, VM_OC_SUPER_CALL | VM_OC_PUT_STACK, VM_OC_SUPER_CALL | VM_OC_PUT_BLOCK, VM_OC_PUSH_CONSTRUCTOR_SUPER | VM_OC_PUT_STACK, VM_OC_PUSH_CONSTRUCTOR_SUPER | VM_OC_PUT_STACK, VM_OC_PUSH_SUPER | VM_OC_PUT_STACK, VM_OC_PUSH_SUPER | VM_OC_PUT_STACK, VM_OC_PUSH_CONSTRUCTOR_THIS | VM_OC_PUT_STACK, VM_OC_SUPER_PROP_REFERENCE, VM_OC_SUPER_PROP_REFERENCE, VM_OC_CONSTRUCTOR_RET | VM_OC_GET_STACK, (VM_OC_ADD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_ADD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_SUB) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_SUB) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_MUL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_MUL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_DIV) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_DIV) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_MOD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_MOD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_STACK, (VM_OC_ADD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_ADD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_SUB) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_SUB) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_MUL) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_MUL) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_DIV) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_DIV) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_MOD) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_MOD) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_LEFT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_UNS_RIGHT_SHIFT) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_AND) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_OR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_STACK | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, (VM_OC_BIT_XOR) | VM_OC_GET_STACK_LITERAL | VM_OC_PUT_REFERENCE | VM_OC_PUT_BLOCK, VM_OC_NONE,
};
	ecma_value_t
vm_run_global (const ecma_compiled_code_t *bytecode_p)
{
	ecma_object_t *glob_obj_p = ecma_builtin_get_global ();
	return vm_run (bytecode_p,
			ecma_make_object_value (glob_obj_p),
			ecma_get_global_environment (),
			0,
			((void *)0),
			0);
}
	ecma_value_t
vm_run_eval (ecma_compiled_code_t *bytecode_data_p,
		uint32_t parse_opts)
{
	ecma_value_t this_binding;
	ecma_object_t *lex_env_p;
	if (parse_opts & ECMA_PARSE_DIRECT_EVAL)
	{
		this_binding = ecma_copy_value ((jerry_global_context.vm_top_context_p)->this_binding);
		lex_env_p = (jerry_global_context.vm_top_context_p)->lex_env_p;
	}
	else
	{
		ecma_object_t *global_obj_p = ecma_builtin_get_global ();
		ecma_ref_object (global_obj_p);
		this_binding = ecma_make_object_value (global_obj_p);
		lex_env_p = ecma_get_global_environment ();
	}
	ecma_ref_object (lex_env_p);
	if ((bytecode_data_p->status_flags & CBC_CODE_FLAGS_STRICT_MODE) != 0)
	{
		ecma_object_t *strict_lex_env_p = ecma_create_decl_lex_env (lex_env_p);
		ecma_deref_object (lex_env_p);
		lex_env_p = strict_lex_env_p;
	}
	ecma_value_t completion_value = vm_run (bytecode_data_p,
			this_binding,
			lex_env_p,
			parse_opts,
			((void *)0),
			0);
	ecma_deref_object (lex_env_p);
	ecma_free_value (this_binding);
	ecma_bytecode_deref (bytecode_data_p);
	return completion_value;
}
	static ecma_value_t
vm_construct_literal_object (vm_frame_ctx_t *frame_ctx_p,
		ecma_value_t lit_value)
{
	ecma_compiled_code_t *bytecode_p;
		bytecode_p = ((ecma_compiled_code_t *) (jmem_decompress_pointer (lit_value)));
	if (!(bytecode_p->status_flags & CBC_CODE_FLAGS_FUNCTION))
	{
		ecma_value_t ret_value;
		ret_value = ecma_op_create_regexp_object_from_bytecode ((re_compiled_code_t *) bytecode_p);
		if ((((ret_value) == ECMA_VALUE_ERROR)))
		{
			return ECMA_VALUE_UNDEFINED;
		}
		return ret_value;
	}
	do { if ((!(bytecode_p->status_flags & CBC_CODE_FLAGS_FUNCTION))) { jerry_assert_fail ("bytecode_p->status_flags & CBC_CODE_FLAGS_FUNCTION", "sao-vm.c", __func__, 337); } } while (0);
	ecma_object_t *func_obj_p;
	if (!(bytecode_p->status_flags & CBC_CODE_FLAGS_ARROW_FUNCTION))
	{
		func_obj_p = ecma_op_create_function_object (frame_ctx_p->lex_env_p,
				bytecode_p);
	}
	else
	{
		func_obj_p = ecma_op_create_arrow_function_object (frame_ctx_p->lex_env_p,
				bytecode_p,
				frame_ctx_p->this_binding);
	}
	return ecma_make_object_value (func_obj_p);
}
	static inline _Bool
vm_get_implicit_this_value (ecma_value_t *this_value_p)
{
	if (ecma_is_value_object (*this_value_p))
	{
		ecma_object_t *this_obj_p = ecma_get_object_from_value (*this_value_p);
		if (ecma_is_lexical_environment (this_obj_p))
		{
			ecma_value_t completion_value = ecma_op_implicit_this_value (this_obj_p);
			do { if ((!(!(((completion_value) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("!ECMA_IS_VALUE_ERROR (completion_value)", "sao-vm.c", __func__, 377); } } while (0);
			*this_value_p = completion_value;
			return 1;
		}
	}
	return 0;
}
	static void
vm_super_call (vm_frame_ctx_t *frame_ctx_p)
{
	do { if ((!(frame_ctx_p->call_operation == VM_EXEC_SUPER_CALL))) { jerry_assert_fail ("frame_ctx_p->call_operation == VM_EXEC_SUPER_CALL", "sao-vm.c", __func__, 393); } } while (0);
	do { if ((!(frame_ctx_p->byte_code_p[0] == CBC_EXT_OPCODE))) { jerry_assert_fail ("frame_ctx_p->byte_code_p[0] == CBC_EXT_OPCODE", "sao-vm.c", __func__, 394); } } while (0);
	uint32_t arguments_list_len = frame_ctx_p->byte_code_p[2];
	ecma_value_t *stack_top_p = frame_ctx_p->stack_top_p - arguments_list_len;
	ecma_value_t func_value = stack_top_p[-1];
	ecma_value_t completion_value;
	ecma_op_set_super_called (frame_ctx_p->lex_env_p);
	ecma_value_t this_value = ecma_op_get_class_this_binding (frame_ctx_p->lex_env_p);
	if (!ecma_is_constructor (func_value))
	{
		completion_value = ecma_raise_type_error ("Class extends value is not a constructor.");
	}
	else
	{
		completion_value = ecma_op_function_construct (ecma_get_object_from_value (func_value),
				this_value,
				stack_top_p,
				arguments_list_len);
		if (this_value != completion_value && ecma_is_value_object (completion_value))
		{
			ecma_op_set_class_prototype (completion_value, this_value);
			ecma_op_set_class_this_binding (frame_ctx_p->lex_env_p, completion_value);
		}
	}
	for (uint32_t i = 0; i < arguments_list_len; i++)
	{
		ecma_fast_free_value (stack_top_p[i]);
	}
	ecma_free_value (stack_top_p[-1]);
	stack_top_p[-1] = completion_value;
	frame_ctx_p->stack_top_p = stack_top_p;
	frame_ctx_p->call_operation = VM_EXEC_CALL;
}
	static void
opfunc_call (vm_frame_ctx_t *frame_ctx_p)
{
	uint8_t opcode = frame_ctx_p->byte_code_p[0];
	uint32_t arguments_list_len;
	if (opcode >= CBC_CALL0)
	{
		arguments_list_len = (unsigned int) ((opcode - CBC_CALL0) / 6);
	}
	else
	{
		arguments_list_len = frame_ctx_p->byte_code_p[1];
	}
	_Bool is_call_prop = ((opcode - CBC_CALL) % 6) >= 3;
	ecma_value_t this_value = ECMA_VALUE_UNDEFINED;
	ecma_value_t *stack_top_p = frame_ctx_p->stack_top_p - arguments_list_len;
	if (is_call_prop)
	{
		this_value = stack_top_p[-3];
		if (this_value == ECMA_VALUE_REGISTER_REF)
		{
			stack_top_p[-2] = ECMA_VALUE_UNDEFINED;
			this_value = ECMA_VALUE_UNDEFINED;
		}
		else if (vm_get_implicit_this_value (&this_value))
		{
			ecma_free_value (stack_top_p[-3]);
			stack_top_p[-3] = this_value;
		}
	}
	ecma_value_t func_value = stack_top_p[-1];
	ecma_value_t completion_value;
	if (!ecma_op_is_callable (func_value))
	{
		completion_value = ecma_raise_type_error (((void *)0));
	}
	else
	{
		ecma_object_t *func_obj_p = ecma_get_object_from_value (func_value);
		completion_value = ecma_op_function_call (func_obj_p,
				this_value,
				stack_top_p,
				arguments_list_len);
	}
	(jerry_global_context.status_flags) &= (uint32_t) ~ECMA_STATUS_DIRECT_EVAL;
	for (uint32_t i = 0; i < arguments_list_len; i++)
	{
		ecma_fast_free_value (stack_top_p[i]);
	}
	if (is_call_prop)
	{
		ecma_free_value (*(--stack_top_p));
		ecma_free_value (*(--stack_top_p));
	}
	ecma_free_value (stack_top_p[-1]);
	stack_top_p[-1] = completion_value;
	frame_ctx_p->stack_top_p = stack_top_p;
}
	static void
opfunc_construct (vm_frame_ctx_t *frame_ctx_p)
{
	uint8_t opcode = frame_ctx_p->byte_code_p[0];
	unsigned int arguments_list_len;
	if (opcode >= CBC_NEW0)
	{
		arguments_list_len = (unsigned int) (opcode - CBC_NEW0);
	}
	else
	{
		arguments_list_len = frame_ctx_p->byte_code_p[1];
	}
	ecma_value_t *stack_top_p = frame_ctx_p->stack_top_p - arguments_list_len;
	ecma_value_t constructor_value = stack_top_p[-1];
	ecma_value_t completion_value;
	if (!ecma_is_constructor (constructor_value))
	{
		completion_value = ecma_raise_type_error (((void *)0));
	}
	else
	{
		ecma_object_t *constructor_obj_p = ecma_get_object_from_value (constructor_value);
		completion_value = ecma_op_function_construct (constructor_obj_p,
				ECMA_VALUE_UNDEFINED,
				stack_top_p,
				arguments_list_len);
	}
	for (uint32_t i = 0; i < arguments_list_len; i++)
	{
		ecma_fast_free_value (stack_top_p[i]);
	}
	ecma_free_value (stack_top_p[-1]);
	stack_top_p[-1] = completion_value;
	frame_ctx_p->stack_top_p = stack_top_p;
}
	static void
vm_init_loop (vm_frame_ctx_t *frame_ctx_p)
{
	const ecma_compiled_code_t *bytecode_header_p = frame_ctx_p->bytecode_header_p;
	uint8_t *byte_code_p = frame_ctx_p->byte_code_p;
	uint16_t encoding_limit;
	uint16_t encoding_delta;
	uint16_t register_end;
	ecma_value_t *literal_start_p = frame_ctx_p->literal_start_p;
	_Bool is_strict = ((frame_ctx_p->bytecode_header_p->status_flags & CBC_CODE_FLAGS_STRICT_MODE) != 0);
	ecma_value_t self_reference;
	(self_reference) = jmem_compress_pointer (bytecode_header_p);
	if (!(bytecode_header_p->status_flags & CBC_CODE_FLAGS_FULL_LITERAL_ENCODING))
	{
		encoding_limit = 255;
		encoding_delta = 0xfe01;
	}
	else
	{
		encoding_limit = 128;
		encoding_delta = 0x8000;
	}
	if (frame_ctx_p->bytecode_header_p->status_flags & CBC_CODE_FLAGS_UINT16_ARGUMENTS)
	{
		cbc_uint16_arguments_t *args_p = (cbc_uint16_arguments_t *) (frame_ctx_p->bytecode_header_p);
		register_end = args_p->register_end;
	}
	else
	{
		cbc_uint8_arguments_t *args_p = (cbc_uint8_arguments_t *) (frame_ctx_p->bytecode_header_p);
		register_end = args_p->register_end;
	}
	while (1)
	{
		switch (*byte_code_p)
		{
			case CBC_DEFINE_VARS:
				{
					uint32_t literal_index_end;
					uint32_t literal_index = register_end;
					byte_code_p++;
					do { (literal_index_end) = *byte_code_p++; if ((literal_index_end) >= encoding_limit) { (literal_index_end) = (uint16_t) ((((literal_index_end) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
					while (literal_index <= literal_index_end)
					{
						ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]);
						vm_var_decl (frame_ctx_p, name_p);
						literal_index++;
					}
					break;
				}
			case CBC_INITIALIZE_VAR:
			case CBC_INITIALIZE_VARS:
				{
					uint8_t type = *byte_code_p;
					uint32_t literal_index;
					uint32_t literal_index_end;
					byte_code_p++;
					do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
					if (type == CBC_INITIALIZE_VAR)
					{
						literal_index_end = literal_index;
					}
					else
					{
						do { (literal_index_end) = *byte_code_p++; if ((literal_index_end) >= encoding_limit) { (literal_index_end) = (uint16_t) ((((literal_index_end) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
					}
					while (literal_index <= literal_index_end)
					{
						uint32_t value_index;
						ecma_value_t lit_value;
						_Bool is_immutable_binding = 0;
						do { (value_index) = *byte_code_p++; if ((value_index) >= encoding_limit) { (value_index) = (uint16_t) ((((value_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
						if (value_index < register_end)
						{
							lit_value = frame_ctx_p->registers_p[value_index];
						}
						else
						{
							is_immutable_binding = (self_reference == literal_start_p[value_index]);
							lit_value = vm_construct_literal_object (frame_ctx_p,
									literal_start_p[value_index]);
						}
						if (literal_index < register_end)
						{
							frame_ctx_p->registers_p[literal_index] = lit_value;
						}
						else
						{
							ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]);
							if ((!is_immutable_binding))
							{
								vm_var_decl (frame_ctx_p, name_p);
								ecma_object_t *ref_base_lex_env_p = ecma_op_resolve_reference_base (frame_ctx_p->lex_env_p, name_p);
								ecma_value_t put_value_result = ecma_op_put_value_lex_env_base (ref_base_lex_env_p,
										name_p,
										is_strict,
										lit_value);
								do { if ((!(ecma_is_value_boolean (put_value_result) || ecma_is_value_empty (put_value_result) || (((put_value_result) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("ecma_is_value_boolean (put_value_result) || ecma_is_value_empty (put_value_result) || ECMA_IS_VALUE_ERROR (put_value_result)", "sao-vm.c", __func__, 761); } } while (0);
								if ((((put_value_result) == ECMA_VALUE_ERROR)))
								{
									ecma_free_value ((jerry_global_context.error_value));
								}
							}
							else
							{
								ecma_op_create_immutable_binding (frame_ctx_p->lex_env_p, name_p, lit_value);
							}
							if (value_index >= register_end)
							{
								ecma_free_value (lit_value);
							}
						}
						literal_index++;
					}
					break;
				}
			default:
				{
					frame_ctx_p->byte_code_p = byte_code_p;
					return;
				}
		}
	}
}
	static ecma_value_t
vm_loop (vm_frame_ctx_t *frame_ctx_p)
{
	const ecma_compiled_code_t *bytecode_header_p = frame_ctx_p->bytecode_header_p;
	uint8_t *byte_code_p = frame_ctx_p->byte_code_p;
	ecma_value_t *literal_start_p = frame_ctx_p->literal_start_p;
	ecma_value_t *stack_top_p;
	uint16_t encoding_limit;
	uint16_t encoding_delta;
	uint16_t register_end;
	uint16_t ident_end;
	uint16_t const_literal_end;
	int32_t branch_offset = 0;
	uint8_t branch_offset_length = 0;
	ecma_value_t left_value;
	ecma_value_t right_value;
	ecma_value_t result = ECMA_VALUE_EMPTY;
	ecma_value_t block_result = ECMA_VALUE_UNDEFINED;
	_Bool is_strict = ((frame_ctx_p->bytecode_header_p->status_flags & CBC_CODE_FLAGS_STRICT_MODE) != 0);
	if (!(bytecode_header_p->status_flags & CBC_CODE_FLAGS_FULL_LITERAL_ENCODING))
	{
		encoding_limit = 255;
		encoding_delta = 0xfe01;
	}
	else
	{
		encoding_limit = 128;
		encoding_delta = 0x8000;
	}
	if (bytecode_header_p->status_flags & CBC_CODE_FLAGS_UINT16_ARGUMENTS)
	{
		cbc_uint16_arguments_t *args_p = (cbc_uint16_arguments_t *) (bytecode_header_p);
		register_end = args_p->register_end;
		ident_end = args_p->ident_end;
		const_literal_end = args_p->const_literal_end;
	}
	else
	{
		cbc_uint8_arguments_t *args_p = (cbc_uint8_arguments_t *) (bytecode_header_p);
		register_end = args_p->register_end;
		ident_end = args_p->ident_end;
		const_literal_end = args_p->const_literal_end;
	}
	stack_top_p = frame_ctx_p->stack_top_p;
	while (1)
	{
		while (1)
		{
			uint8_t *byte_code_start_p = byte_code_p;
			uint8_t opcode = *byte_code_p++;
			uint32_t opcode_data = opcode;
			if (opcode == CBC_EXT_OPCODE)
			{
				opcode = *byte_code_p++;
				opcode_data = (uint32_t) ((CBC_END + 1) + opcode);
			}
			opcode_data = vm_decode_table[opcode_data];
			left_value = ECMA_VALUE_UNDEFINED;
			right_value = ECMA_VALUE_UNDEFINED;
			uint32_t operands = ((opcode_data) & (0x7 << 7));
			if (operands >= VM_OC_GET_LITERAL)
			{
				uint16_t literal_index;
				do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
				do { if ((literal_index) < ident_end) { if ((literal_index) < register_end) { (left_value) = ecma_fast_copy_value (frame_ctx_p->registers_p[literal_index]); } else { ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]); result = ecma_op_resolve_reference_value (frame_ctx_p->lex_env_p, name_p); if ((((result) == ECMA_VALUE_ERROR))) { goto error; } (left_value) = result; } } else if (literal_index < const_literal_end) { (left_value) = ecma_fast_copy_value (literal_start_p[literal_index]); } else { (left_value) = vm_construct_literal_object (frame_ctx_p, literal_start_p[literal_index]); } } while (0);
				if (operands != VM_OC_GET_LITERAL)
				{
					switch (operands)
					{
						case VM_OC_GET_LITERAL_LITERAL:
							{
								uint16_t second_literal_index;
								do { (second_literal_index) = *byte_code_p++; if ((second_literal_index) >= encoding_limit) { (second_literal_index) = (uint16_t) ((((second_literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
								do { if ((second_literal_index) < ident_end) { if ((second_literal_index) < register_end) { (right_value) = ecma_fast_copy_value (frame_ctx_p->registers_p[second_literal_index]); } else { ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[second_literal_index]); result = ecma_op_resolve_reference_value (frame_ctx_p->lex_env_p, name_p); if ((((result) == ECMA_VALUE_ERROR))) { goto error; } (right_value) = result; } } else if (second_literal_index < const_literal_end) { (right_value) = ecma_fast_copy_value (literal_start_p[second_literal_index]); } else { (right_value) = vm_construct_literal_object (frame_ctx_p, literal_start_p[second_literal_index]); } } while (0);
								break;
							}
						case VM_OC_GET_STACK_LITERAL:
							{
								do { if ((!(stack_top_p > frame_ctx_p->registers_p + register_end))) { jerry_assert_fail ("stack_top_p > frame_ctx_p->registers_p + register_end", "sao-vm.c", __func__, 899); } } while (0);
								right_value = left_value;
								left_value = *(--stack_top_p);
								break;
							}
						default:
							{
								do { if ((!(operands == VM_OC_GET_THIS_LITERAL))) { jerry_assert_fail ("operands == VM_OC_GET_THIS_LITERAL", "sao-vm.c", __func__, 906); } } while (0);
								right_value = left_value;
								left_value = ecma_copy_value (frame_ctx_p->this_binding);
								break;
							}
					}
				}
			}
			else if (operands >= VM_OC_GET_STACK)
			{
				do { if ((!(operands == VM_OC_GET_STACK || operands == VM_OC_GET_STACK_STACK))) { jerry_assert_fail ("operands == VM_OC_GET_STACK || operands == VM_OC_GET_STACK_STACK", "sao-vm.c", __func__, 918); } } while (0);
				do { if ((!(stack_top_p > frame_ctx_p->registers_p + register_end))) { jerry_assert_fail ("stack_top_p > frame_ctx_p->registers_p + register_end", "sao-vm.c", __func__, 920); } } while (0);
				left_value = *(--stack_top_p);
				if (operands == VM_OC_GET_STACK_STACK)
				{
					do { if ((!(stack_top_p > frame_ctx_p->registers_p + register_end))) { jerry_assert_fail ("stack_top_p > frame_ctx_p->registers_p + register_end", "sao-vm.c", __func__, 925); } } while (0);
					right_value = left_value;
					left_value = *(--stack_top_p);
				}
			}
			else if (operands == VM_OC_GET_BRANCH)
			{
				branch_offset_length = ((opcode) & 0x3);
				do { if ((!(branch_offset_length >= 1 && branch_offset_length <= 3))) { jerry_assert_fail ("branch_offset_length >= 1 && branch_offset_length <= 3", "sao-vm.c", __func__, 933); } } while (0);
				branch_offset = *(byte_code_p++);
				if ((branch_offset_length != 1))
				{
					branch_offset <<= 8;
					branch_offset |= *(byte_code_p++);
					if ((branch_offset_length == 3))
					{
						branch_offset <<= 8;
						branch_offset |= *(byte_code_p++);
					}
				}
				if (opcode_data & 0x4000)
				{
					branch_offset = -branch_offset;
				}
			}
			switch (((opcode_data) & 0x7f))
			{
				case VM_OC_POP:
					{
						do { if ((!(stack_top_p > frame_ctx_p->registers_p + register_end))) { jerry_assert_fail ("stack_top_p > frame_ctx_p->registers_p + register_end", "sao-vm.c", __func__, 989); } } while (0);
						ecma_free_value (*(--stack_top_p));
						continue;
					}
				case VM_OC_POP_BLOCK:
					{
						ecma_fast_free_value (block_result);
						block_result = *(--stack_top_p);
						continue;
					}
				case VM_OC_PUSH:
					{
						*stack_top_p++ = left_value;
						continue;
					}
				case VM_OC_PUSH_TWO:
					{
						*stack_top_p++ = left_value;
						*stack_top_p++ = right_value;
						continue;
					}
				case VM_OC_PUSH_THREE:
					{
						uint16_t literal_index;
						*stack_top_p++ = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
						do { if ((literal_index) < ident_end) { if ((literal_index) < register_end) { (left_value) = ecma_fast_copy_value (frame_ctx_p->registers_p[literal_index]); } else { ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]); result = ecma_op_resolve_reference_value (frame_ctx_p->lex_env_p, name_p); if ((((result) == ECMA_VALUE_ERROR))) { goto error; } (left_value) = result; } } else if (literal_index < const_literal_end) { (left_value) = ecma_fast_copy_value (literal_start_p[literal_index]); } else { (left_value) = vm_construct_literal_object (frame_ctx_p, literal_start_p[literal_index]); } } while (0);
						*stack_top_p++ = right_value;
						*stack_top_p++ = left_value;
						continue;
					}
				case VM_OC_PUSH_UNDEFINED:
					{
						*stack_top_p++ = ECMA_VALUE_UNDEFINED;
						continue;
					}
				case VM_OC_PUSH_TRUE:
					{
						*stack_top_p++ = ECMA_VALUE_TRUE;
						continue;
					}
				case VM_OC_PUSH_FALSE:
					{
						*stack_top_p++ = ECMA_VALUE_FALSE;
						continue;
					}
				case VM_OC_PUSH_NULL:
					{
						*stack_top_p++ = ECMA_VALUE_NULL;
						continue;
					}
				case VM_OC_PUSH_THIS:
					{
						*stack_top_p++ = ecma_copy_value (frame_ctx_p->this_binding);
						continue;
					}
				case VM_OC_PUSH_0:
					{
						*stack_top_p++ = ecma_make_integer_value (0);
						continue;
					}
				case VM_OC_PUSH_POS_BYTE:
					{
						ecma_integer_value_t number = *byte_code_p++;
						*stack_top_p++ = ecma_make_integer_value (number + 1);
						continue;
					}
				case VM_OC_PUSH_NEG_BYTE:
					{
						ecma_integer_value_t number = *byte_code_p++;
						*stack_top_p++ = ecma_make_integer_value (-(number + 1));
						continue;
					}
				case VM_OC_PUSH_LIT_0:
					{
						stack_top_p[0] = left_value;
						stack_top_p[1] = ecma_make_integer_value (0);
						stack_top_p += 2;
						continue;
					}
				case VM_OC_PUSH_LIT_POS_BYTE:
					{
						ecma_integer_value_t number = *byte_code_p++;
						stack_top_p[0] = left_value;
						stack_top_p[1] = ecma_make_integer_value (number + 1);
						stack_top_p += 2;
						continue;
					}
				case VM_OC_PUSH_LIT_NEG_BYTE:
					{
						ecma_integer_value_t number = *byte_code_p++;
						stack_top_p[0] = left_value;
						stack_top_p[1] = ecma_make_integer_value (-(number + 1));
						stack_top_p += 2;
						continue;
					}
				case VM_OC_PUSH_OBJECT:
					{
						ecma_object_t *obj_p = ecma_create_object (ecma_builtin_get (ECMA_BUILTIN_ID_OBJECT_PROTOTYPE),
								0,
								ECMA_OBJECT_TYPE_GENERAL);
						*stack_top_p++ = ecma_make_object_value (obj_p);
						continue;
					}
				case VM_OC_SET_COMPUTED_PROPERTY:
					{
						left_value ^= right_value;
						right_value ^= left_value;
						left_value ^= right_value;
					}
				case VM_OC_SET_PROPERTY:
					{
						enum { static_assertion_failed_1111_vm_oc_non_static_flag_must_be_equal_to_vm_oc_backward_branch = 1 / (!!((0x1 << 14) == 0x4000)) };
						do { if ((!((opcode_data >> 14) <= 0x1))) { jerry_assert_fail ("(opcode_data >> VM_OC_NON_STATIC_SHIFT) <= 0x1", "sao-vm.c", __func__, 1113); } } while (0);
						result = right_value;
						if ((!ecma_is_value_string (right_value)))
						{
							result = ecma_op_to_string (right_value);
							if ((((result) == ECMA_VALUE_ERROR)))
							{
								goto error;
							}
						}
						ecma_string_t *prop_name_p = ecma_get_string_from_value (result);
						if ((ecma_compare_ecma_string_to_magic_id (prop_name_p, LIT_MAGIC_STRING_PROTOTYPE))
								&& !(opcode_data & (0x1 << 14)))
						{
							if (!ecma_is_value_string (right_value))
							{
								ecma_deref_ecma_string (prop_name_p);
							}
							result = ecma_raise_type_error (((void *)0));
							goto error;
						}
						const int index = (int) (opcode_data >> 14) - 2;
						ecma_object_t *object_p = ecma_get_object_from_value (stack_top_p[index]);
						ecma_property_t *property_p = ecma_find_named_property (object_p, prop_name_p);
						if (property_p != ((void *)0)
								&& ((ecma_property_types_t) ((*property_p) & 0x3)) != ECMA_PROPERTY_TYPE_NAMEDDATA)
						{
							ecma_delete_property (object_p, ((ecma_property_value_t *) (((uintptr_t) ((((uint8_t *) (property_p)) + (sizeof (ecma_property_value_t) * 2 - 1)))) & ~(sizeof (ecma_property_value_t) - 1))));
							property_p = ((void *)0);
						}
						ecma_property_value_t *prop_value_p;
						if (property_p == ((void *)0))
						{
							prop_value_p = ecma_create_named_data_property (object_p,
									prop_name_p,
									(ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_ENUMERABLE | ECMA_PROPERTY_FLAG_WRITABLE),
									((void *)0));
						}
						else
						{
							prop_value_p = ((ecma_property_value_t *) (((uintptr_t) ((((uint8_t *) (property_p)) + (sizeof (ecma_property_value_t) * 2 - 1)))) & ~(sizeof (ecma_property_value_t) - 1)));
						}
						ecma_named_data_property_assign_value (object_p, prop_value_p, left_value);
						if (!ecma_is_value_string (right_value))
						{
							ecma_deref_ecma_string (prop_name_p);
						}
						goto free_both_values;
					}
				case VM_OC_SET_GETTER:
				case VM_OC_SET_SETTER:
					{
						do { if ((!((opcode_data >> 14) <= 0x1))) { jerry_assert_fail ("(opcode_data >> VM_OC_NON_STATIC_SHIFT) <= 0x1", "sao-vm.c", __func__, 1183); } } while (0);
						result = left_value;
						if ((!ecma_is_value_string (left_value)))
						{
							result = ecma_op_to_string (left_value);
							if ((((result) == ECMA_VALUE_ERROR)))
							{
								goto error;
							}
						}
						ecma_string_t *prop_name_p = ecma_get_string_from_value (result);
						if ((ecma_compare_ecma_string_to_magic_id (prop_name_p, LIT_MAGIC_STRING_PROTOTYPE))
								&& !(opcode_data & (0x1 << 14)))
						{
							if (!ecma_is_value_string (left_value))
							{
								ecma_deref_ecma_string (prop_name_p);
							}
							result = ecma_raise_type_error (((void *)0));
							goto error;
						}
						const int index = (int) (opcode_data >> 14) - 2;
						opfunc_set_accessor (((opcode_data) & 0x7f) == VM_OC_SET_GETTER,
								stack_top_p[index],
								prop_name_p,
								right_value);
						if (!ecma_is_value_string (left_value))
						{
							ecma_deref_ecma_string (prop_name_p);
						}
						goto free_both_values;
					}
				case VM_OC_PUSH_ARRAY:
					{
						result = ecma_op_create_array_object (((void *)0), 0, 0);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						continue;
					}
				case VM_OC_SUPER_CALL:
					{
						if (frame_ctx_p->call_operation == VM_NO_EXEC_OP)
						{
							frame_ctx_p->call_operation = VM_EXEC_SUPER_CALL;
							frame_ctx_p->byte_code_p = byte_code_start_p;
							frame_ctx_p->stack_top_p = stack_top_p;
							frame_ctx_p->call_block_result = block_result;
							return ECMA_VALUE_UNDEFINED;
						}
						byte_code_p++;
						frame_ctx_p->call_operation = VM_NO_EXEC_OP;
						result = *(--stack_top_p);
						block_result = frame_ctx_p->call_block_result;
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						if (!(opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK)))
						{
							ecma_fast_free_value (result);
						}
						else if (opcode_data & VM_OC_PUT_STACK)
						{
							*stack_top_p++ = result;
						}
						else
						{
							ecma_fast_free_value (block_result);
							block_result = result;
						}
						continue;
					}
				case VM_OC_CLASS_HERITAGE:
					{
						ecma_value_t super_value = *(--stack_top_p);
						ecma_object_t *super_class_p;
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 1286); } } while (0);
						if (ecma_is_value_null (super_value))
						{
							super_class_p = ecma_create_object (((void *)0), 0, ECMA_OBJECT_TYPE_GENERAL);
						}
						else
						{
							result = ecma_op_to_object (super_value);
							ecma_free_value (super_value);
							if ((((result) == ECMA_VALUE_ERROR)) || !ecma_is_constructor (result))
							{
								if ((((result) == ECMA_VALUE_ERROR)))
								{
									ecma_free_value ((jerry_global_context.error_value));
								}
								ecma_free_value (result);
								result = ecma_raise_type_error ("Value provided by class extends is not an object or null.");
								goto error;
							}
							else
							{
								super_class_p = ecma_get_object_from_value (result);
							}
						}
						ecma_object_t *super_env_p = ecma_create_object_lex_env (frame_ctx_p->lex_env_p,
								super_class_p,
								ECMA_LEXICAL_ENVIRONMENT_SUPER_OBJECT_BOUND);
						ecma_deref_object (super_class_p);
						(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) + (1));
						stack_top_p += 1;
						stack_top_p[-1] = ((ecma_value_t) ((VM_CONTEXT_SUPER_CLASS) | (branch_offset) << 4));
						frame_ctx_p->lex_env_p = super_env_p;
						continue;
					}
				case VM_OC_CLASS_INHERITANCE:
					{
						ecma_value_t child_value = stack_top_p[-2];
						ecma_value_t child_prototype_value = stack_top_p[-1];
						ecma_object_t *child_class_p = ecma_get_object_from_value (child_value);
						ecma_object_t *child_prototype_class_p = ecma_get_object_from_value (child_prototype_value);
						ecma_property_value_t *prop_value_p;
						prop_value_p = ecma_create_named_data_property (child_prototype_class_p,
								ecma_get_magic_string (LIT_MAGIC_STRING_CONSTRUCTOR),
								(ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE),
								((void *)0));
						ecma_named_data_property_assign_value (child_prototype_class_p, prop_value_p, child_value);
						ecma_object_t *super_class_p = ecma_get_lex_env_binding_object (frame_ctx_p->lex_env_p);
						if (ecma_get_object_prototype (super_class_p))
						{
							ecma_value_t super_prototype_value = ecma_op_object_get_by_magic_id (super_class_p,
									LIT_MAGIC_STRING_PROTOTYPE);
							if (ecma_get_object_type (super_class_p) == ECMA_OBJECT_TYPE_BOUND_FUNCTION
									&& !ecma_is_value_object (super_prototype_value))
							{
								ecma_free_value (super_prototype_value);
								result = ecma_raise_type_error (((void *)0));
								goto error;
							}
							if (!((((super_prototype_value) == ECMA_VALUE_ERROR)) || !ecma_is_value_object (super_prototype_value)))
							{
								ecma_object_t *super_prototype_class_p = ecma_get_object_from_value (super_prototype_value);
								do { void *ptr_value = (void *) super_prototype_class_p; if (((ptr_value) == ((void *)0))) { (child_prototype_class_p->prototype_or_outer_reference_cp) = ((jmem_cpointer_t) 0); } else { (child_prototype_class_p->prototype_or_outer_reference_cp) = jmem_compress_pointer (ptr_value); } } while (0);;
								do { void *ptr_value = (void *) super_class_p; if (((ptr_value) == ((void *)0))) { (child_class_p->prototype_or_outer_reference_cp) = ((jmem_cpointer_t) 0); } else { (child_class_p->prototype_or_outer_reference_cp) = jmem_compress_pointer (ptr_value); } } while (0);;
							}
							ecma_free_value (super_prototype_value);
						}
						continue;
					}
				case VM_OC_PUSH_CLASS_CONSTRUCTOR:
					{
						ecma_object_t *prototype_obj_p = ecma_builtin_get (ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE);
						ecma_object_t *function_obj_p = ecma_create_object (prototype_obj_p,
								sizeof (ecma_extended_object_t),
								ECMA_OBJECT_TYPE_EXTERNAL_FUNCTION);
						ecma_extended_object_t *ext_func_obj_p = (ecma_extended_object_t *) function_obj_p;
						ext_func_obj_p->u.external_handler_cb = ecma_op_function_implicit_constructor_handler_cb;
						*stack_top_p++ = ecma_make_object_value (function_obj_p);
						continue;
					}
				case VM_OC_SET_CLASS_CONSTRUCTOR:
					{
						ecma_object_t *new_constructor_obj_p = ecma_get_object_from_value (left_value);
						ecma_object_t *current_constructor_obj_p = ecma_get_object_from_value (stack_top_p[-2]);
						ecma_extended_object_t *new_ext_func_obj_p = (ecma_extended_object_t *) new_constructor_obj_p;
						ecma_extended_object_t *current_ext_func_obj_p = (ecma_extended_object_t *) current_constructor_obj_p;
						uint16_t type_flags_refs = current_constructor_obj_p->type_flags_refs;
						const int new_type = ECMA_OBJECT_TYPE_FUNCTION - ECMA_OBJECT_TYPE_EXTERNAL_FUNCTION;
						current_constructor_obj_p->type_flags_refs = (uint16_t) (type_flags_refs + new_type);
						ecma_compiled_code_t *bytecode_p;
						bytecode_p = (ecma_compiled_code_t *) ecma_op_function_get_compiled_code (new_ext_func_obj_p);
						bytecode_p->status_flags |= CBC_CODE_FLAGS_CONSTRUCTOR;
						ecma_bytecode_ref ((ecma_compiled_code_t *) bytecode_p);
						(current_ext_func_obj_p->u.function.bytecode_cp) = jmem_compress_pointer (bytecode_p);
						(current_ext_func_obj_p->u.function.scope_cp) = jmem_compress_pointer (((const ecma_object_t *) (jmem_decompress_pointer (new_ext_func_obj_p->u.function.scope_cp))));
						ecma_deref_object (new_constructor_obj_p);
						continue;
					}
				case VM_OC_PUSH_IMPL_CONSTRUCTOR:
					{
						ecma_object_t *current_constructor_obj_p = ecma_get_object_from_value (stack_top_p[-2]);
						uint16_t type_flags_refs = current_constructor_obj_p->type_flags_refs;
						const int new_type = ECMA_OBJECT_TYPE_BOUND_FUNCTION - ECMA_OBJECT_TYPE_EXTERNAL_FUNCTION;
						current_constructor_obj_p->type_flags_refs = (uint16_t) (type_flags_refs + new_type);
						ecma_extended_object_t *ext_function_p = (ecma_extended_object_t *) current_constructor_obj_p;
						ecma_object_t *super_obj_p = ecma_op_resolve_super_reference_value (frame_ctx_p->lex_env_p);
						(ext_function_p->u.bound_function.target_function) = jmem_compress_pointer (super_obj_p);
						ext_function_p->u.bound_function.args_len_or_this = ECMA_VALUE_IMPLICIT_CONSTRUCTOR;
						continue;
					}
				case VM_OC_CLASS_EXPR_CONTEXT_END:
					{
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p - 1))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p - 1", "sao-vm.c", __func__, 1431); } } while (0);
						do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-2]) & 0xf)) == VM_CONTEXT_SUPER_CLASS))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-2]) == VM_CONTEXT_SUPER_CLASS", "sao-vm.c", __func__, 1433); } } while (0);
						stack_top_p = vm_stack_context_abort (frame_ctx_p, stack_top_p - 1);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 1436); } } while (0);
						stack_top_p++;
						stack_top_p[-1] = *stack_top_p;
						continue;
					}
				case VM_OC_CLASS_EVAL:
					{
						do { (jerry_global_context.status_flags) |= ((uint32_t) *byte_code_p++ << (32 - 8)) | ECMA_STATUS_DIRECT_EVAL; } while (0);
						continue;
					}
				case VM_OC_PUSH_CONSTRUCTOR_SUPER:
					{
						do { if ((!(byte_code_start_p[0] == CBC_EXT_OPCODE))) { jerry_assert_fail ("byte_code_start_p[0] == CBC_EXT_OPCODE", "sao-vm.c", __func__, 1448); } } while (0);
						_Bool is_super_called = ecma_op_is_super_called (frame_ctx_p->lex_env_p);
						if (byte_code_start_p[1] != CBC_EXT_PUSH_CONSTRUCTOR_SUPER_PROP)
						{
							if (is_super_called)
							{
								result = ecma_raise_reference_error (((void *)0));
								goto error;
							}
						}
						else if (!is_super_called)
						{
							result = ecma_raise_reference_error (((void *)0));
							goto error;
						}
					}
				case VM_OC_PUSH_SUPER:
					{
						do { if ((!(byte_code_start_p[0] == CBC_EXT_OPCODE))) { jerry_assert_fail ("byte_code_start_p[0] == CBC_EXT_OPCODE", "sao-vm.c", __func__, 1474); } } while (0);
						if (byte_code_start_p[1] == CBC_EXT_PUSH_SUPER
								|| byte_code_start_p[1] == CBC_EXT_PUSH_CONSTRUCTOR_SUPER_PROP)
						{
							ecma_object_t *super_class_p = ecma_op_resolve_super_reference_value (frame_ctx_p->lex_env_p);
							ecma_value_t super_prototype = ecma_op_object_get_by_magic_id (super_class_p,
									LIT_MAGIC_STRING_PROTOTYPE);
							if ((((super_prototype) == ECMA_VALUE_ERROR)))
							{
								result = super_prototype;
								goto error;
							}
							*stack_top_p++ = super_prototype;
						}
						else
						{
							ecma_object_t *super_class_p = ecma_op_resolve_super_reference_value (frame_ctx_p->lex_env_p);
							*stack_top_p++ = ecma_fast_copy_value (ecma_make_object_value (super_class_p));
						}
						continue;
					}
				case VM_OC_PUSH_CONSTRUCTOR_THIS:
					{
						if (!ecma_op_is_super_called (frame_ctx_p->lex_env_p))
						{
							result = ecma_raise_reference_error (((void *)0));
							goto error;
						}
						*stack_top_p++ = ecma_copy_value (ecma_op_get_class_this_binding (frame_ctx_p->lex_env_p));
						continue;
					}
				case VM_OC_SUPER_PROP_REFERENCE:
					{
						const int index = (byte_code_start_p[1] == CBC_EXT_SUPER_PROP_ASSIGN) ? -1 : -3;
						ecma_free_value (stack_top_p[index]);
						stack_top_p[index] = ecma_copy_value (frame_ctx_p->this_binding);
						continue;
					}
				case VM_OC_CONSTRUCTOR_RET:
					{
						result = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						if (!ecma_is_value_object (result))
						{
							if (ecma_is_value_undefined (result))
							{
								if (!ecma_op_is_super_called (frame_ctx_p->lex_env_p))
								{
									result = ecma_raise_reference_error (((void *)0));
								}
							}
							else
							{
								ecma_free_value (result);
								result = ecma_raise_type_error (((void *)0));
							}
						}
						goto error;
					}
				case VM_OC_PUSH_ELISON:
					{
						*stack_top_p++ = ECMA_VALUE_ARRAY_HOLE;
						continue;
					}
				case VM_OC_APPEND_ARRAY:
					{
						ecma_object_t *array_obj_p;
						uint32_t length_num;
						uint32_t values_length = *byte_code_p++;
						stack_top_p -= values_length;
						array_obj_p = ecma_get_object_from_value (stack_top_p[-1]);
						ecma_extended_object_t *ext_array_obj_p = (ecma_extended_object_t *) array_obj_p;
						length_num = ext_array_obj_p->u.array.length;
						for (uint32_t i = 0; i < values_length; i++)
						{
							if (!ecma_is_value_array_hole (stack_top_p[i]))
							{
								ecma_string_t *index_str_p = ecma_new_ecma_string_from_uint32 (length_num);
								ecma_property_value_t *prop_value_p;
								prop_value_p = ecma_create_named_data_property (array_obj_p,
										index_str_p,
										(ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_ENUMERABLE | ECMA_PROPERTY_FLAG_WRITABLE),
										((void *)0));
								do { if ((!(ecma_is_value_undefined (prop_value_p->value)))) { jerry_assert_fail ("ecma_is_value_undefined (prop_value_p->value)", "sao-vm.c", __func__, 1575); } } while (0);
								prop_value_p->value = stack_top_p[i];
								if (ecma_is_value_object (stack_top_p[i]))
								{
									ecma_free_value (stack_top_p[i]);
								}
								ecma_deref_ecma_string (index_str_p);
							}
							length_num++;
						}
						ext_array_obj_p->u.array.length = length_num;
						continue;
					}
				case VM_OC_PUSH_UNDEFINED_BASE:
					{
						stack_top_p[0] = stack_top_p[-1];
						stack_top_p[-1] = ECMA_VALUE_UNDEFINED;
						stack_top_p++;
						continue;
					}
				case VM_OC_IDENT_REFERENCE:
					{
						uint16_t literal_index;
						do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
						do { if ((!(literal_index < ident_end))) { jerry_assert_fail ("literal_index < ident_end", "sao-vm.c", __func__, 1606); } } while (0);
						if (literal_index < register_end)
						{
							*stack_top_p++ = ECMA_VALUE_REGISTER_REF;
							*stack_top_p++ = literal_index;
							*stack_top_p++ = ecma_fast_copy_value (frame_ctx_p->registers_p[literal_index]);
						}
						else
						{
							ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]);
							ecma_object_t *ref_base_lex_env_p;
							ref_base_lex_env_p = ecma_op_resolve_reference_base (frame_ctx_p->lex_env_p,
									name_p);
							result = ecma_op_get_value_lex_env_base (ref_base_lex_env_p,
									name_p,
									is_strict);
							if ((((result) == ECMA_VALUE_ERROR)))
							{
								goto error;
							}
							ecma_ref_object (ref_base_lex_env_p);
							ecma_ref_ecma_string (name_p);
							*stack_top_p++ = ecma_make_object_value (ref_base_lex_env_p);
							*stack_top_p++ = ecma_make_string_value (name_p);
							*stack_top_p++ = result;
						}
						continue;
					}
				case VM_OC_PROP_REFERENCE:
					{
						if (opcode == CBC_PUSH_PROP_REFERENCE)
						{
							left_value = stack_top_p[-2];
							right_value = stack_top_p[-1];
						}
						else if (opcode == CBC_PUSH_PROP_LITERAL_REFERENCE)
						{
							*stack_top_p++ = left_value;
							right_value = left_value;
							left_value = stack_top_p[-2];
						}
						else
						{
							do { if ((!(opcode == CBC_PUSH_PROP_LITERAL_LITERAL_REFERENCE || opcode == CBC_PUSH_PROP_THIS_LITERAL_REFERENCE))) { jerry_assert_fail ("opcode == CBC_PUSH_PROP_LITERAL_LITERAL_REFERENCE || opcode == CBC_PUSH_PROP_THIS_LITERAL_REFERENCE", "sao-vm.c", __func__, 1657); } } while (0);
							*stack_top_p++ = left_value;
							*stack_top_p++ = right_value;
						}
					}
				case VM_OC_PROP_GET:
				case VM_OC_PROP_PRE_INCR:
				case VM_OC_PROP_PRE_DECR:
				case VM_OC_PROP_POST_INCR:
				case VM_OC_PROP_POST_DECR:
					{
						result = vm_op_get_value (left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							if (opcode >= CBC_PUSH_PROP_REFERENCE && opcode < CBC_PRE_INCR)
							{
								left_value = ECMA_VALUE_UNDEFINED;
								right_value = ECMA_VALUE_UNDEFINED;
							}
							goto error;
						}
						if (opcode < CBC_PRE_INCR)
						{
							if (opcode >= CBC_PUSH_PROP_REFERENCE)
							{
								left_value = ECMA_VALUE_UNDEFINED;
								right_value = ECMA_VALUE_UNDEFINED;
							}
							break;
						}
						stack_top_p += 2;
						left_value = result;
						right_value = ECMA_VALUE_UNDEFINED;
					}
				case VM_OC_PRE_INCR:
				case VM_OC_PRE_DECR:
				case VM_OC_POST_INCR:
				case VM_OC_POST_DECR:
					{
						uint32_t opcode_flags = ((opcode_data) & 0x7f) - VM_OC_PROP_PRE_INCR;
						byte_code_p = byte_code_start_p + 1;
						if (ecma_is_value_integer_number (left_value))
						{
							result = left_value;
							left_value = ECMA_VALUE_UNDEFINED;
							ecma_integer_value_t int_value = (ecma_integer_value_t) result;
							ecma_integer_value_t int_increase = 0;
							if (opcode_flags & 0x1)
							{
								if (int_value > (-0x7fffffff - 1))
								{
									int_increase = -(1 << 4);
								}
							}
							else if (int_value < 0x7ffffff0)
							{
								int_increase = 1 << 4;
							}
							if ((int_increase != 0))
							{
								if (opcode_flags & 0x2)
								{
									if (opcode_data & VM_OC_PUT_STACK)
									{
										if (opcode_flags & 0x4)
										{
											do { if ((!(opcode == CBC_POST_INCR_IDENT_PUSH_RESULT || opcode == CBC_POST_DECR_IDENT_PUSH_RESULT))) { jerry_assert_fail ("opcode == CBC_POST_INCR_IDENT_PUSH_RESULT || opcode == CBC_POST_DECR_IDENT_PUSH_RESULT", "sao-vm.c", __func__, 1736); } } while (0);
											*stack_top_p++ = result;
										}
										else
										{
											do { if ((!(opcode == CBC_POST_INCR_PUSH_RESULT || opcode == CBC_POST_DECR_PUSH_RESULT))) { jerry_assert_fail ("opcode == CBC_POST_INCR_PUSH_RESULT || opcode == CBC_POST_DECR_PUSH_RESULT", "sao-vm.c", __func__, 1746); } } while (0);
											stack_top_p++;
											stack_top_p[-1] = stack_top_p[-2];
											stack_top_p[-2] = stack_top_p[-3];
											stack_top_p[-3] = result;
										}
										opcode_data &= (uint32_t)~VM_OC_PUT_STACK;
									}
									else if (opcode_data & VM_OC_PUT_BLOCK)
									{
										ecma_free_value (block_result);
										block_result = result;
										opcode_data &= (uint32_t) ~VM_OC_PUT_BLOCK;
									}
								}
								result = (ecma_value_t) (int_value + int_increase);
								break;
							}
						}
						else if (ecma_is_value_float_number (left_value))
						{
							result = left_value;
							left_value = ECMA_VALUE_UNDEFINED;
						}
						else
						{
							result = ecma_op_to_number (left_value);
							if ((((result) == ECMA_VALUE_ERROR)))
							{
								goto error;
							}
						}
						ecma_number_t increase = ((ecma_number_t) 1);
						ecma_number_t result_number = ecma_get_number_from_value (result);
						if (opcode_flags & 0x1)
						{
							increase = ((ecma_number_t) -1);
						}
						if (opcode_flags & 0x2)
						{
							if (opcode_data & VM_OC_PUT_STACK)
							{
								if (opcode_flags & 0x4)
								{
									do { if ((!(opcode == CBC_POST_INCR_IDENT_PUSH_RESULT || opcode == CBC_POST_DECR_IDENT_PUSH_RESULT))) { jerry_assert_fail ("opcode == CBC_POST_INCR_IDENT_PUSH_RESULT || opcode == CBC_POST_DECR_IDENT_PUSH_RESULT", "sao-vm.c", __func__, 1799); } } while (0);
									*stack_top_p++ = ecma_copy_value (result);
								}
								else
								{
									do { if ((!(opcode == CBC_POST_INCR_PUSH_RESULT || opcode == CBC_POST_DECR_PUSH_RESULT))) { jerry_assert_fail ("opcode == CBC_POST_INCR_PUSH_RESULT || opcode == CBC_POST_DECR_PUSH_RESULT", "sao-vm.c", __func__, 1809); } } while (0);
									stack_top_p++;
									stack_top_p[-1] = stack_top_p[-2];
									stack_top_p[-2] = stack_top_p[-3];
									stack_top_p[-3] = ecma_copy_value (result);
								}
								opcode_data &= (uint32_t)~VM_OC_PUT_STACK;
							}
							else if (opcode_data & VM_OC_PUT_BLOCK)
							{
								ecma_free_value (block_result);
								block_result = ecma_copy_value (result);
								opcode_data &= (uint32_t) ~VM_OC_PUT_BLOCK;
							}
						}
						if (ecma_is_value_integer_number (result))
						{
							result = ecma_make_number_value (result_number + increase);
						}
						else
						{
							result = ecma_update_float_number (result, result_number + increase);
						}
						break;
					}
				case VM_OC_ASSIGN:
					{
						result = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						break;
					}
				case VM_OC_ASSIGN_PROP:
					{
						result = stack_top_p[-1];
						stack_top_p[-1] = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						break;
					}
				case VM_OC_ASSIGN_PROP_THIS:
					{
						result = stack_top_p[-1];
						stack_top_p[-1] = ecma_copy_value (frame_ctx_p->this_binding);
						*stack_top_p++ = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						break;
					}
				case VM_OC_RET:
					{
						do { if ((!(opcode == CBC_RETURN || opcode == CBC_RETURN_WITH_BLOCK || opcode == CBC_RETURN_WITH_LITERAL))) { jerry_assert_fail ("opcode == CBC_RETURN || opcode == CBC_RETURN_WITH_BLOCK || opcode == CBC_RETURN_WITH_LITERAL", "sao-vm.c", __func__, 1861); } } while (0);
						if (opcode == CBC_RETURN_WITH_BLOCK)
						{
							left_value = block_result;
							block_result = ECMA_VALUE_UNDEFINED;
						}
						result = left_value;
						left_value = ECMA_VALUE_UNDEFINED;
						goto error;
					}
				case VM_OC_THROW:
					{
						(jerry_global_context.error_value) = left_value;
						(jerry_global_context.status_flags) |= ECMA_STATUS_EXCEPTION;
						result = ECMA_VALUE_ERROR;
						left_value = ECMA_VALUE_UNDEFINED;
						goto error;
					}
				case VM_OC_THROW_REFERENCE_ERROR:
					{
						result = ecma_raise_reference_error (((void *)0));
						goto error;
					}
				case VM_OC_EVAL:
					{
						(jerry_global_context.status_flags) |= ECMA_STATUS_DIRECT_EVAL;
						do { if ((!(*byte_code_p >= CBC_CALL && *byte_code_p <= CBC_CALL2_PROP_BLOCK))) { jerry_assert_fail ("*byte_code_p >= CBC_CALL && *byte_code_p <= CBC_CALL2_PROP_BLOCK", "sao-vm.c", __func__, 1890); } } while (0);
						continue;
					}
				case VM_OC_CALL:
					{
						if (frame_ctx_p->call_operation == VM_NO_EXEC_OP)
						{
							frame_ctx_p->call_operation = VM_EXEC_CALL;
							frame_ctx_p->byte_code_p = byte_code_start_p;
							frame_ctx_p->stack_top_p = stack_top_p;
							frame_ctx_p->call_block_result = block_result;
							return ECMA_VALUE_UNDEFINED;
						}
						if (opcode < CBC_CALL0)
						{
							byte_code_p++;
						}
						frame_ctx_p->call_operation = VM_NO_EXEC_OP;
						result = *(--stack_top_p);
						block_result = frame_ctx_p->call_block_result;
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						if (!(opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK)))
						{
							ecma_fast_free_value (result);
						}
						else if (opcode_data & VM_OC_PUT_STACK)
						{
							*stack_top_p++ = result;
						}
						else
						{
							ecma_fast_free_value (block_result);
							block_result = result;
						}
						continue;
					}
				case VM_OC_NEW:
					{
						if (frame_ctx_p->call_operation == VM_NO_EXEC_OP)
						{
							frame_ctx_p->call_operation = VM_EXEC_CONSTRUCT;
							frame_ctx_p->byte_code_p = byte_code_start_p;
							frame_ctx_p->stack_top_p = stack_top_p;
							frame_ctx_p->call_block_result = block_result;
							return ECMA_VALUE_UNDEFINED;
						}
						if (opcode < CBC_NEW0)
						{
							byte_code_p++;
						}
						frame_ctx_p->call_operation = VM_NO_EXEC_OP;
						result = *(--stack_top_p);
						block_result = frame_ctx_p->call_block_result;
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						continue;
					}
				case VM_OC_PROP_DELETE:
					{
						result = vm_op_delete_prop (left_value, right_value, is_strict);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						do { if ((!(ecma_is_value_boolean (result)))) { jerry_assert_fail ("ecma_is_value_boolean (result)", "sao-vm.c", __func__, 1972); } } while (0);
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_DELETE:
					{
						uint16_t literal_index;
						do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
						if (literal_index < register_end)
						{
							*stack_top_p++ = ECMA_VALUE_FALSE;
							continue;
						}
						result = vm_op_delete_var (literal_start_p[literal_index],
								frame_ctx_p->lex_env_p);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						do { if ((!(ecma_is_value_boolean (result)))) { jerry_assert_fail ("ecma_is_value_boolean (result)", "sao-vm.c", __func__, 1997); } } while (0);
						*stack_top_p++ = result;
						continue;
					}
				case VM_OC_JUMP:
					{
						byte_code_p = byte_code_start_p + branch_offset;
						continue;
					}
				case VM_OC_BRANCH_IF_STRICT_EQUAL:
					{
						ecma_value_t value = *(--stack_top_p);
						do { if ((!(stack_top_p > frame_ctx_p->registers_p + register_end))) { jerry_assert_fail ("stack_top_p > frame_ctx_p->registers_p + register_end", "sao-vm.c", __func__, 2011); } } while (0);
						if (ecma_op_strict_equality_compare (value, stack_top_p[-1]))
						{
							byte_code_p = byte_code_start_p + branch_offset;
							ecma_free_value (*--stack_top_p);
						}
						ecma_free_value (value);
						continue;
					}
				case VM_OC_BRANCH_IF_TRUE:
				case VM_OC_BRANCH_IF_FALSE:
				case VM_OC_BRANCH_IF_LOGICAL_TRUE:
				case VM_OC_BRANCH_IF_LOGICAL_FALSE:
					{
						uint32_t opcode_flags = ((opcode_data) & 0x7f) - VM_OC_BRANCH_IF_TRUE;
						ecma_value_t value = *(--stack_top_p);
						_Bool boolean_value = ecma_op_to_boolean (value);
						if (opcode_flags & 0x1)
						{
							boolean_value = !boolean_value;
						}
						if (boolean_value)
						{
							byte_code_p = byte_code_start_p + branch_offset;
							if (opcode_flags & 0x2)
							{
								++stack_top_p;
								continue;
							}
						}
						ecma_fast_free_value (value);
						continue;
					}
				case VM_OC_PLUS:
				case VM_OC_MINUS:
					{
						result = opfunc_unary_operation (left_value, ((opcode_data) & 0x7f) == VM_OC_PLUS);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_left_value;
					}
				case VM_OC_NOT:
					{
						result = opfunc_logical_not (left_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_left_value;
					}
				case VM_OC_BIT_NOT:
					{
						enum { static_assertion_failed_2078_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_is_value_integer_number (left_value))
						{
							*stack_top_p++ = (~left_value) & (ecma_value_t) (~((1u << 3) | 0x7u));
							goto free_left_value;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_NOT,
								left_value,
								left_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_left_value;
					}
				case VM_OC_VOID:
					{
						*stack_top_p++ = ECMA_VALUE_UNDEFINED;
						goto free_left_value;
					}
				case VM_OC_TYPEOF_IDENT:
					{
						uint16_t literal_index;
						do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
						do { if ((!(literal_index < ident_end))) { jerry_assert_fail ("literal_index < ident_end", "sao-vm.c", __func__, 2109); } } while (0);
						if (literal_index < register_end)
						{
							left_value = ecma_copy_value (frame_ctx_p->registers_p[literal_index]);
						}
						else
						{
							ecma_string_t *name_p = ecma_get_string_from_value (literal_start_p[literal_index]);
							ecma_object_t *ref_base_lex_env_p = ecma_op_resolve_reference_base (frame_ctx_p->lex_env_p,
									name_p);
							if (ref_base_lex_env_p == ((void *)0))
							{
								result = ECMA_VALUE_UNDEFINED;
							}
							else
							{
								result = ecma_op_get_value_lex_env_base (ref_base_lex_env_p,
										name_p,
										is_strict);
							}
							if ((((result) == ECMA_VALUE_ERROR)))
							{
								goto error;
							}
							left_value = result;
						}
					}
				case VM_OC_TYPEOF:
					{
						result = opfunc_typeof (left_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_left_value;
					}
				case VM_OC_ADD:
					{
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							result = ecma_make_int32_value ((int32_t) (left_integer + right_integer));
							break;
						}
						if (ecma_is_value_float_number (left_value)
								&& ecma_is_value_number (right_value))
						{
							ecma_number_t new_value = (ecma_get_float_from_value (left_value) +
									ecma_get_number_from_value (right_value));
							result = ecma_update_float_number (left_value, new_value);
							left_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						if (ecma_is_value_float_number (right_value)
								&& ecma_is_value_integer_number (left_value))
						{
							ecma_number_t new_value = ((ecma_number_t) ecma_get_integer_from_value (left_value) +
									ecma_get_float_from_value (right_value));
							result = ecma_update_float_number (right_value, new_value);
							right_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						result = opfunc_addition (left_value, right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_SUB:
					{
						enum { static_assertion_failed_2199_doubled_ecma_numbers_must_fit_into_int32_range = 1 / (!!(0x7ffffff * 2 <= 2147483647 && -0x8000000 * 2 >= (-2147483647-1))) };
						do { if ((!(!(((left_value) == ECMA_VALUE_ERROR)) && !(((right_value) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("!ECMA_IS_VALUE_ERROR (left_value) && !ECMA_IS_VALUE_ERROR (right_value)", "sao-vm.c", __func__, 2202); } } while (0);
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							result = ecma_make_int32_value ((int32_t) (left_integer - right_integer));
							break;
						}
						if (ecma_is_value_float_number (left_value)
								&& ecma_is_value_number (right_value))
						{
							ecma_number_t new_value = (ecma_get_float_from_value (left_value) -
									ecma_get_number_from_value (right_value));
							result = ecma_update_float_number (left_value, new_value);
							left_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						if (ecma_is_value_float_number (right_value)
								&& ecma_is_value_integer_number (left_value))
						{
							ecma_number_t new_value = ((ecma_number_t) ecma_get_integer_from_value (left_value) -
									ecma_get_float_from_value (right_value));
							result = ecma_update_float_number (right_value, new_value);
							right_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						result = do_number_arithmetic (NUMBER_ARITHMETIC_SUBSTRACTION,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_MUL:
					{
						do { if ((!(!(((left_value) == ECMA_VALUE_ERROR)) && !(((right_value) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("!ECMA_IS_VALUE_ERROR (left_value) && !ECMA_IS_VALUE_ERROR (right_value)", "sao-vm.c", __func__, 2247); } } while (0);
						enum { static_assertion_failed_2251_square_of_integer_multiply_max_must_fit_into_integer_value_range = 1 / (!!(0x2d41 * 0x2d41 <= 0x7ffffff && -(0x2d41 * 0x2d41) >= -0x8000000)) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							if (-0x2d41 <= left_integer
									&& left_integer <= 0x2d41
									&& -0x2d41 <= right_integer
									&& right_integer <= 0x2d41
									&& left_value != 0
									&& right_value != 0)
							{
								result = ecma_integer_multiply (left_integer, right_integer);
								break;
							}
							ecma_number_t multiply = (ecma_number_t) left_integer * (ecma_number_t) right_integer;
							result = ecma_make_number_value (multiply);
							break;
						}
						if (ecma_is_value_float_number (left_value)
								&& ecma_is_value_number (right_value))
						{
							ecma_number_t new_value = (ecma_get_float_from_value (left_value) *
									ecma_get_number_from_value (right_value));
							result = ecma_update_float_number (left_value, new_value);
							left_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						if (ecma_is_value_float_number (right_value)
								&& ecma_is_value_integer_number (left_value))
						{
							ecma_number_t new_value = ((ecma_number_t) ecma_get_integer_from_value (left_value) *
									ecma_get_float_from_value (right_value));
							result = ecma_update_float_number (right_value, new_value);
							right_value = ECMA_VALUE_UNDEFINED;
							break;
						}
						result = do_number_arithmetic (NUMBER_ARITHMETIC_MULTIPLICATION,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_DIV:
					{
						do { if ((!(!(((left_value) == ECMA_VALUE_ERROR)) && !(((right_value) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("!ECMA_IS_VALUE_ERROR (left_value) && !ECMA_IS_VALUE_ERROR (right_value)", "sao-vm.c", __func__, 2309); } } while (0);
						result = do_number_arithmetic (NUMBER_ARITHMETIC_DIVISION,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_MOD:
					{
						do { if ((!(!(((left_value) == ECMA_VALUE_ERROR)) && !(((right_value) == ECMA_VALUE_ERROR))))) { jerry_assert_fail ("!ECMA_IS_VALUE_ERROR (left_value) && !ECMA_IS_VALUE_ERROR (right_value)", "sao-vm.c", __func__, 2324); } } while (0);
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							if (right_integer != 0)
							{
								ecma_integer_value_t mod_result = left_integer % right_integer;
								if (mod_result != 0 || left_integer >= 0)
								{
									result = ecma_make_integer_value (mod_result);
									break;
								}
							}
						}
						result = do_number_arithmetic (NUMBER_ARITHMETIC_REMAINDER,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_EQUAL:
					{
						result = opfunc_equality (left_value, right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_NOT_EQUAL:
					{
						result = opfunc_equality (left_value, right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = ecma_invert_boolean_value (result);
						goto free_both_values;
					}
				case VM_OC_STRICT_EQUAL:
					{
						_Bool is_equal = ecma_op_strict_equality_compare (left_value, right_value);
						result = ecma_make_boolean_value (is_equal);
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_STRICT_NOT_EQUAL:
					{
						_Bool is_equal = ecma_op_strict_equality_compare (left_value, right_value);
						result = ecma_make_boolean_value (!is_equal);
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_BIT_OR:
					{
						enum { static_assertion_failed_2398_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							result = left_value | right_value;
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_LOGIC_OR,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_BIT_XOR:
					{
						enum { static_assertion_failed_2419_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							result = (left_value ^ right_value) & (ecma_value_t) (~((1u << 3) | 0x7u));
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_LOGIC_XOR,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_BIT_AND:
					{
						enum { static_assertion_failed_2440_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							result = left_value & right_value;
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_LOGIC_AND,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_LEFT_SHIFT:
					{
						enum { static_assertion_failed_2461_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							result = ecma_make_int32_value ((int32_t) (left_integer << (right_integer & 0x1f)));
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_SHIFT_LEFT,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_RIGHT_SHIFT:
					{
						enum { static_assertion_failed_2484_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							result = ecma_make_integer_value (left_integer >> (right_integer & 0x1f));
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_SHIFT_RIGHT,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_UNS_RIGHT_SHIFT:
					{
						enum { static_assertion_failed_2507_direct_type_mask_must_fill_all_bits_before_the_value_starts = 1 / (!!(((1u << 3) | 0x7u) == ((1 << 4) - 1))) };
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							uint32_t left_uint32 = (uint32_t) ecma_get_integer_from_value (left_value);
							ecma_integer_value_t right_integer = ecma_get_integer_from_value (right_value);
							result = ecma_make_uint32_value (left_uint32 >> (right_integer & 0x1f));
							break;
						}
						result = do_number_bitwise_logic (NUMBER_BITWISE_SHIFT_URIGHT,
								left_value,
								right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						break;
					}
				case VM_OC_LESS:
					{
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							_Bool is_less = (ecma_integer_value_t) left_value < (ecma_integer_value_t) right_value;
							if (*byte_code_p <= CBC_BRANCH_IF_TRUE_BACKWARD_3 && *byte_code_p >= CBC_BRANCH_IF_TRUE_BACKWARD)
							{
								byte_code_start_p = byte_code_p++;
								branch_offset_length = ((*byte_code_start_p) & 0x3);
								do { if ((!(branch_offset_length >= 1 && branch_offset_length <= 3))) { jerry_assert_fail ("branch_offset_length >= 1 && branch_offset_length <= 3", "sao-vm.c", __func__, 2539); } } while (0);
								if (is_less)
								{
									branch_offset = *(byte_code_p++);
									if ((branch_offset_length != 1))
									{
										branch_offset <<= 8;
										branch_offset |= *(byte_code_p++);
										if ((branch_offset_length == 3))
										{
											branch_offset <<= 8;
											branch_offset |= *(byte_code_p++);
										}
									}
									byte_code_p = byte_code_start_p - branch_offset;
								}
								else
								{
									byte_code_p += branch_offset_length;
								}
								continue;
							}
							*stack_top_p++ = ecma_make_boolean_value (is_less);
							continue;
						}
						if (ecma_is_value_number (left_value) && ecma_is_value_number (right_value))
						{
							ecma_number_t left_number = ecma_get_number_from_value (left_value);
							ecma_number_t right_number = ecma_get_number_from_value (right_value);
							*stack_top_p++ = ecma_make_boolean_value (left_number < right_number);
							goto free_both_values;
						}
						result = opfunc_relation (left_value, right_value, 1, 0);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_GREATER:
					{
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = (ecma_integer_value_t) left_value;
							ecma_integer_value_t right_integer = (ecma_integer_value_t) right_value;
							*stack_top_p++ = ecma_make_boolean_value (left_integer > right_integer);
							continue;
						}
						if (ecma_is_value_number (left_value) && ecma_is_value_number (right_value))
						{
							ecma_number_t left_number = ecma_get_number_from_value (left_value);
							ecma_number_t right_number = ecma_get_number_from_value (right_value);
							*stack_top_p++ = ecma_make_boolean_value (left_number > right_number);
							goto free_both_values;
						}
						result = opfunc_relation (left_value, right_value, 0, 0);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_LESS_EQUAL:
					{
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = (ecma_integer_value_t) left_value;
							ecma_integer_value_t right_integer = (ecma_integer_value_t) right_value;
							*stack_top_p++ = ecma_make_boolean_value (left_integer <= right_integer);
							continue;
						}
						if (ecma_is_value_number (left_value) && ecma_is_value_number (right_value))
						{
							ecma_number_t left_number = ecma_get_number_from_value (left_value);
							ecma_number_t right_number = ecma_get_number_from_value (right_value);
							*stack_top_p++ = ecma_make_boolean_value (left_number <= right_number);
							goto free_both_values;
						}
						result = opfunc_relation (left_value, right_value, 0, 1);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_GREATER_EQUAL:
					{
						if (ecma_are_values_integer_numbers (left_value, right_value))
						{
							ecma_integer_value_t left_integer = (ecma_integer_value_t) left_value;
							ecma_integer_value_t right_integer = (ecma_integer_value_t) right_value;
							*stack_top_p++ = ecma_make_boolean_value (left_integer >= right_integer);
							continue;
						}
						if (ecma_is_value_number (left_value) && ecma_is_value_number (right_value))
						{
							ecma_number_t left_number = ecma_get_number_from_value (left_value);
							ecma_number_t right_number = ecma_get_number_from_value (right_value);
							*stack_top_p++ = ecma_make_boolean_value (left_number >= right_number);
							goto free_both_values;
						}
						result = opfunc_relation (left_value, right_value, 1, 1);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_IN:
					{
						result = opfunc_in (left_value, right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_INSTANCEOF:
					{
						result = opfunc_instanceof (left_value, right_value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						*stack_top_p++ = result;
						goto free_both_values;
					}
				case VM_OC_WITH:
					{
						ecma_value_t value = *(--stack_top_p);
						ecma_object_t *object_p;
						ecma_object_t *with_env_p;
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2712); } } while (0);
						result = ecma_op_to_object (value);
						ecma_free_value (value);
						if ((((result) == ECMA_VALUE_ERROR)))
						{
							goto error;
						}
						object_p = ecma_get_object_from_value (result);
						with_env_p = ecma_create_object_lex_env (frame_ctx_p->lex_env_p,
								object_p,
								ECMA_LEXICAL_ENVIRONMENT_THIS_OBJECT_BOUND);
						ecma_deref_object (object_p);
						(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) + (1));
						stack_top_p += 1;
						stack_top_p[-1] = ((ecma_value_t) ((VM_CONTEXT_WITH) | (branch_offset) << 4));
						frame_ctx_p->lex_env_p = with_env_p;
						continue;
					}
				case VM_OC_FOR_IN_CREATE_CONTEXT:
					{
						ecma_value_t value = *(--stack_top_p);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2741); } } while (0);
						ecma_value_t expr_obj_value = ECMA_VALUE_UNDEFINED;
						ecma_collection_chunk_t *prop_names_p = opfunc_for_in (value, &expr_obj_value);
						ecma_free_value (value);
						if (prop_names_p == ((void *)0))
						{
							byte_code_p = byte_code_start_p + branch_offset;
							continue;
						}
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) + (4));
						stack_top_p += 4;
						stack_top_p[-1] = (ecma_value_t) ((ecma_value_t) ((VM_CONTEXT_FOR_IN) | (branch_offset) << 4));
						do { void *ptr_value = (void *) prop_names_p; if (((ptr_value) == ((void *)0))) { (stack_top_p[-2]) = ((jmem_cpointer_t) 0); } else { (stack_top_p[-2]) = jmem_compress_pointer (ptr_value); } } while (0);;
						stack_top_p[-3] = 0;
						stack_top_p[-4] = expr_obj_value;
						continue;
					}
				case VM_OC_FOR_IN_GET_NEXT:
					{
						ecma_value_t *context_top_p = frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth;
						ecma_collection_chunk_t *chunk_p;
						chunk_p = (((((context_top_p[-2]) == ((jmem_cpointer_t) 0))) ? ((void *)0) : ((ecma_collection_chunk_t *) (jmem_decompress_pointer (context_top_p[-2])))));
						do { if ((!(((vm_stack_context_type_t) ((context_top_p[-1]) & 0xf)) == VM_CONTEXT_FOR_IN))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (context_top_p[-1]) == VM_CONTEXT_FOR_IN", "sao-vm.c", __func__, 2771); } } while (0);
						uint32_t index = context_top_p[-3];
						do { if ((!(!ecma_is_value_pointer (chunk_p->items[index])))) { jerry_assert_fail ("!ecma_is_value_pointer (chunk_p->items[index])", "sao-vm.c", __func__, 2775); } } while (0);
						*stack_top_p++ = chunk_p->items[index];
						index++;
						if ((!ecma_is_value_pointer (chunk_p->items[index])))
						{
							context_top_p[-3] = index;
							continue;
						}
						context_top_p[-3] = 0;
						ecma_collection_chunk_t *next_chunk_p;
						next_chunk_p = (ecma_collection_chunk_t *) ecma_get_pointer_from_value (chunk_p->items[index]);
						do { void *ptr_value = (void *) next_chunk_p; if (((ptr_value) == ((void *)0))) { (context_top_p[-2]) = ((jmem_cpointer_t) 0); } else { (context_top_p[-2]) = jmem_compress_pointer (ptr_value); } } while (0);;
						jmem_heap_free_block (chunk_p, sizeof (ecma_collection_chunk_t));
						continue;
					}
				case VM_OC_FOR_IN_HAS_NEXT:
					{
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2797); } } while (0);
						ecma_collection_chunk_t *chunk_p;
						chunk_p = (((((stack_top_p[-2]) == ((jmem_cpointer_t) 0))) ? ((void *)0) : ((ecma_collection_chunk_t *) (jmem_decompress_pointer (stack_top_p[-2])))));
						uint32_t index = stack_top_p[-3];
						ecma_object_t *object_p = ecma_get_object_from_value (stack_top_p[-4]);
						while (1)
						{
							if (chunk_p == ((void *)0))
							{
								ecma_deref_object (object_p);
								(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) - (4));
								stack_top_p -= 4;
								break;
							}
							ecma_string_t *prop_name_p = ecma_get_string_from_value (chunk_p->items[index]);
							if ((ecma_op_object_has_property (object_p, prop_name_p)))
							{
								byte_code_p = byte_code_start_p + branch_offset;
								break;
							}
							index++;
							ecma_value_t value = chunk_p->items[index];
							if ((!ecma_is_value_pointer (value)))
							{
								stack_top_p[-3] = index;
							}
							else
							{
								index = 0;
								stack_top_p[-3] = 0;
								ecma_collection_chunk_t *next_chunk_p;
								next_chunk_p = (ecma_collection_chunk_t *) ecma_get_pointer_from_value (value);
								do { void *ptr_value = (void *) next_chunk_p; if (((ptr_value) == ((void *)0))) { (stack_top_p[-2]) = ((jmem_cpointer_t) 0); } else { (stack_top_p[-2]) = jmem_compress_pointer (ptr_value); } } while (0);;
								jmem_heap_free_block (chunk_p, sizeof (ecma_collection_chunk_t));
								chunk_p = next_chunk_p;
							}
							ecma_deref_ecma_string (prop_name_p);
						}
						continue;
					}
				case VM_OC_TRY:
					{
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2853); } } while (0);
						(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) + (2));
						stack_top_p += 2;
						stack_top_p[-1] = (ecma_value_t) ((ecma_value_t) ((VM_CONTEXT_TRY) | (branch_offset) << 4));
						continue;
					}
				case VM_OC_CATCH:
					{
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2864); } } while (0);
						do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_TRY))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_TRY", "sao-vm.c", __func__, 2865); } } while (0);
						byte_code_p = byte_code_start_p + branch_offset;
						continue;
					}
				case VM_OC_FINALLY:
					{
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2874); } } while (0);
						do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_TRY || ((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_CATCH))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_TRY || VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_CATCH", "sao-vm.c", __func__, 2877); } } while (0);
						if (((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_CATCH)
						{
							ecma_object_t *lex_env_p = frame_ctx_p->lex_env_p;
							frame_ctx_p->lex_env_p = ecma_get_lex_env_outer_reference (lex_env_p);
							ecma_deref_object (lex_env_p);
						}
						stack_top_p[-1] = (ecma_value_t) ((ecma_value_t) ((VM_CONTEXT_FINALLY_JUMP) | (branch_offset) << 4));
						stack_top_p[-2] = (ecma_value_t) branch_offset;
						continue;
					}
				case VM_OC_CONTEXT_END:
					{
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2892); } } while (0);
						switch (((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)))
						{
							case VM_CONTEXT_FINALLY_JUMP:
								{
									uint32_t jump_target = stack_top_p[-2];
									(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) - (2));
									stack_top_p -= 2;
									if (vm_stack_find_finally (frame_ctx_p,
												&stack_top_p,
												VM_CONTEXT_FINALLY_JUMP,
												jump_target))
									{
										do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_FINALLY_JUMP))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_FINALLY_JUMP", "sao-vm.c", __func__, 2909); } } while (0);
										byte_code_p = frame_ctx_p->byte_code_p;
										stack_top_p[-2] = jump_target;
									}
									else
									{
										byte_code_p = frame_ctx_p->byte_code_start_p + jump_target;
									}
									break;
								}
							case VM_CONTEXT_FINALLY_THROW:
								{
									(jerry_global_context.error_value) = stack_top_p[-2];
									(jerry_global_context.status_flags) |= ECMA_STATUS_EXCEPTION;
									(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) - (2));
									stack_top_p -= 2;
									result = ECMA_VALUE_ERROR;
									goto error;
								}
							case VM_CONTEXT_FINALLY_RETURN:
								{
									result = stack_top_p[-2];
									(frame_ctx_p->context_depth) = (uint16_t) ((frame_ctx_p->context_depth) - (2));
									stack_top_p -= 2;
									goto error;
								}
							default:
								{
									stack_top_p = vm_stack_context_abort (frame_ctx_p, stack_top_p);
								}
						}
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2949); } } while (0);
						continue;
					}
				case VM_OC_JUMP_AND_EXIT_CONTEXT:
					{
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2954); } } while (0);
						branch_offset += (int32_t) (byte_code_start_p - frame_ctx_p->byte_code_start_p);
						if (vm_stack_find_finally (frame_ctx_p,
									&stack_top_p,
									VM_CONTEXT_FINALLY_JUMP,
									(uint32_t) branch_offset))
						{
							do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_FINALLY_JUMP))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_FINALLY_JUMP", "sao-vm.c", __func__, 2963); } } while (0);
							byte_code_p = frame_ctx_p->byte_code_p;
							stack_top_p[-2] = (uint32_t) branch_offset;
						}
						else
						{
							byte_code_p = frame_ctx_p->byte_code_start_p + branch_offset;
						}
						do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 2972); } } while (0);
						continue;
					}
				default:
					{
						do { if ((!(((opcode_data) & 0x7f) == VM_OC_NONE))) { jerry_assert_fail ("VM_OC_GROUP_GET_INDEX (opcode_data) == VM_OC_NONE", "sao-vm.c", __func__, 3098); } } while (0);
						jerry_fatal (ERR_DISABLED_BYTE_CODE);
						do { jerry_unreachable ("sao-vm.c", __func__, 3101); } while (0);
					}
			}
			do { if ((!(((opcode_data) & (0xf << 10))))) { jerry_assert_fail ("VM_OC_HAS_PUT_RESULT (opcode_data)", "sao-vm.c", __func__, 3105); } } while (0);
			if (opcode_data & VM_OC_PUT_IDENT)
			{
				uint16_t literal_index;
				do { (literal_index) = *byte_code_p++; if ((literal_index) >= encoding_limit) { (literal_index) = (uint16_t) ((((literal_index) << 8) | *byte_code_p++) - encoding_delta); } } while (0);
				if (literal_index < register_end)
				{
					ecma_fast_free_value (frame_ctx_p->registers_p[literal_index]);
					frame_ctx_p->registers_p[literal_index] = result;
					if (opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK))
					{
						result = ecma_fast_copy_value (result);
					}
				}
				else
				{
					ecma_string_t *var_name_str_p = ecma_get_string_from_value (literal_start_p[literal_index]);
					ecma_object_t *ref_base_lex_env_p = ecma_op_resolve_reference_base (frame_ctx_p->lex_env_p,
							var_name_str_p);
					ecma_value_t put_value_result = ecma_op_put_value_lex_env_base (ref_base_lex_env_p,
							var_name_str_p,
							is_strict,
							result);
					if ((((put_value_result) == ECMA_VALUE_ERROR)))
					{
						ecma_free_value (result);
						result = put_value_result;
						goto error;
					}
					if (!(opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK)))
					{
						ecma_fast_free_value (result);
					}
				}
			}
			else if (opcode_data & VM_OC_PUT_REFERENCE)
			{
				ecma_value_t property = *(--stack_top_p);
				ecma_value_t object = *(--stack_top_p);
				if (object == ECMA_VALUE_REGISTER_REF)
				{
					ecma_fast_free_value (frame_ctx_p->registers_p[property]);
					frame_ctx_p->registers_p[property] = result;
					if (!(opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK)))
					{
						goto free_both_values;
					}
					result = ecma_fast_copy_value (result);
				}
				else
				{
					ecma_value_t set_value_result = vm_op_set_value (object,
							property,
							result,
							is_strict);
					if ((((set_value_result) == ECMA_VALUE_ERROR)))
					{
						ecma_free_value (result);
						result = set_value_result;
						goto error;
					}
					if (!(opcode_data & (VM_OC_PUT_STACK | VM_OC_PUT_BLOCK)))
					{
						ecma_fast_free_value (result);
						goto free_both_values;
					}
				}
			}
			if (opcode_data & VM_OC_PUT_STACK)
			{
				*stack_top_p++ = result;
			}
			else if (opcode_data & VM_OC_PUT_BLOCK)
			{
				ecma_fast_free_value (block_result);
				block_result = result;
			}
free_both_values:
			ecma_fast_free_value (right_value);
free_left_value:
			ecma_fast_free_value (left_value);
		}
error:
		ecma_fast_free_value (left_value);
		ecma_fast_free_value (right_value);
		if ((((result) == ECMA_VALUE_ERROR)))
		{
			ecma_value_t *vm_stack_p = stack_top_p;
			for (vm_stack_p = frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth;
					vm_stack_p < stack_top_p;
					vm_stack_p++)
			{
				if (*vm_stack_p == ECMA_VALUE_REGISTER_REF)
				{
					do { if ((!(vm_stack_p < stack_top_p))) { jerry_assert_fail ("vm_stack_p < stack_top_p", "sao-vm.c", __func__, 3218); } } while (0);
					vm_stack_p++;
				}
				else
				{
					ecma_free_value (*vm_stack_p);
				}
			}
			stack_top_p = frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth;
		}
		do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 3260); } } while (0);
		if (frame_ctx_p->context_depth == 0)
		{
			ecma_fast_free_value (block_result);
			return result;
		}
		if (!(((result) == ECMA_VALUE_ERROR)))
		{
			if (vm_stack_find_finally (frame_ctx_p,
						&stack_top_p,
						VM_CONTEXT_FINALLY_RETURN,
						0))
			{
				do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_FINALLY_RETURN))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_FINALLY_RETURN", "sao-vm.c", __func__, 3277); } } while (0);
				do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 3278); } } while (0);
				byte_code_p = frame_ctx_p->byte_code_p;
				stack_top_p[-2] = result;
				continue;
			}
		}
		else if ((jerry_global_context.status_flags) & ECMA_STATUS_EXCEPTION)
		{
			if (vm_stack_find_finally (frame_ctx_p,
						&stack_top_p,
						VM_CONTEXT_FINALLY_THROW,
						0))
			{
				do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 3292); } } while (0);
				byte_code_p = frame_ctx_p->byte_code_p;
				if (((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_CATCH)
				{
					*stack_top_p++ = (jerry_global_context.error_value);
					do { if ((!(byte_code_p[0] == CBC_ASSIGN_SET_IDENT))) { jerry_assert_fail ("byte_code_p[0] == CBC_ASSIGN_SET_IDENT", "sao-vm.c", __func__, 3304); } } while (0);
					uint32_t literal_index = byte_code_p[1];
					if (literal_index >= encoding_limit)
					{
						literal_index = ((literal_index << 8) | byte_code_p[2]) - encoding_delta;
					}
					ecma_object_t *catch_env_p = ecma_create_decl_lex_env (frame_ctx_p->lex_env_p);
					ecma_string_t *catch_name_p = ecma_get_string_from_value (literal_start_p[literal_index]);
					ecma_op_create_mutable_binding (catch_env_p, catch_name_p, 0);
					frame_ctx_p->lex_env_p = catch_env_p;
				}
				else
				{
					do { if ((!(((vm_stack_context_type_t) ((stack_top_p[-1]) & 0xf)) == VM_CONTEXT_FINALLY_THROW))) { jerry_assert_fail ("VM_GET_CONTEXT_TYPE (stack_top_p[-1]) == VM_CONTEXT_FINALLY_THROW", "sao-vm.c", __func__, 3325); } } while (0);
					stack_top_p[-2] = (jerry_global_context.error_value);
				}
				continue;
			}
		}
		else
		{
			do
			{
				do { if ((!(frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p))) { jerry_assert_fail ("frame_ctx_p->registers_p + register_end + frame_ctx_p->context_depth == stack_top_p", "sao-vm.c", __func__, 3336); } } while (0);
				stack_top_p = vm_stack_context_abort (frame_ctx_p, stack_top_p);
			}
			while (frame_ctx_p->context_depth > 0);
		}
		ecma_free_value (block_result);
		return result;
	}
}
	static ecma_value_t
vm_execute (vm_frame_ctx_t *frame_ctx_p,
		const ecma_value_t *arg_p,
		ecma_length_t arg_list_len)
{
	const ecma_compiled_code_t *bytecode_header_p = frame_ctx_p->bytecode_header_p;
	ecma_value_t completion_value;
	uint16_t argument_end;
	uint16_t register_end;
	if (bytecode_header_p->status_flags & CBC_CODE_FLAGS_UINT16_ARGUMENTS)
	{
		cbc_uint16_arguments_t *args_p = (cbc_uint16_arguments_t *) bytecode_header_p;
		argument_end = args_p->argument_end;
		register_end = args_p->register_end;
	}
	else
	{
		cbc_uint8_arguments_t *args_p = (cbc_uint8_arguments_t *) bytecode_header_p;
		argument_end = args_p->argument_end;
		register_end = args_p->register_end;
	}
	frame_ctx_p->stack_top_p = frame_ctx_p->registers_p + register_end;
	if (arg_list_len > argument_end)
	{
		arg_list_len = argument_end;
	}
	for (uint32_t i = 0; i < arg_list_len; i++)
	{
		frame_ctx_p->registers_p[i] = ecma_fast_copy_value (arg_p[i]);
	}
	if (register_end > arg_list_len)
	{
		ecma_value_t *stack_p = frame_ctx_p->registers_p + arg_list_len;
		for (uint32_t i = arg_list_len; i < register_end; i++)
		{
			*stack_p++ = ECMA_VALUE_UNDEFINED;
		}
	}
	(jerry_global_context.status_flags) &= (uint32_t) ~ECMA_STATUS_DIRECT_EVAL;
	(jerry_global_context.vm_top_context_p) = frame_ctx_p;
	vm_init_loop (frame_ctx_p);
	while (1)
	{
		completion_value = vm_loop (frame_ctx_p);
		if (frame_ctx_p->call_operation == VM_NO_EXEC_OP)
		{
			break;
		}
		if (frame_ctx_p->call_operation == VM_EXEC_CALL)
		{
			opfunc_call (frame_ctx_p);
		}
		else if (frame_ctx_p->call_operation == VM_EXEC_SUPER_CALL)
		{
			vm_super_call (frame_ctx_p);
		}
		else
		{
			do { if ((!(frame_ctx_p->call_operation == VM_EXEC_CONSTRUCT))) { jerry_assert_fail ("frame_ctx_p->call_operation == VM_EXEC_CONSTRUCT", "sao-vm.c", __func__, 3432); } } while (0);
			opfunc_construct (frame_ctx_p);
		}
	}
	for (uint32_t i = 0; i < register_end; i++)
	{
		ecma_fast_free_value (frame_ctx_p->registers_p[i]);
	}
	(jerry_global_context.vm_top_context_p) = frame_ctx_p->prev_context_p;
	return completion_value;
}
	ecma_value_t
vm_run (const ecma_compiled_code_t *bytecode_header_p,
		ecma_value_t this_binding_value,
		ecma_object_t *lex_env_p,
		uint32_t parse_opts,
		const ecma_value_t *arg_list_p,
		ecma_length_t arg_list_len)
{
	ecma_value_t *literal_p;
	vm_frame_ctx_t frame_ctx;
	uint32_t call_stack_size;
	if (bytecode_header_p->status_flags & CBC_CODE_FLAGS_UINT16_ARGUMENTS)
	{
		cbc_uint16_arguments_t *args_p = (cbc_uint16_arguments_t *) bytecode_header_p;
		call_stack_size = (uint32_t) (args_p->register_end + args_p->stack_limit);
		literal_p = (ecma_value_t *) ((uint8_t *) bytecode_header_p + sizeof (cbc_uint16_arguments_t));
		literal_p -= args_p->register_end;
		frame_ctx.literal_start_p = literal_p;
		literal_p += args_p->literal_end;
	}
	else
	{
		cbc_uint8_arguments_t *args_p = (cbc_uint8_arguments_t *) bytecode_header_p;
		call_stack_size = (uint32_t) (args_p->register_end + args_p->stack_limit);
		literal_p = (ecma_value_t *) ((uint8_t *) bytecode_header_p + sizeof (cbc_uint8_arguments_t));
		literal_p -= args_p->register_end;
		frame_ctx.literal_start_p = literal_p;
		literal_p += args_p->literal_end;
	}
	frame_ctx.bytecode_header_p = bytecode_header_p;
	frame_ctx.byte_code_p = (uint8_t *) literal_p;
	frame_ctx.byte_code_start_p = (uint8_t *) literal_p;
	frame_ctx.lex_env_p = lex_env_p;
	frame_ctx.prev_context_p = (jerry_global_context.vm_top_context_p);
	frame_ctx.this_binding = this_binding_value;
	frame_ctx.context_depth = 0;
	frame_ctx.is_eval_code = parse_opts & ECMA_PARSE_DIRECT_EVAL;
	frame_ctx.call_operation = VM_NO_EXEC_OP;
	ecma_value_t stack[(((call_stack_size) < (1)) ? (1) : (call_stack_size))];
	frame_ctx.registers_p = stack;
	return vm_execute (&frame_ctx, arg_list_p, arg_list_len);
}
