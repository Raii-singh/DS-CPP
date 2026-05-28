#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to find the better index based on the rules
    inline int get_best(int i, int j, const vector<string>& wordsContainer) {
        if (i == -1) return j;
        if (wordsContainer[i].length() < wordsContainer[j].length()) return i;
        if (wordsContainer[j].length() < wordsContainer[i].length()) return j;
        return min(i, j);
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Find global best index for empty suffix fallback
        int root_idx = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            root_idx = get_best(root_idx, i, wordsContainer);
        }

        // Flat Trie arrays to avoid object allocation overhead
        // next_node[curr_node][char] = child_node_index
        vector<vector<int>> next_node;
        vector<int> best_idx;

        // Create the root node (node 0)
        next_node.push_back(vector<int>(26, -1));
        best_idx.push_back(root_idx);

        // Build the Trie with reversed words
        for (int idx = 0; idx < wordsContainer.size(); ++idx) {
            int curr = 0; // Start at root node
            const string& word = wordsContainer[idx];
            
            best_idx[curr] = get_best(best_idx[curr], idx, wordsContainer);

            // Traverse the string backwards
            for (int i = word.length() - 1; i >= 0; --i) {
                int char_idx = word[i] - 'a';
                
                if (next_node[curr][char_idx] == -1) {
                    // Create a new node by adding tracking fields to our vectors
                    next_node[curr][char_idx] = next_node.size();
                    next_node.push_back(vector<int>(26, -1));
                    best_idx.push_back(idx);
                }
                
                curr = next_node[curr][char_idx];
                best_idx[curr] = get_best(best_idx[curr], idx, wordsContainer);
            }
        }

        // Process each query
        vector<int> ans;
        ans.reserve(wordsQuery.size()); // Reserve memory to prevent reallocations
        
        for (const string& query : wordsQuery) {
            int curr = 0; // Start at root node
            for (int i = query.length() - 1; i >= 0; --i) {
                int char_idx = query[i] - 'a';
                if (next_node[curr][char_idx] != -1) {
                    curr = next_node[curr][char_idx];
                } else {
                    break; // Suffix match breaks here
                }
            }
            ans.push_back(best_idx[curr]);
        }

        return ans;
    }
};