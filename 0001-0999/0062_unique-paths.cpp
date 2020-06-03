//Link: https://leetcode.com/problems/unique-paths/ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        memset(f, 0, sizeof(f));
        for( int i = 0 ; i < m; i++)
        {
            f[i][0] = 1;
            f[i][n-1] = 1;
        }
        for( int i = 0 ; i < n; i++)
        {
            f[0][i] = 1;
            f[m-1][i] = 1;
        }
        for( int i =1; i< m ; i++)
        {
            for( int j =1; j< n ; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};