#pragma once

#include <iostream>

namespace glass
{
    enum class ECommandType
    {
        NONE,
        RUN,
        BREAK,
        CONTINUE
    };

    class ICommand
    {
      public:
        virtual void execute() const = 0;
    };

    struct CommandNone : ICommand
    {
        static inline const ECommandType type = ECommandType::NONE;
        std::string m_command_string;

        void execute() const override;
    };

    class Repl
    {
      private:
        const char* _filename;
        bool _done;

      public:
        void greet() const;
        void set_active_file(const char* filename);
        void start();

      private:
        const ICommand* parse(const std::string& str) const;
        void execute(const ICommand* command) const;
    };

} // namespace glass
