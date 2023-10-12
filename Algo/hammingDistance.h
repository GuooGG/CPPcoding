#pragma once
#include<intrin.h>
#include<vector>

//LeeCode.461	汉明距离
//Date:2023/9/25 16:21
//Author:GGO
//汉明距离广泛应用于多个领域。在编码理论中用于错误检测，在信息论中量化字符串之间的差异。
//两个整数之间的汉明距离是对应位置上数字不同的位数。
int hammingDistance(int x, int y);
int hammingDistanceByShift(int x, int y);
int hammingDistanceByBK(int x, int y); 
//LeeCode.477	汉明距离总和
//Date:2023/9/25 16:21
//Author:GGO
//给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和。
int totalHammingDistance(std::vector<int>& nums);