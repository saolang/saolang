
//syntax, expression to two level codes
//high level script-like
// => eventually translated into low level code
//low level as asm to machine instructives

//syntax switcher TBD
//default is controlled by the .ext of file

//JIT ASM is somehow ASM but more platform adopted


//for syntax JIT-ASM, using regexp is much eaier to compiler then, right?

```

function addNumber(total, value){
  return total + value;
}
function sum(...args){
  return args.reduce(addNumber, 0);
}
sum(1,2,3); //6

^sum(...args){ @~ args.reduce(addNumber,0) }
@sum=(...args)=>args.reduce(addNumber,0)

```

```
@ref ECMA-262 3rd
https://www.ecma-international.org/publications/files/ECMA-ST-ARCH/ECMA-262,%203rd%20edition,%20December%201999.pdf
https://en.wikipedia.org/wiki/JSON

Literal
::
NullLiteral
BooleanLiteral
NumericLiteral
StringLiteral
```

to get compliance with JSON, seem true/false/null is un-avoidable to use in SAO Lang...
