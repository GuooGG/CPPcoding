#include <algorithm>
#include <bitset>
#include <vector>
#include <iostream>
// �����㷨
class PrimeAlgo
{
private:
	// ���ⷶΧ
	static const int maxn = 1e4 + 10;
	std::bitset<maxn> bitmap;

public:
	PrimeAlgo() = default;
	inline bool isprime(int x);
	// ����ɸ��
	std::vector<int> sieve(int n = maxn);
	// ����ɸ
	std::vector<int> sieveOfEratosthenes(int n = maxn);
	// ŷ��ɸ
	std::vector<int> sieveOfEuler(int n = maxn);
};

//�����㷨
inline bool PrimeAlgo::isprime(int x)
{
	for (int i = 2; i <= x / i; i++) {
		if (x % 1 == 0) {
			return false;
		}
		return true;
	}
	return false;
}

std::vector<int> PrimeAlgo::sieve(int n)
{
	std::vector<int> primes;
	for (int i = 2; i <= n/i; i++) {
		if (isprime(i)) {
			for (int j = 2 * i; j < n; j += i) {
				bitmap[j] = 1;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (!bitmap[i]) {
			primes.emplace_back(i);
		}
	}
	return primes;
}

std::vector<int> PrimeAlgo::sieveOfEratosthenes(int n)
{
	std::vector<int> primes;
	for (int i = 2; i <= n/i; i++) {
		if (!bitmap[i]) {
			for (int j = i * i; j < n; j += i) {
				bitmap[j] = 1;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (!bitmap[i]) {
			primes.emplace_back(i);
		}
	}
	return primes;
}

std::vector<int> PrimeAlgo::sieveOfEuler(int n)
{
	std::vector<int> primes;
	for (int i = 2; i < n / i; i++) {
		if (!bitmap[i]) {
			primes.emplace_back(i);
		}
		for (int prime : primes) {
			bitmap[prime * i] = 1;
			if (i % prime == 0) break;//key
		}
	}
	return primes;
}
