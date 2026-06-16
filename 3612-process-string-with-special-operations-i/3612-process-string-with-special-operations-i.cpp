class Solution {
public:
    string processStr(string s) {
        string result;
      
        // Iterate through each character in the input string
        for (char c : s) {
            // If character is alphabetic, append it to result
            if (isalpha(c)) {
                result += c;
            } 
            // If character is '*', remove the last character from result
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            // If character is '#', duplicate the current result string
            else if (c == '#') {
                result += result;
            } 
            // If character is '%', reverse the entire result string
            else if (c == '%') {
                std::reverse(result.begin(), result.end());
            }
        }
      
        return result;
    }
};