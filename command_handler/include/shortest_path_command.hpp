//

#ifndef MIN_PATH_SHORTEST_PATH_COMMAND
#define MIN_PATH_SHORTEST_PATH_COMMAND

#include <string>

#include "icommand.hpp"
#include "../../service/include/service.hpp"
#include "graph_builder/graph_builder.hpp"

namespace min_path {

    namespace command_handler {

        using namespace service;
        using namespace graph_builder;

        /**
         * @class FindShortestPathCommand
         */
        class FindShortestPathCommand : public ICommand {
        public:

            /**
             * @brief ShortestPathCommand - constructor
             * @param filename - input filename
             * @param inVertex - input (start) vertex
             * @param outVertex - output (end) vertex
             */
            FindShortestPathCommand(const std::string &filename, unsigned int inVertex,
                                    unsigned int outVertex);

            /**
             * @brief ~ShortestPathCommand - destructor
             */
            ~FindShortestPathCommand() override = default;

            /**
             * @brief execute  - find shortest path between inVertex and outVertex and print it
             */
            void execute() override;

            /**
             * @brief ShortestPathCommand - copy constructor
             */
            FindShortestPathCommand(const FindShortestPathCommand &) = default;

            /**
             * @brief ShortestPathCommand - move constructor
             */
            FindShortestPathCommand(FindShortestPathCommand &&) = default;

            /**
             * @brief ShortestPathCommand - copy assignment operator
             */
            FindShortestPathCommand &operator=(const FindShortestPathCommand &) = default;

            /**
             *@brief  ShortestPathCommand - move assignment operator
             */
            FindShortestPathCommand &operator=(FindShortestPathCommand &&)  = default;

        private:

            /**
             * @brief filename_ - input filename
             */
            std::string filename_;

            /**
             * @brief inVertex_ - input (start) vertex
             */
            int inVertex_;

            /**
             * @brief outVertex_ - out (end) vertex
             */
            int outVertex_;

            /**
             * @@brief fordBellman - the classical implementation of the Ford-Bellman algorithm
             * @param graph - a list of edges of the graph
             * @param vertexCount - number of vertices
             * @param edgesCount - number of edges
             */
            void fordBellman(const EdgesListGraphView &graph, const int vertexCount, const size_t edgesCount);

            /**
             * @brief isValidVertices - Checks for the presence of input and output vertices in the graph
             * @param graph
             * @return - true, if input and output vertices exists
             */
            bool isValidVertices(const EdgesListGraphView &graph);

            /**
             * @brief calculatePathLength
             * @param path - numbers of vertices in shortest path between input and output vertices
             * @param graph - graph
             * @return length of shortest path between input and output vertices
             */
            int calculatePathLength(const std::vector<int> &path, const EdgesListGraphView &graph);

        };//class FindShortestPathCommand

    }//namespace command_handler

} //namespace min_path


#endif//MIN_PATH_SHORTEST_PATH_COMMAND




