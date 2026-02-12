class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1; // at least 1 character is balanced

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (isBalanced(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    bool isBalanced(vector<int>& freq) {
        int target = 0;

        for (int x : freq) {
            if (x == 0) continue;

            if (target == 0) {
                target = x;
            } else if (x != target) {
                return false;
            }
        }

        return true;
    }
};
