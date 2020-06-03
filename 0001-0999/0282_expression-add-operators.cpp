//Link: https://leetcode.com/problems/expression-add-operators/ 
class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        vector<pair<int, int> > items;
        solve(num, 0, target, 0, items);
        return ans;
    }
    
    void solve(string &str, int total, int target, int idx, vector<pair<int, int> > &items) {
        if (idx == str.size()) {
            if (target == total) {
                string s;
                for (int i = 0; i < items.size(); i++) {
                    auto &item = items[i];
                    s += to_string(item.first);
                    if (i < items.size() - 1) 
                        s.push_back(items[i+1].second);
                }
                ans.push_back(s);
            }
            return;
        }
        long long sum = 0;
        for (int i = idx; i < str.size(); ++i) {
            sum = sum * 10 + (str[i] - '0');
            if (sum > INT_MAX)
                break;
            items.push_back({sum, '+'});
            solve(str, total + sum, target, i+1, items);
            items.pop_back();
            if (items.size() > 0) {
                items.push_back({sum, '-'});
                solve(str, total - sum, target, i+1, items);
                items.pop_back();
                int prev = 1;
                for (int j = items.size()-1; j>=0; --j) {
                    prev *= items[j].first;
                    if (items[j].second == '-'){
                        prev *= -1;
                    }
                    if (items[j].second != '*')
                        break;
                }
                items.push_back({sum, '*'});
                solve(str, total - prev + prev * sum, target, i+1, items);
                items.pop_back();
            }
            if (sum == 0)
                break;
        }
    }
};