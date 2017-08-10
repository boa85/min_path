//

#ifndef MIN_PATH_SHORTEST_PATH_COMMAND
#define MIN_PATH_SHORTEST_PATH_COMMAND

#include "icommand.hpp"

namespace min_path {

    namespace command_handler {
        class ShortestPathCommand : public ICommand {
        public:
            ~ShortestPathCommand() override = default;

            void execute() override;

            ShortestPathCommand(const ShortestPathCommand &command) = default;

            ShortestPathCommand(ShortestPathCommand &&command) = default;

            ShortestPathCommand &operator=(const ShortestPathCommand &command) = default;

            ShortestPathCommand &operator=(ShortestPathCommand &&command)  = default;
        };

    }//namespace command_handler

} //namespace min_path


#endif//MIN_PATH_SHORTEST_PATH_COMMAND




