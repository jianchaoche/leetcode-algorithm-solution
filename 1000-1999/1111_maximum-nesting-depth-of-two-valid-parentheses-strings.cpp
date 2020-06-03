//Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/ 
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int md = 0, d = 0;
        for(char c : seq) {
            if( c== '(')
                ++d;
            else
                --d;
            md = max(md, d);
        }
        vector<int> ans;
        d = 0;
        int hd = md/2;
        for(auto c : seq) {
            if( c =='('){
                if(d < md/2 ){
                    ans.push_back(0);
                }else
                    ans.push_back(1);
                ++d;
            }else{
                --d;
                if(d < md/2 ){
                    ans.push_back(0);
                }else
                    ans.push_back(1);
                
            }
        }
        return ans;
    }
};