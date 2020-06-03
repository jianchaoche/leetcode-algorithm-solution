//Link: https://leetcode.com/problems/base-7/ 
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int s = num < 0 ? -1 : 1;
        num = abs(num);
        string ans;
        while(num > 0) {
            ans += num % 7 + '0';
            num /= 7;
        }
        if(s < 0) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};