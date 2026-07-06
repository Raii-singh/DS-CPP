class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int avg = 0;
        for(int i = 0; i < k; i++){
            avg += arr[i];
        }
        if(avg/k >= threshold) count++;

        for(int i = k; i < arr.size(); i++){
            avg -= arr[i - k];
            avg += arr[i];

            if(avg/k >= threshold) count++; 
        }
        return count;
    }
};