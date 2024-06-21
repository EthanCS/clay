#include <clay_das/clay_das.h>
#include <daScript/daScriptC.h>

const char* TUTORIAL_SOURCE_CODE = R""""(
[export]
def test
    print("Hello, daslang!\n")
)"""";

void clay::das::init()
{
    das_initialize();
}

void clay::das::run()
{
    das_text_writer*  tout          = das_text_make_printer();       // output stream for all compiler messages (stdout. for stringstream use TextWriter)
    das_module_group* dummyLibGroup = das_modulegroup_make();        // module group for compiled program
    das_file_access*  fAccess       = das_fileaccess_make_default(); // default file access
    das_context*      ctx           = NULL;
    // compile program
    das_fileaccess_introduce_file(fAccess, "tutorial.das", TUTORIAL_SOURCE_CODE);
    das_program* program   = das_program_compile("tutorial.das", fAccess, tout, dummyLibGroup);
    int          err_count = das_program_err_count(program);
    if (err_count)
    {
        // if compilation failed, report errors
        das_text_output(tout, "failed to compile\n");
        for (int ei = 0; ei != err_count; ++ei)
        {
            das_error* error = das_program_get_error(program, ei);
            das_error_output(error, tout);
        }
        goto shutdown;
    }
    // create daScript context
    ctx = das_context_make(das_program_context_stack_size(program));
    if (!das_program_simulate(program, ctx, tout))
    {
        // if interpretation failed, report errors
        das_text_output(tout, "failed to simulate\n");
        err_count = das_program_err_count(program);
        for (int ei = 0; ei != err_count; ++ei)
        {
            das_error* error = das_program_get_error(program, ei);
            das_error_output(error, tout);
        }

        goto shutdown;
    }
    // find function 'test' in the context
    das_function* fnTest = das_context_find_function(ctx, "test");
    if (!fnTest)
    {
        das_text_output(tout, "function 'test' not found\n");
        goto shutdown;
    }
    // evaluate 'test' function in the context
    das_context_eval_with_catch(ctx, fnTest, NULL);
    char* ex = das_context_get_exception(ctx);
    if (ex != NULL)
    {
        das_text_output(tout, "exception: ");
        das_text_output(tout, ex);
        das_text_output(tout, "\n");
        goto shutdown;
    }
shutdown:;
    das_program_release(program);
    das_fileaccess_release(fAccess);
    das_modulegroup_release(dummyLibGroup);
    das_text_release(tout);
}

void clay::das::shutdown()
{
    das_shutdown();
}