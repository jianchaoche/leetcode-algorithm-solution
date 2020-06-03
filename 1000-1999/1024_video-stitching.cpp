//Link: https://leetcode.com/problems/video-stitching/ 
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(T+1, 1000);
        dp[0] = 0;
        for(int i = 0; i < clips.size(); ++i) {
            int end = clips[i][1];
            end = (end > T ? T : end);
            for(int j = clips[i][0]; j <= end; ++j) {
                dp[end] = min(dp[end], dp[j] + 1);
            }
        }
        return dp[T] >= 1000 ? -1 : dp[T];
    }
};