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
        }

        void ArgumentParser::initDescriptions() {
            generalDescription_.add_options()
                    ("help,h", "\nmin path v 1.0\n"
                            "author: boa85\n"
                            "program options: \n "
                            "mode, filename, vertex1, vertex2 \n"
                            "e.g ./min_path -m normal -f Test.tst  -i 1 -o 13\n"
                            "Searches for the shortest distance between vertices using the Dijkstra algorithm"
                            "\n or \n "
                            "e.g ./min_path -m negative -f Test.tst  -i 1 -o 13\n"
                            "Searches for the shortest distance between vertices using the Ford-Bellman algorithm\n")
                    ("mode,m", po::value<std::string>(&mode_)->required(),
                     "program mode: normal, negative");
            findMinPathDescription_.add_options()
                    ("file,f", po::value<std::string>(), "input filename, e.g. Test.tst")
                    ("i,input", po::value<unsigned int>(), " input vertex")
                    ("o,out", po::value<unsigned int>(), " output vertex");
        }

        void ArgumentParser::prepareFindMinimumPathMode(const po::variables_map &vm) {
            std::string filename;//filename
            unsigned int input;//input vertex
            unsigned int out;//output vertex
            const auto fKey = "file";//TODO тута, по-хорошему, нужно завести мапу для режимов,
            // с именем режима в качестве ключа и  некой структурой, содержащей описание (po::options_description)
            // и обработчик параметров режима, в качестве значения. Это позволит легко расширять количество режимов,
            // простым наследованием.
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
/*
            if (isValidFile(filename, errorCode)) {//if a file exists and it is a regular file
                countOccurrencesWord(filename, word);//sent command to run program in WORD_COUNT mode
            } else {
                error("invalid value " + filename + " " + errorCode.message());
            }
*/

        }

        void ArgumentParser::error(const std::string &errorMessage) {
            std::cout << errorMessage << std::endl << "See help " << std::endl << generalDescription_ << std::endl;
            throw ArgsParseException(errorMessage);
        }

        void ArgumentParser::startParsing(int argc, char *argv[]) {
            po::variables_map vm;//
            po::parsed_options parsed =//magic
                    po::command_line_parser(argc, argv).options(generalDescription_).allow_unregistered().run();

            po::store(parsed, vm);//more magic
            po::notify(vm);//even more magic

            if (vm.count("help") != 0u) {//if found a help flag
                std::cout << generalDescription_;//show help
                return;
            }
            if (mode_ == "normal" || mode_ == "negative") {//check program mode
                generalDescription_.add(findMinPathDescription_);//add FIND_MINIMAL_PATH mode options descriptions
                po::store(po::parse_command_line(argc, argv, generalDescription_),
                          vm);//checks the correctness of the mode parameters
                // and sent command to run mode
                prepareFindMinimumPathMode(vm);//
            } else {
                error("unknown program mode");
            }

        }
    }// argument_parser
}//min_path
