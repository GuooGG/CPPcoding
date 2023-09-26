#pragma once
class tools
{
private:
	//递归快速幂算法
	double quickMulRecursion(double x, long long n);
	//迭代快速幂算法
	double quickMulInteration(double x, long long n);
public:
	double myPow(double x, int n);
};

