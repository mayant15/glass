#include <glass/glass.h>

namespace glass
{
    int parent_process(int pid)
    {
        GLASS_LOG_PARENT("attached to pid %d", pid);

        int status = 0;
        do
        {
            waitpid(pid, &status, 0);
            if (WIFSTOPPED(status))
            {
                // Let the process continue when stop received
                trace_continue(pid);
            }
        } while (!WIFEXITED(status));

        return 0;
    }

    int child_process(const char* filename)
    {
        trace_me();
        GLASS_SAFECALL(execl(filename, filename));
        return 0;
    }

    void trace_me()
    {
        GLASS_SAFECALL(ptrace(PTRACE_TRACEME));
        GLASS_SAFECALL(std::raise(SIGSTOP));
    }

    void trace_continue(int pid)
    {
        GLASS_SAFECALL(ptrace(PTRACE_CONT, pid, 0, 0));
    }

} // namespace glass
