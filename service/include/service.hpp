//
// Created by boa on 09.08.17.
//

#ifndef MIN_PATH_SERVICE_HPP
#define MIN_PATH_SERVICE_HPP

#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace min_path {
    namespace service {

        enum class PROGRAM_MODE {
            NORMAL = 1,
            NEGATIVE
        };

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
