class Solution {
public:
    void fx(int i, vector<int>& nums, vector<int>& sub, vector<vector<int>>& dom){
        if(i == nums.size()){
            dom.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        fx(i + 1, nums,sub,dom);
        while(i + 1 != nums.size() && nums[i] == nums[i+1]) i++;
        sub.pop_back();
        fx(i + 1, nums,sub,dom);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> dom;
        sort(nums.begin(), nums.end());
        fx(0, nums, sub, dom);
        return dom;
    }
};