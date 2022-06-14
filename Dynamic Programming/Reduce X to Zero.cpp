class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        int sum[nums.size()], ans = INT_MAX;
        map<int,int> m;
        sum[0] = nums[0], m[sum[0]] = 1;
        if( sum[0] == x ) return 1;
        
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i-1]+nums[i];
            m[sum[i]] = i+1;
            if( sum[i] == x ) ans = i+1;
            if( nums[i] == x ) return 1;
        }
        
        if( sum[nums.size()-1] < x ) return -1;
        
        nums.push_back(0);
        
        for(int i = nums.size()-2, cnt = 0; i >= 0; i--){
            nums[i] += nums[i+1], cnt++;
            if( m[x-nums[i]] )
                ans = min(ans, m[x-nums[i]] + cnt);
            if( x == nums[i] )
                ans = min(ans,cnt);
        }
        
        if( ans == INT_MAX ) return -1;
        else return ans;
    }
};
