#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int parent[MAX_N];
bool hasCycle = false;

void dfs(int v, int par) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, v);
        }
        else if (neighbor != par) {
            hasCycle = true;
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
        parent[i] = -1;
    }
    hasCycle = false;

    int edgeCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            if (value == 1) {
                if (i < j) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    edgeCount++;
                }
            }
        }
    }

    if (edgeCount != n - 1) {
        cout << "NO\n";
        return 0;
    }

    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
            components++;
            if (components > 1 || hasCycle) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}