#include "Kahn.h"
#include <iostream>

using namespace std;

void output_vertices(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    for (; begin != end; ++begin)
        cout << *begin + 1 << ' ';
    cout << '\n';
}

int main()
{
    int q_vert; cin >> q_vert;
    Kahn graph(q_vert); graph.input_conn_list(cin);

    if (graph.is_DAG() == false)
    {
        cout << "-1\n";
        return 0;
    }

    vector<int> graph_sorted_vertices = graph.topology_sort();
    output_vertices(graph_sorted_vertices.begin(), graph_sorted_vertices.end());

    return 0;
}