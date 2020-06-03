//Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ 
class Solution {
public:
    int minSteps(string s, string t) {
        map<int, int>m;
        for(auto c :s)
            ++m[c];
        for(auto c :t)
            --m[c];
        int ans = 0;
        for(auto &[a, b] :m) {
            ans += abs(b);
        }
        return ans / 2;
    }
};