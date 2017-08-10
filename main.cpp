#include <iostream>
#include <memory>

#include "args_parser/include/argument_parser.hpp"
#include "command_handler/include/command_handler.hpp"
#include "command_handler/include/invoker.hpp"
#include "args_parser/include/args_parse_exception.hpp"

/**
 * Есть файл каждая строка которого имеет формат:
 * вершина:расстояние:вершина.
 * Вершины - это вершины графа, расстояние - это расстояние между данными вершинами.
 * Требуется написать программу, которая будет на вход получать данный файл и номера двух вершин,
 * а на выходе выдавать минимальное расстояние между вершинами
 * и распечатывать маршрут между данными вершинами.
 */
using namespace min_path;
using namespace argument_parser;
using namespace command_handler;
int main(int argc, char *argv[]) {
    try {
        auto parser = std::make_shared<ArgumentParser>();
        auto invoker = std::make_shared<Invoker>();
        auto commandHandler = std::make_shared<CommandHandler>();
        parser->generateGraph.connect(boost::bind(&Invoker::generateGraph, invoker, _1, _2, _3));
        parser->findShortestPath.connect(boost::bind(&Invoker::findShortestPath, invoker, _1, _2, _3));
        invoker->start.connect(boost::bind(&CommandHandler::start, commandHandler, _1));
        parser->startParsing(argc, argv);
    }
    catch (ArgsParseException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}