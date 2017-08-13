//
// Created by boa on 13.08.17.
//

#ifndef MIN_PATH_GRAPH_GENERATOR_HPP
#define MIN_PATH_GRAPH_GENERATOR_HPP

#include <string>

#include "../../../service/include/service.hpp"

namespace min_path {

    namespace graph_generator {

        using namespace service;

        class GraphGenerator {

        public:
            GraphGenerator(const std::string &filename, unsigned int count, unsigned int probability);

            ~GraphGenerator() = default;

            GraphGenerator(const GraphGenerator &) = default;

            GraphGenerator(GraphGenerator &&) = default;

            GraphGenerator &operator=(const GraphGenerator &)= default;

            GraphGenerator &operator=(GraphGenerator &&)= default;

            void generate();

            void generate(const std::string &filename, unsigned int count, unsigned int probability);

        public:
            const std::string &filename() const;

            void setFilename(const std::string &filename);

            unsigned int verticesCount() const;

            void setVerticesCount(unsigned int verticesCount);

            unsigned int probability() const;

            void setProbability(unsigned int probability);

        private:
            unsigned int verticesCount_;
            unsigned int probability_;
            std::string filename_;

            AdjacencyMatrixGraphView reserve(unsigned int count);
        };//class GraphGenerator

    }//namespace graph_generator

}//namespace min_path


#endif //MIN_PATH_GRAPH_GENERATOR_HPP
