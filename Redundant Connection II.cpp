class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        vector<int> parent(2001, -1);
        vector<int> can1, can2;
        for(auto &edge : edges)
        {
            if(parent[edge[1]] == -1)
                parent[edge[1]] = edge[0];
            else
            {
                can1 = {parent[edge[1]], edge[1]};
                can2 = edge;
                edge[1] = 0;
            }
        }
        for(int i=1; i<2001; i++)
            parent[i] = i;
        for(auto &edge : edges)
        {
            if(edge[1] == 0)
                continue;
            if(unionFind(parent, edge[0]) == edge[1])
            {
                if(can1.empty())
                    return edge;
                return can1;
            }
            parent[edge[1]] = edge[0];
        }
        return can2;
    }
    int unionFind(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = unionFind(parent, parent[x]);
    }
};
