#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
vector<int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int v) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        graph[i].clear();
        visited[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            if (value == 1) {
                graph[i].push_back(j);
            }
        }
    }

    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << "\n";
    return 0;
}