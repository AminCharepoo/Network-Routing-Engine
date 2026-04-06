#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
using namespace std;

struct Edge {
    int to;
    double bandwidth;
};

struct Node {
    int id;
    vector<Edge> edges;
};

class RoutingEngine {
private:
    vector<unique_ptr<Node>> nodes;
    int numNodes;

    bool dfs(int curr, int dest, double minBW,
             vector<bool>& visited, vector<int>& path) {
        visited[curr] = true;
        path.push_back(curr);

        if (curr == dest) return true;   // found it!

        for (auto& edge : nodes[curr]->edges) {
            if (!visited[edge.to] && edge.bandwidth >= minBW) {
                if (dfs(edge.to, dest, minBW, visited, path))
                    return true;
            }
        }

        path.pop_back();   // backtrack
        return false;
    }

public:
    RoutingEngine(int n) : numNodes(n) {
        for (int i = 0; i < n; i++) {
            auto node = make_unique<Node>();
            node->id = i;
            nodes.push_back(move(node));
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        int u, v;
        double bw;
        while (file >> u >> v >> bw) {
            nodes[u]->edges.push_back({v, bw});
        }
        file.close();
    }

    void printGraph() const {
        for (auto& node : nodes) {
            cout << "Node " << node->id << ": ";
            for (auto& e : node->edges) {
                cout << "-(" << e.bandwidth << ")-> "
                     << e.to << "  ";
            }
            cout << endl;
        }
    }

    vector<int> findPath(int source, int dest, double minBW) {
        vector<bool> visited(numNodes, false);
        vector<int> path;

        if (dfs(source, dest, minBW, visited, path)) {
            cout << "Path found (min BW >= " << minBW << "): ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
        } else {
            cout << "No feasible path found." << endl;
        }

        return path;
    }
};

int main() {
    RoutingEngine engine(6);   // 6 nodes (0-5)
    engine.loadFromFile("network.txt");

    cout << "=== Network Topology ===" << endl;
    engine.printGraph();

    cout << endl;
    cout << "=== Finding paths ===" << endl;
    engine.findPath(0, 5, 50);    // S=0, T=5, min BW=50
    engine.findPath(0, 5, 100);   // higher BW requirement
    engine.findPath(0, 5, 200);   // impossible

    return 0;
}