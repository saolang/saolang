#if 0
eg:
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=1 -I ../../sljit_github/sljit_src/ -run sljitTestSao.c -v

scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=1 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c 

scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=0 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c -v

scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=0 -I ../../sljit_github/sljit_src/ -I ../scc -E -P0 sljitTestSao1.c > sljitTestSao1.pp.c

scc -I ../scc/ -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=0 -I ../../sljit_github/sljit_src/ -E -P0 sljitTestSao1.c > sljitTestSao1.pp.c

scc -I ../scc -I ../scc/build_Darwin_x86_64/ -run ../scc/scc.c -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=1 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c 

//no-debug no-verbose (currently best?)
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -I ../../sljit_github/sljit_src/ -I ../scc -E -P0 sljitTestSao1.c > sljitTestSao1.pp.c
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c

dtcc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -I saolang/scc -I sljit_github/sljit_src -E -P0 saolang/test/sljitTestSao1.c > saolang/test/sljitTestSao1.lnx.pp.c
dtcc -c saolang/test/sljitTestSao1.lnx.pp.c -o saolang/test/sljitTestSao1.lnx.pp.o

scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_UTIL_GLOBAL_LOCK=0 -D SLJIT_EXECUTABLE_ALLOCATOR=0 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c 
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_SINGLE_THREADED=1 -D SLJIT_EXECUTABLE_ALLOCATOR=0 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c 


scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_EXECUTABLE_ALLOCATOR=0 -I ../../sljit_github/sljit_src/ -I ../scc -run sljitTestSao1.c 
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_EXECUTABLE_ALLOCATOR=0 -I ../../sljit_github/sljit_src/ -I ../scc -E -P0 sljitTestSao1.c >> sljitTestSao1.pp.c


scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_EXECUTABLE_ALLOCATOR=0 -I ../../sljit_github/sljit_src/ -I ../scc -E -P0 sljitTestSao1.c > sljitTestSao1.pp.c


////SLJIT_EXECUTABLE_ALLOCATOR
//no-util-global-lock
scc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_UTIL_GLOBAL_LOCK=0 -I ../../sljit_github/sljit_src/ -I ../scc -E -P0 sljitTestSao1.c > sljitTestSao1.pp.c

gcc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_VERBOSE=1 -I ../../sljit_github/sljit_src/ -I ../scc sljitTestSao1.c && ./a.out -v
gcc -D SLJIT_CONFIG_AUTO=1 -D SLJIT_DEBUG=0 -D SLJIT_VERBOSE=0 -D SLJIT_UTIL_GLOBAL_LOCK=0 -I ../../sljit_github/sljit_src/ -I ../scc sljitTestSao1.c && ./a.out -v

#endif

//#include "scc_dl.h"
//
//#ifndef NULL
//#define NULL ((void*)0)
//#endif
//
//#include "sljitLir.h"
//
//#if (defined SLJIT_EXECUTABLE_ALLOCATOR && SLJIT_EXECUTABLE_ALLOCATOR)
//#else
//
////sys/mman.h
//#include <sys/mman.h>
//
//#define	PROT_READ	0x01
//#define	PROT_WRITE	0x02
//#define	PROT_EXEC	0x04
//#define MAP_FAILED	((void *)-1)
//#define	MAP_PRIVATE	0x0002
////#define	MAP_COPY	MAP_PRIVATE
//static sljit_s32 dev_zero = -1;
//#include "sljitExecAllocator.c"
//#define SLJIT_MALLOC_EXEC(size) sljit_malloc_exec(size)
//#define SLJIT_FREE_EXEC(ptr) sljit_free_exec(ptr)
////#define SLJIT_EXEC_OFFSET(ptr) sljit_exec_offset(ptr)
//#define SLJIT_EXEC_OFFSET(ptr) 0
////SLJIT_API_FUNC_ATTRIBUTE sljit_sw sljit_exec_offset(void* ptr)
////{
////	return ((struct block_header *)(ptr))[-1].executable_offset;
////}
//static SLJIT_INLINE void allocator_grab_lock(void)
//{
//	/* Always successful. */
//}
//
//static SLJIT_INLINE void allocator_release_lock(void)
//{
//	/* Always successful. */
//}
//#define	O_RDWR		0x0002
//static SLJIT_INLINE sljit_s32 open_dev_zero(void)
//{
//	dev_zero = SCC(open)("/dev/zero", O_RDWR);
//	return dev_zero < 0;
//}
//
//#endif
//#include "sljitLir.c"

