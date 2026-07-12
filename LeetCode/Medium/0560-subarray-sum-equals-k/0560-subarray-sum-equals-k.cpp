class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i] += sum;
            sum = nums[i];
        }
        unordered_map<int,int> mp;

        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            int need = nums[i] - k;
            if(mp[need]){
                count += mp[need];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};