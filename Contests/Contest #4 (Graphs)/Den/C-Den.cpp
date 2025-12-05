#include <bits/stdc++.h>
using namespace std;

void read_matrix(int vertex_cnt, int matrix[][105]) {
    for (int i = 0; i < vertex_cnt; i++) {
        for (int j = 0; j < vertex_cnt; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertex_cnt;
    cin >> vertex_cnt;
    
    int matrix[105][105];
    int degrees[105] = {0};
    read_matrix(vertex_cnt, matrix);
    
    for (int i = 0; i < vertex_cnt; i++) {
        for (int j = 0; j < vertex_cnt; j++) {
            if (matrix[i][j] == 1) {
                degrees[i]++;
            }
        }
    }
    
    for (int i = 0; i < vertex_cnt; i++) {
        cout << degrees[i] << " ";
    }
    
    return 0;
}