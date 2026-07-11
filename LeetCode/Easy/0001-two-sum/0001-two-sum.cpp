class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> temp;

        for(int i = 0; i < nums.size(); i++){
            int num = target - nums[i];

            if(temp.count(num)) return {temp[num], i};

            temp[nums[i]] = i;
        }
        return{};
    }
};