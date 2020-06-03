//Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/ 
struct BIT {
    vector<int> sums;
    BIT(int n) : sums(n+1){}
    void update(int n, int c) {
        while(n < sums.size()) {
            sums[n] += c;
            n += lowbit(n);
        }
    }
    
    int query(int n) {
        int s = 0;
        while(n>0) {
            s += sums[n];
            n -= lowbit(n);
        }
        return s;
    }
    int lowbit(int x) { return x & -x;}
    
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> m;
        BIT bit(s.size());
        vector<int> ans;
        int rank = 1;
        for(int n : s){
            m[n] = rank++;
        }
        for(int i = nums.size() - 1; i >= 0; --i) {
            int n = nums[i];
            ans.push_back(bit.query(m[n] - 1));
            bit.update(m[n], 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};