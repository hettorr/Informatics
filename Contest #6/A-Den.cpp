#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dist;
    int v;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void readGraph(int vertices, vector<vector<int>>& graph) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }
}

int dijkstra(int vertices, int vstart, int vfinish, vector<vector<int>>& graph) {
    vector<int> dist(vertices, INT_MAX);
    dist[vstart] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, vstart});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.dist <= dist[cur.v]) {
            for (int v = 0; v < vertices; v++) {
                if (cur.v != v && graph[cur.v][v] > 0) {
                    int nd = dist[cur.v] + graph[cur.v][v];
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    return dist[vfinish] == INT_MAX ? -1 : dist[vfinish];
}

int main() {
    int vertices, vstart, vfinish;
    cin >> vertices >> vstart >> vfinish;
    vector<vector<int>> graph(vertices, vector<int>(vertices));
    readGraph(vertices, graph);

    cout << dijkstra(vertices, vstart - 1, vfinish - 1, graph) << "\n";
    return 0;
}