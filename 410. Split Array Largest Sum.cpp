class Solution {
public:
    int findMinimum( vector<int>& nums, int m ,int mid) {
        int add = 0,cnt = 1;
        
        for(int i = 0; i < nums.size(); i++){
            add += nums[i];
            if( add > mid ){
                cnt++, add = nums[i];
            }
        }
        
        return cnt <= m ;
    }
    
    int splitArray(vector<int>& nums, int m) {

        long long int sum = 0;
        int low = 0, ans;
        for(int i = 0; i < nums.size(); i++){
           sum += nums[i];
            low = max(low, nums[i]);
        }
        if( m == nums.size() ) return low;
        
        while( low <= sum ){
            int mid = low + (sum-low)/2;
            if( findMinimum(nums, m, mid) ){
                ans = mid;
                sum = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};
