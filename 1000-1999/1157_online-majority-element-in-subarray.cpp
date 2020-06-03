//Link: https://leetcode.com/problems/online-majority-element-in-subarray/ 


class MajorityChecker {
public:
    map<int, unordered_map<int, vector<int> > > freq;
    MajorityChecker(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int n : arr)
            ++m[n];
        for(int i = 0; i < arr.size(); ++i){
            int n = arr[i];
            freq[m[n]][n].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int res = -1;
        auto it = freq.lower_bound(threshold);
        while(it != freq.end()){
            for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
                int num = it2->first;
                auto &vec = it2->second;
                if(upper_bound(vec.begin(), vec.end(), right) - lower_bound(vec.begin(), vec.end(), left) >= threshold)
                    return num;
            }
            ++it;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */