class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1); // check last bit
            n >>= 1;        // shift right
        }
        return cnt;
    }
};