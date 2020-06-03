//Link: https://leetcode.com/problems/mini-parser/ 
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 1;
        if (s[0] == '[')
            return solve(s, i);
        i = 0;
        return solve(s, i);
    }
    NestedInteger solve(string s, int &i) {
        NestedInteger integer;
        int num = 0, sign = 1;
        bool isNum = false;
        for (; i < s.size(); ++i) {
            char c = s[i];
            if (c == '[') {
                sign = 1;
                num = 0,
                i++;
                isNum = false;
                integer.add(solve(s, i));
            }else if (c == ']') {
                if (isNum)
                    integer.add(NestedInteger(num * sign));
                isNum = false;
                return integer;
            }else if (c == ',') {
                if (isNum)
                    integer.add(NestedInteger(num * sign));
                num = 0;
                sign = 1;
                isNum = false;
            }else if (c == '-')
                sign = -1;
            else {
                isNum = true;
                num = num * 10 + (c-'0');
            }
        }
        integer.setInteger(num*sign);
        return integer;
    }
};