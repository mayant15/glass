#include "command.h"
#include <glass/glass.h>
#include <iostream>

namespace glass::cmd
{
    bool None::execute() const
    {
        std::cout << _command_string << std::endl;
        return false;
    }

    bool Exit::execute() const
    {
        std::cout << "Thanks for using GLASS! Quitting..." << std::endl;
        glass::cleanup();
        return true;
    }

} // namespace glass::cmd
