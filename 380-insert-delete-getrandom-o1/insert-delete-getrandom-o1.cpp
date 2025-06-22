class RandomizedSet {
public:
    unordered_map<int, int> mp;
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
    }
    
    bool insert(int val) {
        if(mp[val] == 0) {
            mp[val] = 1;
            return true;
        }
        else return false; 
    }
    
    bool remove(int val) {
        return mp.erase(val);
    }
    
    int getRandom() {
        return next(mp.begin(), rand()%mp.size())->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */