** Approach 1 : **

class Solution {
public:
    void makePerm(vector<int>& perm, int t,int index,int k, vector<string>& permutations){
        string s = "";
        if( t == perm.size() ){
            for(int i = 0; i < perm.size(); i++)
                s += (perm[i] + '0');
            permutations.push_back(s);
            return;
        }
        for(int i = index; i < perm.size(); i++){
            swap(perm[index], perm[i]);
            makePerm(perm, t+1, index+1, k, permutations);
            swap(perm[index], perm[i]);
        }
    }
    string getPermutation(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<int> perm;
        vector<string> permutations;
        for(int i = 1; i <=n; i++){
            perm.push_back(i);
        }
        makePerm(perm,0,0,k,permutations);
        sort(permutations.begin(), permutations.end());
        return permutations[k-1];
    }
};
