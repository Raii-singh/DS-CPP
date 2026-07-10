class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<int, int> ss;
        unordered_map<int, int> tt;

        for(int x: s){
            ss[x]++;
        }
        for(int x: t){
            tt[x]++;
        }

        for(int i = 0; i < ss.size(); i++){
            if(ss[i] == tt[i]) continue;
            else return false;
        }
        return true;
    }
};