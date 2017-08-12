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
            int tmp1 = 0;
            int tmp2 = 0;
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
                tmp1 = std::max(edge.inVertex, tmp1);
                tmp2 = std::max(edge.outVertex, tmp2);
                graph->push_back(edge);
            }

            edgeCount_ = graph->size();
            vertexCount_ = std::max(tmp1, tmp2);
            input.close();
            if (!isValidGraph(vertexCount_, edgeCount_)) {
                throw std::logic_error("");
            }
            return graph;

        }//buildEdgesListGraphView

        void GraphBuilder::getGraph(const GRAPH_FORMAT &graphFormat) {
            switch (graphFormat) {
                case GRAPH_FORMAT::EDGE_LIST: {
                    auto graph = buildEdgesListGraphView();
                    edgesListGraph(graph, vertexCount_, edgeCount_);
                    break;
                }
                case GRAPH_FORMAT::ADJACENCY_MATRIX: {
                    auto graph = buildAdjacencyMatrixGraphView();
                    adjacencyMatrixGraph(graph);
                    break;
                }
            }
        }//getGraph

        std::shared_ptr<AdjacencyMatrixGraphView> GraphBuilder::buildAdjacencyMatrixGraphView() {
            return std::make_shared<AdjacencyMatrixGraphView>();
        }

        bool GraphBuilder::isValidGraph(int vertex, unsigned long edge) {
            return (edge <= ((vertex * (vertex - 1)) / 2));//max edges count = n(n-1)/2, n - number of vertex
        }

    }//namespace graph_builder

}//namespace min_path

