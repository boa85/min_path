//

#include <iostream>


#include "../include/shortest_path_command.hpp"

namespace min_path {

    namespace command_handler {


        FindShortestPathCommand::FindShortestPathCommand(const std::string &filename,
                                                         const unsigned int inVertex,
                                                         const unsigned int outVertex)
                : filename_(filename),
                  inVertex_(inVertex),
                  outVertex_(outVertex) {}

        void FindShortestPathCommand::execute() {
            auto graphBuilder = std::make_shared<GraphBuilder>(filename_);
            graphBuilder->buildGraph(GRAPH_FORMAT::EDGE_LIST);
            auto vertexCount = graphBuilder->vertexCount();
            auto edgesCount = graphBuilder->edgeCount();
            auto graph = graphBuilder->getEdgesListGraphView();
            if (!isValidVertices(graph)) {
                throw std::logic_error("The input or output vertices are not set correctly");
            }
            fordBellman(graph, vertexCount, edgesCount);
        }//execute

        void FindShortestPathCommand::fordBellman(const EdgesListGraphView &graph,
                                                  const int vertexCount,
                                                  const size_t edgesCount) {
            const auto INF = std::numeric_limits<int>::max();//infinity
            std::vector<int> d(vertexCount, INF);//array of distances
            d[inVertex_] = 0;//
            std::vector<int> p(vertexCount, -1);
            for (;;) {
                bool any = false;
                for (size_t j = 0; j < edgesCount; ++j)
                    if (d[graph[j].inVertex] < INF) {
                        if (d[graph[j].outVertex] > d[graph[j].inVertex] + graph[j].cost) {
                            d[graph[j].outVertex] = d[graph[j].inVertex] + graph[j].cost;
                            p[graph[j].outVertex] = graph[j].inVertex;
                            any = true;
                        }
                    }
                if (!any) {
                    break;
                }
            }

            if (d[outVertex_] == INF) {
                std::cout << "No path from " << inVertex_ << " to " << outVertex_ << ".";
            } else {
                std::vector<int> path;
                for (int cur = outVertex_; cur != -1; cur = p[cur]) {
                    path.push_back(cur);
                }
                reverse(path.begin(), path.end());
                std::cout << "Path from " << inVertex_ << " to " << outVertex_ << ": ";
                std::cout << std::endl;
                for (auto i: path) {
                    std::cout << i << ' ';
                }
                std::cout << "length of path = " << calculatePathLength(path, graph);

            }
        }//fordBellman

        bool FindShortestPathCommand::isValidVertices(const EdgesListGraphView &graph) {
            auto in = std::find_if(graph.cbegin(), graph.cend(), [this](const Edge edge) -> bool {
                return edge.inVertex == inVertex_;
            });
            auto out = std::find_if(graph.cbegin(), graph.cend(), [this](const Edge edge) -> bool {
                return edge.outVertex == outVertex_;
            });
            return (in != graph.end() && out != graph.end());

        }//isValidVertices

        int FindShortestPathCommand::calculatePathLength(const std::vector<int> &path,
                                                         const EdgesListGraphView &graph) {
            int totalCost = 0;
            for (size_t i = 0; i < path.size() - 1; ++i) {//пошли по всем вершинам полученного пути
                auto inVertex = path[i];
                auto outVertex = path[i + 1];
                for (auto e : graph) {//ищем в графе ребра с этими решниами
                    if (e.inVertex == inVertex && e.outVertex == outVertex) {
                        totalCost += e.cost;
                    }
                }
            }
            return totalCost;
        }//calculatePathLength


    }//namespace command_handler

} //namespace min_path
