#pragma once
#include <vector>

// LeeCode.461	��������
// Date:2023/9/25 16:21
// Author:GGO
// ��������㷺Ӧ���ڶ�������ڱ������������ڴ����⣬����Ϣ���������ַ���֮��Ĳ��졣
// ��������֮��ĺ��������Ƕ�Ӧλ�������ֲ�ͬ��λ����
int hammingDistance(int x, int y);
int hammingDistanceByShift(int x, int y);
int hammingDistanceByBK(int x, int y);
// LeeCode.477	���������ܺ�
// Date:2023/9/25 16:21
// Author:GGO
// ����һ���������� nums��������㲢���� nums ������������֮�� ����������ܺ͡�
int totalHammingDistance(std::vector<int> &nums);
//���������㷨
int hammingDistance(int x, int y)
{
	//��������������˼�������Ʊ����1�������ĺ�����������Ӧ��ֱ��ʹ��
	//gcc������Ϊ__builtin_popcount,microsoft�༭���п���ʹ�����º�����ͷ�ļ�<intrin.h>
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
	//Brian Kernighan �㷨
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
