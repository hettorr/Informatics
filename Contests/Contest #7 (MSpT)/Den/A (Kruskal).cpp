#include <bits/stdc++.h>
using namespace std;

struct rib {
    int start, end, weight, number;
};

bool operator<(const rib& a, const rib& b) {
    return a.weight > b.weight;
}

void read_ribs(int edges, priority_queue<rib>& q) {
    for (int i = 1; i <= edges; i++) {
        rib temp;
        cin >> temp.start >> temp.end >> temp.weight;
        temp.number = i;
        q.push(temp);
    }
}

int find_set(int v, vector<int>& links) {
    if (v == links[v]) return v;
    return links[v] = find_set(links[v], links);
}

bool union_sets(int a, int b, vector<int>& links) {
    a = find_set(a, links);
    b = find_set(b, links);
    if (a == b) return false;
    links[b] = a;
    return true;
}

int kruskal(int vertices, priority_queue<rib>& q, vector<rib>& tree, vector<int>& links) {
    int count = 0;
    int total_weight = 0;

    while (!q.empty() && count < vertices - 1) {
        rib cur = q.top();
        q.pop();

        if (union_sets(cur.start, cur.end, links)) {
            tree[count] = cur;
            total_weight += cur.weight;
            count++;
        }
    }

    return total_weight;
}

void output_tree(vector<rib>& tree, int count) {
    sort(tree.begin(), tree.begin() + count, [](const rib& a, const rib& b) {
        return a.number < b.number;
    });

    for (int i = 0; i < count; i++) {
        cout << tree[i].number << "\n";
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> links(vertices + 1);
    for (int i = 1; i <= vertices; i++) {
        links[i] = i;
    }

    priority_queue<rib> q;
    read_ribs(edges, q);

    vector<rib> tree(vertices - 1);
    int total_weight = kruskal(vertices, q, tree, links);

    int count = 0;
    for (int i = 0; i < vertices - 1; i++) {
        if (tree[i].number != 0) count++;
    }

    if (count < vertices - 1) {
        cout << -1 << "\n";
    } else {
        cout << total_weight << "\n";
        output_tree(tree, count);
    }

    return 0;
}