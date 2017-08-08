//
// Created by boa on 09.08.17.
//

#ifndef MIN_PATH_INVOKER_HPP
#define MIN_PATH_INVOKER_HPP


namespace min_path {

    namespace command_handler {
        /**
         * @class Invoker - Based on the input data received from the client,
         * it generates commands and passes it on to execution
         */
        class Invoker {
        public:
            /**
             * @brief Invoker - constructor
             */
            Invoker() = default;

            /**
             * @brief ~Invoker - destructor
             */
            virtual  ~Invoker() = default;

            /**
             * @brief Invoker - copy contructor
             */
            Invoker(const Invoker &) = default;

            /**
             * @brief Invoker - move constructor
             */
            Invoker(Invoker &&) = default;

            /**
             * @brief operator= - copy assignment operator
             */
            Invoker &operator=(const Invoker &) = default;

            /**
             * @brief operator= move assignment operator
             */
            Invoker &operator=(Invoker &&) = default;

        };


    }//namespace command_handler

}//namespace min_path



#endif //MIN_PATH_INVOKER_HPP
