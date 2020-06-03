//Link: https://leetcode.com/problems/01-matrix/ 
class Solution {
public:
    int m; 
    int n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0 ) return matrix;
        m = matrix[0].size();
        if( m == 0 )return matrix;
        vector<vector<int>> visit( n, vector<int>(m,0));
        int x = 0,y =0;
        queue<pair<int,int>> q;
        for( int i = 0; i<n; i++){
            for( int j = 0; j<m; j++ ){
                if(matrix[i][j] == 0 ){
                    //solve(i, j, matrix, visit);
                    q.push({i,j});
                }else{
                    matrix[i][j] = 10000000;
                }
            }
        }
        while(!q.empty() ){
            static int dx[] = {1,0, -1, 0};
            static int dy[] = {0, 1, 0, -1};
            auto &point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;
            if( visit[x][y] > 0) continue;
            int distance = 10000000;
            for( int i = 0; i<4;i++){
                int mx = x + dx[i];
                int my = y + dy[i];
                if( mx>=0 && my>=0 && mx<n && my<m  ){
                    distance = min(matrix[mx][my], distance);
                    if( visit[mx][my] == 0 )
                        q.push({mx,  my});
                }
            }
            visit[x][y] = 1;
            distance += 1;
            if( matrix[x][y] > 0 )
                matrix[x][y] = distance;
        }
        return matrix;
    }/*
    void solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& visit){
        if( visit[x][y] >0 ) return;
        static int dx[] = {1,0, -1, 0};
        static int dy[] = {0, 1, 0, -1};
        int distance = 1000000;
        map<int, int> point;
        for( int i = 0; i<4;i++){
                int mx = x + dx[i];
                int my = y + dy[i];
                if( mx>=0 && my>=0 && mx<n && my<m && visit[x][y] == 0 ){
                    distance = min(matrix[mx][my], distance);
                    visit[x][y] = 1;
                    point[mx] = my;
                }
            }
        distance += 1;
        if(matrix[x][y]>0)
            matrix[x][y] = distance;
        for(auto& it:point){
            solve(it.first, it.second,matrix, visit);
        }
    }*/
};