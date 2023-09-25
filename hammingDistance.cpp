#include"hammingDistance.h"

int hammingDistance(int x, int y)
{
	//��������������˼�������Ʊ����1�������ĺ�����������Ӧ��ֱ��ʹ��
	//gcc������Ϊ__builtin_popcount,microsoft�༭���п���ʹ�����º�����ͷ�ļ�<intrin.h>
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
