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
             * @brief GraphBuilder - copy constructor
             */
            GraphBuilder(const GraphBuilder &) = default;

            /**
             * @brief GraphBuilder - move constructor
             */
            GraphBuilder(GraphBuilder &&) = default;

            /**
             * @brief - copy assignment operator
             */
            GraphBuilder &operator=(const GraphBuilder &) = default;

            /**
             * @brief move assignment operator
             */
            GraphBuilder &operator=(GraphBuilder &&) = default;

            /**
             * @brief getGraph - Returns a graph constructed from the input data read from the file
             */
            void getGraph(const GRAPH_FORMAT &graphFormat);

            bs::signal<void(std::shared_ptr<EdgesListGraphView>)> edgesListGraph;

            bs::signal<void(std::shared_ptr<AdjacencyMatrixGraphView>)> adjacencyMatrixGraph;
        private:

            /**
             * @brief filename_ - input filename
             */
            std::string filename_;

            /**
             * @brief build build a graph  from the input data read from the file
             */
            std::shared_ptr<EdgesListGraphView> buildEdgesListGraphView();

            std::shared_ptr<AdjacencyMatrixGraphView> buildAdjacencyMatrixGraphView();

            bool isValidGragh(const unsigned int vertex, const unsigned int edge);
        };//class GraphBuilder

    }//namespace graph_builder

}//namespace min_path


#endif //MIN_PATH_GRAPH_BUILDER

