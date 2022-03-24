// ** Approach : Recursion **

class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int t){
        if( r >= l ) {
            
            int m = l + (r-l)/2;
        
            if( nums[m] == t ) 
                return m;
            if( nums[m] > t )
                return binarySearch(nums, l, m-1, t);
            if( nums[m] < t )
                 return binarySearch(nums, m+1, r, t);
            
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ans = binarySearch(nums, 0, nums.size() -1, target);
        return ans;
    }
};

// ** Approach : Loop **

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while( l <= r ){
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            if( nums[m] > target )
                r = m - 1;
            if( nums[m] < target )
                l = m + 1;
        }
        
        return -1;
    }
};
