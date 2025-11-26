#include <bits/stdc++.h>
using namespace std;

bool is_scg(int N, int M, int edges[][2]) {
    bool adj[101][101] = {false};
    
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = true;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && !adj[i][j] && !adj[j][i]) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   
   int tests;
   cin >> tests;
   
   for (int i = 0; i < tests; i++) {
        int N, M;
        cin >> N >> M;
    
        int edges[10000][2];
        for (int i = 0; i < M; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
    
        if (is_scg(N, M, edges)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}