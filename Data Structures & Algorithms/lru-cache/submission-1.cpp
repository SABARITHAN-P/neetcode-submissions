class LRUCache {
public:
    int cap;

    // {key, value}
    list<pair<int,int>> dll;

    // key -> iterator pointing to node in list
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        // move to front (most recently used)
        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {

        // key already exists
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // cache full
        else if(dll.size() == cap) {
            int lruKey = dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }

        // insert at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};