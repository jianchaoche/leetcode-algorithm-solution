//Link: https://leetcode.com/problems/burst-balloons/ 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[nums.size()+1][nums.size()+1]={0};
        for( int len = 1; len<=n; len++ ){
            for( int i = 1; i<=n-len+1; i++){
                int j = i+len-1;
                for( int k = i; k<=j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+ nums[i-1]*nums[k]*nums[j+1]+dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
        
    }
};