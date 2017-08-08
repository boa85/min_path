//
// Created by boa on 09.08.17.
//

#include "../include/command_handler.hpp"

namespace min_path {

    namespace command_handler {

        void CommandHandler::start(std::shared_ptr<ICommand> &command) {
            command->execute();
        }//start

    }//namespace command_handler

}//namespace min_path
