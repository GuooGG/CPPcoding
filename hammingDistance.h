#pragma once
#include<intrin.h>
//LeeCode.461	汉明距离
//Date:2023/9/25 14:18
//Author:GGO
//汉明距离广泛应用于多个领域。在编码理论中用于错误检测，在信息论中量化字符串之间的差异。
//两个整数之间的汉明距离是对应位置上数字不同的位数。
int hammingDistance(int x, int y);
int hammingDistanceByShift(int x, int y);
int hammingDistanceByBK(int x, int y); 