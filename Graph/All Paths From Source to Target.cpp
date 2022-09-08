class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> path;
        queue<vector<int>> q;
        q.push({0});
        int n = graph.size()-1;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto next = graph[cur[cur.size()-1]];
            for(int i = 0; i < next.size(); i++){
                auto p = cur;
                p.push_back(next[i]);
                if(next[i] == n)
                    path.push_back(p);
                else
                    q.push(p);
            }
        }
        
        return path;
    }
};
