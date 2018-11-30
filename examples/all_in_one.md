# jit

/*
union executable_code {
	void* code;
	long (SLJIT_CALL *func)(long* a);
};
typedef union executable_code executable_code;
*/

//Using sljit:
//  Copy the content of sljit_src directory into your project source directory.
//  Add sljitLir.c source file to your build environment. All other files are
//  included by sljitLir.c (if required). Define the machine by SLJIT_CONFIG_*
//  selector. See sljitConfig.h for all possible values. For C++ compilers,
//  rename sljitLir.c to sljitLir.cpp.

/* Architecture selection. */
/* #define SLJIT_CONFIG_X86_32 1 */
/* #define SLJIT_CONFIG_X86_64 1 */
/* #define SLJIT_CONFIG_ARM_V5 1 */
/* #define SLJIT_CONFIG_ARM_V7 1 */
/* #define SLJIT_CONFIG_ARM_THUMB2 1 */
/* #define SLJIT_CONFIG_ARM_64 1 */
/* #define SLJIT_CONFIG_PPC_32 1 */
/* #define SLJIT_CONFIG_PPC_64 1 */
/* #define SLJIT_CONFIG_MIPS_32 1 */
/* #define SLJIT_CONFIG_MIPS_64 1 */
/* #define SLJIT_CONFIG_SPARC_32 1 */
/* #define SLJIT_CONFIG_TILEGX 1 */

/* #define SLJIT_CONFIG_AUTO 1 */
/* #define SLJIT_CONFIG_UNSUPPORTED 1 */

//we can have a mpping from scc_platform.h to that/

** build sljit into SAL internally...
//jit and run
<SLJIT,options,args,scratches,saveds,fscratches,fsaveds,local_size>
{
//create_compiler()

//emit_enter(int options, int args, int scratches, int saveds, int fscratches, int fsaveds, int local_size)
ENTER($options,$args...)

//emit_return(compiler, SLJIT_MOV, SLJIT_RETURN_REG, 0);
RETURN(SLJIT_MOV,SLJIT_RETURN_REG,0);

//generate_code(),free_compiler(buff=true),free_code
}

# running

/** remember-helper

@#   hash => hashing => switch
@%   percent => ratio => running => continue
@~   ~ => escape => break
@?   ask => if
@:   ?: => else
@:?  else+if => elseif
@$   money => loop

@()  return
@{}  return or export object
@[]  return or export array
@<..> import & declare

$func= ()=>{}

YY ? XX : ZZ

$func(){
}

<..>    declare ?
@<
expression in syntax
@>

//pipe expressions to handler //omit delimiter if default handler ?
@{
//expresss in multiline
}|(asm)

@<asm>{
	//using asm module to process express in between
}

stdin/stdout/stderr
=> std stream/pipe in/out

@$
@$()

*/

/* NOTES: default sao syntax if in .sao ext */
//<sao>{

//ASM with ARM INTEL syntax, auto ignore if platform is not correct
<ASM(ARM,64,ATNT)>{
	//ASM AT&T
}//<ASM()>

//using ASM with X86 INTEL syntax
<ASM(X86,32,INTL)>{
	//ASM AT&T
}//<ASM()>

<c>{
	#include "wtf.h"
}

//import and declare
@<c>
@<c.math>
@<c.printf>
@<sao>

test1 = ()=>{ @(11) }
test2 = (x)=> x;
test3 = ()=>33;

main(){
	printf("haha",test1())

	//casting to <c.int8>
	c.printf("%d", 
		<c.int8> (math.rand()>0.5)?test3():test1()
	);

	sao.printf(sao.stdout,"%s",test2(math.rand()));

	//declare x
	<int> x=math.round(math.rand()*10) % 5;

	//YY ? XX : ZZ
	one_or_zero = ()=> ( math.rand()>0.5 ? 1 : 0 )

	@# (one_or_zero())
	{
		1:{
			print("111")
		}
		0:{
			print("000")
		}
	}

//	//if true/false
//	(one_or_zero()>0.5)?
//	{
//		true:{
//			print("ttt")
//		}
//		false:{
//			print("fff")
//		}
//	}

@?()//if()
{
}
@:?()//elseif()
{
}
@://else
{
}

	@$() //while()
	{
		@% //continue
		@~ //break
	}

	//do
	@<
		expressions
	>(0);//while();

	//for(;;)
	@(;;){
	}

	//return 42
	@(42);
}

//export
@[main]
//@{main}

//}//<sao>
