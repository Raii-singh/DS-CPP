class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = 0;
        int t1 = 0;

        if(s.size() > t.size()) return false;
        if(t.size() == 1 && s[0] != t[0]) return false;
        if(s.size() == 0) return true;

        while(s1 < s.size() && t1 < t.size()){
            if(t[t1] == s[s1]){
                s1++;
            }
            t1++;
        } 
        if(s1 == s.size()) return true;
        return false;
    }
};