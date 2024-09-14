#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

void dfs(const unordered_map<char, vector<char>> &graph, char startingNode)
{
  stack<char> s;
  unordered_set<char> visited;

  s.push(startingNode);
  visited.insert(startingNode);

  while (!s.empty())
  {
    char current = s.top();
    s.pop();

    cout << current << " ";

    for (char neighbor : graph.at(current))
    {
      if (visited.count(neighbor) == 0)
      {
        s.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }
}

bool hasPath(const unordered_map<char, vector<char>> &graph, char startingNode, char endingNode)
{
  stack<char> s;
  unordered_set<char> visited;

  s.push(startingNode);
  visited.insert(startingNode);

  while (!s.empty())
  {
    char current = s.top();
    s.pop();

    if (current == endingNode)
      return true;

    for (char neighbor : graph.at(current))
    {
      if (visited.count(neighbor) == 0)
      {
        s.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }

  return false;
}

int shortestPath(unordered_map<char, vector<pair<char, int>>> &weightedGraph, char startingNode, char endingNode)
{
  unordered_map<char, int> distances;
  // Initialize all distances to infinity
  for (auto row : weightedGraph)
    distances[row.first] = 1e9;

  // Use a set to store nodes to be processed, ordered by distance
  set<pair<int, char>> toProcess;

  distances[startingNode] = 0;
  toProcess.insert({0, startingNode});

  while (!toProcess.empty())
  {
    // Get the node with the smallest distance
    auto current = *toProcess.begin();
    toProcess.erase(toProcess.begin());

    auto currentNode = current.second;
    auto currentDistance = current.first;

    // If we reached the ending node, return the distance
    if (currentNode == endingNode)
      return currentDistance;

    // Explore the neighbors
    for (auto neighbor : weightedGraph.at(currentNode))
    {
      auto nextNode = neighbor.first;
      auto edgeWeight = neighbor.second;

      // Calculate the new distance
      auto newDistance = currentDistance + edgeWeight;

      // If the new distance is smaller, update it
      if (newDistance < distances[nextNode])
      {
        // Remove the old entry if it exists
        if (distances[nextNode] != 1e9)
          toProcess.erase({distances[nextNode], nextNode});

        distances[nextNode] = newDistance;
        toProcess.insert({newDistance, nextNode});
      }
    }
  }

  return -1;
}

void printShortestPath(unordered_map<char, vector<pair<char, int>>> &weightedGraph, char startingNode, char endingNode)
{
  unordered_map<char, int> distances;
  unordered_map<char, char> predecessors; // To store the shortest path predecessors

  // Initialize all distances to infinity
  for (auto node : weightedGraph)
    distances[node.first] = 1e9;

  // Use a set to store nodes to be processed, ordered by distance
  set<pair<int, char>> toProcess;

  distances[startingNode] = 0;
  toProcess.insert({0, startingNode});

  while (!toProcess.empty())
  {
    // Get the node with the smallest distance
    auto current = *toProcess.begin();
    toProcess.erase(toProcess.begin());

    char currentNode = current.second;
    int currentDistance = current.first;

    // If we reached the ending node, reconstruct and print the path
    if (currentNode == endingNode)
    {
      // Reconstruct the path from endingNode to startingNode
      stack<char> path;
      char step = endingNode;

      while (step != startingNode)
      {
        path.push(step);
        step = predecessors[step];
      }
      path.push(startingNode); // Push the starting node to complete the path

      // Print the path
      cout << "Shortest path: ";
      while (!path.empty())
      {
        cout << path.top();
        path.pop();
        if (!path.empty())
          cout << " -> ";
      }
      cout << endl;

      cout << "Shortest distance: " << currentDistance << endl;
      return;
    }

    // Explore the neighbors
    for (auto neighbor : weightedGraph.at(currentNode))
    {
      char nextNode = neighbor.first;
      int edgeWeight = neighbor.second;

      // Calculate the new distance
      int newDistance = currentDistance + edgeWeight;

      // If the new distance is smaller, update it
      if (newDistance < distances[nextNode])
      {
        // Remove the old entry if it exists
        if (distances[nextNode] != 1e9)
          toProcess.erase({distances[nextNode], nextNode});

        distances[nextNode] = newDistance;
        predecessors[nextNode] = currentNode; // Store the predecessor
        toProcess.insert({newDistance, nextNode});
      }
    }
  }

  cout << "No path found from " << startingNode << " to " << endingNode << endl;
}

int main()
{
  // adjacency list
  unordered_map<char, vector<char>> graph{
      {'a', {'b'}},
      {'b', {'a', 'c', 'd', 'e'}},
      {'c', {'b'}},
      {'d', {}},
      {'e', {'b', 'c'}},
      {'f', {}}};

  // adjacency list
  unordered_map<char, vector<pair<char, int>>> weightedGraph{
      {'a', {{'b', 4}, {'c', 4}}},
      {'b', {{'a', 4}, {'c', 2}}},
      {'c', {{'a', 4}, {'b', 4}, {'d', 3}, {'e', 1}, {'f', 6}}},
      {'d', {{'c', 3}, {'f', 2}}},
      {'e', {{'c', 1}, {'f', 3}}},
      {'f', {{'c', 6}, {'d', 2}, {'e', 3}}}};

  // cout << hasPath(graph, 'a', 'e') << endl;
  // cout << shortestPath(weightedGraph, 'a', 'f') << endl;
  printShortestPath(weightedGraph, 'a', 'f');

  cout << endl
       << endl;
}
