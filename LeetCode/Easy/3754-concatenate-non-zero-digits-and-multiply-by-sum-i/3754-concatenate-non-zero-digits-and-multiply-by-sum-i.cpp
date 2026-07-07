class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x = 0;
        long long sum = 0;
        
        // Extract non-zero digits and compute their sum simultaneously
        for (char c : s) {
            if (c != '0') {
                int digit = c - '0';
                x = x * 10 + digit;
                sum += digit;
            }
        }
        
        // Return x * sum
        return x * sum;
    }
};
