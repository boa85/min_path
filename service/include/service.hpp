//
// Created by boa on 09.08.17.
//

#ifndef MIN_PATH_SERVICE_HPP
#define MIN_PATH_SERVICE_HPP

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/signals2.hpp>
#include <boost/program_options.hpp>

namespace min_path {
    namespace service {
        namespace bs=boost::signals2;
        namespace po=boost::program_options;
        namespace fs=boost::filesystem;

        struct Edge {
            Edge() = default;
            int inVertex;
            int outVertex;
            int cost;

            bool isValid() {
                return inVertex > 0 && outVertex > 0;
            }
        };

        enum class GRAPH_FORMAT {
            EDGE_LIST,
            ADJACENCY_MATRIX
        };
        /**
         * @typedef EdgesListGraphView - list of edges
         */
        typedef std::vector<Edge> EdgesListGraphView;

        /**
         * @typedef adiacency matrix
         */
        using AdjacencyMatrixGraphView = std::vector<std::vector<int> >;


        /**
         * @brief isValidFile - checks the existence of the file and its status
         * @param filename - filename
         * @param errorCode - boost::system::error_code, return system error message
         * @return true, if a file exists and it is a regular file
         */
        bool isValidFile(const std::string &filename, boost::system::error_code &errorCode);

    }//namespace service
}//namespace min_path

#endif //MIN_PATH_SERVICE_HPP
