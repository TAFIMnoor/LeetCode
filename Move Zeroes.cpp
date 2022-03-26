class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if( nums.empty() || nums.size() == 1 )
            return;
        
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] == 0 ) { j++; continue; }
            nums[i-j] = nums[i];
            if ( j ) 
                nums[i] = 0;
        }
        
    }
};
