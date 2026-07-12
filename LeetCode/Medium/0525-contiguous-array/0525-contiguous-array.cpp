class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int length = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) nums[i] = -1;
            nums[i] += sum;
            sum = nums[i];
        }
        unordered_map<int ,int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            
            if(mp.count(nums[i])) maxi = max(maxi, i - mp[nums[i]]);
            
            else mp[nums[i]] = i;
        }
        return maxi;
    }
};