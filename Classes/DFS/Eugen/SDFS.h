#ifndef DEN_BOD_ART_PROG_SDFS_H
#define DEN_BOD_ART_PROG_SDFS_H

#include <iostream>
#include <vector>

#endif //DEN_BOD_ART_PROG_SDFS_H

class SDFS
{
private:
    int size;
    std::vector<std::vector<int>> ribs;
    std::vector<bool> used;

    void dfs(const int &par, const int &v)
    {
        used[v] = true;
        for (const int u : ribs[v])
            if (u != par && used[u] == false)
                dfs(v, u);
    }

public:
    SDFS():size(0){}
    explicit SDFS(const int size):size(size)
    {
        this->ribs.resize(size);
        this->used.resize(size);
    }

    void input_adj_matrix(std::istream &input)
    {
        for (int i = 0, is_rib; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                input >> is_rib;
                if (is_rib)
                    ribs[i].push_back(j);
            }
    }

    int count_connectivity_components()
    {
        int cnt = 0;
        for (int i = 0; i < size; ++i)
            if (used[i] == false)
            {
                dfs(i,i);
                ++cnt;
            }
        return cnt;
    }
};
