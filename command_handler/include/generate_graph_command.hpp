//

#ifndef MIN_PATH_GENERATE_GRAPH_COMMAND
#define MIN_PATH_GENERATE_GRAPH_COMMAND

#include "icommand.hpp"

namespace min_path {

    namespace command_handler {
        class GenerateGraphCommand : public ICommand {
        public:
            ~GenerateGraphCommand() override = default;

            GenerateGraphCommand(const GenerateGraphCommand &command) = default;

            GenerateGraphCommand(GenerateGraphCommand &&command) = default;

            GenerateGraphCommand &operator=(const GenerateGraphCommand &command) = default;

            GenerateGraphCommand &operator=(GenerateGraphCommand &&command)  = default;

            void execute() override;
        };

    }//namespace command_handler

} //namespace min_path





#endif//MIN_PATH_GENERATE_GRAPH_COMMAND
