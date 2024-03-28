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
    bool visited{false};
  };
  using NodeIndexName = std::map<std::string, int>;
  using AdjacencyList = std::vector<std::vector<std::shared_ptr<Node>>>;
  using Path = std::vector<std::unique_ptr<Node>>;
  using NodeLabel = std::string;
  // Constructor
  Graph(const std::string &id);
  // Add edge to graph
  void addEdge(const NodeLabel &from, const NodeLabel &to, int weight);
  // Load graph from a json file
  void loadGraph(const std::string &filename);
  // Get adjacency list
  const AdjacencyList &getAdjacencyList() const;
 private:
  AdjacencyList adj;
  std::string graph_id;
};

std::vector<std::unique_ptr<Graph::Node>> shortestPathDijkstra(
    const Graph &graph, const Graph::NodeLabel &start, const Graph::NodeLabel &end);
std::vector<std::unique_ptr<Graph::Node>> dfsPathSearch(
    const Graph &graph, const Graph::NodeLabel &start, const Graph::NodeLabel &end);
std::vector<std::unique_ptr<Graph::Node>> bfsPathSearch(
    const Graph &graph, const Graph::NodeLabel &start, const std::string &end);
std::vector<std::unique_ptr<Graph::Node>> aStarSearch(
    const Graph &graph, const Graph::NodeLabel &start, const std::string &end);
}  // namespace pathfinding
#endif