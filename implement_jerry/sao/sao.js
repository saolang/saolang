//const xx = 1;
//let xx = 1;

var ttt = (x, y)=>1.0*Math.pow(x+y,0.5);//sqrt

function f(c){
	print("c="+c+":");
	@?(c==1){
		print ("IF BR");
	}@:@?(c==2){
		print ("ELSE IF BR");
	}@:{
		print ("ELSE BR");
	}
}

f(1);
f(2);
f(3);

print(ttt(3.0*3.0,4.0*4.0));


/** NOTES
const/let (2015 fetaure) not yet for jerry: it's ok, sao don't need it at all
*/
