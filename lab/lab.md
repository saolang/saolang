* bootstrap - must be able to compile and build itself, with some tricks of cause.
* keep tiny - size does matter
* ffi support - //with import
* package support -
* keyword zero -
* elegant - what is the meaning if not so?

```
# form 1
($cmd
()
()
)

(
# $cmd(){}

if(){}/if(){}else{}

=> ()?():()

while(){}/do(){}
=> (;;){}

continue;
break;
return;


```

```
SAO
https://en.wiktionary.org/wiki/%E9%A8%B7

!@#$%^&*
-=_+\|:;/?.,`~
(){}[]""'<>

{
	$import($lib.*) // import symbol under $lib, if $lib is not loaded, try load shared lib?
		//function
	{$aaa,$bbb}=
	((kk,hh){
	 $symbol=()=>{
	 }
	 $sym_rt=$symbol("xx",'yy',(xx));

	 $return() //simbol?
	 })(999,'bb');//semicolon is not mandatory.

	$asm( $expression );

	[$ccc,$ddd]=$haha();

	@( $return value )
}


{
import:"",
exp:"",
return:""
}

()=>{
:
:
:
}

`` js tmp cmd

~	二进制补码运算符是一元运算符，具有"翻转"位效果，即0变成1，1变成0。	(~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式
&	如果同时存在于两个操作数中，二进制 AND 运算符复制一位到结果中。	(A & B) 将得到 12，即为 0000 1100
|	如果存在于任一操作数中，二进制 OR 运算符复制一位到结果中。	(A | B) 将得到 61，即为 0011 1101
^	如果存在于其中一个操作数中但不同时存在于两个操作数中，二进制异或运算符复制一位到结果中。	(A ^ B) 将得到 49，即为 0011 0001
~	二进制补码运算符是一元运算符，具有"翻转"位效果，即0变成1，1变成0。	(~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。
<<	二进制左移运算符。左操作数的值向左移动右操作数指定的位数。	A << 2 将得到 240，即为 1111 0000
>>	二进制右移运算符。左操作数的值向右移动右操作数指定的位数。	A >> 2 将得到 15，即为 0000 1111

? (if)
: (else)
?? (while)
?! (catch)
>. (return)
<. (exit)
>n (forward goto label n) <n (backward goto label n)
-> (new)  //no need
<- (delete) //no need too
>, (break)
<, (continue) ^: protected: | (switch)
= (#define)
[ (declarations)


```


```
Round I
* keyword-less
* bootstrap
* symbol=[A-Za-z_][0-9A-Za-z_]*
* express in args
* mathmetically?
* enclosure / anonymous function
* json/bson support

Round II

Round III
* regexp native like JS

```


