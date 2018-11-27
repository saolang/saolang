# SAO

A Very "Sao" Computer Language

```
                         :yyydmmmMMMh`                  
       yMh+smNMMd-      -NMMMMMMMMMMM:                  
       mMMMMMMMMN/       +mMNhoodMMMN`                  
      `NMMyMMMh-`        .:+-   hMMMh                   
      `NMN.MMMh          dMMMo .NMMM/                   
      -NMy`MMMy`      -` `yMMM-sMMMy                    
      /MM+/MMMMN+   `dMNy- +Nd-NMMM-                    
      oMMMMMMMMd+    `+mMMy. `hMMMy                     
      oMNsmMMMs        `yMMMdmMMMN.                     
      oMN`/MMM:          /NMMMMMMs                      
      oMm oMMMNm+         +MMMMMM+                      
      sMMmMMMMMNo         -NMMMMMMNo`                   
      hMNNMMMMo          /NMMMMMMMMMNd/-                
      dMo`hMMN`        `sMMMMNooNMMMMMMMms/`            
     `mMy sMMh`/:     .dMMMMMMMh`oNMMMMMMMMNy+.         
     .NMdodMMNNMMs   -mMMMd/dMMM: :NMMMMMMMMMMMNmh+.    
     :MMMMMMmdmMMM/ /NMMN/ `mMMMmhNMMMNmMMMMMMMNNNNm`   
     .NMNy+.  :MMMmoho/NMymMMMMMyodMMMm`:ohmy/.         
      sM+ .::-/MMMh    yMmdNMMMM. dMMMs                 
       /- `dMMNMMMo    +Mh `mMMm oMMMm`                 
    /` oMN:`oNMMMN:    :Mm -MMMMNMMMs`                  
os- dNo`yN+  `hMMM-    -NMmNMMMMMMmo                    
dMd /Nm` ~`   sMMN.    .NMMMMMMh.``Md:                  
/MN- `        hMMm`    `dM//MMM:   dMM+                 
 oN`         `NMMh      `h.oMMM-   yMMN:                
             :MMMo         yMMN+shddMMMh                
        `hms+hMMN.        :NMMMMN/ `mMMN.               
          oNMMMMs      `/hMMMMdo.   yMMM/               
           oMMMd` `+oodMMMMho.      oMMM+               
           -NNo`  +MMMMMNs.         -NMM+               
            +-    .dMMMd-            /Ny`               
                   `ohs               -                 
```

# Feature

Phrase I

* bootstrap         - self-hosting
* keyword-less      - there is no (natual language) keywords
* FFI/DL            - dynamically load libraries
* import/export     - file is module when compile
* keep tiny         - size does matter
* keep elegant      - meaningless if not so

Phrase II

* free syntax sugar
* JSON/BSON built-in support

Phrase III

* multi-processing/multi-threading/coroutines
* hardware abstracted binary codes + vm interpretor
* sao-vm like qemu
* promise/q     - inner promise pattern support
* await/async

# Sao Syntactic-Sugar
## Core 

| sao | c | remember-helper |
|---|---|---|
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
| @#(x){1:@\~;2:x+2;@\~;@:x-1;} | switch(x) {case 1:break;case 2:x+2;break;default:x-1;} | eg switch |
| @(;;){} | for(;;){} |
| @(i=1;i<x;i++){@?(i%3==0)@%;} | for(i=1;i<x;i++) {if(i%3==0)continue;} | eg for |
| @$(){} | while(){} | money => loop |
| @$()@\_{} | while(){}  | while()do{} |
| @\_{}@$() | do{}while() | 
| @\_{}; | do{}while(0) | doonce{} |
| @(); | return; | return void |
| @(42); | return 42; | 
| XXX(){} | XXX(){} |
| XXX()<type>{} | type XXX(){} |

* keyword-less - removed all english keywording
* delimiter(;) is strongly recommented, but somehow/sometime it works when omited
* parentheses {} is very important for matching

## Ext 

| sao | pseudo | remember-helper |
|---|---|---|
| @\<c\>; | N/A | import c; |
| @\<cmath\>; | N/A | import cmath; |
| @{main}; | N/A | export {main}; |
| @[func1,func2]; | N/A | export [func1,func2]; |
| ()=>{} | function(){} | closure |
| ()<type>=>{} | function()<type>{} | declare return type |
| XXX = x => (x^2) | function XXX(x){ return x^2} | assign closure to var |
| XXX(x)<SaoType*>{@(x^2)} | function XXX()<SaoType*>{return <SaoType*>x^2;} |  |
| XXX = (x)<SaoType*> => (x^2) | function XXX()<SaoType*>{return <SaoType*>x^2;} |  |
| XXX(x)<c.byte8>{@(x^2)} | function XXX()<c.byte8>{return (<c.byte8>) x^2;} | ... |
| @\*\<language-handler>{..} | | eating .. with prefer language handler, * => mouth => eat |
| @\*\<SAO\>{..} | using SAO handler (default) to process .. |
| @\*\<SLJIT\>{..} | using SLJIT (StackLessJIT) handler to process .. |
| {..} @\|\<handler> | | piping .. to handler |

* like ES6; function default return <SaoType*>, and do calc by guessing...
* like golang, a return type is support?

## OS Mode

stdin/stdout/stderr is controlled/assigned by caller(the OS or intepreter)

#

# StackLess JIT

# misc TODO 

* stdin/stdout/stderr => std stream/pipe in/out
* piping

## JSON

```JSON
[x,y]=[1,2];
{x,y}={};
```

## DLFCN/FFI
```DL/FFI
<dlfcn>
dlfcn.dlsym()
```

# FAQ

## What mean Sao?

https://en.wiktionary.org/wiki/%E9%A8%B7














