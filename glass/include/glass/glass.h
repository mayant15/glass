#include <cerrno>
#include <csignal>
#include <cstdlib>
#include <cstring>

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <string>

#define GLASS_LOG_ERR(FMT, ...)    fprintf(stderr, "[ERROR ] " FMT "\n", ##__VA_ARGS__)
#define GLASS_LOG(FMT, ...)        fprintf(stdout, FMT "\n", ##__VA_ARGS__)
#define GLASS_LOG_PARENT(FMT, ...) GLASS_LOG("[parent] " FMT, ##__VA_ARGS__)
#define GLASS_LOG_CHILD(FMT, ...)  GLASS_LOG("[child ] " FMT, ##__VA_ARGS__)

#define GLASS_SAFECALL(CALL)                                                                                           \
    {                                                                                                                  \
        int err = CALL;                                                                                                \
        if (err == -1)                                                                                                 \
        {                                                                                                              \
            GLASS_LOG_ERR("Call to `" #CALL "` failed");                                                               \
            GLASS_LOG_ERR("\tMessage: %s", std::strerror(errno));                                                      \
            GLASS_LOG_ERR("\tFile: %s", __FILE__);                                                                     \
            GLASS_LOG_ERR("\tLine: %d", __LINE__);                                                                     \
            std::abort();                                                                                              \
        }                                                                                                              \
    }

namespace glass
{

    int parent_process(int pid);
    int child_process(const char* filename);
    void trace_me();
    void trace_continue(int pid);

} // namespace glass
