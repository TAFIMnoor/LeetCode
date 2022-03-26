class Solution {
public:
    string reverseWords(string s) {
        
        for(int i = 0, j = 0; i < s.size(); i++){
            if( s[i] == ' ' || i+1 == s.size()){
               int n = (i - j + 1)/2;
               int k = ( i+1 == s.size() ? i : i-1 );
               while( n-- ){
                   swap(s[j++],s[k--]);
               }
               j = i+1;
            }
        }
        return s;
    }
};
