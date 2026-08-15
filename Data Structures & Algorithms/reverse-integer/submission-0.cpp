class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);

        long long val = llabs((long long)x);
        string s = to_string(val);

        std::reverse(s.begin(), s.end());

        long long temp = stoll(s);

        if (neg)
            temp = -temp;

        if (temp > INT_MAX || temp < INT_MIN)
            return 0;

        return (int)temp;
    }
};