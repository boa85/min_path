#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include<boost/algorithm/string.hpp>

#include "../../include/graph_builder/graph_builder.hpp"

namespace min_path {

    namespace graph_builder {

        GraphBuilder::GraphBuilder(const std::string &filename)
                : filename_(filename) {}

        std::shared_ptr<Graph> GraphBuilder::build() {
            auto graph = std::make_shared<Graph>();
            std::ifstream input(filename_);
            std::string line;
            while (getline(input, line)) {
                std::vector<std::string> array;
                boost::algorithm::split(array, line, boost::is_any_of(":"));
                Edge edge{};
                edge.inVertex = std::stoi(array[0]);
                edge.cost = std::stoi(array[1]);
                edge.outVertex = std::stoi(array[2]);
                if (!edge.isValid()) {
                    throw std::invalid_argument("invalid value edge");
                }
                graph->push_back(edge);
            }
            input.close();
            return graph;

        }//build

        std::shared_ptr<Graph> GraphBuilder::getGraph() {
            return build();
        }


    }//namespace graph_builder

}//namespace min_path

