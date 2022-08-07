class Solution {
public:
    
    bool isPalin(string st)
    {
        for(int i=0;i<st.size()/2;i++)
        {
            if(st[i]!=st[st.size()-1-i])
                return false;
        }
        return true;
    }
    
    void check(vector<vector<string>>& ans, int pos, vector<string>& vec, string s){
       
        if(pos >= s.size()) {
            ans.push_back(vec);
            return;
        }
        string t = "";
        
        for(int i = pos; i < s.size(); i++){
            t+=s[i];
            if(isPalin(t))
            {
                vec.push_back(t);
                check(ans,i+1,vec,s);
                vec.pop_back();
            }
        }
       
    }
    vector<vector<string>> partition(string s) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<vector<string>> ans;
        vector<string> vec;
        
        check(ans,0,vec,s);
        
        return ans;
        
    }
};
