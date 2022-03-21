class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        map<char,int> mapp;
        for(int i = s.size()-1; i >= 0; i--){
            if( mapp[s[i]] == 0 )
                mapp[s[i]] = i+1;
        }
        
        vector<int> ans;
        for(int i = 0, prev = 0; i < s.size(); i++){
            int n = mapp[s[i]];
            for(int j = i; j < n; j++){
                n = max(n, mapp[s[j]]);
            }
            ans.push_back(n-prev);
            i = n-1, prev = n;
        }
        
        return ans;
    }
    
};
