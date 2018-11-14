## remember-helper

```SAO
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
