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

<..>    declare 

*/
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
