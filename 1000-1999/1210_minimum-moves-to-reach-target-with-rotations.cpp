//Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ 
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        q.push({0, 0, 0, 1});
        set<vector<int>> v;
        v.insert({0, 0, 0, 1});
        int n = grid.size();
        int step = 0;
        int d[3] = {0, 1, 0};
        while(q.size()){
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                int x0 = p[0], y0 = p[1], x1 = p[2], y1 = p[3];
                q.pop();
                if(x0 == n- 1 && y0 == n - 2 && x1 == n - 1 && y1 == n - 1){
                    return step;
                }
                for(int i = 0; i < 2; ++i) {
                    int nx = x0 + d[i];
                    int ny = y0 + d[i + 1];
                    int nx1 = x1 + d[i];
                    int ny1 = y1 + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >=n || ny >= n || grid[nx][ny] == 1) continue;
                    if(nx1 < 0 || ny1 < 0 || nx1 >=n || ny1 >= n || grid[nx1][ny1] == 1) continue;
                    auto np = {nx, ny, nx1, ny1};
                    if(v.count(np)) continue;
                    v.insert(np);
                    q.push(np);
                }
                if(x1 > x0 && y0 + 1 < n && grid[x0][y0+1] == 0 && grid[x1][y0+1] == 0) {
                    x1 = x0;
                    y1 = y0 + 1;
                }else if(y1 > y0 && x0 + 1 < n && grid[x0 + 1][y0] == 0 && grid[x0+1][y1] == 0) {
                    x1 = x0 + 1;
                    y1 = y0;
                }
                auto np = {x0, y0, x1, y1};
                if(v.count(np) == 0){
                    q.push(np);
                    v.insert(np);
                }
            }
            ++step;
        }
        return -1;
    }
};