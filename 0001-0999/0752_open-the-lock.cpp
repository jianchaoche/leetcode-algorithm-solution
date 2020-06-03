//Link: https://leetcode.com/problems/open-the-lock/ 
class Solution {
public:
    unordered_set<string> visited;
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        string start = "0000";
        if( start == target ) return 0;
        if( deadset.count(start) ) return -1;
        unordered_set<string> visited = {start};
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(q.size()){
            int size = q.size();
            ans++;
            while(size-->0){
                string str = q.front();
                
                for( auto &c:str){
                    char src = c;
                    for( int i = -1; i<=1; i+=2){
                        c = ((c + i + 10-'0')%10) + '0';
                        if( str == target )
                            return ans;
                        if( !visited.count(str) && !deadset.count(str) ) {
                            q.push(str);
                            visited.insert(str);
                        }
                        c = src;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};