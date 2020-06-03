//Link: https://leetcode.com/problems/largest-1-bordered-square/ 
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto row = grid;
        auto col = grid;
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    ++ans;
                if(grid[i][j] > 0) {
                    row[i][j] += (j > 0 ? row[i][j-1] : 0);
                    col[i][j] += (i > 0 ? col[i-1][j] : 0);
                }
            }
        }
        
        for(auto v : row){
            for(auto n : v)
                cout<< n <<" ";
            cout<<endl;
        }
        cout<<endl;
        for(auto v : col){
            for(auto n : v)
                cout<< n <<" ";
            cout<<endl;
        }
        if(ans <= 1) return ans;
        ans = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0)
                    continue;
                for(int k = 1; k <min(m, n); ++k){
                    
                    if(i +k >= m) continue;
                    if(j +k >= n) continue;
                    int ru = row[i][j+k];
                    int cr = col[i+k][j];
                    int cl = col[i+k][j+k];
                    int rd = row[i+k][j+k];
                    if(ru >= k && cr >=k && cl >=k && rd >=k )
                        ans = max(ans, (k+1) *(k+1));
                }
            }
        }
        return ans;
    }
};