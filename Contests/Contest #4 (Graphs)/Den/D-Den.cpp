#include <bits/stdc++.h>
using namespace std;

void read_matrix(int vertex_cnt, int matrix[][105]) {
    for (int i = 0; i < vertex_cnt; i++) {
        for (int j = 0; j < vertex_cnt; j++) {
            cin >> matrix[i][j];
        }
    }
}

void find_sources_sinks(int vertex_cnt, int matrix[][105], int sources[], int& source_cnt, int sinks[], int& sink_cnt) {
    for (int i = 0; i < vertex_cnt; i++) {
        bool has_outgoing = false;
        bool has_incoming = false;
        
        for (int j = 0; j < vertex_cnt; j++) {
            if (matrix[i][j] == 1) {
                has_outgoing = true;
            }
            if (matrix[j][i] == 1) {
                has_incoming = true;
            }
        }
        
        if (!has_incoming) {
            sources[source_cnt++] = i + 1;
        }
        if (!has_outgoing) {
            sinks[sink_cnt++] = i + 1;
        }
    }
}

void print_result(int sources[], int source_cnt, int sinks[], int sink_cnt) {
    cout << source_cnt << " ";
    for (int i = 0; i < source_cnt; i++) {
        cout << sources[i] << " ";
    }
    cout << "\n";
    
    cout << sink_cnt << " ";
    for (int i = 0; i < sink_cnt; i++) {
        cout << sinks[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertex_cnt;
    cin >> vertex_cnt;
    
    int matrix[105][105];
    read_matrix(vertex_cnt, matrix);
    
    int sources[105], sinks[105];
    int source_cnt = 0, sink_cnt = 0;
    
    find_sources_sinks(vertex_cnt, matrix, sources, source_cnt, sinks, sink_cnt);
    print_result(sources, source_cnt, sinks, sink_cnt);
    
    return 0;
}