#include "jit_wrapper.h"
//#include <jit_wrapper.c>

//#include "SLJIT_Wrapper.c"

//size of signed word
#define SIZE_SW sizeof(sljit_sw)
//size of unsigned word
#define SIZE_UW sizeof(sljit_uw)

////@ref https://stackoverflow.com/questions/26099745/test-if-preprocessor-symbol-is-defined-inside-macro
//#define __ARG_PLACEHOLDER_1 0,
//#define __take_second_arg(__ignored, val, ...) val
//#define __is_defined(x)         ___is_defined(x)
//#define ___is_defined(val)      ____is_defined(__ARG_PLACEHOLDER_##val)
//#define ____is_defined(arg1_or_junk)    __take_second_arg(arg1_or_junk 1, 0)

//#define IS_DEFINED(x) IS_DEFINED2(x)
//#define IS_DEFINED2(x) (#x[0] == 0 || (#x[0] >= '0' && #x[0] <= '9'))
//#define SCC_IS_DEFINED(x) IS_DEFINED2(x)

#define SCC_IS_DEFINED(x) (#x[0] == 0 || (#x[0] >= '0' && #x[0] <= '9')) //NOTES: only works for [0-9] or empty define now...
#define SCC_IS_DEFINED_AS_NUM(x) (#x[0] >= '0' && #x[0] <= '9') //NOTES: only works for [0-9] or empty define now...
#define SCC_FIRST_CHAR(x) (#x[0])

