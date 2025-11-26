#include <bits/stdc++.h>
using namespace std;

void read_matrix(int n, int matrix[][105]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool is_transitive(int n, int matrix[][105]) {
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (matrix[u][v] == 1) {
                for (int w = 0; w < n; w++) {
                    if (matrix[v][w] == 1 && matrix[u][w] == 0 && u != w) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;
    
    for (int test = 0; test < k; test++) {
        int n;
        cin >> n;
        
        int matrix[105][105];
        read_matrix(n, matrix);
        
        if (is_transitive(n, matrix)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}