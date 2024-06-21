#include <cstdio>
#include <cstddef>

#include <clay_das/clay_das.h>

const char* TUTORIAL_SOURCE_CODE = R""""(
require clay_test

def twice(var a: int&)
    a = a + a
def twicePointer(var a: int?)
    twice(*a)

[export]
def test
    print("Hello, daslang!\n")
    
    unsafe
        var s : int
        s = 10
        twicePointer(addr(s))

        var p : Point
        p.x = 1
        p.y = 2

        das_c_func(p.x)
        das_c_func(p.y)

        das_c_func_ptr(addr(p))
)"""";

// this is test function
vec4f das_c_func(das_context* ctx, das_node* node, vec4f* args)
{
    (void)ctx;
    (void)node;
    printf("from das_c_func(%i)\n", das_argument_int(args[0]));
    return das_result_void();
}

struct Point {
    int x;
    int y;
};

vec4f das_c_func_ptr(das_context* ctx, das_node* node, vec4f* args)
{
    (void)ctx;
    (void)node;
    Point* p = (Point*)das_argument_ptr(args[0]);
    printf("Point x:(%i) y:(%i)\n", p->x, p->y);
    return das_result_void();
}

das_module* register_module_clay_test()
{
    // create module and library
    das_module*       mod = das_module_create((char*)"clay_test");
    das_module_group* lib = das_modulegroup_make();
    das_modulegroup_add_module(lib, mod);

    // handled structure
    das_structure* st = das_structure_make(lib, "Point", "Point", sizeof(Point), alignof(Point));
    das_structure_add_field(st, mod, lib, "x", "x", offsetof(Point, x), "i");
    das_structure_add_field(st, mod, lib, "y", "y", offsetof(Point, y), "i");
    das_module_bind_structure(mod, st);

    // bind das_c_func
    das_module_bind_interop_function(mod, lib, &das_c_func, (char*)"das_c_func", (char*)"das_c_func", SIDEEFFECTS_modifyExternal, (char*)"v i");
    das_module_bind_interop_function(mod, lib, &das_c_func_ptr, (char*)"das_c_func_ptr", (char*)"das_c_func_ptr", SIDEEFFECTS_modifyExternal, (char*)"v ?");

    // cleanup
    das_modulegroup_release(lib);
    return mod;
}

void clay::das::init()
{
    das_initialize();

    das_module* clay_test_module = register_module_clay_test();
}

void clay::das::run()
{
    das_text_writer*  tout          = das_text_make_printer();       // output stream for all compiler messages (stdout. for stringstream use TextWriter)
    das_module_group* dummyLibGroup = das_modulegroup_make();        // module group for compiled program
    das_file_access*  fAccess       = das_fileaccess_make_default(); // default file access
    das_context*      ctx           = NULL;

    // compile program
    das_fileaccess_introduce_file(fAccess, "tutorial.das", TUTORIAL_SOURCE_CODE);
    das_program* program = das_program_compile((char*)"tutorial.das", fAccess, tout, dummyLibGroup);

    auto shutdown = [&]() {
        das_program_release(program);
        das_fileaccess_release(fAccess);
        das_modulegroup_release(dummyLibGroup);
        das_text_release(tout);
    };

    int err_count = das_program_err_count(program);
    if (err_count)
    {
        // if compilation failed, report errors
        das_text_output(tout, (char*)"failed to compile\n");
        for (int ei = 0; ei != err_count; ++ei)
        {
            das_error* error = das_program_get_error(program, ei);
            das_error_output(error, tout);
        }

        shutdown();
        return;
    }

    // create daScript context
    ctx = das_context_make(das_program_context_stack_size(program));
    if (!das_program_simulate(program, ctx, tout))
    {
        // if interpretation failed, report errors
        das_text_output(tout, (char*)"failed to simulate\n");
        err_count = das_program_err_count(program);
        for (int ei = 0; ei != err_count; ++ei)
        {
            das_error* error = das_program_get_error(program, ei);
            das_error_output(error, tout);
        }

        shutdown();
        return;
    }

    // find function 'test' in the context
    das_function* fnTest = das_context_find_function(ctx, (char*)"test");
    if (!fnTest)
    {
        das_text_output(tout, (char*)"function 'test' not found\n");

        shutdown();
        return;
    }

    // evaluate 'test' function in the context
    das_context_eval_with_catch(ctx, fnTest, NULL);
    char* ex = das_context_get_exception(ctx);
    if (ex != NULL)
    {
        das_text_output(tout, (char*)"exception: ");
        das_text_output(tout, ex);
        das_text_output(tout, (char*)"\n");

        shutdown();
        return;
    }
}

void clay::das::shutdown()
{
    das_shutdown();
}