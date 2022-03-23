class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int ans = 0;
        while( startValue < target ){
            ans += target % 2, target += target % 2;
            target >>= 1;
            ans++;
        }
     
        return ans + (startValue - target);
    }
};
