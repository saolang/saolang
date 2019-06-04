# Syntactic-Sugar

* Sao™ is trademark-registered and shared to human race for free forever, hoping this shows respect to Musk ;)

## Core V1.0 

NOTES:

* English keywords removed;
* Suitable for pseudocode also

| sao | c/js/php | brain-helper |
|---|---|---|
|  |  |  |
| ()?():() | ()?():() | classic ternary operator |
| @? | if | ask => if |
| @: | else |  |
| @:@? | else if |  |
| @# | switch | #=>hash=>hashing=>switch |
| @= | case | case => equals |
| @=: | default | case default |
|  |  |  |
| @\* | for | \* => all => for loop |
| @$ | while | money => loop |
| @\_ | do| bottom line => just do it |
| @! | break | ! => astonished => break |
| @% | continue | % => percent => continue |
|  |  |  |
| @^ | function | |
| @~ | return | |
|  |  |  |
| @(lib) | import/require lib | |
| @:? | elseif | shorthand of else if |
|  |  |  |
| @@() | async() | |
| @@^() | async function() | |
| @@= | await | |


e.g.

```
@?(){}
if(){}

@?(){}@:{}
if(){}else{}

@?(){}@:@?(){}@:{}
if(){}else if(){}else{}

@?(){}@:?(){}@:{}
if(){}elseif(){}else{}

@\_{}@$()
do{}while()

@\*(;;){}
for(;;){}

@^XXX(){}
function XXX(){}

$(){}
while(){}

@#(x){@=1:@!;@=2:x+2;@!;@=:x-1;}
switch(x){case 1:break;case 2:x+2;break;default:x-1;}

@*(i=1;i<x;i++){@?(i%3==0)@%}
for(i=1;i<x;i++){if(i%3==0)continue;}

@lib=@(libname);
var lib=require(libname);

```

## Designing (not stable yet):

| sao | c/js/php | remember-helper |
|---|---|---|
| stdin/stdout/stderr | | |
| json | | core structure like lua-table ? |
| lbl: |  | label for jumping |
| @1 | true | |
| @0 | false | |
| @& | null | |
| @ | var | |

* but true/false/null is still enable for JSON
* use the Core level to build the vm runner
* delimiter(;) is strongly recommented, but somehow/sometime it works when omited
* parentheses {} is very important for matching
* stdin/stdout/stderr is controlled/assigned by caller(the OS or intepreter)
* stdin/stdout/stderr => std stream/pipe in/out

e.g.
```
@[lib1,lib2]=@(lib1name,lib2name);
```

## Not support syntax sugar...

Abandom feature from ES (which should be using sao runtime)
```
@sao=@('sao')
```
|    | this | |
|    | new | |
|    | typeof | |
|    | instanceof | |

## Ext Syntactic Sugar (W.I.P.)

* make parse into two levels ( default buildin .core and then .ext )

| sao | pseudo | remember-helper |
|---|---|---|
| @<?()@?!(ex){}@?!>{}@\>!{} | try/catch/finally | |
| @() | require() | module import |
| x\|\|z | (tmp=x)?tmp:z | binary operator |
| @[] | var[] | destructuring |
| @{} | var{} | destructuring |
| ()=>{} | function(){} | closure |
| XXX = x => (x^2) | function XXX(x){ return x^2} | assign closure func to var |
| (...aaa)=>aaa | get the args |
| @:? | elseif | elif/elseif |
| @\_{}; | do{}while(0) | doonce{} |
| @\<\> | require() | buildin module import, @<c>,@<math>,@<console> |
| @\<c\>; | N/A | import c; |
| @\<cmath\>; | N/A | import cmath; |
|  | may give up typeing |
| XXX()\<type\>{} | type XXX(){} |
| ()type=>{} | function()type{} | declare return type |
| XXX(x)returnType{@~(x^2)} | function XXX()returnType{return (returnType)x^2;} |  |
| XXX = (x)\<SaoType*\> => (x^2) | function XXX()\<SaoType*\>{return \<SaoType\>x^2;} |  |
| XXX(x)\<c.byte8\>{@~(x^2)} | function XXX()\<c.byte8\>{return (\<c.byte8\>) x^2;} | ... |
|  | lang handler |
| @\*\<language-handler\>{..} | | eating .. with prefer language handler, * =\> mouth =\> eat |
| @\*\<SAO\>{..} | using SAO handler (default) to process .. |
| @\*\<SLJIT\>{..} | using SLJIT (StackLessJIT) handler to process .. |
| {..} @\|\<handler\> | | piping .. to handler |

