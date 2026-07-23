class Solution {
public:
    void fx(int idx, vector<int>& sub, vector<vector<int>>& dom, vector<int>& candidates, int target){
        if(target == 0){
            dom.push_back(sub);
            return;
        }
        if(target < 0 || idx == candidates.size()) return;

        sub.push_back(candidates[idx]);
        fx(idx + 1, sub, dom, candidates, target - candidates[idx]);

        sub.pop_back();
        while(idx + 1 < candidates.size() && candidates[idx] == candidates[idx+1]){
            idx++;
        }        
        fx(idx + 1, sub, dom, candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> dom;
        sort(candidates.begin(), candidates.end());
        fx(0, sub, dom, candidates, target);
        return dom;
    }
};