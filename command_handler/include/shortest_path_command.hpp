//

#ifndef MIN_PATH_SHORTEST_PATH_COMMAND
#define MIN_PATH_SHORTEST_PATH_COMMAND

#include <string>

#include "icommand.hpp"

namespace min_path {

    namespace command_handler {
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
             * @brief ~ShortestPathComman - destructor
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

        };//class FindShortestPathCommand

    }//namespace command_handler

} //namespace min_path


#endif//MIN_PATH_SHORTEST_PATH_COMMAND




