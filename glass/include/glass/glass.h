#pragma once

#include "base.h"
#include "utils.h"

namespace glass
{

    int parent_process(int pid);
    int child_process(const char* filename);
    void trace_me();
    void trace_continue(int pid);

} // namespace glass
