//Link: https://leetcode.com/problems/reverse-pairs/ 
struct BIT{
    vector<int> nums;
    BIT(int size) : nums(size){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<long long> s;
        for(long long num : nums) {
            s.insert(num);
            s.insert(num*2);
        }
        map<long long, long long> m;
        int rank = 1;
        for(auto n : s) {
            m[n] = rank++;
        }
        int ans = 0;
        BIT bit(s.size() + 10);
        for(int i = nums.size()-1; i >= 0; --i){
            int r1 = m[nums[i]];
            int r2 = m[2*(long long)nums[i]];
            ans += bit.query(r1-1);
            bit.update(r2, 1);
        }
        return ans;
    }
};