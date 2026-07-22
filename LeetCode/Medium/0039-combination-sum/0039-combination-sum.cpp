class Solution {
public:
    void fx(int idx, vector<int>& nums, vector<vector<int>>& ans
    , vector<int> candidates, int target){
        if(target < 0 || idx == candidates.size()) return;
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        nums.push_back(candidates[idx]);
        fx(idx, nums, ans, candidates, target - candidates[idx]);

        nums.pop_back();
        fx(idx + 1, nums, ans, candidates, target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        fx(0, nums, ans, candidates, target);
        return ans;
    }
};