//
// Created by boa on 08.08.17.
//

#ifndef MIN_PATH_ARGS_PARSE_EXCEPTION_HPP
#define MIN_PATH_ARGS_PARSE_EXCEPTION_HPP

#include <exception>
#include <string>
#include <stdexcept>

namespace min_path {
    namespace argument_parser {
        /**
         * @class ArgsParseException - my exception
         */
        class ArgsParseException : public std::logic_error {
        public:
            /**
             * @brief ArgsParseException  - constructor
             * @param message - error message
             */
            explicit ArgsParseException(const std::string &message);

            /**
             * @brief ArgsParseException - constructor
             * @param message
             */
            explicit ArgsParseException(const char *message);

            /**
             * @brief ArgsParseException - copy constructor
             */
            ArgsParseException(const ArgsParseException &) = default;

            /**
             * @param ArgsParseException - copy assignment operator
             */
            ArgsParseException &operator=(const ArgsParseException &) = default;

            /**
             * @brief ArgsParseException - destructor
             */
            ~ArgsParseException() override = default;

            /**
             * @brief what - override method
             * @return Returns a C-style character string describing the general cause of
             * the current error (the same string passed to the ctor).
             */
            const char *what() const throw() override;
        };//class ArgsParseException
    }// argument_parser
}//min_path




#endif //MIN_PATH_ARGS_PARSE_EXCEPTION_HPP
