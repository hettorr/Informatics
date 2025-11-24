#include <bits/stdc++.h>
using namespace std;

bool isRegularGraph(int vertices, int ribs, int edges[][2]) {
    int degree[105] = {0};
    
    for (int i = 0; i < ribs; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        degree[u]++;
        degree[v]++;
    }
    
    int firstDegree = degree[1];
    for (int i = 2; i <= vertices; i++) {
        if (degree[i] != firstDegree) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int graphs;
    cin >> graphs;
    
    for (int graph = 0; graph < graphs; graph++) {
        int vertices, ribs;
        cin >> vertices >> ribs;
        
        int edges[10005][2];
        for (int i = 0; i < ribs; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        
        if (isRegularGraph(vertices, ribs, edges)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}