
#include "pathfinding.h"
namespace pathfinding {

void pathfinding::Graph::addEdge(const std::string &from, const std::string &to,
                                 int weight) {
  // adj[from].push_back(Node{to, weight});
  //   adj[to].push_back(Node{from, weight});
}

void pathfinding::Graph::loadGraph(const std::string &filename) {
  // Load graph from file
}

std::vector<std::unique_ptr<Graph::Node>> shortestPathDijkstra(
    const Graph &graph, const std::string &start, const std::string &end) {
  std::vector<std::unique_ptr<Graph::Node>> path;
  return path;
}
std::vector<std::unique_ptr<Graph::Node>> dfsPathSearch(
    const Graph &graph, const std::string &start, const std::string &end) {
  std::vector<std::unique_ptr<Graph::Node>> path;
  return path;
}
std::vector<std::unique_ptr<Graph::Node>> bfsPathSearch(
    const Graph &graph, const std::string &start, const std::string &end) {
  std::vector<std::unique_ptr<Graph::Node>> path;
  return path;
}
std::vector<std::unique_ptr<Graph::Node>> a_star_search(
    const Graph &graph, const std::string &start, const std::string &end) {
  std::vector<std::unique_ptr<Graph::Node>> path;
  return path;
}