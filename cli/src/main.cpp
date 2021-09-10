#include <dub/dub.h>

void greet()
{
    DUB_LOG("###### dub v0.0.1-alpha ######");
}

void print_usage()
{
    DUB_LOG("Usage: dub-cli <path-to-executable>");
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        print_usage();
        return 0;
    }

    greet();

    // Start the application passed as argument in a new process
    int pid = fork();
    if (pid < 0)
    {
        DUB_LOG_ERR("Failed to create a child process");
        return -1;
    }
    else if (pid == 0)
    {
        return dub::child_process(argv[1]);
    }
    else
    {
        return dub::parent_process(pid);
    }
}
