//Link: https://leetcode.com/problems/implement-strstr/ 
//"aabaaabaaac"
//"aabaaac"
class Solution {
public:
    int strStr1(string haystack, string needle) {
        if( haystack.size() < needle.size() ) return -1;
        if( needle.size() == 0 ){
            return 0;
        }
        vector<int> prefix(needle.size());
        build_prefix(needle, prefix);
        int i = 0, j = 0;
        while( i < haystack.size() ){
            if( haystack[i] == needle[j])i++,j++;
            else{
                j = prefix[j];
                if( j < 0 )i++,j++;
            }
            if( j == needle.size() )
                return i-needle.size();
        }
        return -1;
    }
    void build_prefix(string &pattern, vector<int> &prefix){
        prefix[0] = 0;
        int len = 0;
        int i = 1;
        while(i < pattern.size()){
            if( pattern[len] == pattern[i])
                prefix[i++] = ++len;
            else{
                if( len > 0 )
                    len = prefix[len-1];
                else
                    prefix[i++] = len; 
            }
        }
        for( int i = pattern.size()-1; i>0; i-- )
            prefix[i] = prefix[i-1];
        prefix[0] = -1;
        //for( int i = 0; i<prefix.size(); i++){
            //cout<<prefix[i]<<" ";
        //}
    }
    int strStr(string haystack, string needle) {
        if( haystack.size() < needle.size() ) return -1;
        if( needle.size() == 0 ){
            return 0;
        }
        auto pre = computeLPS(needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); ++i) {
            while(j > 0 && haystack[i] != needle[j]) j = pre[j-1];
            if(haystack[i] == needle[j]) ++j;
            if(j == needle.size()) return i - j + 1;
        }
        return -1;
    }
    vector<int> computeLPS(string& str) { // Longest Prefix also Suffix
        int n = str.size();
        vector<int> lps = vector<int>(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && str[i] != str[j]) j = lps[j - 1];
            if (str[i] == str[j]) lps[i] = ++j;
        }
        return lps;
    }
};