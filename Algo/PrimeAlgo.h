#pragma once
#include<algorithm>
#include<bitset>
#include<vector>
#include<iostream>
class PrimeAlgo
{
private:
	//���ⷶΧ
	static const int maxn = 1e4 + 10;
	std::bitset<maxn> bitmap;
public:
	PrimeAlgo() = default;
	inline bool isprime(int x);
	//����ɸ��
	std::vector<int> sieve(int n = maxn);
	//����ɸ
	std::vector<int> sieveOfEratosthenes(int n = maxn);
	//ŷ��ɸ
	std::vector<int> sieveOfEuler(int n = maxn);
};
