class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        char mid_char = '\0';
        int odd_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                mid_char = 'a' + i;
                odd_count++;
            }
            count[i] /= 2; // Keep only half counts for permutation
        }

        // Impossible to form any palindrome
        if (odd_count > 1) return "";

        int half_len = 0;
        for (int i = 0; i < 26; ++i) half_len += count[i];

        // Safe combinations calculator (nCr) that caps at 2e18 to prevent overflow
        auto nCr = [](int n, int r) {
            if (r < 0 || r > n) return 0LL;
            if (r == 0 || r == n) return 1LL;
            if (r > n - r) r = n - r;
            long long res = 1;
            for (int i = 1; i <= r; ++i) {
                // Check potential overflow before multiplying
                if (res > 2000000000000000000LL / (n - i + 1)) {
                    return 2000000000000000000LL;
                }
                res = res * (n - i + 1) / i;
            }
            return res;
        };

        // Multi-set permutation counting using safe nCr calculations
        auto count_perms = [&](const vector<int>& cnt) {
            int total = 0;
            for (int i = 0; i < 26; ++i) total += cnt[i];
            
            long long res = 1;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                long long combinations = nCr(total, cnt[i]);
                
                // Safe multiplication check
                if (combinations == 2000000000000000000LL || res > 2000000000000000000LL / combinations) {
                    return 2000000000000000000LL;
                }
                res *= combinations;
                total -= cnt[i];
            }
            return res;
        };

        // Early exit if k exceeds maximum total possible permutations
        if ((long long)k > count_perms(count)) return "";

        string half = "";
        long long target_k = k;

        for (int i = 0; i < half_len; ++i) {
            bool placed = false;
            for (int c = 0; c < 26; ++c) {
                if (count[c] == 0) continue;
                
                count[c]--; // Try placing character c
                long long total = count_perms(count);
                
                if (target_k <= total) {
                    half += ('a' + c);
                    placed = true;
                    break; // Move to the next position
                } else {
                    target_k -= total;
                    count[c]++; // Revert choices
                }
            }
            if (!placed) return "";
        }

        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        
        if (mid_char != '\0') {
            return half + mid_char + rev_half;
        }
        return half + rev_half;
    }
};
