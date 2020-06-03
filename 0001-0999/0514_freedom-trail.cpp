//Link: https://leetcode.com/problems/freedom-trail/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > dp;
    int findRotateSteps(string ring, string key) {
        return dfs(ring, key, 0, 0);
    }
    
    int dfs(string &ring, string &key, int i, int j) {
        if(j == key.size())
            return 0;
        if (dp[i].count(j))
            return dp[i][j];
        int res = INT_MAX;
        for(int k = 0; k < ring.size(); ++k) {
            if(ring[k] == key[j]) {
                int diff = min(abs(i - k), min((int)ring.size() - k + i, (int)ring.size() - i + k)) + 1;
                res = min(res, dfs(ring, key, k, j+1) + diff);
            }
        }
        dp[i][j] = res;
        return res;
    }
};