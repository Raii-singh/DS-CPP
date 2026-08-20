class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int x: nums){
            mp[x]++;
        }

        auto cmp = [](pair<int, int>&a, pair<int,int>&b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto x: mp){
            pq.push({x.first, x.second});
        }

        while(k){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};