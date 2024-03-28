#include <iostream>
#include <cassert>
#include "pathfinding.h"

void testGraph() {
  pathfinding::Graph graph("TestGraph");

  // Test adding edges
  graph.addEdge("A", "B", 1);
  graph.addEdge("B", "C", 2);
  graph.addEdge("C", "D", 3);

  // Test loading graph from file
  graph.loadGraph("graph.txt");

  // Test getting adjacency list
  const pathfinding::AdjacencyMap& adjacencyList = graph.getAdjacencyList();
  assert(adjacencyList.size() == 4); // Assuming 4 nodes in the graph

  // Test Dijkstra's algorithm
  std::vector<std::unique_ptr<pathfinding::Graph::Node>> dijkstraPath = pathfinding::shorted_path_dijkstra(graph, "A", "D");
  assert(dijkstraPath.size() == 3); // Assuming there is a path from A to D

  // Test DFS path search
  std::vector<std::unique_ptr<pathfinding::Graph::Node>> dfsPath = pathfinding::dfs_path_search(graph, "A", "D");
  assert(dfsPath.size() == 3); // Assuming there is a path from A to D

  // Test BFS path search
  std::vector<std::unique_ptr<pathfinding::Graph::Node>> bfsPath = pathfinding::bfs_path_search(graph, "A", "D");
  assert(bfsPath.size() == 3); // Assuming there is a path from A to D

  // Test A* search
  std::vector<std::unique_ptr<pathfinding::Graph::Node>> aStarPath = pathfinding::a_start_search(graph, "A", "D");
  assert(aStarPath.size() == 3); // Assuming there is a path from A to D

  std::cout << "All tests passed!" << std::endl;
}

int main() {
  testGraph();
  return 0;
}