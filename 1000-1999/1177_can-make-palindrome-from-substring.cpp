//Link: https://leetcode.com/problems/can-make-palindrome-from-substring/ 
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int> > arr(256);
        for(int i = 0; i < s.size(); ++i) {
            arr[s[i]].push_back(i);
        }
        for(auto &q : queries) {
            int i = q[0], j = q[1], k = q[2];
            int diff = 0;
            for(int c = 'a'; c <='z'; ++c) {
                int b = lower_bound(arr[c].begin(), arr[c].end(), i) - arr[c].begin();
                int e = upper_bound(arr[c].begin(), arr[c].end(), j) - arr[c].begin();
                diff += (e - b) % 2;
            }
            ans.push_back(diff/2 <= k);
        }
        return ans;
    }
};