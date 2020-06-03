//Link: https://leetcode.com/problems/sliding-puzzle/ 

class Solution {
public:
    int hash(vector<vector<int> > &b) {
        int mask = 0;
        for(int i = 0; i < b.size(); ++i)
            for(int j = 0; j < b[0].size(); ++j)
                mask |= (b[i][j] << ((i * 3 + j) * 4) );
        return mask;
    }
    pair<int, int> getZero(vector<vector<int> > &b) {
        for(int i = 0; i < b.size(); ++i)
            for(int j = 0; j < b[0].size(); ++j)
                if(b[i][j] == 0) return {i, j};
        return {-111, -111};
    }
    bool check(vector<vector<int> > &b) {
        return b[0][0] == 1 && b[0][1] == 2 && b[0][2] == 3 && b[1][0] == 4 && b[1][1] == 5 && b[1][2] == 0;
    }
    unordered_set<int> v;
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int> > > q;
        q.push(board);
        v.insert(hash(board));
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto &b = q.front();
                if(check(b)) return step;
                auto point = getZero(b);
                int x = point.first;
                int y = point.second;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= b.size() || ny >=b[0].size())
                        continue;
                    swap(b[x][y], b[nx][ny]);
                    int h = hash(b);
                    if(v.count(h) == 0){
                        q.push(b);
                        v.insert(h);
                    }
                    swap(b[x][y], b[nx][ny]);
                }
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};