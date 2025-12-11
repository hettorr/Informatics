#ifndef DEN_BOD_ART_PROG_KAHN_H
#define DEN_BOD_ART_PROG_KAHN_H

#include <iostream>
#include <vector>
#include <queue>

class Kahn
{
private:
    enum COLOR
    {
        WHITE, GRAY, BLACK
    };

    int size;
    std::vector<COLOR> used;
    std::vector<int> in_ribs;
    std::vector<std::vector<int>> out_ribs;

    void set_not_used()
    {
        for (int i = 0; i < size; ++i)
            used[i] = WHITE;
    }

    bool is_DAG_dfs(const int &v)
    {
        used[v] = GRAY;
        for (const int &u : out_ribs[v])
            if (used[u] == GRAY || (used[u] == WHITE && is_DAG_dfs(u) == false))
                return false;
        used[v] = BLACK;
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

    void input_adj_matrix(std::istream &input)
    {
        bool is_rib;
        for (int v = 0; v < size; ++v)
            for (int u = 0; u < size; ++u)
            {
                input >> is_rib;
                if (is_rib)
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
        form_in_ribs();
        set_not_used();

        for (int i = 0; i < size; ++i)
            if (in_ribs[i] == 0 && is_DAG_dfs(i) == false)
                return false;
        for (int i = 0; i < size; ++i)
            if (used[i] != BLACK)
                return false;

        return true;
    }

    std::vector<int> topology_sort()
    {
        form_in_ribs();
        set_not_used();

        std::vector<int> topology;
        std::queue<int> q;

        for (int v = 0; v < size; ++v)
            if (in_ribs[v] == 0)
                q.push(v);

        while (q.empty() == false)
        {
            int v = q.front(); q.pop();
            used[v] = BLACK;

            topology.push_back(v);
            for (int u : out_ribs[v])
            {
                --in_ribs[u];
                if (in_ribs[u] == 0 && used[u] == WHITE)
                    q.push(u);
            }
        }

        return topology;
    }
};

#endif //DEN_BOD_ART_PROG_KAHN_H
