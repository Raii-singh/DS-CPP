class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0;
        int zero = 0;
        for(int x: students){
            if(x == 0) zero++;
            else one++;
        }
        for(int i = 0; i < sandwiches.size(); i++){
            if(sandwiches[i] == 0) zero--;
            else one--;

            if(zero < 0 || one < 0){
                return sandwiches.size() - i;
            }
        }
        return 0;
    }
};