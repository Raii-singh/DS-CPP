class Solution {
public:
    string makeGood(string s) {
        if(s.size() == 0) return s;
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && (tolower(st.top()) == tolower(s[i]))){
                if(st.top() == s[i]) st.push(s[i]);

                else st.pop();
            }
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};