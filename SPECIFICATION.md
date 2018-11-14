# Core Syntactic-Sugar

* keyword-less - removed all english keywording
* delimiter(;) is strongly recommented, but somehow/sometime it works when omited

| sao | c | remark / remember-helper |
|---|---|---|---|
| ()?():() | ()?():() | classic ternary operator |
| (x)?:(z) | (tmp=x)?tmp:z | binary operator |
| @? | if | ask => if |
| @: | 'else' for if or 'default' for switch | ?: => : => else |
| @:? | else if | elif/elseif |
| @?(){} | if(){} |
| @?(){}@:{} | if(){}else{} |
| @?(){}@:?(){}@:{} | if(){}else if(){}else{} |
| @# | switch | #=>hash=>hasing=>switch |
| @~ | break | ~ => escape => break |
| @% | continue | % => percent => continue |
| @\_ | do| bottom line => just do it |
| @#(x){1:@\~;2:x+2;@\~;@:x-1;} | switch(x){ case 1:break; case 2:x+2;break; default:x-1;} |
| @(;;){} | for(;;){} |
| @(i=1;i<x;i++){ @?(i%3==0) @%; } | for(i=1;i<x;i++){ if(i%3==0)continue;} |
| @$(){} | while(){} | 
| @$()@_{} | while(){}  | while()do{} |
| @_{}@$() | do{}while() | 
| @_{}; | do{}while(0) | doonce{} |
| @(); | return; | return void |
| @(42); | return 42; | 
| @\<c\>; | N/A | import c; |
| @\<cmath\>; | N/A | import cmath; |
| @{main}; | N/A | export {main}; |
| @[func1,func2]; | N/A | export [func1,func2]; |

## remember-helper

```SAO
@:   ?: => else
@:?  else+if => elseif
@#   hash => hashing => switch
@$   money => loop
@%   percent => ratio => running => continue
@~   ~ => escape => break

@()  return
@{}  return or export object
@[]  return or export array
@<..> import & declare?

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
```

# ext1

* like ES6; function default return <SaoType*>, and do calc by guessing...
* like golang, a return type is support?

| sao | comp | misc |
| -- | -- | -- |
| ()=>{} | function(){} |
| XXX(){} | function XXX(){} |
| XXX = x => (x^2) | function XXX(x){ return x^2} |
| XXX(){} | function XXX(){} |
| -- | -- | -- |
| XXX(x)<SaoType*>=>(x^2)| function XXX()<SaoType*>{return <SaoType*>x^2;} | <SaoType*> is by default |
| XXX(x)<c.byte8>=>(x^2)| function XXX()<c.byte8>{return <c.byte8> x^2;} | convert to preferred...? * TODO |

# SLJIT

//run expression using SLJIT syntax
<SLJIT>{
}

# inline asm

$ModuleName=ASM if omit.

```
<<<@$ModuleName

@$ModuleName>>>
```

```LIBC
<c>
<c.xxx>
<c.math>

//for
(i=1;i<33;i++){
	(i=1;i<33;i++){
		(math.rand()>0.5) ? @# : @~
	}
}

()?{//if()
}:()?{//elseif
}:{//else
}

//like switch

(y)?{
	1:@~
	2:@~
}

```

``` shared lib

@{
sao_new:
}

```

```JSON
[x,y]=[1,2];
{x,y}={};
```

```DL/FFI
<dlfcn>
dlfcn.dlsym()
```
