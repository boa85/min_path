//

#ifndef MIN_PATH_GRAPH_BUILDER
#define MIN_PATH_GRAPH_BUILDER

#include <list>
#include <string>
#include <memory>

#include "../../../service/include/service.hpp"

namespace min_path {

    namespace graph_builder {
        using namespace service;

        struct Edge {
            int inVertex;
            int outVertex;
            int cost;

            bool isValid() {
                return inVertex > 0 && outVertex > 0;
            }

        };

        using Graph = std::list<Edge>;

        class GraphBuilder {

        public:
            explicit GraphBuilder(const std::string &filename);

            ~GraphBuilder() = default;

            GraphBuilder(const GraphBuilder &) = default;

            GraphBuilder(GraphBuilder &&) = default;

            GraphBuilder &operator=(const GraphBuilder &) = default;

            GraphBuilder &operator=(GraphBuilder &&) = default;

            std::shared_ptr<Graph> getGraph();
        private:
            std::string filename_;

            std::shared_ptr<Graph> build();
        };//class GraphBuilder


    }//namespace graph_builder

}//namespace min_path


#endif //MIN_PATH_GRAPH_BUILDER

