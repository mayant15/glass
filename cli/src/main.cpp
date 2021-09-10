#include "repl.h"
#include <glass/glass.h>

void print_usage()
{
    GLASS_LOG("Usage: glass-cli <path-to-executable>");
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        print_usage();
        return 0;
    }

    glass::Repl repl;
    repl.set_active_file(argv[1]);
    repl.start();

    // Start the application passed as argument in a new process
    // int pid = fork();
    // if (pid < 0)
    // {
    //     GLASS_LOG_ERR("Failed to create a child process");
    //     return -1;
    // }
    // else if (pid == 0)
    // {
    //     return glass::child_process(argv[1]);
    // }
    // else
    // {
    //     return glass::parent_process(pid);
    // }
}
