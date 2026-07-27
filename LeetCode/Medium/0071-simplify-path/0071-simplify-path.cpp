class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i < path.length()){
            while(i < path.length() && path[i] == '/') i++;

            string temp = "";
            while(i < path.length() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == "") continue;
            else if(temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }
        vector<string>dir;
        while(!st.empty()){
            dir.push_back(st.top());
            st.pop();
        }
        reverse(dir.begin(), dir.end());
        string ans;
        for(string x: dir){
            ans += "/";
            ans += x;
        }
        if(ans.empty()) return "/";
        return ans;        
    }
};