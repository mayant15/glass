#include <dub/dub.h>

namespace dub
{
    int parent_process(int pid)
    {
        DUB_LOG_PARENT("attached to pid %d", pid);

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
        DUB_SAFECALL(execl(filename, filename));
        return 0;
    }

    void trace_me()
    {
        DUB_SAFECALL(ptrace(PTRACE_TRACEME));
        DUB_SAFECALL(std::raise(SIGSTOP));
    }

    void trace_continue(int pid)
    {
        DUB_SAFECALL(ptrace(PTRACE_CONT, pid, 0, 0));
    }

} // namespace dub
