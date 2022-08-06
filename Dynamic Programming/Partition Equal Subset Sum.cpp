class Solution {
    vector<vector<int>> dp;
public:
    bool subset(vector<int>& nums, int n, int target){
        
        if(target == 0) return true;
        if(n<=0 || target<0) return false;
        
        if( dp[n][target] != -1 ) return dp[n][target];
        
        if( nums[n] > target)
            return dp[n][target] = subset(nums,n-1,target);
        else
            return dp[n][target] = subset(nums,n-1,target) || subset(nums,n-1,target-nums[n]);
        
    }
    bool canPartition(vector<int>& nums) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        
        if( sum&1 || nums.size()==1 ) return false;
        
        sum /=2 ;
        dp.resize(nums.size()+1,vector<int>(sum+1, -1));
        
        if(subset(nums,nums.size()-1,sum)){
            return true;
        }
        return false;
    }
};
