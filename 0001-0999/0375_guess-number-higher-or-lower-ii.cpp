//Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/ 
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n+1, vector<int>(n+1));
        return solve(1, n, dp);
    }
    unordered_map<int, int> m;
    int solve(int l, int r, vector<vector<int> > &dp){
        if( l >= r ) return 0;
        if(dp[l][r]) return dp[l][r];
        int ans = INT_MAX;
        for( int i = l; i<=r; i++){
            ans = min(ans, i + max(solve(l, i-1, dp), solve(i+1, r, dp) ) );
        }
        dp[l][r] = ans;
        return ans;
    }
};