#include <bits/stdc++.h>

using namespace std;

constexpr int DIM = 100;

vector<int> vert[DIM];
bool used[DIM];
int q_vert;

void input_graf() {
    bool is_rib;
    for (int i = 0; i < q_vert; ++i)
        for (int j = 0; j < q_vert; ++j){
            cin >> is_rib;
            if (is_rib)
                vert[i].push_back(j);
        }
}

bool is_acyclic(const int &v, const int &par) {
    used[v] = true;
    for (const int &u : vert[v])
        if (u != par && (used[u] || !is_acyclic(u, v)))
            return false;
    return true;
}

bool is_connected(){
    for (int i = 0; i < q_vert; ++i)
        if (!used[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q_vert;
    input_graf();

    cout << ((is_acyclic(0, 0) && is_connected()) ? "YES\n" : "NO\n");

    return 0;
}