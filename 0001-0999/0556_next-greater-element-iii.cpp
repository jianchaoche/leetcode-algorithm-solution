//Link: https://leetcode.com/problems/next-greater-element-iii/ 
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        map<int, int> m;
        for(int i = s.size() - 1; i>=0; --i) {
            int c = s[i];
            auto it = m.upper_bound(c);
            m[c] = i;
            if(it == m.end()) continue;
            swap(s[i], s[it->second]);
            sort(s.begin()+i + 1, s.end());
            return stoll(s) > INT_MAX ? -1 : stoi(s);
        }
        return -1;
    }
};