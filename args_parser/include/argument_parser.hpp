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
        namespace po=boost::program_options;
        namespace bs=boost::signals2;

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
             * @brief findMinPath - the program switching signal to the @mode
             * @mode - normal mode - using the Dijkstra algorithm, negative - using the Ford-Bellman algorithm
             * @filename - input filename
             * @inVertex - input vertex number
             * @outVertex - output vertex number
             */
            bs::signal<void(const PROGRAM_MODE mode, const std::string &filename, const unsigned int inVertex,
                            const unsigned int outVertex)> findMinPath;


        private:
            /**
             * @brief generalDescription_ - command line options description
             */
            po::options_description generalDescription_;

            /**
             * @brief findMinPathDescription_ -Description of the minimum path search mode
             */
            po::options_description findMinPathDescription_;


            /**
             * @brief mode_ - string program mode: path
             */
            std::string mode_;


            /**
             * @brief initDescriptions - init boost program options descriptions
             */
            void initDescriptions();

            /**
             * @brief prepareWordCountMode -  checks the correctness of the mode parameters and sent command to run mode
             * @param vm - boost::program_options variable map with program arguments
             */
            void prepareFindMinimumPathMode(const po::variables_map &vm);


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
        };//class ArgumentParser

    }// argument_parser

}//min_path



#endif //MIN_PATH_ARGUMENT_PARSER_HPP
