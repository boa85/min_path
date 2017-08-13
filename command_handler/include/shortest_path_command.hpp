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
             * @brief ShortestPathCommand - copy assignment operator, delete
             */
            FindShortestPathCommand &operator=(const FindShortestPathCommand &) = delete;

            /**
             *@brief  ShortestPathCommand - move assignment operator, delete
             */
            FindShortestPathCommand &operator=(FindShortestPathCommand &&)  = delete;

        private:

            /**
             * @brief filename_ - input filename
             */
            const std::string filename_;

            /**
             * @brief inVertex_ - input (start) vertex
             */
            const unsigned int inVertex_;

            /**
             * @brief outVertex_ - out (end) vertex
             */
            const unsigned int outVertex_;

        private:
            /**
             * @@brief fordBellman - the classical implementation of the Ford-Bellman algorithm
             * @param graph - a list of edges of the graph
             * @param vertexCount - number of vertices
             * @param edgesCount - number of edges
             */
            void fordBellman(const EdgesListGraphView &graph, int vertexCount, unsigned long edgesCount);

            /**
             * @brief isValidVertices - check the
             * @param graph
             * @return
             */
            bool isValidVertices(const EdgesListGraphView &graph);

            int calculatePathLength(const std::vector<int> &path, const EdgesListGraphView &graph);
        };//class FindShortestPathCommand

    }//namespace command_handler

} //namespace min_path


#endif//MIN_PATH_SHORTEST_PATH_COMMAND




