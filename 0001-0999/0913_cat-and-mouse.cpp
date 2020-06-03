//Link: https://leetcode.com/problems/cat-and-mouse/ 
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(2 * n, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(graph, 0, 1, 2, dp);
    }
    int helper(vector<vector<int>>& graph, int t, int x, int y, vector<vector<vector<int>>>& dp) {
        if (t == graph.size() * 2) return 0;
        if (x == y) return dp[t][x][y] = 2;
        if (x == 0) return dp[t][x][y] = 1;
        if (dp[t][x][y] != -1) return dp[t][x][y];
        bool mouseTurn = (t % 2 == 0);
        if (mouseTurn) {
            bool catWin = true;
            for (int i = 0; i < graph[x].size(); ++i) {
                int next = helper(graph, t + 1, graph[x][i], y, dp);
                if (next == 1) return dp[t][x][y] = 1;
                else if (next != 2) catWin = false;
            }
            if (catWin) return dp[t][x][y] = 2;
            else return dp[t][x][y] = 0;
        } else {
            bool mouseWin = true;
            for (int i = 0; i < graph[y].size(); ++i) {
                if (graph[y][i] == 0) continue;
                int next = helper(graph, t + 1, x, graph[y][i], dp);
                if (next == 2) return dp[t][x][y] = 2;
                else if (next != 1) mouseWin = false;
            }
            if (mouseWin) return dp[t][x][y] = 1;
            else return dp[t][x][y] = 0;
        }
    }
};