//Link: https://leetcode.com/problems/repeated-substring-pattern/ 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i <= s.size()/2; ++i) {
            if(s.size() % i) continue;
            bool f = true;
            for(int j = i; j < s.size(); ++j) {
                if(s[j] != s[j % i]) {
                    f = false;
                    break;
                }
            }
            if(f) return true;
        }
        return false;
    }
};