/* macro magic for scc */

#define SCC_CAT_RAW(a,...) a##__VA_ARGS__
#define SCC_CAT(a,...) SCC_CAT_RAW(a,__VA_ARGS__)

#define SCC_IIF_0(t, ...) __VA_ARGS__
#define SCC_IIF_1(t, ...) t
#define SCC_IIF(c) SCC_CAT_RAW(SCC_IIF_,c)

#define SCC_CHECK_N(x, n, ...) n
#define SCC_CHECK(...) SCC_CHECK_N(__VA_ARGS__, 0,)

#define SCC_COMPL_0 1
#define SCC_COMPL_1 0
#define SCC_COMPL(b) SCC_CAT_RAW(SCC_COMPL_, b)

#define SCC_PROBE(x) x, 1,
#define SCC_NOT_0 SCC_PROBE(~)
#define SCC_NOT(x) SCC_CHECK(SCC_CAT_RAW(SCC_NOT_,x))

// has x => 0
#define SCC_BOOL(x) SCC_COMPL(SCC_NOT(x))

// SCC_IF(c)( when not c, c) ?
#define SCC_IF(c) SCC_IIF(SCC_BOOL(c))

#define SCC_IS_PAREN_PROBE(...) SCC_PROBE(~)
#define SCC_IS_PAREN(x) SCC_CHECK(SCC_IS_PAREN_PROBE x)

#define SCC_EAT(...)
#define SCC_EXPAND(...) __VA_ARGS__
#define SCC_WHEN(c) SCC_IF(c)(SCC_EXPAND,SCC_EAT)

// e.g. SCC_IF_ELSE(__VA_ARGS__)( __VA_ARGS__, void* )
#define SCC_IF_ELSE(...) SCC_IF(SCC_NOT(SCC_IS_PAREN(__VA_ARGS__ ())))

// return vargs or else returns d
#define SCC_OR_ELSE(d,...) SCC_IF_ELSE(__VA_ARGS__)(__VA_ARGS__,d)

#define SCC_EMPTY()
#define SCC_DEFER(id) id SCC_EMPTY()
#define SCC_OBSTRUCT(...) __VA_ARGS__ SCC_DEFER(SCC_EMPTY)()

#define SCC_EVAL(...)  SCC_EVAL1(SCC_EVAL1(SCC_EVAL1(__VA_ARGS__)))
#define SCC_EVAL1(...) SCC_EVAL2(SCC_EVAL2(SCC_EVAL2(__VA_ARGS__)))
#define SCC_EVAL2(...) SCC_EVAL3(SCC_EVAL3(SCC_EVAL3(__VA_ARGS__)))
#define SCC_EVAL3(...) SCC_EVAL4(SCC_EVAL4(SCC_EVAL4(__VA_ARGS__)))
#define SCC_EVAL4(...) SCC_EVAL5(SCC_EVAL5(SCC_EVAL5(__VA_ARGS__)))
#define SCC_EVAL5(...) __VA_ARGS__

// eat 1 value every time
#define SCC_WHILE1(macro,value1,...)\
	SCC_WHEN(SCC_NOT(SCC_IS_PAREN(value1 ())))\
(\
  SCC_OBSTRUCT(macro)(value1)\
  SCC_OBSTRUCT(WHILE_INDIRECT1) () (macro,__VA_ARGS__)\
)
#define WHILE_INDIRECT1() SCC_WHILE1

//TODO buggy, need rewrite again...
///// eat 2 value every time
///#define SCC_WHILE2(macro,value1,value2, ...)\
///	SCC_WHEN(SCC_NOT(SCC_IS_PAREN(value2 ())))\
///(\
///  SCC_OBSTRUCT(macro) (value1,value2)\
///  SCC_OBSTRUCT(WHILE_INDIRECT2) () (macro, value1,__VA_ARGS__)\
///)
///#define WHILE_INDIRECT2() SCC_WHILE2
///
///// eat 3
///#define SCC_WHILE3(macro,value1,value2,value3,...)\
///	SCC_WHEN(SCC_NOT(SCC_IS_PAREN(value3 ())))\
///(\
///  SCC_OBSTRUCT(macro) (value1,value2,value3)\
///  SCC_OBSTRUCT(SCC_WHILE_INDIRECT3) () (macro,value1,value2,__VA_ARGS__)\
///)
///#define SCC_WHILE_INDIRECT3() SCC_WHILE3
///
///// ITR => WHILE
#define SCC_ITR1(...) SCC_EVAL(SCC_WHILE1(__VA_ARGS__))
///#define SCC_ITR2(...) SCC_EVAL(SCC_WHILE2(__VA_ARGS__))
///#define SCC_ITR3(...) SCC_EVAL(SCC_WHILE3(__VA_ARGS__))
/////#define SCC_ITR4(...) SCC_EVAL(SCC_WHILE4(__VA_ARGS__))
///#define SCC_ITR(n,...) SCC_EVAL(SCC_WHILE##n(__VA_ARGS__))

// YYY,ZZZ => "YYY,ZZZ"
#define SCC_QUOTE_PACK(...) #__VA_ARGS__

// ZZZ => "$ZZZ"
#define SCC_QUOTE(...) SCC_QUOTE_PACK(__VA_ARGS__)

// XXXX => {XXXX}
#define SCC_BRACKET_WRAP(...) {__VA_ARGS__}

//99% SOLUTION FOR MCAT(): Variable Argument Macro (VA_MACRO) up to 9 arguments 
#define SCC_NUM_ARGS_(_1, _2, _3, _4, _5, _6, _7, _8, _9, TOTAL, ...) TOTAL
#define SCC_NUM_ARGS(...) SCC_NUM_ARGS_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SCC_MCAT(...) SCC_CAT(SCC_MCAT, SCC_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)
#define SCC_MCAT1(_1) _1
#define SCC_MCAT2(_1, _2)  SCC_CAT(SCC_MCAT1(_1),_2)
#define SCC_MCAT3(_1, _2, _3)  SCC_CAT(SCC_MCAT2(_1,_2),_3)
#define SCC_MCAT4(_1, _2, _3, _4)  SCC_CAT(SCC_MCAT3(_1,_2,_3),_4)
#define SCC_MCAT5(_1, _2, _3, _4, _5)  SCC_CAT(SCC_MCAT4(_1,_2,_3,_4),_5)
#define SCC_MCAT6(_1, _2, _3, _4, _5, _6) SCC_CAT(SCC_MCAT5(_1,_2,_3,_4,_5),_6)
#define SCC_MCAT7(_1, _2, _3, _4, _5, _6,_7) SCC_CAT(SCC_MCAT6(_1,_2,_3,_4,_5,_6),_7)
#define SCC_MCAT8(_1, _2, _3, _4, _5, _6,_7,_8) SCC_CAT(SCC_MCAT7(_1,_2,_3,_4,_5,_6,_7),_8)
#define SCC_MCAT9(_1, _2, _3, _4, _5, _6,_7,_8,_9) SCC_CAT(SCC_MCAT8(_1,_2,_3,_4,_5,_6,_7,_8),_9)


//@ref:
//http://p99.gforge.inria.fr/p99-html/p99__for_8h_source.html
//https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
//http://pfultz2.com/blog/2012/05/10/turing/

