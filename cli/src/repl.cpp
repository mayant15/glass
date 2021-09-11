#include "repl.h"

namespace glass
{
    void Repl::greet() const
    {
        std::cout << "###### glass v0.0.1-alpha ######" << std::endl;
    }

    void Repl::set_active_file(const char* filename)
    {
        _filename = filename;
    }

    void Repl::start()
    {
        bool done = false;
        while (!done)
        {
            std::cout << "glass> ";

            std::string input = "";
            std::getline(std::cin, input);

            const auto command = parse(input);
            done = execute(command);
        }
    }

    const cmd::ICommand* Repl::parse(const std::string& str) const
    {
        if (str == "exit")
        {
            return new cmd::Exit;
        }
        else
        {
            return new cmd::None(str);
        }
    }

    bool Repl::execute(const cmd::ICommand* cmd)
    {
        bool val = cmd->execute();
        delete cmd;
        return val;
    }

} // namespace glass
