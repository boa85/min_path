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
         * @class GraphBuilder - read input file and build graph as list of edges
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
             * @brief getGraph - Returns a graph constructed from the input data read from the file
             */
            void getGraph(const GRAPH_FORMAT &graphFormat);

            bs::signal<void(std::shared_ptr<EdgesListGraphView>, int, unsigned long)> edgesListGraph;

            bs::signal<void(std::shared_ptr<AdjacencyMatrixGraphView>)> adjacencyMatrixGraph;
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
            unsigned long edgeCount_;

            /**
             * @brief buildEdgesListGraphView - build a graph as list of edges  from the input data read from the file
             */
            std::shared_ptr<EdgesListGraphView> buildEdgesListGraphView();

            /**
             * @brief buildAdjacencyMatrixGraphView - build a graph as adjacency matrix  from the input data read from the file
             */
            std::shared_ptr<AdjacencyMatrixGraphView> buildAdjacencyMatrixGraphView();

            /**
             * @brief isValidGraph
             * @param vertex - number of vertices
             * @param edge - number of edges
             * @return  - true, if edgesNumber(max of edges number in the
             * ) <= n(n - 1)/2,
             */
            bool isValidGraph(int vertex, unsigned long edge);
        };//class GraphBuilder

    }//namespace graph_builder

}//namespace min_path


#endif //MIN_PATH_GRAPH_BUILDER

