//Link: https://leetcode.com/problems/construct-k-palindrome-strings/ 
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        map<int, int> m;
        for(auto c : s)
            ++m[c];
        int cnt = 0;
        for(auto it : m) {
            if(it.second % 2)
                ++cnt;
        }
        return cnt <= k;
    }
};