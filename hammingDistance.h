#pragma once
#include<intrin.h>
#include<vector>
//LeeCode.461	��������
//Date:2023/9/25 16:21
//Author:GGO
//��������㷺Ӧ���ڶ�������ڱ������������ڴ����⣬����Ϣ���������ַ���֮��Ĳ��졣
//��������֮��ĺ��������Ƕ�Ӧλ�������ֲ�ͬ��λ����
int hammingDistance(int x, int y);
int hammingDistanceByShift(int x, int y);
int hammingDistanceByBK(int x, int y); 
//LeeCode.477	���������ܺ�
//Date:2023/9/25 16:21
//Author:GGO
//����һ���������� nums��������㲢���� nums ������������֮�� ����������ܺ͡�
int totalHammingDistance(std::vector<int>& nums);