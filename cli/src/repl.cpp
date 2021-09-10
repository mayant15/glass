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
            std::cin >> input;

            const auto command = parse(input);
            execute(command);
        }
    }

    const ICommand* Repl::parse(const std::string& str) const
    {
        auto* cmd = new CommandNone;
        cmd->m_command_string = str;
        return cmd;
    }

    void Repl::execute(const ICommand* command) const
    {
        command->execute();
    }

    void CommandNone::execute() const
    {
        std::cout << m_command_string << std::endl;
    }

} // namespace glass
