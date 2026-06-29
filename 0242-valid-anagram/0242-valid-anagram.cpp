class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> sans;
        unordered_map<char,int> tans;

        for(int x: s) sans[x]++;
        for(int x: t) tans[x]++;

        return (sans == tans);
    }
};