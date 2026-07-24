class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); i++){
            // if(operations[i] == "0" || 
            // operations[i] == "1" || 
            // operations[i] == "2" || 
            // operations[i] == "3" || 
            // operations[i] == "4" || 
            // operations[i] == "5" || 
            // operations[i] == "6" || 
            // operations[i] == "7" || 
            // operations[i] == "8" || 
            // operations[i] == "9"){

            //     st.push(operations[i]);
            // }
            if(operations[i] == "+"){
                int temp = st.top();
                st.pop();
                int sum = temp + st.top();
                st.push(temp);
                st.push(sum);
            }
            else if(operations[i] == "D"){
                int temp = st.top() * 2;
                st.push(temp);
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else{
                int temp = stoi(operations[i]);
                st.push(temp);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};