#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Edge {
    int target;
    int weight;
    Edge(int t, int w) : target(t), weight(w) {}
};

std::vector<int> dijkstra(int k, const std::vector<std::vector<Edge>>& graph) {
    int n = graph.size();
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    distances[k - 1] = 0; // Starting node has distance 0

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > distances[currentNode - 1]) {
            continue; // Skip if we've found a shorter path
        }

        for (const Edge& neighbor : graph[currentNode - 1]) {
            int newDist = currentDist + neighbor.weight;
            if (newDist < distances[neighbor.target - 1]) {
                distances[neighbor.target - 1] = newDist;
                pq.push({newDist, neighbor.target});
            }
        }
    }

    return distances;
}

int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<Edge>> graph(n);

    for (const auto& time : times) {
        graph[time[0] - 1].emplace_back(time[1], time[2]);
    }

    std::vector<int> distances = dijkstra(k, graph);

    int maxTime = 0;
    for (int distance : distances) {
        if (distance == std::numeric_limits<int>::max()) {
            return -1; // Some nodes are not reachable
        }
        maxTime = std::max(maxTime, distance);
    }

    return maxTime;
}

int main() {
    // Example usage:
    std::vector<std::vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4; // Number of nodes
    int k = 2; // Source node

    int result = networkDelayTime(times, n, k);

    if (result != -1) {
        std::cout << "Minimum time to reach all nodes: " << result << std::endl;
    } else {
        std::cout << "Not all nodes can receive the signal." << std::endl;
    }

    return 0;
}
