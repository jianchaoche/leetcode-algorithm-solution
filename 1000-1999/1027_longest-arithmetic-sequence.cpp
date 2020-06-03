//Link: https://leetcode.com/problems/longest-arithmetic-sequence/ 
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() <= 0) return A.size();
        vector<unordered_map<int, int> > m(A.size());
        int ans = 1;
        for(int i = 0; i < A.size(); ++i) {
            int a = A[i];
            for(int j = 0; j < i; ++j) {
                int b = A[j];
                int diff = a - b;
                if(m[j].count(diff))
                    m[i][diff] = max(m[i][diff], 1 + m[j][diff]);
                else
                    m[i][diff] = 2;
                ans = max(ans, m[i][diff]);
            }
        }
        return ans;
    }
};