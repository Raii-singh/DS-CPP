class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxtemp = 0;

        for(int i = 0; i < k; i++){
            maxtemp += nums[i];
        }
        int maxval = maxtemp;
        for(int i  = k; i < nums.size(); i++){
            maxtemp -= nums[i -k];
            maxtemp += nums[i];

            maxval = max(maxval, maxtemp);
        }
        return (double)maxval/k;
    }
};