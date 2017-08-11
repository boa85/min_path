#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include<boost/algorithm/string.hpp>

#include "../../include/graph_builder/graph_builder.hpp"

namespace min_path {

    namespace graph_builder {

        GraphBuilder::GraphBuilder(const std::string &filename)
                : filename_(filename) {}

        std::shared_ptr<EdgesListGraphView> GraphBuilder::buildEdgesListGraphView() {
            auto graph = std::make_shared<EdgesListGraphView>();
            std::ifstream input(filename_);
            std::string line;
            while (getline(input, line)) {//read next line
                std::vector<std::string> array;
                boost::algorithm::split(array, line, boost::is_any_of(":"));
                if (array.size() != 3) {
                    throw std::invalid_argument("invalid data format");
                }
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

        }//buildEdgesListGraphView

        void GraphBuilder::getGraph(const GRAPH_FORMAT &graphFormat) {
            switch (graphFormat) {
                case GRAPH_FORMAT::EDGE_LIST: {
                    auto graph = buildEdgesListGraphView();
                    edgesListGraph(graph);
                    break;
                }
                case GRAPH_FORMAT::ADJACENCY_MATRIX: {
                    auto graph = buildAdjacencyMatrixGraphView();
                    adjacencyMatrixGraph(graph);
                    break;
                }
            }
        }

        std::shared_ptr<AdjacencyMatrixGraphView> GraphBuilder::buildAdjacencyMatrixGraphView() {
            return std::make_shared<AdjacencyMatrixGraphView>();
        }

        bool GraphBuilder::isValidGragh(const unsigned int vertex, const unsigned int edge) {
            return (edge <= ((vertex * (vertex - 1)) / 2));//max edges count = n(n-1)/2, n - number of vertex
        }
//getGraph


    }//namespace graph_builder

}//namespace min_path

