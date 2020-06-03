//Link: https://leetcode.com/problems/arithmetic-slices/ 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, cnt = 0;
        for( int i = 2; i<A.size(); i++){
            if( A[i] - A[i-1] == A[i-1] - A[i-2]){
                cnt += 1;
                ans += cnt;
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};