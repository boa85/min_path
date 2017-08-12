//
// Created by boa on 08.08.17.
//

#ifndef MIN_PATH_ARGUMENT_PARSER_HPP
#define MIN_PATH_ARGUMENT_PARSER_HPP

#include <boost/program_options.hpp>
#include <boost/signals2.hpp>
#include <iostream>

#include "../../service/include/service.hpp"


namespace min_path {

    namespace argument_parser {
        using namespace service;


        /**
         * @class ArgumentParser - command line arguments parser, based on boost::program_options
         */
        class ArgumentParser {
        public:
            /**
             * @brief ArgumentParser - default constructor, init generalDescription_
             */
            ArgumentParser();

            /**
             * @brief ArgumentParser - destructor
             */
            ~ArgumentParser() = default;

            /**
             * @brief ArgumentParser - copy constructor, is forbidden  because the signals are not copied
             */
            ArgumentParser(const ArgumentParser &) = delete;

            /**
             * @brief ArgumentParser - move constructor
             */
            ArgumentParser(ArgumentParser &&) = default;

            /**
             * @brief operator= - copy assignment operator, is forbidden  because the signals are not copied
             */
            ArgumentParser &operator=(const ArgumentParser &)  = delete;

            /**
             * @brief move assignment operator, is forbidden  because the boost::program_options are not assignment
             */
            ArgumentParser &operator=(ArgumentParser &&) = delete;

            /**
             * @brief findMinPath - the program switching signal to the @mode
             * @filename - input filename
             * @inVertex - input vertex number
             * @outVertex - output vertex number
             */
            bs::signal<void(const std::string &filename, const unsigned int inVertex,
                            const unsigned int outVertex)> findShortestPath;

            bs::signal<void(const std::string &filename, const unsigned int vertexNumber,
                            const unsigned int probability)> generateGraph;

        private:
            /**
             * @brief generalDescription_ - command line options description
             */
            po::options_description generalDescription_;

            /**
             * @brief findMinPathDescription_ - description of the shortest path search mode
             */
            po::options_description findShortestPathModeDescription_;

            /**
             * @brief generateGraphDescription_ - description of the generate graph mode
             */
            po::options_description generateGraphModeDescription_;

            /**
             * @brief mode_ - string program mode
             */
            std::string mode_;


            /**
             * @brief initDescriptions - init boost program options descriptions
             */
            void initDescriptions();

            /**
             * @brief prepareWordCountMode - checks the correctness of the mode parameters and sent command to run mode
             * @param vm - boost::program_options variable map with program arguments
             */
            void prepareFindMinimumPathMode(const po::variables_map &vm);

            /**
             * @brief prepareGenerateGraphMode - checks the correctness of the mode parameters and sent command to run mode
             * @param vm - boost::program_options variable map with program arguments
             */
            void prepareGenerateGraphMode(const po::variables_map &vm);

            /**
             * @brief error - error handler method
             * @param errorMessage - message about error
             */
            void error(const std::string &errorMessage);

        public:
            /**
             * @brief startParsing start command line arguments parser
             * @param argc count of arguments
             * @param argv  - values of arguments
             */
            void startParsing(int argc, char *argv[]);

            const unsigned int MINIMUM_VERTEX_NUMBER = 3;

            const std::string SHORTEST_PATH = "minpath";

            const std::string GENERATE_GRAPH = "generate";

        };//class ArgumentParser

    }//namespace argument_parser

}//namespace min_path



#endif //MIN_PATH_ARGUMENT_PARSER_HPP
