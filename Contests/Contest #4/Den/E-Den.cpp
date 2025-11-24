#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertex_cnt, edge_cnt;
    cin >> vertex_cnt >> edge_cnt;
    
    int in_degree[105] = {0};
    int out_degree[105] = {0};
    
    for (int i = 0; i < edge_cnt; i++) {
        int u, v;
        cin >> u >> v;
        out_degree[u]++;
        in_degree[v]++;
    }
    
    for (int i = 1; i <= vertex_cnt; i++) {
        cout << in_degree[i] << " " << out_degree[i] << "\n";
    }
    
    return 0;
}