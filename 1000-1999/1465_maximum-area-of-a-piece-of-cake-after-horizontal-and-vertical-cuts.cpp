//Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/ 
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long c = 0, r = 0;
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i = 1; i < horizontalCuts.size(); ++i) {
            r = max(r, (long long)(horizontalCuts[i] - horizontalCuts[i-1]));
        }
        for(int i = 1; i < verticalCuts.size(); ++i) {
            c = max(c, (long long)(verticalCuts[i] - verticalCuts[i-1]));
        }
        return (r * c) % 1000000007;
    }
};