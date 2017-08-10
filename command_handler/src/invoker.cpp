//
// Created by boa on 09.08.17.
//

#include "../include/invoker.hpp"
#include "../include/generate_graph_command.hpp"
#include "../include/shortest_path_command.hpp"

namespace min_path {

    namespace command_handler {

        void Invoker::generateGraph(const std::string &filename, const unsigned int vertexNumber,
                                    const unsigned int probability) {
            auto command = createGenerateGraphCommand(filename, vertexNumber, probability);
            start(command);
        }//generateGraph

        void Invoker::findShortestPath(const std::string &filename, const unsigned int inVertex,
                                       const unsigned int outVertex) {
            auto command = createFindShortestCommand(filename, inVertex, outVertex);
            start(command);
        }//findShortestPath

        std::shared_ptr<ICommand> Invoker::createGenerateGraphCommand(const std::string &filename,
                                                                      const unsigned int vertexNumber,
                                                                      const unsigned int probability) {
            return std::make_shared<GenerateGraphCommand>(filename, vertexNumber, probability);
        }//createGenerateGraphCommand

        std::shared_ptr<ICommand> Invoker::createFindShortestCommand(const std::string &filename,
                                                                     const unsigned int inVertex,
                                                                     const unsigned int outVertex) {
            return std::make_shared<FindShortestPathCommand>(filename, inVertex, outVertex);
        }//createFindShortestCommand

    }//namespace command_handler

}//namespace min_path
