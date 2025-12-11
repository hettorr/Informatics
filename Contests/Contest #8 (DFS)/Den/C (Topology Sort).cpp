#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>>& adj, vector<int>& color, vector<int>& result) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 1) {
            return false;
        }
        else if (color[u] == 0) {
            if (!dfs(u, adj, color, result)) {
                return false;
            }
        }
    }

    color[v] = 2;
    result.push_back(v);
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> color(n + 1, 0);
    vector<int> result;
    bool hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, adj, color, result)) {
                hasCycle = true;
            }
        }
    }

    if (hasCycle) {
        cout << -1 << "\n";
    }
    else {
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
            if (i > 0) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}