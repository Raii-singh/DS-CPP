class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int test=0;
        for(int val : nums){
            test ^=val;

        }
        return test;
    }
};