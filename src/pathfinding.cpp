
#include "pathfinding.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
namespace pathfinding {

void Graph::addEdge(const NodeLabel &from, const NodeLabel &to, int weight) {
  auto edge_from_to = std::make_shared<Node>(Node{to, weight});
  auto edge_to_from = std::make_shared<Node>(Node{from, weight});
  auto idx_from{0};
  auto idx_to{0};
  if (nodeIndex_.find(from) == nodeIndex_.end()) {
    idx_from = adj_.size();
    nodeIndex_[from] = idx_from;
    adj_.push_back(std::vector<std::shared_ptr<Node>>());
  } else {
    idx_from = nodeIndex_[from];
  }
  if (nodeIndex_.find(to) == nodeIndex_.end()) {
    idx_to = adj_.size();
    nodeIndex_[to] = idx_to;
    adj_.push_back(std::vector<std::shared_ptr<Node>>());
  } else {
    idx_to = nodeIndex_[to];
  }
  adj_[idx_from].push_back(edge_from_to);
  adj_[idx_to].push_back(edge_to_from);
}

void Graph::loadGraph(const std::string &filename) {
  // Load graph from file
  std::ifstream file(filename);
  if (file.is_open()) {
      nlohmann::json json_graph;
      file >> json_graph;

      file.close();
    } else {
      // Handle file open error
      // ...
    }
  }
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
}  // namespace pathfinding