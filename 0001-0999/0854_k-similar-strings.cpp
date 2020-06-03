//Link: https://leetcode.com/problems/k-similar-strings/ 
class Solution {
public:
    int kSimilarity(string A, string B) {
        unordered_set<string> v;
        queue<string> q;
        q.push(A);
        v.insert(A);
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto s = q.front();
                q.pop();
                if(s == B)
                    return step;
                for(int i = 0; i < s.size(); ++i) {
                    if(s[i] == B[i]) continue;
                    for(int j = i + 1; j < B.size(); ++j){
                        if(s[i] == B[j] ) {
                            swap(s[i], s[j]);
                            if(v.count(s) == 0){
                                q.push(s);
                                v.insert(s);
                            }
                            swap(s[i], s[j]);
                        }
                    }
                    break;
                }
            }
            ++step;
        }
        return step;
    }
};