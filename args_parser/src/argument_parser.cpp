//
// Created by boa on 08.08.17.
//

#include <boost/system/error_code.hpp>

#include "../include/argument_parser.hpp"
#include "../include/args_parse_exception.hpp"

namespace min_path {
    namespace argument_parser {

        ArgumentParser::ArgumentParser() : generalDescription_("program options") {
            initDescriptions();
        }//ArgumentParser

        void ArgumentParser::initDescriptions() {

            generalDescription_.add_options()
                    ("help,h", "\nmin path v 1.0\n"
                            "author: boa85\n"
                            "program options: \n "
                            "mode, filename, vertex1, vertex2 \n"
                            "e.g ./min_path -m minpath -f Test.tst  -i 1 -o 13\n"
                            "Searches for the shortest distance between vertices  "
                            "\n or \n "
                            "e.g ./min_path -m generate -f Test.tst  -c 13 -p 33\n"
                            "generate new input file with graph description in next format: \"in:weight:out\" \n")
                    ("mode,m", po::value<std::string>(&mode_)->required(),
                     "program mode: minpath, generate");

            findShortestPathModeDescription_.add_options()
                    ("file,f", po::value<std::string>(), "input filename, e.g. Test.tst")
                    ("input,i", po::value<unsigned int>(), " input vertex, unsigned int")
                    ("out,o", po::value<unsigned int>(), " output vertex, unsigned int");

            generateGraphModeDescription_.add_options()
                    ("file,f", po::value<std::string>(), "input filename, e.g. Test.tst")
                    ("number,n", po::value<unsigned int>(), "number of vertices")
                    ("probability,p", po::value<unsigned int>(),
                     "probability of appearance of an edge between vertices in percent");
        }//initDescriptions

        void ArgumentParser::prepareFindMinimumPathMode(const po::variables_map &vm) {
            std::string filename;//filename
            unsigned int input = 0;//input vertex
            unsigned int out = 0;//output vertex
            const auto fKey = "file";//TODO тута, по-хорошему, нужно завести мапу для режимов,
            // с именем режима в качестве ключа и  некой структурой,
            // содержащей описание (po::options_description)
            // и обработчик параметров режима, в качестве значения.
            // Это позволит легко расширять количество режимов, простым добавлением конфигурации.
            const auto iKey = "input";
            const auto oKey = "out";
            if (vm.count(fKey) != 0u) {//find required argument filename
                filename = vm[fKey].as<std::string>();
                if (filename.empty()) {
                    error("empty value of the filename argument");
                }
            } else {//if not found, sent error
                error("the option \"filename\" is required but missing");
            }
            if (vm.count(iKey) != 0u) {//find required argument input vertex
                input = vm[iKey].as<unsigned int>();
                if (input <= 0) {
                    error("negative value of the input vertex argument");
                }
            } else {//if not found, sent error
                error("the option \" input vertex \" is required but missing");
            }

            if (vm.count(oKey) != 0u) {//find required argument output vertex
                out = vm[oKey].as<unsigned int>();
                if (out <= 0) {
                    error("negative value of the output vertex argument");
                }
            } else {//if not found, sent error
                error("the option \" output vertex \" is required but missing");
            }

            boost::system::error_code errorCode;
            isValidFile(filename, errorCode) ?
            findShortestPath(filename, input, out) : error("invalid value " + filename + " " + errorCode.message());

        }//prepareFindMinimumPathMode

        void ArgumentParser::prepareGenerateGraphMode(const po::variables_map &vm) {
            std::string filename;//output filename
            unsigned int number = 0;//number of vertex
            unsigned int probability = 0;//probability of appearance of an edge between vertices in percent
            const auto fKey = "file";
            const auto nKey = "number";
            const auto pKey = "probability";
            if (vm.count(fKey) != 0u) {//find required argument filename
                filename = vm[fKey].as<std::string>();
                if (filename.empty()) {
                    error("empty value of the filename argument");
                }
            } else {//if not found, sent error
                error("the option \"filename\" is required but missing");
            }
            if (vm.count(nKey) != 0u) {//find required argument number of vertex
                number = vm[nKey].as<unsigned int>();
                if (number <= MINIMUM_VERTEX_NUMBER) {
                    error("invalid value of the number of vertex argument");
                }
            } else {//if not found, sent error
                error("the option \"number of vertex\" is required but missing");
            }

            if (vm.count(pKey) != 0u) {//find required argument probability
                probability = vm[pKey].as<unsigned int>();
                if (probability <= 0) {
                    error("negative value of the probability argument");
                }
            } else {//if not found, sent error
                error("the option \" probability \" is required but missing");
            }
            generateGraph(filename, number, probability);
        }

        void ArgumentParser::error(const std::string &errorMessage) {
            std::cout << errorMessage << std::endl << "See help " << std::endl << generalDescription_ << std::endl;
            throw ArgsParseException(errorMessage);
        }//error

        void ArgumentParser::startParsing(int argc, char *argv[]) {
            /** Concrete variables map which store variables in real map.
             * This class is derived from std::map<std::string, variable_value>,
             * so you can use all map operators to examine its content.
            */
            po::variables_map vm;//
            po::parsed_options parsed =//magic
                    po::command_line_parser(argc, argv).options(generalDescription_).allow_unregistered().run();

            po::store(parsed, vm);//more magic
            po::notify(vm);//even more magic

            if (vm.count("help") != 0u) {//if found a help flag
                std::cout << generalDescription_;//show help
                return;
            }

            if (mode_ == SHORTEST_PATH) {//check program mode
                generalDescription_.add(findShortestPathModeDescription_);//add FIND_MINIMAL_PATH mode options descriptions
                po::store(po::parse_command_line(argc, argv, generalDescription_), vm);
                prepareFindMinimumPathMode(vm);//
            } else if (mode_ == GENERATE_GRAPH) {
                generalDescription_.add(generateGraphModeDescription_);
                po::store(po::parse_command_line(argc, argv, generalDescription_), vm);
                prepareGenerateGraphMode(vm);
            } else {
                error("unknown program mode");
            }

        }// startParsing

    }// argument_parser

}//min_path
