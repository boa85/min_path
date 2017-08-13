#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include<boost/algorithm/string.hpp>

#include "../../include/graph_builder/graph_builder.hpp"

namespace min_path {

    namespace graph_builder {

        GraphBuilder::GraphBuilder(const std::string &filename)
                : filename_(filename) {}

        EdgesListGraphView GraphBuilder::buildEdgesListGraphView() {
            EdgesListGraphView graph;
            std::ifstream input(filename_);
            if (!input.is_open()) {
                throw std::runtime_error(("cannot open file ") + filename_);
            }
            std::string line;
            int tmp1 = 0;
            int tmp2 = 0;
            while (getline(input, line)) {//read next line
                std::vector<std::string> array;
                boost::algorithm::split(array, line, boost::is_any_of(":"));//split input data
                if (array.size() != EDGE_PARM_COUNT) {
                    throw std::invalid_argument("invalid data format");
                }
                Edge edge{};
                edge.inVertex = std::stoi(array[0]);
                edge.cost = std::stoi(array[1]);
                edge.outVertex = std::stoi(array[2]);
                if (!edge.isValid()) {
                    throw std::invalid_argument("invalid value edge");
                }
                tmp1 = std::max(edge.inVertex, tmp1);//for calculation number of vertices
                tmp2 = std::max(edge.outVertex, tmp2);
                graph.push_back(edge);
            }

            edgeCount_ = graph.size();
            vertexCount_ = std::max(tmp1, tmp2);//определяем количество вершин
            input.close();
            if (!isValidGraph(vertexCount_, edgeCount_)) {
                throw std::logic_error("invalid edges count,"
                                               "max edges count = n(n-1)/2, n - number of vertices");
            }
            return graph;
        }//buildEdgesListGraphView

        void GraphBuilder::buildGraph(const GRAPH_FORMAT &graphFormat) {
            switch (graphFormat) {
                case GRAPH_FORMAT::EDGE_LIST: {
                    edgesListGraphView_ = buildEdgesListGraphView();
                    break;
                }
                case GRAPH_FORMAT::ADJACENCY_MATRIX: {
                    adjacencyMatrixGraphView_ = buildAdjacencyMatrixGraphView();
                    break;
                }
            }
        }//buildGraph

        AdjacencyMatrixGraphView &GraphBuilder::buildAdjacencyMatrixGraphView() {
            adjacencyMatrixGraphView_.reserve(100);
            for (auto v:adjacencyMatrixGraphView_) {
                v.reserve(100);
                v = {-1};
            }
            return adjacencyMatrixGraphView_;
        }//buildAdjacencyMatrixGraphView

        bool GraphBuilder::isValidGraph(const unsigned int vertex, const size_t edge) {
            return (edge >= 1) &&
                   (edge <= ((vertex * (vertex - 1)) / 2));//max edges count = n(n-1)/2, n - number of vertices
        }//isValidGraph

        int GraphBuilder::vertexCount() const {
            return vertexCount_;
        }//vertexCount

        unsigned long GraphBuilder::edgeCount() const {
            return edgeCount_;
        }//edgeCount

        const EdgesListGraphView &GraphBuilder::getEdgesListGraphView() const {
            return edgesListGraphView_;
        }//getEdgesListGraphView

        const AdjacencyMatrixGraphView &GraphBuilder::getAdjacencyMatrixGraphView() const {
            return adjacencyMatrixGraphView_;
        }//getEdgesListGraphView

        void GraphBuilder::setFilename(const std::string &filename) {
            filename_ = filename;
        }//setFilename


    }//namespace graph_builder

}//namespace min_path

