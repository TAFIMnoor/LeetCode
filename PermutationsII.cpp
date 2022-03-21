class Solution {
public:
    void makePerm(vector<vector<int>>& ans, vector<int>& nums, int index){
       if(index == nums.size()){
            ans.push_back(nums);
           return;
       }
        map<int,int> mapp;
        for(int i = index; i < nums.size(); i++){
            if(mapp[nums[i]] == 0){
                swap(nums[index],nums[i]);
                makePerm(ans,nums,index+1);
                swap(nums[index],nums[i]);
                mapp[nums[i]]++;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        makePerm(ans,nums,0);
        return ans;
    }
};