#define TEST_CHK_MACRO(name) \
	SCC(printf)("trace:"#name" [%d,%d,%s] %s\n",SCC_FIRST_CHAR(name),SCC_IS_DEFINED_AS_NUM(name),SCC_IS_DEFINED_AS_NUM(name)?"D":"U",SCC_QUOTE_PACK(name));

#define KKK 9

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

#if defined _WIN32 || defined _WIN64
//TODO in some cases it works?
#define COLOR_RED
#define COLOR_GREEN
#define COLOR_ARCH
#define COLOR_DEFAULT
#else
#define COLOR_RED "\33[31m"
#define COLOR_GREEN "\33[32m"
#define COLOR_ARCH "\33[33m"
#define COLOR_DEFAULT "\33[0m"
#endif

//using union to share the entry for different argc.... just a trick to easily
//  cast to the function we want.
union executable_code {
	void* code;
	sljit_sw (SLJIT_CALL *func0)(void);
	sljit_sw (SLJIT_CALL *func1)(sljit_sw a);
	sljit_sw (SLJIT_CALL *func2)(sljit_sw a, sljit_sw b);
	sljit_sw (SLJIT_CALL *func3)(sljit_sw a, sljit_sw b, sljit_sw c);
};
typedef union executable_code executable_code;

static sljit_s32 successful_tests = 0;
static sljit_s32 verbose = 0;
static sljit_s32 silent = 0;

#define FAILED(cond, text) \
	if (SLJIT_UNLIKELY(cond)) { \
		SCC(printf)(text); \
		return; \
	}

#define MYCHECK(compiler) \
	if (sljit_get_compiler_error(compiler) != SLJIT_ERR_COMPILED) { \
		SCC(printf)("Compiler error: %d\n", sljit_get_compiler_error(compiler)); \
		sljit_free_compiler(compiler); \
		return; \
	}

static void cond_set(struct sljit_compiler *compiler, sljit_s32 dst, sljit_sw dstw, sljit_s32 type)
{
	/* Testing both sljit_emit_op_flags and sljit_emit_jump. */
	struct sljit_jump* jump;
	struct sljit_label* label;

	sljit_emit_op_flags(compiler, SLJIT_MOV, dst, dstw, SLJIT_UNUSED, 0, type);
	jump = sljit_emit_jump(compiler, type);
	sljit_emit_op2(compiler, SLJIT_ADD, dst, dstw, dst, dstw, SLJIT_IMM, 2);
	label = sljit_emit_label(compiler);
	sljit_set_label(jump, label);
}
static void testx(void)
{
	/* Enter and return from an sljit function. */
	//struct sljit_compiler *compiler = (struct sljit_compiler*)malloc(sizeof(struct sljit_compiler));
	struct sljit_compiler *compiler = SCC(malloc,struct sljit_compiler*)(sizeof(struct sljit_compiler));
//	executable_code code;
//#ifdef __APPLE__
//	//tmp hack for OSX....
//	//  Find page size for this system.
//	size_t pagesize = sysconf(_SC_PAGESIZE);
//	SCC(printf)("mprotect 111, &compiler=%d, pagesize=%d\n",pagesize);
//
//	//  Calculate start and end addresses for the write.
//	uintptr_t start = (uintptr_t) &compiler;
//	uintptr_t end = start + sizeof compiler;
//
//	//  Calculate start of page for mprotect.
//	uintptr_t pagestart = start & -pagesize;
//	SCC(printf)("mprotect 222\n");
//	if (-1 == mprotect((void *)pagestart, end - pagestart, PROT_READ | PROT_WRITE))
//	{
//		SCC(printf)("mprotect failed\n");
//		return;
//	}
//	SCC(printf)("mprotect 333\n");
//#endif
	if (!compiler) return;
	SCC(printf)("x334\n");
	compiler->error = SLJIT_SUCCESS;
	SCC(printf)("x335\n");
}

static void test1(void)
{
	/* Enter and return from an sljit function. */
	executable_code code;
	struct sljit_compiler* compiler = sljit_create_compiler(NULL);

	if (verbose)
		SCC(printf)("Run test1\n");

	FAILED(!compiler, "cannot create compiler\n");

	/* 3 arguments passed, 3 arguments used. */
	sljit_emit_enter(compiler, 0, 3, 3, 3, 0, 0, 0);

	//equivalent:
	//sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_RETURN_REG, 0, SLJIT_S1, 0);
	//sljit_emit_return(compiler, 0, 0, 0);
	sljit_emit_return(compiler, SLJIT_MOV, SLJIT_S1, 0);

	//after try compile
	SLJIT_ASSERT(sljit_get_generated_code_size(compiler) == 0);
	code.code = sljit_generate_code(compiler);
	MYCHECK(compiler);
	SLJIT_ASSERT(compiler->error == SLJIT_ERR_COMPILED);
	SLJIT_ASSERT(sljit_get_generated_code_size(compiler) > 0);
	sljit_free_compiler(compiler);

	//
	FAILED(code.func3(3, -21, 86) != -21, "test1 case 1 failed\n");
	FAILED(code.func3(4789, 47890, 997) != 47890, "test1 case 2 failed\n");

	sljit_free_code(code.code);
	successful_tests++;
	/*
	 .func3
	 JIT_ENTER(0,3,3,3,0,0,0)
	 JIT_RETURN(MOV,S1,0)
	 func3(,,)
	 */
	/*?sao
	 @*<sljit>{
	 .func3
		ENTER 0,3,3,3,0,0,0
		RETURN MOV, S1, 0
	 }
		FAILED_IF(-21!=func3(3,-21,86), "test1 failed")
		FAILED_IF(47890!=func3(4789,47890,997)
	 */
}

static void test2(void)
{
	/* Test mov. */
	executable_code code;
	struct sljit_compiler* compiler = sljit_create_compiler(NULL);
	sljit_sw buf[8];
	static sljit_sw data[2] = { 0, -9876 };

	if (verbose)
		SCC(printf)("Run test2\n");

	FAILED(!compiler, "cannot create compiler\n");

	buf[0] = 5678;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = 0;
	buf[4] = 0;
	buf[5] = 0;
	buf[6] = 0;
	buf[7] = 0;
	//1 arg, using 3/2 int register...
	sljit_emit_enter(compiler, 0, 1, 3, 2, 0, 0, 0);

	//MOV 0,0,0x80,&buf
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_UNUSED, 0, SLJIT_MEM0(), (sljit_sw)&buf);

	//9999=>R0
	//MOV R0,0,IMM,9999
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_IMM, 9999);

	//S0=>S1, the param 1 store onto S1 ? i.e. S1=&buf ??
	//MOV S1,0,S0,0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_S1, 0, SLJIT_S0, 0);

	//R0 => *S1 ?
	//MOV (0x80|S1),SIZE_SW,R0,0
	//MOV (0x80|(SLJIT_NUMBER_OF_REGISTERS - 1)),SIZE_SW*8,1,0
	//MOV *S1,SIZE_SW,R0,0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_S1), SIZE_SW, SLJIT_R0, 0);

	//MOV R1,0,IMM,SIZE_SW
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R1, 0, SLJIT_IMM, SIZE_SW);
	//MOV R2,0,MEM2(S1,R1),0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R2, 0, SLJIT_MEM2(SLJIT_S1, SLJIT_R1), 0);
	//MOV S0,0,IMM,2
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_S0, 0, SLJIT_IMM, 2);
	//MOV MEM2(S1,S0),WORD_SHIFT,MEM2(S1,R1),0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM2(SLJIT_S1, SLJIT_S0), SLJIT_WORD_SHIFT, SLJIT_MEM2(SLJIT_S1, SLJIT_R1), 0);
	//MOV S0,0,IMM,3
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_S0, 0, SLJIT_IMM, 3);
	//MOV MEM2(S1,S0),WORD_SHIFT,MEM0,&buf
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM2(SLJIT_S1, SLJIT_S0), SLJIT_WORD_SHIFT, SLJIT_MEM0(), (sljit_sw)&buf);

	//MOV R0,0,IMM,SIZE_SW
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_IMM, SIZE_SW);
	//MOV R0,0,MEM1(R0),&data
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_MEM1(SLJIT_R0), (sljit_sw)&data);

	//MOV MEM1(S1),4*SIZE_SW,R0,0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_S1), 4 * SIZE_SW, SLJIT_R0, 0);
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_IMM, (sljit_sw)&buf - 0x12345678);

	//MOV R0,0,*R0,0x12345678
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_MEM1(SLJIT_R0), 0x12345678);
	//*S1,5*SIZE_SW,R0,0
	//R0=>S1+5 ?
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_S1), 5 * SIZE_SW, SLJIT_R0, 0);
	//3456=>R0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R0, 0, SLJIT_IMM, 3456);
	//&buf-0xff890+6 => R1
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R1, 0, SLJIT_IMM, (sljit_sw)&buf - 0xff890 + 6 * SIZE_SW);
	//R0=>R1,0xff890??
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_R1), 0xff890, SLJIT_R0, 0);

	//fill buf[7]
	//MOV R1,0,IMM,&buf + 0xff890 + 7*SIZE_SW
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R1, 0, SLJIT_IMM, (sljit_sw)&buf + 0xff890 + 7 * SIZE_SW);
	//
	//MOV MEM1(R1) -0xff890 R0 0
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_R1), -0xff890, SLJIT_R0, 0);
	//RET R2
	sljit_emit_return(compiler, SLJIT_MOV, SLJIT_R2, 0);

	code.code = sljit_generate_code(compiler);
	MYCHECK(compiler);
	sljit_free_compiler(compiler);

	FAILED(code.func1((sljit_sw)&buf) != 9999, "test2 case 1 failed\n");
	FAILED(buf[1] != 9999, "test2 case 2 failed\n");
	FAILED(buf[2] != 9999, "test2 case 3 failed\n");
	FAILED(buf[3] != 5678, "test2 case 4 failed\n");
	FAILED(buf[4] != -9876, "test2 case 5 failed\n");
	FAILED(buf[5] != 5678, "test2 case 6 failed\n");
	FAILED(buf[6] != 3456, "test2 case 6 failed\n");
	FAILED(buf[7] != 3456, "test2 case 6 failed\n");

	sljit_free_code(code.code);
	successful_tests++;

	/*?sao
	 @*<sljit>{
	 .func3
		ENTER 0, 1, 3, 2, 0, 0, 0
		buf
		data
		MOV UNUSED, 0, MEM0, buf
		MOV R0, 0, IMM 9999
		MOV S1, 0, S0, 0
		MOV MEM1(S1), sizeof(sw), R0, 0
		MOV R1, 0, IMM, buf + 0xff890+7*SIZE_SW
		MOV MEM1(R1), -0xff899, R0, 0
		RETURN MOV, R1, 0
	 }

	 */
}

