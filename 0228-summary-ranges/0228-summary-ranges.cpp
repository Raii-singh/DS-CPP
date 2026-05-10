class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i  = 0;
        vector<string> ans;

        while(i < nums.size()){
            int temp = i;

            while(i+1 < nums.size() && nums[i + 1] == nums[i] + 1){
                i++;
            }

            if(temp == i){
                ans.push_back(to_string(nums[i]));
            }

            else{
                ans.push_back(to_string(nums[temp]) + "->" + to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};