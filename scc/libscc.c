#ifndef LIBSCC_H
#define LIBSCC_H

//#ifndef LIBSCCAPI
//# define LIBSCCAPI
//#endif

#ifdef __cplusplus
extern "C" {
#endif

//TODO return LibSao*
//LibSao* sao=scc_new();
//sao->compile();

scc_new();
scc_free();

scc_set_options();
scc_add_inc_path();
scc_add_inc_sys_path();
scc_add_file();
scc_add_lib();
scc_add_lib_path();
scc_set_lib_path();//NULL to clear

scc_define_symbol();
scc_undefine_symbol();
scc_add_symbol();
scc_get_symbol();

scc_compile_str();
//scc_compile_file();
scc_set_output_type();
#define SCC_OUTPUT_MEM 1
#define SCC_OUTPUT_EXE 2
#define SCC_OUTPUT_DLL 3
#define SCC_OUTPUT_OBJ 4
#define SCC_OUTPUT_PP  5

scc_relocate();
///* possible values for 'ptr':
//   - SCC_RELOCATE_AUTO : Allocate and manage memory internally
//   - NULL              : return required memory size for the step below
//   - memory address    : copy code to memory passed by the caller
//   returns -1 if error. */
//#define SCC_RELOCATE_AUTO (void*)1

scc_run();
scc_output_file();

scc_set_error_func

#ifdef __cplusplus
}
#endif

#endif//LIBSCC_H
