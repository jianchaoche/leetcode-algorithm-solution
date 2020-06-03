//Link: https://leetcode.com/problems/tweet-counts-per-frequency/ 
class TweetCounts {
public:
    TweetCounts() {
        
    }
    unordered_map<string, map<int, int > > m;
    void recordTweet(string tweetName, int time) {
        m[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = 0;
        if(freq == "minute") interval = 60;
        else if(freq == "hour") interval = 3600;
        else if(freq == "day") interval = 3600 * 24;
        const auto &it = m.find(tweetName);
        vector<int> ans((endTime-startTime) /  interval +  1);
        if(it == m.end()) return ans;
        auto sit = it->second.lower_bound(startTime);
        int idx = 0;
        while(startTime <= endTime) {
            int ed = min(endTime, startTime + interval - 1);
            while(sit != it->second.end() && sit->first >= startTime && sit->first <= ed) {
                ans[idx] += sit->second;
                ++sit;
            }
            ++idx;
            startTime = ed + 1;
            if(sit == it->second.end()) break;
        }
        return ans;
    }
};
