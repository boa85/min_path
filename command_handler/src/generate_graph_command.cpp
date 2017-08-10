//

#include "../include/generate_graph_command.hpp"

namespace min_path {

    namespace command_handler {


        GenerateGraphCommand::GenerateGraphCommand(const std::string &filename, const unsigned int vertexNumber,
                                                   const unsigned int probability) : filename_(filename),
                                                                                     vertexNumber_(vertexNumber),
                                                                                     probability_(probability) {}

        void GenerateGraphCommand::execute() {

        }//execute

    }//namespace command_handler

} //namespace min_path
