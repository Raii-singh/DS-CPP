class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        for(int i = 0; i < numRows; i++){
            vector<int> in;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) in.push_back(1);

                else{
                    in.push_back(out[i-1][j-1] + out[i-1][j]);
                }
            }
            out.push_back(in);
        }
        return out;
    }
};