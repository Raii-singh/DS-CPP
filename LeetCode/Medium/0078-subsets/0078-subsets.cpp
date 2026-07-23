class Solution {
public:
    void fx(int idx, vector<int>& nums, vector<int>& sub, vector<vector<int>>& dom){

        if(idx == nums.size()){
            dom.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        fx(idx + 1, nums, sub, dom);

        sub.pop_back();
        fx(idx + 1, nums, sub, dom);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> dom;

        fx(0, nums, sub, dom); 
        return dom;       
    }
};