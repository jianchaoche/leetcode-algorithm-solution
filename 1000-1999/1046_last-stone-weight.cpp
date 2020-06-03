//Link: https://leetcode.com/problems/last-stone-weight/ 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s : stones)
            pq.push(s);
        while(pq.size() > 1 ){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a - b != 0)
                pq.push(abs(a-b));
        }
        return pq.size() ? pq.top(): 0;
    }
};