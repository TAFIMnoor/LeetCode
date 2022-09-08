class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> path;
        queue<vector<int>> q;
        q.push({0});
        int n = graph.size()-1;
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int next = cur[cur.size()-1];
            if(next == n){
                path.push_back(cur);
            }
            for(auto it:graph[next]){
                cur.push_back(it);
                q.push(cur);
                cur.pop_back();
            }
        }
        
        return path;
    }
};
