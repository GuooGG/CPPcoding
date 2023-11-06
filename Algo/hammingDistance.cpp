#pragma once
#include <vector>

// LeeCode.461	汉明距离
// Date:2023/9/25 16:21
// Author:GGO
// 汉明距离广泛应用于多个领域。在编码理论中用于错误检测，在信息论中量化字符串之间的差异。
// 两个整数之间的汉明距离是对应位置上数字不同的位数。
int hammingDistance(int x, int y);
int hammingDistanceByShift(int x, int y);
int hammingDistanceByBK(int x, int y);
// LeeCode.477	汉明距离总和
// Date:2023/9/25 16:21
// Author:GGO
// 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和。
int totalHammingDistance(std::vector<int> &nums);
//汉明距离算法
int hammingDistance(int x, int y)
{
	//大多数语言内置了计算二进制表达中1的数量的函数，工程中应当直接使用
	//gcc函数名为__builtin_popcount,microsoft编辑器中可以使用如下函数，头文件<intrin.h>
	return __builtin_popcount(x ^ y);
}

int hammingDistanceByShift(int x, int y)
{
	int s = x ^ y;
	int ret = 0;
	while (s) {
		ret += s & 1;
		s = s >> 1;
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
