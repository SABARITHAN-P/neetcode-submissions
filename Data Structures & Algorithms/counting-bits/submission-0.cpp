class Solution {
public:
    int count(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);

        for (int i = 1; i <= n; i++) {
            ans.push_back(count(i));   
        }

        return ans;
    }
};