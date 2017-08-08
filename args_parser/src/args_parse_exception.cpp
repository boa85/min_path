//
// Created by boa on 08.08.17.
//

#include "../include/args_parse_exception.hpp"

namespace min_path {
    namespace argument_parser {
        ArgsParseException::ArgsParseException(const std::string &message)
                : std::logic_error(message) {}

        const char *ArgsParseException::what() const throw() {
            return std::logic_error::what();
        }

        ArgsParseException::ArgsParseException(const char *message)
                : std::logic_error(message) {}

    }// argument_parser
}//min_path
