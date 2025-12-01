//
// Created by manzeriko on 01.12.25.
//

#include "SDFS.h"

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int q_vert; cin >> q_vert;

    SDFS graph(q_vert);
    graph.input_adj_matrix(cin);

    cout << graph.count_connectivity_components() << '\n';

    return 0;
}