class Solution {
public:
    void fx(int idx, vector<int>& candidates, vector<int>& sub, vector<vector<int>>& dom, int target){
        if(target < 0 || idx == candidates.size()) return;
        if(target == 0){
            dom.push_back(sub);
            return;
        }

        sub.push_back(candidates[idx]);
        fx(idx, candidates, sub, dom, target - candidates[idx]);
        
        sub.pop_back();
        fx(idx + 1, candidates, sub, dom, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> dom;

        fx(0, candidates, sub, dom, target);
        return dom;
    }
};