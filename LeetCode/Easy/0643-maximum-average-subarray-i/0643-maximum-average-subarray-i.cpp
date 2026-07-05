class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int winval = 0;
        for(int i = 0; i < k; i++){
            winval += nums[i];
        }
        int maxval = winval;
        for(int i = k; i < nums.size(); i++){
            winval += nums[i];
            winval -= nums[i-k];
            maxval = max(maxval, winval);
        }
        return (double)maxval/k;
    }
};