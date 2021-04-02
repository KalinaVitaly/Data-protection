#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int EulerFunction(int p, int q);
int MOD(int p, int q);
int EFunction(int f);
std::vector<bool> PrimeNumbers(int n);
int EuclidAlgorithm(int a, int b);
int DFind(int f, int e);
int ReEncryptionSymbol(int number, int power, int n)
{
	unsigned long long res = 1;
	while (power)
	{
		if (power % 2)
			res = (res * number) % n;
		number = (number * number) % n;
		power /= 2;
	}
	return res;
}


int main() {
	int p = 7;
	int q = 131;
	int f = -1;
	int mod = -1;
	int e = -1;
	int d = -1;
	int data = 98;
	std::string data_number;
	std::string reEncriptionData = "";
	std::vector<int> encriptionDataCode;

	mod = MOD(p, q);
	f = EulerFunction(p, q);
	e = EFunction(f);

	std::cout << data << std::endl;

	d = DFind(f, e);
	std::cout << "E: " << e << std::endl;
	std::cout << "D: " << d << std::endl;
	data = ReEncryptionSymbol(data, e, mod);
	std::cout << "Encryption: " << data << std::endl;
	std::cout << "Reencryption: " << ReEncryptionSymbol(data, d, mod) << std::endl;
	
	return 0;
}

int EulerFunction(int p, int q) {
	return (p - 1) * (q - 1);
}

int MOD(int p, int q) {
	return p * q;
}

int EFunction(int f) {
	std::vector<bool> numbers = PrimeNumbers(f);
	int e = 2;

	for (e = 2; e < f; e++)
	{
		if (EuclidAlgorithm(f, e) == 1)
		{
			return e;
		}
	}

	return -1;
}

int EuclidAlgorithm(int a, int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		std::swap(a, b);
	}

	return a;
}

std::vector<bool> PrimeNumbers(int n) {
	std::vector<bool> numbers(n + 1);
	std::fill(numbers.begin(), numbers.end(), true);

	for (int i = 2; i <= n; i++) {
		if (numbers[i] == true) {
			for (int j = i * i; j <= n; j += i)
				numbers[j] = false;
		}
	}

	return numbers;
}

int DFind(int f, int e) {
	int d = 0;
	
	while (d * e % f != 1)
	{
		//std::cout << "D: " << d << " E: " << e << " F: " << f << " Result: " << d * e % f << std::endl;
		++d;
	}

	return d;
}