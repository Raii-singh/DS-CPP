#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    // Helper to calculate the minimum number of digits needed to satisfy the prime factor counts
    int getMinDigitsNeeded(int f2, int f3, int f5, int f7) {
        int min_d = 1e9;
        for (int cnt8 = 0; cnt8 <= f2 / 3 + 1; ++cnt8) {
            for (int cnt9 = 0; cnt9 <= f3 / 2 + 1; ++cnt9) {
                int rem2 = max(0, f2 - cnt8 * 3);
                int rem3 = max(0, f3 - cnt9 * 2);
                for (int cnt6 = 0; cnt6 <= min(rem2, rem3); ++cnt6) {
                    int r2 = rem2 - cnt6;
                    int r3 = rem3 - cnt6;
                    int cnt4 = r2 / 2;
                    int cnt2 = r2 % 2;
                    int cnt3 = r3;
                    
                    int tot = cnt8 + cnt9 + cnt6 + cnt4 + cnt2 + cnt3;
                    min_d = min(min_d, tot);
                }
            }
        }
        return min_d + f5 + f7;
    }

    // Helper to generate the lexicographically smallest sorted suffix string for a set of required factors
    string getBestSuffix(int req2, int req3, int req5, int req7, int rem_len) {
        string best_suffix = "";
        
        for (int cnt8 = 0; cnt8 <= req2 / 3 + 1; ++cnt8) {
            for (int cnt9 = 0; cnt9 <= req3 / 2 + 1; ++cnt9) {
                int rem2 = max(0, req2 - cnt8 * 3);
                int rem3 = max(0, req3 - cnt9 * 2);
                for (int cnt6 = 0; cnt6 <= min(rem2, rem3); ++cnt6) {
                    int r2 = rem2 - cnt6;
                    int r3 = rem3 - cnt6;
                    int cnt4 = r2 / 2;
                    int cnt2 = r2 % 2;
                    int cnt3 = r3;
                    
                    int tot = cnt8 + cnt9 + cnt6 + cnt4 + cnt2 + cnt3 + req5 + req7;
                    if (tot <= rem_len) {
                        string current_suffix = "";
                        current_suffix.append(cnt2, '2');
                        current_suffix.append(cnt3, '3');
                        current_suffix.append(cnt4, '4');
                        current_suffix.append(req5, '5');
                        current_suffix.append(cnt6, '6');
                        current_suffix.append(req7, '7');
                        current_suffix.append(cnt8, '8');
                        current_suffix.append(cnt9, '9');
                        
                        int ones_needed = rem_len - current_suffix.length();
                        current_suffix.append(ones_needed, '1');
                        sort(current_suffix.begin(), current_suffix.end());
                        
                        if (best_suffix.empty() || current_suffix < best_suffix) {
                            best_suffix = current_suffix;
                        }
                    }
                }
            }
        }
        return best_suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> factors(10, 0);
        vector<int> primes = {2, 3, 5, 7};
        for (int p : primes) {
            while (t % p == 0) {
                factors[p]++;
                t /= p;
            }
        }
        if (t > 1) return "-1"; 

        int n = num.length();
        vector<vector<int>> digit_factors(10, vector<int>(10, 0));
        for (int d = 1; d <= 9; ++d) {
            int temp = d;
            for (int p : primes) {
                while (temp % p == 0) {
                    digit_factors[d][p]++;
                    temp /= p;
                }
            }
        }

        int limit = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                limit = i;
                break;
            }
        }

        vector<vector<int>> pref_f(n + 1, vector<int>(10, 0));
        for (int i = 0; i < limit; ++i) {
            int d = num[i] - '0';
            for (int p : primes) {
                pref_f[i + 1][p] = pref_f[i][p] + digit_factors[d][p];
            }
        }

        if (limit == n) {
            if (max(0, factors[2] - pref_f[n][2]) == 0 &&
                max(0, factors[3] - pref_f[n][3]) == 0 &&
                max(0, factors[5] - pref_f[n][5]) == 0 &&
                max(0, factors[7] - pref_f[n][7]) == 0) {
                return num;
            }
        }

        for (int i = limit; i >= 0; --i) {
            if (i == n) continue;
            int rem_len = n - 1 - i;
            int start_d = (i < limit) ? (num[i] - '0' + 1) : 1;
            
            for (int d = start_d; d <= 9; ++d) {
                int req2 = max(0, factors[2] - (pref_f[i][2] + digit_factors[d][2]));
                int req3 = max(0, factors[3] - (pref_f[i][3] + digit_factors[d][3]));
                int req5 = max(0, factors[5] - (pref_f[i][5] + digit_factors[d][5]));
                int req7 = max(0, factors[7] - (pref_f[i][7] + digit_factors[d][7]));
                
                if (getMinDigitsNeeded(req2, req3, req5, req7) <= rem_len) {
                    string ans = num.substr(0, i) + to_string(d);
                    string suffix = getBestSuffix(req2, req3, req5, req7, rem_len);
                    return ans + suffix;
                }
            }
        }

        // Expand length to n + 1 or more
        int min_len = getMinDigitsNeeded(factors[2], factors[3], factors[5], factors[7]);
        int target_len = max(n + 1, min_len);
        return getBestSuffix(factors[2], factors[3], factors[5], factors[7], target_len);
    }
};
