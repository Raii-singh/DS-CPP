class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int x: stones){
            pq.push(x);
        }
        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();

            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            if(one == two) continue;
            else{
                one = one - two;
                pq.push(one);
            }
        }
        return 0;
    }
};