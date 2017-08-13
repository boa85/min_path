//
// Created by boa on 13.08.17.
//

#include <random>
#include <fstream>
#include <iostream>
#include "../../include/graph_generator/graph_generator.hpp"

namespace min_path {
    namespace graph_generator {

        GraphGenerator::GraphGenerator(const std::string &filename,
                                       const unsigned int count,
                                       const unsigned int probability)
                : filename_(filename),
                  verticesCount_(count),
                  probability_(probability) {}

        const std::string &GraphGenerator::filename() const {
            return filename_;
        }

        void GraphGenerator::setFilename(const std::string &filename) {
            filename_ = filename;
        }

        unsigned int GraphGenerator::verticesCount() const {
            return verticesCount_;
        }

        void GraphGenerator::setVerticesCount(unsigned int verticesCount) {
            verticesCount_ = verticesCount;
        }

        unsigned int GraphGenerator::probability() const {
            return probability_;
        }

        void GraphGenerator::setProbability(unsigned int probability) {
            probability_ = probability;
        }

        void GraphGenerator::generate() {
            generate(filename_, verticesCount_, probability_);
        }

        void GraphGenerator::generate(const std::string &filename, unsigned int count, unsigned int probability) {
            EdgesListGraphView graph;
            std::mt19937 gen(std::time(0));
            std::uniform_int_distribution<int> uid(0, 100);
            std::uniform_int_distribution<int> uid2(-100, 100);
            for (int i = 0; i < count; ++i) {
                for (int j = i + 1; j < count; ++j) {
                    auto p = uid(gen);
                    if (p < probability) {
                        Edge edge{};
                        edge.inVertex = i + 1;
                        edge.outVertex = j + 1;
                        edge.cost = uid2(gen);
                        graph.push_back(edge);
                    }
                }
            }
            std::ofstream out(filename);//я знаю, что за такое стрелять надо, позже исправлю
            boost::system::error_code errorCode;
            if (!isValidFile(filename, errorCode)) {
                throw std::invalid_argument(errorCode.message());
            }
            if (!out.is_open()) {
                throw std::runtime_error("cannot  open file");
            }
            std::cout << "edges count = " << graph.size() << std::endl;
            for (auto e : graph) {
//                e.print();
                out << e.inVertex << ":" << e.cost << ":" << e.outVertex << std::endl;
            }
            out.close();
        }

    }//namespace graph_generator
}//namespace min_path
