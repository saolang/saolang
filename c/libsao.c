#ifndef LIBSAO_H
#define LIBSAO_H

//#ifndef LIBSAOAPI
//# define LIBSAOAPI
//#endif

#ifdef __cplusplus
extern "C" {
#endif

//TODO return LibSao*
//LibSao* sao=sao_new();
//sao->compile();

sao_new();
sao_free();

sao_set_options();
sao_add_inc_path();
sao_add_inc_sys_path();
sao_add_file();
sao_add_lib();
sao_add_lib_path();
sao_set_lib_path();//NULL to clear

sao_define_symbol();
sao_undefine_symbol();
sao_add_symbol();
sao_get_symbol();

sao_compile_str();
//sao_compile_file();
sao_set_output_type();
#define SAO_OUTPUT_MEM 1
#define SAO_OUTPUT_EXE 2
#define SAO_OUTPUT_DLL 3
#define SAO_OUTPUT_OBJ 4
#define SAO_OUTPUT_PP  5

sao_relocate();
///* possible values for 'ptr':
//   - SAO_RELOCATE_AUTO : Allocate and manage memory internally
//   - NULL              : return required memory size for the step below
//   - memory address    : copy code to memory passed by the caller
//   returns -1 if error. */
//#define SAO_RELOCATE_AUTO (void*)1

sao_run();
sao_output_file();

sao_set_error_func

#ifdef __cplusplus
}
#endif

#endif//LIBSAO_H
