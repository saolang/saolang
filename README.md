# SAO

A very SAO computer language.

```
                                            .::-`                          
          yho..-:/++++:`         /sddddmmmmmNMMNNy`                        
         :MMMNNNMMMMmdh+         .ohmmhhooodMMMMMd`                        
         oMMMd:MMMMM.`           .ymmmdo. -NMMMMm.                         
         dMMM:/MMMMMso.     :sys+:-:ydMN+:NMMMMy`                          
        .MMMNdNMMMMNys:     `-/ymNNds+++sNMMMMo                            
        .MMMo.yMMMMy--`         `-smMMMMMMMMN/                             
        -MMMyyNMMMMNmho            :NMMMMMMMNhs/-.`                        
        +MMNoyMMMMM+.`          .+hNMMMMNdmNMMMMNmmhys/:-.`                
        hMMm..NMMMm:+s+-     .+hNMMMmmMMNmd:/smMMMMMMMMMNmdhso/:---.`      
       `NMMMmmNmmdddMMMNy..:ydNMMNs+/+MMMMMdosmMMMMMdmNNMMMMNmmdddhhy/     
        smNd/-:::--:MMMMMo-:/.-dMNdhmNMMMMM+-/MMMMMm.`.-::+:-.```````      
     `.` .hy+/.odmNNMMMMN      :MMm..yMMMMN+omMMNds.                       
/ys+`.ddh:-shm-  .:hMMMMy       MMMdhNMMMMNmdddmo-`                        
-mMMs ./o:   .     hMMMM/       yNMy/NMMMM/    mMNd+`                      
 `:s/       ```   :MMMMm`        .o`-MMMMN-://+hMMMMm-                     
            -shhyyNMMMm-       ``.-omMMMNNmdo-.`sMMMMm`                    
              .oMMMNms`  /oooshdmMNNhso/-.`     .NMMMM-                    
                +h+-`    sNMMMMmy/.`             :yNNs`                    
                          `:++:`                   .`                      
```

# Feature

inline

* ASM built-in support

art

* bootstrap     - self-hosting
* keyword-less  - there is no (natual language) keywords
* FFI/DL        - dynamically load libraries
* import/export - file is module when compile
* keep tiny     - size does matter
* keep elegant  - meaningless if not so

inline+

* JSON/BSON built-in support
* more inline support via sao-plugin, such as RegExp

future

* multi-processing/multi-threading/coroutines
* hardware abstracted binary codes + vm interpretor
* sao-vm like qemu
* promise/q     - inner promise pattern support
* await/async

# Core Syntactic-Sugar

* keyword-less - removed all english keywording
* delimiter(;) is strongly recommented, but somehow/sometime it works when omited

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
| @#(x){1:@\~;2:x+2;@\~;@:x-1;} | switch(x){case 1:break;case 2:x+2;break;default:x-1;} | eg switch |
| @(;;){} | for(;;){} |
| @(i=1;i<x;i++){@?(i%3==0)@%;} | for(i=1;i<x;i++){ if(i%3==0)continue;} | eg for |
| @$(){} | while(){} | money => loop |
| @$()@\_{} | while(){}  | while()do{} |
| @\_{}@$() | do{}while() | 
| @\_{}; | do{}while(0) | doonce{} |
| @(); | return; | return void |
| @(42); | return 42; | 

# Ext Syntactic-Sugar

| sao | pseudo | remember-helper |
|---|---|---|
| @\<c\>; | N/A | import c; |
| @\<cmath\>; | N/A | import cmath; |
| @{main}; | N/A | export {main}; |
| @[func1,func2]; | N/A | export [func1,func2]; |
| ()=>{} | function(){} |
| XXX(){} | function XXX(){} |
| XXX(){} | function XXX(){} |
| XXX = x => (x^2) | function XXX(x){ return x^2} |
| XXX(x)<SaoType*>{@(x^2)} | function XXX()<SaoType*>{return <SaoType*>x^2;} |  |
| XXX = (x)<SaoType*> => (x^2) | function XXX()<SaoType*>{return <SaoType*>x^2;} |  |
| XXX(x)<c.byte8>{@(x^2)} | function XXX()<c.byte8>{return (<c.byte8>) x^2;} | ... |

* like ES6; function default return <SaoType*>, and do calc by guessing...
* like golang, a return type is support?

# StackLess JIT

```
//run expression using SLJIT syntax
<SLJIT>{
}
```















