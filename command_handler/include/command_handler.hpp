//
// Created by boa on 09.08.17.
//

#ifndef MIN_PATH_COMMAND_HANDLER_HPP
#define MIN_PATH_COMMAND_HANDLER_HPP

#include <string>
#include <functional>
#include <memory>


#include "icommand.hpp"

namespace min_path {

    namespace command_handler {

        /**
 * @class CommandHandler  - in classical description (GoF) Receiver, executes commands
 */
        class CommandHandler {
        public:
            /**
             * @brief CommandHandler - constructor
             */
            CommandHandler() = default;

            /**
             * @brief ~CommandHandler - destructor
             */
            ~CommandHandler() = default;

            /**
             * @brief CommandHandler -  copy constructor
             */
            CommandHandler(const CommandHandler &) = default;

            /**
             * @brief  - move constructor
             */
            CommandHandler(CommandHandler &&) = default;

            /**
             * @brief operator= copy assignment operator
             */
            CommandHandler &operator=(const CommandHandler &) = default;

            /**
             * @brief operator= move assignment operator
             */
            CommandHandler &operator=(CommandHandler &&) = default;

            /**
             * @brief start - run command execution of the command
             * @param command - command to be executed
             */
            void start(std::shared_ptr<ICommand> &command);


        }//namespace command_handler

    }//namespace min_path

    class command_handler {

    };


#endif //MIN_PATH_COMMAND_HANDLER_HPP
