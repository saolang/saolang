#include "scc.h"

//TODO scc.h scc_libc.h later
//TODO sao_compile() => compile to SLJIT bits
//TODO make sao_compile() and sao_run() standalone

/* private */

//ST_FUNC void _sao_preprocess_start(SCCState *s1, int is_asm)
//{
//	CString cstr;
//	int i;
//
//	s1->include_stack_ptr = s1->include_stack;
//	s1->ifdef_stack_ptr = s1->ifdef_stack;
//	file->ifdef_stack_ptr = s1->ifdef_stack_ptr;
//	pp_expr = 0;
//	pp_counter = 0;
//	pp_debug_tok = pp_debug_symv = 0;
//	pp_once++;
//	pvtop = vtop = vstack - 1;
//	s1->pack_stack[0] = 0;
//	s1->pack_stack_ptr = s1->pack_stack;
//
//	set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
//	set_idnum('.', is_asm ? IS_ID : 0);
//
//	cstr_new(&cstr);
//	cstr_cat(&cstr, "\"", -1);
//	cstr_cat(&cstr, file->filename, -1);
//	cstr_cat(&cstr, "\"", 0);
//	scc_define_symbol(s1, "__BASE_FILE__", cstr.data);
//
//	cstr_reset(&cstr);
//	for (i = 0; i < s1->nb_cmd_include_files; i++) {
//		cstr_cat(&cstr, "#include \"", -1);
//		cstr_cat(&cstr, s1->cmd_include_files[i], -1);
//		cstr_cat(&cstr, "\"\n", -1);
//	}
//	if (cstr.size) {
//		*s1->include_stack_ptr++ = file;
//		scc_open_buf(s1, "<command line>", cstr.size);
//		SCC(memcpy)(file->buffer, cstr.data, cstr.size);
//	}
//	cstr_free(&cstr);
//
//	if (is_asm){
//		//@ref test/asmtets.S
//		scc_define_symbol(s1, "__ASSEMBLER__", NULL);
//	}
//
//	parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
//	tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
//}
//
///* cleanup from error/setjmp */
//ST_FUNC void _sao_preprocess_end(SCCState *s1)
//{
//    while (macro_stack)
//        end_macro();
//    macro_ptr = NULL;
//}

static int _sao_check_he0xE(int t, const char *p)
{
	if (t == TOK_PPNUM && toup(SCC(strchr,char*)(p, 0)[-1]) == 'E')
		return 'E';
	return t;
}

static int _sao_need_space(int a, int b)
{
	return 'E' == a ? '+' == b || '-' == b
		: '+' == a ? TOK_INC == b || '+' == b
		: '-' == a ? TOK_DEC == b || '-' == b
		: a >= TOK_IDENT ? b >= TOK_IDENT
		: a == TOK_PPNUM ? b >= TOK_IDENT
		: 0;
}

static void _sao_line(SCCState *s1, BufferedFile *f, int level)
{
	int d = f->line_num - f->line_ref;

	if (s1->dflag & 4)
		return;

	if (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
		;
	} else if (level == 0 && f->line_ref && d < 8) {
		while (d > 0) SCC(fputs)("\n", s1->ppfp), --d;

	} else if (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
		SCC(fprintf)(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);

	} else {
		SCC(fprintf)(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
				level > 0 ? " 1" : level < 0 ? " 2" : "");
	}
	f->line_ref = f->line_num;
}

static int _sao_preprocess(SCCState *s1)
{
	BufferedFile **iptr;
	int token_seen, spcs, level;
	const char *p;
	char white[400];

	parse_flags = PARSE_FLAG_PREPROCESS
		| (parse_flags & PARSE_FLAG_ASM_FILE)
		| PARSE_FLAG_LINEFEED
		| PARSE_FLAG_SPACES
		| PARSE_FLAG_ACCEPT_STRAYS
		;

	if (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
		parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

#ifdef PP_BENCH
	/* for PP benchmarks */
	do next(); while (tok != TOK_EOF);
	return 0;
#endif

	if (s1->dflag & 1) {
		//pp_debug_builtins(s1);
		s1->dflag &= ~1;
	}

	token_seen = TOK_LINEFEED, spcs = 0;
	_sao_line(s1, file, 0);
	for (;;) {
		iptr = s1->include_stack_ptr;
		next();
		if (tok == TOK_EOF)
			break;

		level = s1->include_stack_ptr - iptr;
		if (level) {
			if (level > 0)
				_sao_line(s1, *iptr, 0);
			_sao_line(s1, file, level);
		}
		if (s1->dflag & 7) {
			//pp_debug_defines(s1);
			if (s1->dflag & 4)
				continue;
		}

		if (is_space(tok)) {
			if (spcs < sizeof white - 1)
				white[spcs++] = tok;
			continue;
		} else if (tok == TOK_LINEFEED) {
			spcs = 0;
			if (token_seen == TOK_LINEFEED)
				continue;
			++file->line_ref;
		} else if (token_seen == TOK_LINEFEED) {
			_sao_line(s1, file, 0);
		} else if (spcs == 0 && _sao_need_space(token_seen, tok)) {
			white[spcs++] = ' ';
		}

		white[spcs] = 0;
		SCC(fputs)(white, s1->ppfp);
		spcs = 0;
		SCC(fputs)(p = get_tok_str(tok, &tokc), s1->ppfp);
		token_seen = _sao_check_he0xE(tok, p);
	}
	return 0;
}

/* public */
//reusing SCCState as SAOState... may change in future..
ST_FUNC int sao_compile(SCCState *s1)
{

	//scc_warning("TODO sao_compile()");

	//_sao_preprocess_start()
	_sao_preprocess(s1);//tmp
	//sccgen_compile
	//_sao_preprocess_end()

	//	cur_text_section = NULL;
	//	funcname = "";
	//	anon_sym = SYM_FIRST_ANOM;
	//	section_sym = 0;
	//	const_wanted = 0;
	//	nocode_wanted = 0x80000000;
	//
	//	/* define some often used types */
	//	int_type.t = VT_INT;
	//	char_pointer_type.t = VT_BYTE;
	//	mk_pointer(&char_pointer_type);
	//#if PTR_SIZE == 4
	//	size_type.t = VT_INT | VT_UNSIGNED;
	//	ptrdiff_type.t = VT_INT;
	//#elif LONG_SIZE == 4
	//	size_type.t = VT_LLONG | VT_UNSIGNED;
	//	ptrdiff_type.t = VT_LLONG;
	//#else
	//	size_type.t = VT_LONG | VT_LLONG | VT_UNSIGNED;
	//	ptrdiff_type.t = VT_LONG | VT_LLONG;
	//#endif
	//	func_old_type.t = VT_FUNC;
	//	func_old_type.ref = sym_push(SYM_FIELD, &int_type, 0, 0);
	//	func_old_type.ref->f.func_call = FUNC_CDECL;
	//	func_old_type.ref->f.func_type = FUNC_OLD;
	//
	//	scc_debug_start(s1);
	//
	//#if (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==32)
	//	arm_init(s1);
	//#endif
	//
	//#ifdef INC_DEBUG
	//	printf("%s: **** new file\n", file->filename);
	//#endif
	//
	//	parse_flags= PARSE_FLAG_PREPROCESS |PARSE_FLAG_TOK_NUM |PARSE_FLAG_TOK_STR;
	//	next();
	//	decl(VT_CONST);
	//	gen_inline_functions(s1);
	//	check_vstack();
	//
	//	scc_debug_end(s1);

	return 0;
}
