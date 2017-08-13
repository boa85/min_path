//

#include "../include/generate_graph_command.hpp"
#include "../include/graph_generator/graph_generator.hpp"

namespace min_path {

    namespace command_handler {

        using namespace graph_generator;

        GenerateGraphCommand::GenerateGraphCommand(const std::string &filename, const unsigned int vertexNumber,
                                                   const unsigned int probability) : filename_(filename),
                                                                                     vertexNumber_(vertexNumber),
                                                                                     probability_(probability) {}

        void GenerateGraphCommand::execute() {
            auto generator = std::make_shared<GraphGenerator>(filename_, vertexNumber_, probability_);
            generator->generate();
        }//execute

    }//namespace command_handler

} //namespace min_path
