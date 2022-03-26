class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans; 
        for(int i = 0, j = numbers.size() - 1; i < j;  ){
            if( numbers[i] + numbers[j] == target ){
                ans = {i+1,j+1};
                break;
            }
            if( numbers[i] + numbers[j] < target ) { i++; }
            if( numbers[i] + numbers[j] > target ) { j--; }
        }
        return ans;
    }
};
