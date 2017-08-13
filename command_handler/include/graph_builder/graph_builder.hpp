//

#ifndef MIN_PATH_GRAPH_BUILDER
#define MIN_PATH_GRAPH_BUILDER

#include <list>
#include <string>
#include <memory>
#include <boost/signals2/signal.hpp>

#include "../../../service/include/service.hpp"

namespace min_path {

    namespace graph_builder {

        using namespace service;

        /**
         * @class GraphBuilder - read input file and build graph as list of edges or adjacency matrix
         */
        class GraphBuilder {

        public:
            /**
             * @brief GraphBuilder - constructor
             * @param filename input filename
             */
            explicit GraphBuilder(const std::string &filename);

            /**
             * @brief ~GraphBuilder - destructor
             */
            ~GraphBuilder() = default;

            /**
             * @brief GraphBuilder - copy constructor, is forbidden  because the signals are not copied
             */
            GraphBuilder(const GraphBuilder &) = delete;

            /**
             * @brief GraphBuilder - move constructor
             */
            GraphBuilder(GraphBuilder &&) = default;

            /**
             * @brief - copy assignment operator, is forbidden  because the signals are not copied
             */
            GraphBuilder &operator=(const GraphBuilder &) = delete;

            /**
             * @brief move assignment operator
             */
            GraphBuilder &operator=(GraphBuilder &&) = default;

            /**
             * @brief  buildGraph - Returns a graph constructed from the input data read from the file
             * @param graphFormat - graph view format: list of edges, adjacency matrix
             */
            void buildGraph(const GRAPH_FORMAT &graphFormat);

            /**
             * @return - count of vertices in the graph
             */
            int vertexCount() const;

            /**
             * @return -  count of edges in the graph
             */
            unsigned long edgeCount() const;

            /**
             * @return -  graph as list of edges
             */
            const EdgesListGraphView &getEdgesListGraphView() const;

            /**
             * @return graph as adjacency matrix
             */
            const AdjacencyMatrixGraphView &getAdjacencyMatrixGraphView() const;

            /**
             * @brief setFilename - setter
             * @param filename - input filename
             */
            void setFilename(const std::string &filename);
        private:

            /**
             * @brief filename_ - input filename
             */
            std::string filename_;

            /**
             * @brief vertexCount_ - number of vertices in the graph
             */
            int vertexCount_;

            /**
             * @brief edgeCount - number of edges in the graph
             */
            size_t edgeCount_;

            /**
             * @brief edgesListGraphView_ - current graph as edges list view
             */
            EdgesListGraphView edgesListGraphView_;

            /**
             * @brief adjacencyMatrixGraphView_ - current graph as adjacency matrix view
             */
            AdjacencyMatrixGraphView adjacencyMatrixGraphView_;

            /**
             * @brief buildEdgesListGraphView - build a graph as list of edges  from the input data read from the file
             */
            EdgesListGraphView buildEdgesListGraphView();

            /**
             * @brief buildAdjacencyMatrixGraphView - build a graph as adjacency matrix  from the input data read from the file
             */
            AdjacencyMatrixGraphView &buildAdjacencyMatrixGraphView();

            /**
             * @brief isValidGraph
             * @param vertex - number of vertices
             * @param edge - number of edges
             * @return  - true, if edgesNumber(max of edges number in the graph) <= n(n - 1)/2,
             */
            bool isValidGraph(const int vertex, const size_t edge);

            /**
             * @brief EDGE_PARM_COUNT - count of edge parameters: input vertex, output vertex, cost
             */
            const unsigned int EDGE_PARM_COUNT = 3;

        };//class GraphBuilder

    }//namespace graph_builder

}//namespace min_path


#endif //MIN_PATH_GRAPH_BUILDER

