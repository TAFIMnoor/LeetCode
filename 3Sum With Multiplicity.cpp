class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int mod = 1e9+7, ans = 0;
        int map[101] = {};
        
        for(auto n: arr)
            map[n]++;
        
        for(int i = 0; i <= 100; i++){
            
            for( int j = i+1; j <= 100; j++ ){
                
                for( int k = j+1; k <= 100; k++ ){
                    
                    if( i+k+j == target && map[i] && map[j] && map[k] ){
                        int val = ( map[i] * map[j] * map[k]);
                        ans = ( ans + val ) % mod;
                    }
                    
                }
                
                if( i+i+j == target && map[i] > 1 && map[j] ){
                    int val = (map[i] * (map[i]-1)) / 2;
                    ans =  ( ans + val * map[j] ) % mod;
                }
                if( i+j+j == target && map[i] && map[j] > 1 ){
                    int val = (map[j] * (map[j]-1)) / 2;
                    ans =  ( ans + map[i] * val ) % mod;
                }
                
            }
            
            if( i*3 == target && map[i] > 2 ) {
                long long int val = map[i] * (map[i]-1);
                val = ( val * (map[i]-2)/6 ) % mod;
                ans = ( ans + val ) % mod;
            }
            
        }
        
        return ans;
    }
};
