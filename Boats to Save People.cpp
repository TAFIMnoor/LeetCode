class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int j = people.size() -1, i = 0, ans = 0;
        sort(people.begin(), people.end());
        while( i <= j ){
            if( people[i]+people[j] <= limit) i++;
            --j,ans++;
        }
        return ans;
    }
};
