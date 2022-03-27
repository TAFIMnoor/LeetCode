class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> mapp;
        
        for(int i = 0; i < mat.size(); i++){
            int one = 0;
            for(int j = 0; j < mat[i].size(); j++)
                if( mat[i][j] ) one++;
            mapp[one].push_back(i);
        }
        
        vector<int> ans;
        for(auto pair : mapp){
            for( auto val : pair.second ){
                ans.push_back(val), k--;
                if( !k ) return ans;
            }
        }
        
        return ans;
    }
};
