#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Prefix arrays
        vector<long long> prefix_val(m + 1, 0); // Stores numerical value of non-zero prefixes
        vector<int> prefix_sum(m + 1, 0);       // Stores sum of digits
        vector<int> prefix_count(m + 1, 0);     // Stores count of non-zero digits
        
        // Precomputing powers of 10 modulo 10^9 + 7
        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }
        
        // Step 1: Preprocess the string
        for (int i = 0; i < m; i++) {
            prefix_val[i + 1] = prefix_val[i];
            prefix_sum[i + 1] = prefix_sum[i];
            prefix_count[i + 1] = prefix_count[i];
            
            if (s[i] != '0') {
                int digit = s[i] - '0';
                prefix_val[i + 1] = (prefix_val[i] * 10 + digit) % MOD;
                prefix_sum[i + 1] += digit;
                prefix_count[i + 1] += 1;
            }
        }
        
        // Step 2: Answer queries in O(1) time each
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Total sum of non-zero digits in range
            long long current_sum = prefix_sum[r + 1] - prefix_sum[l];
            
            // Count of non-zero digits in range
            int non_zero_count = prefix_count[r + 1] - prefix_count[l];
            
            // Compute the concatenated value x using prefix math
            long long x = (prefix_val[r + 1] - (prefix_val[l] * power10[non_zero_count]) % MOD + MOD) % MOD;
            
            // Calculate final answer for the query
            long long query_ans = (x * current_sum) % MOD;
            answer.push_back(query_ans);
        }
        
        return answer;
    }
};
