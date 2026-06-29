class Solution {
public:
    int strStr(string haystack, string needle) {
        for(char i = 0; i < haystack.length(); i++){
            int a = 0;
            while(a < needle.length() && haystack[i + a] == needle[a]) a++;
            if(a == needle.length()) return i;
        }

        return -1;
    }
};