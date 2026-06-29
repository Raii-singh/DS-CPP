class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> maxcount;

        for(int x: nums){
            maxcount[x]++;
               
            if(maxcount[x] > nums.size()/2) return x;
        }

        return -1;
    }
};