#ifndef PATHFINDING_H
#define PATHFINDING_H
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace pathfinding {
class Graph {
 public:
  struct Node {
    std::string label;
  };
  using NodeIndexName = std::map<std::string, int>;
  using AdjacencyList = std::vector<std::vector<std::shared_ptr<Node>>>;
  using Path = std::vector<std::unique_ptr<Node>>;
  using NodeLabel = std::string;

  Graph(const std::string &id);
  void addEdge(const std::string &from, const std::string &to, int weight);
  void loadGraph(const std::string &filename);
  const AdjacencyList &getAdjacencyList() const;

 private:
  AdjacencyList adj;
  std::string graph_id;
};

std::vector<std::unique_ptr<Graph::Node>> shorted_path_dijkstra(
    const Graph &graph, const std::string &start, const std::string &end);
std::vector<std::unique_ptr<Graph::Node>> dfs_path_search(
    const Graph &graph, const std::string &start, const std::string &end);
std::vector<std::unique_ptr<Graph::Node>> bfs_path_search(
    const Graph &graph, const std::string &start, const std::string &end);
std::vector<std::unique_ptr<Graph::Node>> a_start_search(
    const Graph &graph, const std::string &start, const std::string &end);
}  // namespace pathfinding
#endif