static void test3(void)
{
	/* Test not. */
	executable_code code;
	struct sljit_compiler* compiler = sljit_create_compiler(NULL);
	sljit_sw buf[5];

	if (verbose)
		SCC(printf)("Run test3\n");

	FAILED(!compiler, "cannot create compiler\n");
	buf[0] = 1234;
	buf[1] = 0;
	buf[2] = 9876;
	buf[3] = 0;
	buf[4] = 0x12345678;

	sljit_emit_enter(compiler, 0, 1, 3, 1, 0, 0, 0);
	sljit_emit_op1(compiler, SLJIT_NOT, SLJIT_UNUSED, 0, SLJIT_MEM0(), (sljit_sw)&buf);
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_MEM1(SLJIT_S0), SIZE_SW, SLJIT_MEM1(SLJIT_S0), 0);
	sljit_emit_op1(compiler, SLJIT_NOT, SLJIT_MEM0(), (sljit_sw)&buf[1], SLJIT_MEM0(), (sljit_sw)&buf[1]);
	sljit_emit_op1(compiler, SLJIT_NOT, SLJIT_RETURN_REG, 0, SLJIT_MEM1(SLJIT_S0), 0);
	sljit_emit_op1(compiler, SLJIT_NOT, SLJIT_MEM1(SLJIT_S0), SIZE_SW * 3, SLJIT_MEM1(SLJIT_S0), SIZE_SW * 2);
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R1, 0, SLJIT_IMM, (sljit_sw)&buf[4] - 0xff0000 - 0x20);
	sljit_emit_op1(compiler, SLJIT_MOV, SLJIT_R2, 0, SLJIT_IMM, (sljit_sw)&buf[4] - 0xff0000);
	sljit_emit_op1(compiler, SLJIT_NOT, SLJIT_MEM1(SLJIT_R1), 0xff0000 + 0x20, SLJIT_MEM1(SLJIT_R2), 0xff0000);
	sljit_emit_return(compiler, SLJIT_MOV, SLJIT_RETURN_REG, 0);

	code.code = sljit_generate_code(compiler);
