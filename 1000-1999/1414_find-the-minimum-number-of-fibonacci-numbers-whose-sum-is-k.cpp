//Link: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ 
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        set<long long> m;
        m.insert(1);m.insert(2);
        long long a = 1, b = 2, c =3;
        while(c < 1000000000) {
            c = a + b;
            m.insert(c);
            a = b;
            b = c;
        }
        int cnt = 0;
        while(k > 0) {
            auto it = m.upper_bound(k);
            --it;
            k -= *it;
            ++cnt;
        }
        return cnt;
    }
};