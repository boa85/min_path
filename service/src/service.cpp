//
// Created by boa on 09.08.17.
//

#include "../include/service.hpp"

namespace min_path {

    namespace service {


        bool isValidFile(const std::string &filename, boost::system::error_code &errorCode) {
            return (fs::exists(filename, errorCode) && fs::is_regular(filename, errorCode));
        }// isValidFile

    }//namespace service

}//namespace min_path
