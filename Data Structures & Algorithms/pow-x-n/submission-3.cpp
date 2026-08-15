class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0)
            return 1;

        double half = solve(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            N = -N;
            return 1.0 / solve(x, N);
        }

        return solve(x, N);
    }
};