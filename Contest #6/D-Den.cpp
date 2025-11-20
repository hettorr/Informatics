#include <bits/stdc++.h>
using namespace std;

struct Bus {
    int from, start, to, end;
};

struct Node {
    int time;
    int city;
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

void readBuses(int routes, vector<Bus>& buses) {
    for (int i = 0; i < routes; i++) {
        cin >> buses[i].from >> buses[i].start >> buses[i].to >> buses[i].end;
    }
}

int dijkstra(int towns, int start, int finish, vector<Bus>& buses) {
    vector<int> dist(towns + 1, INT_MAX);
    dist[start] = 0;
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        if (cur.time <= dist[cur.city]) {
            if (cur.city == finish) {
                return cur.time;
            }
            
            for (const Bus& bus : buses) {
                if (bus.from == cur.city && bus.start >= cur.time) {
                    if (bus.end < dist[bus.to]) {
                        dist[bus.to] = bus.end;
                        pq.push({bus.end, bus.to});
                    }
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int towns, start, finish, routes;
    cin >> towns >> start >> finish >> routes;
    vector<Bus> buses(routes);
    readBuses(routes, buses);
    
    int result = dijkstra(towns, start, finish, buses);
    cout << result << "\n";
    return 0;
}