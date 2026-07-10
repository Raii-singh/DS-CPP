class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<int, int> freq;

        for(int x: s){
            freq[x]++;
        }
        for(int x: t){
            freq[x]--;
        }

        for(auto x: freq){
            if(x.second != 0) return false;
        }
        return true;
    }
};