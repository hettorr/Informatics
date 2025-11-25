#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double calcDist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void readPoints(int N, vector<Point>& points) {
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
}

double dijkstra(int N, vector<Point>& points) {
    vector<double> dist(N, 1e9);
    dist[0] = 0;
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        double cur_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (cur_dist <= dist[u]) {
            if (u == 1) {
                return cur_dist;
            }
            
            for (int v = 0; v < N; v++) {
                if (u != v) {
                    double d = calcDist(points[u], points[v]);
                    double new_cost = max(cur_dist, d);
                    
                    if (new_cost < dist[v]) {
                        dist[v] = new_cost;
                        pq.push({new_cost, v});
                    }
                }
            }
        }
    }
    
    return dist[1];
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    readPoints(N, points);
    
    double result = dijkstra(N, points);
    cout << fixed << setprecision(3) << result << "\n";
    return 0;
}