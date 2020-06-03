//Link: https://leetcode.com/problems/exam-room/ 
class ExamRoom {
public:
    set<int> s;
    int N;
    ExamRoom(int N):N(N) {
    }
    
    int seat() {
        if( s.size() == 0 ){
            s.insert(0);
            return 0;
        }
        else if(s.size() == N )
            return -1;
        else{
            int ans = -1;
            int dis = -1;
            if( *s.begin() != 0 ){
                ans = 0;
                dis = *s.begin();
            }
            
            
            int prev = *s.begin();
            
            auto it = s.begin();
            it++;
            for( ; it!=s.end(); ++it){
                int i = *it;
                int val = (i-prev)/2;
                if( (val+prev) != i && val > dis ){
                    ans = val+prev;
                    dis = val;
                }
                prev = i;
            }
            if( *s.rbegin() != N-1){
                if( N-1-*s.rbegin() > dis ){
                    ans = N-1;
                    dis = N-1-*s.rbegin();
                }
            }
            s.insert(ans);
            return ans;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */