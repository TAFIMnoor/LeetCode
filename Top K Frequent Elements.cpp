class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        map<int,int> m;
        for(auto n: nums)
            m[n]++;
        
        priority_queue<pair<int,int>> pq;
        for( const auto& [key, value]: m ){
            pq.push({value,key});
        }
        
        k = pq.size() - k;
        
        vector<int> ans;
        while( pq.size() > k ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
