//Link: https://leetcode.com/problems/insert-delete-getrandom-o1/ 
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    set<int> data;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( data.find(val) != data.end() )
            return false;
        data.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(  data.find(val) != data.end() )
        {
            data.erase(val);
            return true;
        }
        return false;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%data.size();
        auto iter = data.begin();
        printf("%d %d\n", r, *iter);
        while(r-->0)
            iter++;
        return *iter;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */