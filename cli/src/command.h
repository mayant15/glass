#pragma once

#include <string>

namespace glass::cmd
{
    enum class ECommandType
    {
        NONE,
        RUN,
        BREAK,
        CONTINUE,
        EXIT
    };

    class ICommand
    {
      public:
        virtual bool execute() const = 0;
        virtual ~ICommand(){};
    };

    struct None : ICommand
    {
        static inline const ECommandType type = ECommandType::NONE;

        None(const std::string& str) : _command_string(str)
        {
        }

        bool execute() const override;

      private:
        std::string _command_string;
    };

    struct Exit : ICommand
    {
        static inline const ECommandType type = ECommandType::EXIT;
        bool execute() const override;
    };

} // namespace glass::cmd
