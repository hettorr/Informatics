#ifndef DEN_BOD_ART_PROG_KAHN_H
#define DEN_BOD_ART_PROG_KAHN_H

#include <iostream>
#include <vector>
#include <queue>

class Kahn
{
private:
    int size;
    std::vector<bool> used;
    std::vector<int> in_ribs;
    std::vector<std::vector<int>> out_ribs;

    void set_not_used()
    {
        used.assign(size, false);
    }

    bool is_DAG_dfs(const int &v)
    {
        used[v] = true;
        for (int u : out_ribs[v])
            if (used[u] || is_DAG_dfs(u) == false)
                return false;
        return true;
    }

public:
    explicit Kahn(): size(0){}
    explicit Kahn(const int &size): size(size)
    {
        used.resize(size);
        out_ribs.resize(size);
        in_ribs.resize(size);
    }

    void input_conn_list(std::istream &input)
    {
        int q_ribs; input >> q_ribs;
        for (int i = 0, v, u; i < q_ribs; ++i)
        {
            input >> v >> u; --v; --u;

            out_ribs[v].push_back(u);
        }
    }

    void form_in_ribs()
    {
        for (int &power : in_ribs)
            power = 0;
        for (int v = 0; v < out_ribs.size(); ++v)
            for (const int &u : out_ribs[v])
                ++in_ribs[u];
    }

    bool is_DAG()
    {
        set_not_used();
        return is_DAG_dfs(0);
    }

    std::vector<int> topology_sort()
    {
        form_in_ribs();

        std::vector<int> topology;
        std::queue<int> q;

        for (int v = 0; v < size; ++v)
            if (in_ribs[v] == 0)
                q.push(v);

        while (q.empty() == false)
        {
            int v = q.front(); q.pop();

            topology.push_back(v);
            for (int u : out_ribs[v])
            {
                --in_ribs[u];
                if (in_ribs[u] == 0)
                    q.push(u);
            }
        }

        return topology;
    }
};

#endif //DEN_BOD_ART_PROG_KAHN_H
