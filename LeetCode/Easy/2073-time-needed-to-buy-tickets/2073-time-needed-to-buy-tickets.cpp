class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for(int i = 0; i < tickets.size(); i++){
            q.push({tickets[i], i});
        }
        int time = 0;
        while(1){
            pair<int,int> temp = q.front();
            temp.first--;
            if(temp.first != 0) q.push(temp);
            time++;
            if(temp.first == 0 && temp.second == k) return time;
            q.pop();
        }
        return time;
    }
};