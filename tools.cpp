#include "tools.h"

double tools::quickMulRecursion(double x, long long n)
{
    if (n == 0) {
        return 1.0;
    }
    double y = quickMulRecursion(x, n / 2);
    return n & 1 ? y * y * x : y * y;
}

double tools::quickMulInteration(double x, long long n)
{
    double xContribution = x;
    double ret = 1.0;
    while (n) {
        if (n & 1) {
            ret *= xContribution;
        }
        xContribution *= xContribution;
        n /= 2;
    }
    return ret;
}

double tools::myPow(double x, int n)
{
    long long N = n;
    return n > 0 ? quickMulInteration(x, N) : 1.0/quickMulInteration(x, -N);
}
