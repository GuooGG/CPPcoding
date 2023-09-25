#include"hammingDistance.h"

int hammingDistance(int x, int y)
{
	//大多数语言内置了计算二进制表达中1的数量的函数，工程中应当直接使用
	//gcc函数名为__builtin_popcount,microsoft编辑器中可以使用如下函数，头文件<intrin.h>
	return __popcnt(x ^ y);
}

int hammingDistanceByShift(int x, int y)
{
	int s = x ^ y;
	int ret = 0;
	while (s) {
		ret += s & 1;
		s >> 1;
	}
	return ret;
}

int hammingDistanceByBK(int x, int y)
{
	//Brian Kernighan 算法
	//x =		10001000
	//x-1=		10000111
	//x&(x-1)=	10000000
	int s = x ^ y;
	int ret = 0;
	while (s) {
		s &= s - 1;
		ret++;
	}
	return ret;
}

int totalHammingDistance(std::vector<int>& nums)
{
	int ret = 0;
	int n = nums.size();
	for (int i = 0; i < 30; i++) {
		int c = 0;
		for (int val : nums) {
			c += (val >> i) & 1;
		}
		ret += c * (n - c);
	}
	return ret;
}
