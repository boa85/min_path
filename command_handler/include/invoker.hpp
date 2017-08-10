//
// Created by boa on 09.08.17.
//

#ifndef MIN_PATH_INVOKER_HPP
#define MIN_PATH_INVOKER_HPP

#include <boost/signals2/signal.hpp>
#include <memory>

#include "icommand.hpp"

namespace min_path {

    namespace command_handler {
        namespace bs=boost::signals2;
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
             * @brief Invoker - copy constructor
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

            /**
            * @brief start - boost signal for sending command to CommandHandler
            */
            bs::signal<void(std::shared_ptr<ICommand> &command)> start;

            /**
             * @brief generateGraph create GenerateGraphCommand  and send to CommandHandler
             * @param filename - input filename
             * @param vertexNumber - number of vertex
             * @param probability - probability of appearance of an edge between vertices in percent
             */
            void generateGraph(const std::string &filename, unsigned int vertexNumber, unsigned int probability);

            /**
             * @brief findShortestPath create FindShortestCommand and send to CommandHandler
             * @filename - input filename
             * @inVertex - input vertex number
             * @outVertex - output vertex number
             */
            void findShortestPath(const std::string &filename, unsigned int inVertex, unsigned int outVertex);

        private:
            /**
             * @brief createGenerateGraphCommand - create new exemplar of GenerateGraphCommand
             * @param filename - input filename
             * @param vertexNumber - number of vertex
             * @param probability - probability of appearance of an edge between vertices in percent
             * @return new exemplar of GenerateGraphCommand class
             */
            std::shared_ptr<ICommand> createGenerateGraphCommand(const std::string &filename, unsigned int vertexNumber,
                                                                 unsigned int probability);

            /**
             * @brief create createFindShortestCommand and send to CommandHandler
             * @filename - input filename
             * @inVertex - input vertex number
             * @outVertex - output vertex number
             * @return new exemplar of FindShortestCommand class
             */
            std::shared_ptr<ICommand> createFindShortestCommand(const std::string &filename, unsigned int inVertex,
                                                                unsigned int outVertex);

        };//class Invoker

    }//namespace command_handler

}//namespace min_path



#endif //MIN_PATH_INVOKER_HPP
