//

#include "../include/shortest_path_command.hpp"

namespace min_path {

    namespace command_handler {


        FindShortestPathCommand::FindShortestPathCommand(const std::string &filename, const unsigned int inVertex,
                                                         const unsigned int outVertex) : filename_(filename),
                                                                                         inVertex_(inVertex),
                                                                                         outVertex_(outVertex) {}

        void FindShortestPathCommand::execute() {

        }//execute


    }//namespace command_handler

} //namespace min_path
