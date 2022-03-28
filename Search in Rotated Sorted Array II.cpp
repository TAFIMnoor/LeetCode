class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        if( nums.size() == 1 ){
            return nums[0] == target;
        }
        
        int l = 0, r = nums.size()-1;
        
        while( l<= r ){
            int m = l + (r-l)/2;
            
            if( nums[m] == target )
                return true;
            
            if( nums[l] == nums[m] && nums[m] == nums[r] ) {
                    l++,r--;
            }
            else if( nums[l] <= nums[m] ) {
                if( nums[l] <= target && nums[m] > target )
                    r = m - 1;
                else
                    l = m + 1;
            } 
            else {
                if( nums[r] >= target && nums[m] < target )
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return false;
        
    }
};

