//Link: https://leetcode.com/problems/majority-element-ii/ 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        int n1 = -1, n2= -1, c1 = 0, c2 = 0;
        for(auto n : nums) {
            if(n1 == n){
                ++c1;
            }
            else if(n2 == n)
                ++c2;
            else if(c1 == 0){
                c1 = 1;
                n1 = n;
            }else if(c2 == 0) {
                c2 = 1;
                n2 = n;
            }else{
                --c1;
                --c2;
            }
        }
        c1 = 0, c2 = 0;
        for(int n : nums )
            if(n == n1)
                ++c1;
            else if(n == n2)
                ++c2;
        if(c2 > nums.size()/3 && c1 >nums.size()/3)
            return {n1,n2};
        if(c1 > nums.size()/3)
            return {n1};
        else if(c2 > nums.size()/3)
            return {n2};
        return {};
    }
};