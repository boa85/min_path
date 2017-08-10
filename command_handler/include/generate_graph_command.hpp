//

#ifndef MIN_PATH_GENERATE_GRAPH_COMMAND
#define MIN_PATH_GENERATE_GRAPH_COMMAND

#include <string>

#include "icommand.hpp"

namespace min_path {

    namespace command_handler {
        class GenerateGraphCommand : public ICommand {
        public:
            GenerateGraphCommand(const std::string &filename, unsigned int vertexNumber,
                                 unsigned int probability);
            ~GenerateGraphCommand() override = default;

            GenerateGraphCommand(const GenerateGraphCommand &command) = default;

            GenerateGraphCommand(GenerateGraphCommand &&command) = default;

            GenerateGraphCommand &operator=(const GenerateGraphCommand &command) = delete;

            GenerateGraphCommand &operator=(GenerateGraphCommand &&command)  = delete;

            void execute() override;

        private:
            const std::string filename_;
            const unsigned int vertexNumber_;
            const unsigned int probability_;
        };

    }//namespace command_handler

} //namespace min_path





#endif//MIN_PATH_GENERATE_GRAPH_COMMAND
