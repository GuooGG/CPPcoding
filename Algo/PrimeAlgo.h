#pragma once
#include<algorithm>
#include<bitset>
#include<vector>
#include<iostream>
class PrimeAlgo
{
private:
	//Œ Ã‚∑∂Œß
	static const int maxn = 1e4 + 10;
	std::bitset<maxn> bitmap;
public:
	PrimeAlgo() = default;
	inline bool isprime(int x);
	//∆”Àÿ…∏∑®
	std::vector<int> sieve(int n = maxn);
	//∞£ œ…∏
	std::vector<int> sieveOfEratosthenes(int n = maxn);
	//≈∑¿≠…∏
	std::vector<int> sieveOfEuler(int n = maxn);
};
