//Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, pair<int, int> > > m;
    int mctFromLeafValues(vector<int>& arr) {
        return helper(arr, 0, arr.size()-1).first;
    }
    
    pair<int, int> helper(vector<int>& arr, int i, int j){
        if( i == j)
            return { 0, arr[i] };
        if( j - i == 1)
            return { arr[i] * arr[j], max(arr[i], arr[j]) };
        if(m[i].count(j)) return m[i][j];
        int ans = INT_MAX;
        int leaf = 0;
        for(int k = 0; k < j - i; ++k){
            auto r1 = helper(arr, i, i + k);
            auto r2 = helper(arr, i + k + 1, j);
            int tmp = r1.second * r2.second;
            ans = min(r1.first + r2.first + tmp, ans);
            leaf = max(r1.second, r2.second);
        }
        m[i][j] = {ans, leaf};
        return {ans, leaf};
    }
};