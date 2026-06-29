class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> missing;
        vector<int> ans;

        for(int x: nums){
            missing[x]++;
 
        }
        for(int i = 1; i <= nums.size(); i++){
            if(missing[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};