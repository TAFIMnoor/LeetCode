class Solution {
public:
    string getSmallestString(int n, int k) {
        int ans[n], size = n;
        for(int i = 0; i < n; i++) { ans[i] = 1; k--;}
        while(--n >=0 && k){
            if(k>=25)
                ans[n] += 25, k -=25;
            else
                ans[n] += k, k = 0;
        }
        string s ="";
        for(int i = 0; i < size; i++){
            s += (char) ( ans[i]+96);
        }
        return s;
    }
};
