class Solution {
public:

    void fx(vector<string>& mp, string digits,int index, string output, vector<string>&ans){
        if(index == digits.size()){
            ans.push_back(output);
            return;
        }
        string letters = mp[digits[index] - '2'];
        for(char c: letters){
            output.push_back(c);
            fx(mp,digits, index+1, output, ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};
        vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        vector<string> ans;
        string output;
        fx(mp, digits, 0,output ,ans);
        return ans;
    }
};