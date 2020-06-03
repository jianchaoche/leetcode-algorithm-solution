//Link: https://leetcode.com/problems/lexicographical-numbers/ 
class Solution {
public:
    vector<int> ans;
    int n;
    vector<int> lexicalOrder(int _n) {
        n = _n;
        for(int i =1; i <=9; ++i) {
            dfs(i);
        }
        return ans;
    }
    
    void dfs(int num) {
        if(num > n) return;
        ans.push_back(num);
        for(int i = 0; i <=9; ++i) {
            dfs(num * 10 + i);
        }
    }
};