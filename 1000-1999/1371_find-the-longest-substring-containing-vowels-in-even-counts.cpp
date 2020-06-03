//Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ 
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> m, prefix;
        m['a'] = 0;m['i'] = 0;m['e'] = 0;m['o'] = 0;m['u'] = 0;
        prefix[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(m.count(c)){
                sum ^= c;
            }
            if(prefix.count(sum)) {
                ans = max(ans, i - prefix[sum]);
            }else
                prefix[sum] = i;
            
        }
        return ans;
    }
};