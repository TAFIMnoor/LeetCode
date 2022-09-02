class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<int> ans(n+1,0);
        vector<int> g[n+1];
        
        for(int i = 0; i < paths.size(); i++){
            g[paths[i][0]].push_back(paths[i][1]);
            g[paths[i][1]].push_back(paths[i][0]);
        }
        
        for(int j = 1; j <= n; j++){
            if(ans[j] == 0){
                ans[j] = 1;
                queue<int> q;
                q.push(j);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(auto it:g[u]){
                        if(ans[it] == 0 || ans[it] == ans[u]){
                            ans[it] = ans[u]+1;
                            q.push(it);
                        }
                        if(ans[it] > 4)  ans[it] %= 4; 
                    }
                }
            }
        }
        
        ans.erase(ans.begin());
        
        return ans;
    }
};
