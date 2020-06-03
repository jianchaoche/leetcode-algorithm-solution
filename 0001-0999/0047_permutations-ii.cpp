//Link: https://leetcode.com/problems/permutations-ii/ 
class Solution {
public:
    void build(vector<vector<int>>& ans, vector<int>& nums, vector<int>& item){
        if( item.size() == nums.size() ){
            ans.push_back(item);
            return;
        }
        int prev = INT_MIN;
        for( int &n:nums){
            if( n == prev)
                continue;
            prev = n;
            if( n > INT_MIN ){
                int tmp = n;
                item.push_back(n);
                n=INT_MIN;
                build(ans, nums, item);
                item.pop_back();
                n=tmp;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> item;
        build(ans, nums, item);
        return ans;
    }
};