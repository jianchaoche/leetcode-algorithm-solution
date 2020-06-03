//Link: https://leetcode.com/problems/palindromic-substrings/ 
class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        if( size <= 1 ) return size;
        
        int ans = 0;
        /*
        bool P[s.size()+1][s.size()+1] = {0};
        for( int i = size-1; i>=0; i-- ){
            for( int j = i; j<size; j++){
                if( s[i] == s[j] && ( j-i <=1 || P[i+1][j-1]) ){
                    P[i][j] = true;
                    ans++;
                }
            }
        }*/
        for(int i = 0; i < s.size(); ++i) {
            ++ans;
            int l = i - 1, r = i + 1;
            while(l >=0 && r < s.size() && s[l--] == s[r++] ) {
                ++ans;
            }
            l = i - 1, r = i;
            while(l >=0 && r < s.size() && s[l--] == s[r++] ) {
                ++ans;
            }
        }
        return ans;
    }
};