MYCHECK(compiler);
	sljit_free_compiler(compiler);

	FAILED(code.func1((sljit_sw)&buf) != ~1234, "test3 case 1 failed\n");
	FAILED(buf[1] != ~1234, "test3 case 2 failed\n");
	FAILED(buf[3] != ~9876, "test3 case 3 failed\n");
	FAILED(buf[4] != ~0x12345678, "test3 case 4 failed\n");

	sljit_free_code(code.code);
	successful_tests++;
	/*?sao
NOT UNUSED,0,MEM0,&buf
MOV MEM1(S0),&buf[1],MEM0,&buf[1];
	 */
}

void sljit_test(int argc, char* argv[])
{
	sljit_s32 has_arg = (argc >= 2 && argv[1][0] == '-' && argv[1][2] == '\0');
	verbose = has_arg && argv[1][1] == 'v';
	silent = has_arg && argv[1][1] == 's';

	if (!verbose && !silent)
		SCC(printf)("Pass -v to enable verbose, -s to disable this hint.\n\n");
	testx();
	test1();
	test2();
	test3();

#if (defined SLJIT_EXECUTABLE_ALLOCATOR && SLJIT_EXECUTABLE_ALLOCATOR)
	sljit_free_unused_memory_exec();
#endif

#	define TEST_COUNT 3

	SCC(printf)("SLJIT tests: ");
	if (successful_tests == TEST_COUNT)
		SCC(printf)("all tests are " COLOR_GREEN "PASSED" COLOR_DEFAULT " ");
	else
		SCC(printf)(COLOR_RED "%d" COLOR_DEFAULT " (" COLOR_RED "%d%%" COLOR_DEFAULT ") tests are " COLOR_RED "FAILED" COLOR_DEFAULT " ", TEST_COUNT - successful_tests, (TEST_COUNT - successful_tests) * 100 / 47);
	SCC(printf)("on " COLOR_ARCH "%s" COLOR_DEFAULT "%s\n", sljit_get_platform_name(), sljit_is_fpu_available() ? " (with fpu)" : " (without fpu)");

#	undef TEST_COUNT
}

