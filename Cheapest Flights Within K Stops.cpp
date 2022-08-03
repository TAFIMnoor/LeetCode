class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        vector<pair<int,int>> g[n];
        for(auto x:flights){
            g[x[0]].push_back({x[1],x[2]});
        }
        
        vector<int> cost(n,INT_MAX), level(n,0);
        queue<vector<int>> q;
        cost[src] = 0;
        q.push({src,0,0});
        
        while(!q.empty()){
            vector<int> x = q.front();
            int u = x[0], step = x[1], costB = x[2];
            q.pop();
            for(auto it: g[u]){
                if(costB+it.second < cost[it.first] && step <= k){
                    cost[it.first] = costB + it.second;
                    q.push({it.first,step+1,cost[it.first]});
                }
            }
        }
        
        if(cost[dst] == INT_MAX) return -1;
        else return cost[dst];
    }
};
