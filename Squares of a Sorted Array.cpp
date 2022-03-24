// ** Approach : 1 **
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int j = -1;
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] < 0 ) 
                j = i;
            else {
                while( j >=0 && abs(nums[j]) <= nums[i] ) {
                    ans.push_back(nums[j]*nums[j]);
                    j--;
                }
                ans.push_back(nums[i]*nums[i]);
            }
        }
        while( j >=0 ) {
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        return ans;
    }
};

// ** Approach : 2 **

class Solution {
public:
    // static bool compare(int a, int b){
    //     return abs(a)<abs(b);
    // }
    vector<int> sortedSquares(vector<int>& nums) {
        //sort(nums.begin(), nums.end(), compare);
        sort(nums.begin(), nums.end(), [&] (int a, int b){
            return abs(a)<abs(b);
        });
        
        for(int i = 0; i < nums.size(); i++)
            nums[i] *= nums[i];
        
        return nums;
    }
};