//#include <sys/mman.h>
//#include <sys/types.h>
struct SLJIT
{
	struct sljit_compiler *compiler;
	//struct SLJIT* (* create)();
	struct SLJIT* (* create)();
};

struct SLJIT* SLJIT_create(){
	struct SLJIT* rt = malloc( sizeof(struct SLJIT) );
	rt->compiler = sljit_create_compiler(NULL);
	//rt->create
	return rt;
}

int main(int argc, char* argv[])
{
	//struct Complex c=Complex.new(3., -4.);
	//struct Complex c=Complex.new(3.1, -2.4);
	//printf("c.abs(c) %f\n", c.abs(&c)); // Prints 5

	struct JIT jit = JIT.new(3.0,4.0);
	printf("jit.abs(c) %f\n", jit.abs(&jit));
	//ASSERT 5.0
	
	//import c
	//c->printf();
//#if defined(SLJIT_MALLOC)
//	SCC(printf)("defined SLJIT_MALLOC,");
//	//struct sljit_compiler *compiler = (struct sljit_compiler*)malloc(sizeof(struct sljit_compiler));
//
//	struct sljit_compiler *compiler = mmap(0, sizeof(struct sljit_compiler), PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_ANON, -1, 0);
//
//	SCC(printf)("&compiler=%d\n",compiler);
//	if (!compiler) return NULL;
//	//if (mprotect(compiler, pagesize, PROT_WRITE) == -1)
//	//{
//	//	SCC(printf)("failed mprotect\n");
//	//	return NULL;
//	//}
//	SCC(printf)("--wtf3--\n");
//	//SCC(memset)(compiler,0,sizeof(struct sljit_compiler));
//	compiler->error = SLJIT_SUCCESS;
//	SCC(printf)("--wtf4--\n");
//	
//#else
//	SCC(printf)("ERROR not defined SLJIT_MALLOC, check cc config...");
//	return -1;
//#endif
	TEST_CHK_MACRO(__SCC_TARGET_CROSS__);
	TEST_CHK_MACRO(NATIVE_TARGET);
	TEST_CHK_MACRO(SLJIT_MALLOC);
	TEST_CHK_MACRO(__APPLE__);
	TEST_CHK_MACRO(__x86_64__);
	TEST_CHK_MACRO(_AMD64_);
	TEST_CHK_MACRO(KKK);

	TEST_CHK_MACRO(__GNUC__);
	TEST_CHK_MACRO(__TINYCC__);
	TEST_CHK_MACRO(__SAOCC__);
//#ifdef __SAOCC__
//	SCC(printf)("__SAOCC__=%d\n",__SAOCC__);
//#endif

#ifdef CHECK
	SCC(printf)("CHECK=%s\n",SCC_QUOTE(CHECK));
#endif

	TEST_CHK_MACRO(__SaoOS__);
	TEST_CHK_MACRO(__SAOOS__);
	TEST_CHK_MACRO(__SAO_OS__);

	TEST_CHK_MACRO(SLJIT_CONFIG_X86_64);
	TEST_CHK_MACRO(SLJIT_CONFIG_X86_32);
	TEST_CHK_MACRO(SLJIT_CONFIG_AUTO);
	TEST_CHK_MACRO(SLJIT_CONFIG_X86);

	sljit_test(argc, argv);

	return 0;
}


