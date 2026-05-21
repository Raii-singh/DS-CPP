class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            bool ans = false;
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] == nums[j] && i != j){
                    ans = true;
                }
            }
            if(ans == false) return nums[i];
        }
        return -1;
    }
};