/* control */
//if
?()?{}:{}
//else
:

//while
()?

//break
@~
//continue
@#
//return
@(),@{},@[]
@;
//for
()??{}
//goto
@=$LabelName
//do
()?
//switch
()??
//case
??:
//default
??:
//inline module: $InlineModule [= ASM]
@<<$Module
>>@
//__asm
//__asm__

//short operand
?:
XXX || YYY && ZZZ
()=>{}

//extern
//static
//
//unsigned
//int
//void
//char
//long
//const
//float
//double
//short
//
//struct
//union
//enum
//sizeof
//
//typeof//
//__typeof//
//__typeof__//
//
//volatile
//__volatile//gcc
//__volatile__//gcc
//
//__label__
//
//auto
//inne
//__inline//gcc
//__inline__//gcc
//
//__signed//gcc
//__signed__//gcc
//
//__attribute
//__attribute__
//__alignof
//__alignof__
//
//restrict
//__restrict
//__restrict__
//__extension__//gcc
//
//_Bool
//_Generic//c11

/* preprocessor */
//define
//include
//include_next
//ifdef
//ifndef
//elif
//endif
//defined
//undef
//error
//warning
//line
//pragma
//__LINE__
//__FILE__
//__DATE__
//__TIME__
//__FUNCTION__
//__VA_ARGS__
//__COUNTER__
/////* special identifiers */
//__func__
/////* special floating point values */
//__nan__
//__snan__
//__inf__
