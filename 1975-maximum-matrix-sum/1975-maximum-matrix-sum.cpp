class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // Initialize sum of absolute values
        long long totalSum = 0;
      
        // Track the minimum absolute value and count of negative numbers
        int minAbsValue = INT_MAX;
        int negativeCount = 0;
      
        // Iterate through each row in the matrix
        for (const auto& row : matrix) {
            // Process each element in the current row
            for (int value : row) {
                // Count negative numbers
                if (value < 0) {
                    negativeCount++;
                }
              
                // Get absolute value of current element
                int absValue = abs(value);
              
                // Update minimum absolute value seen so far
                minAbsValue = min(minAbsValue, absValue);
              
                // Add absolute value to total sum
                totalSum += absValue;
            }
        }
      
        // If even number of negatives, all can be made positive
        // If odd number of negatives, one must remain negative (choose the smallest)
        if (negativeCount % 2 == 0) {
            return totalSum;
        } else {
            // Subtract twice the minimum to account for it being negative instead of positive
            return totalSum - 2 * minAbsValue;
        }
    }
};