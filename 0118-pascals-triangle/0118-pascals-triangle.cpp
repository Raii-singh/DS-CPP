class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> row;
        for(int i = 0; i < numRows; i++){
            vector<int> col;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    col.push_back(1);
                }else{
                    col.push_back(row[i-1][j-1] + row[i-1][j]);
                }
            }
            row.push_back(col);
            cout<<endl;
        }
        return row;
    }

};