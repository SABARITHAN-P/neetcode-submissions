class CountSquares {
public:
    map<pair<int, int>, int> mp;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto &it : mp) {
            int x2 = it.first.first;
            int y2 = it.first.second;

            // Skip if not a valid diagonal
            if (x == x2 || y == y2)
                continue;

            if (abs(x - x2) != abs(y - y2))
                continue;

            ans += it.second *
                   mp[{x, y2}] *
                   mp[{x2, y}];
        }

        return ans;
    }
};

/**
 * Your CountSquares object will be instantiated and called as such:
 * CountSquares* obj = new CountSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */