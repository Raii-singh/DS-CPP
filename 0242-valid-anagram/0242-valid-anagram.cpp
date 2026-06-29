class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sans;
        unordered_map<char,int> tans;

        for(int x: s) sans[x]++;
        for(int x: t) tans[x]++;

        if(sans == tans) return true;
        return false;
    }
};