class Solution {
public:

    void fx(int idx,vector<int>& nums, vector<int>& sub, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        fx(idx+1, nums, sub, ans);

        sub.pop_back();
        fx(idx+1, nums, sub, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;

        fx(0, nums, sub, ans);
        return ans;
    }
};