//Link: https://leetcode.com/problems/last-substring-in-lexicographical-order/ 
class Solution {
public:
    string lastSubstring(string s) {
        int mc = 0;
        for(int c : s)
            mc = max(c, mc);
        int prev = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == mc) {
                int idx = i;
                while(i + 1 < s.size() && s[i+1] == s[i])
                    ++i;
                if(prev == -1){
                    prev = idx;
                    continue;
                }
                for(int k = 0; k < s.size() - idx; ++k){
                    if(s[prev+k] > s[idx + k]){
                        break;
                    }
                    else if(s[prev+k] < s[idx + k]){
                        prev = idx;
                        break;
                    }
                }
            }
        }
        return s.substr(prev);
    }
};