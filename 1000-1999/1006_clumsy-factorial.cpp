//Link: https://leetcode.com/problems/clumsy-factorial/ 
class Solution {
public:
    int clumsy(int N) {
        int ans = 0, sign = 1;
        for(int i = N; i >= 1; i-=4) {
            int b = i - 1 > 0 ? i - 1 : 1;
            int c = i - 2 > 0 ? i - 2 : 1;
            int d = i - 3 > 0 ? i - 3 :0;
            ans += sign * i * b / c + d;
            sign = -1;
        }
        return ans;
    }
};