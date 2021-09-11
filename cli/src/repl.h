#pragma once

#include "command.h"
#include <iostream>

namespace glass
{
    class Repl
    {
      private:
        const char* _filename;

      public:
        void greet() const;
        void set_active_file(const char* filename);
        void start();

      private:
        /*!
         * @brief Parse an input string to create a new command structure
         *
         * Creates a new object on the heap, make sure to delete!
         *
         * @param str Input string to be parsed
         * @return const cmd::ICommand* Pointer to the created command
         */
        const cmd::ICommand* parse(const std::string& str) const;

        /*!
         * @brief Execute a command object. Deletes the resource when done
         *
         * @param cmd Pointer to the command to be executed
         * @return bool True if we want to terminate the REPL
         */
        bool execute(const cmd::ICommand* cmd);
    };

} // namespace glass
