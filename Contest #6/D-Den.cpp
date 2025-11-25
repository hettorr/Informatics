#include <bits/stdc++.h>
using namespace std;

struct Bus {
    int start, to, end;
};

struct Node {
    int time;
    int city;
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

void readBuses(int routes, vector<vector<Bus>>& graph) {
    for (int i = 0; i < routes; i++) {
        int from, start, to, end;
        cin >> from >> start >> to >> end;
        graph[from].push_back({start, to, end});
    }
}

int dijkstra(int towns, int start, int finish, vector<vector<Bus>>& graph) {
    vector<int> dist(towns + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (cur.time <= dist[cur.city]) {
            if (cur.city == finish) return cur.time;
            for (const Bus& bus : graph[cur.city]) {
                if (bus.start >= cur.time && bus.end < dist[bus.to]) {
                    dist[bus.to] = bus.end;
                    pq.push({bus.end, bus.to});
                }
            }
        }
    }
    return -1;
}

int main() {
    int towns, start, finish, routes;
    cin >> towns >> start >> finish >> routes;
    vector<vector<Bus>> graph(towns + 1);
    readBuses(routes, graph);
    cout << dijkstra(towns, start, finish, graph) << "\n";
    return 0;
}