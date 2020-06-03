//Link: https://leetcode.com/problems/maximum-students-taking-exam/ 
class Solution {
public:
    map< unsigned long long, int> dp;
    int m;
    int n;
    
    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size();
        n = seats[0].size();
        return max(h(seats, 0, 1), h(seats, n-1, -1));
    }
    
    int h(vector<vector<char>>& seats, int y, int b) {
        if( y < 0) return 0;
        if(y >= n) return 0;
        static int d[6][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0,  1}, {1, -1}, {1, 1}};
        int res = 0;
        for(int i  = 0; i <m; ++i) {
            if(seats[i][y] == '#') continue;
            bool f = true;
            for(int j = 0; j < 6; ++j) {
                int nx = i + d[j][0];
                int ny = y + d[j][1];
                if(nx <0 || ny <0 || nx >= m ||ny >= n) continue;
                if(seats[nx][ny] == 'S') {
                    f = false;
                    break;
                }
            }
            if(f == false) continue;
            ++res;
            seats[i][y] = 'S';
        }
        
        res += h(seats, y +b, b);
        for(int i  = 0; i <m; ++i) {
            if(seats[i][y] == 'S')
                seats[i][y] = '.';
        }
        return max(res, h(seats, y + b, b));
    }
};