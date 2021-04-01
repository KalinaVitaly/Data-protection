#include <iostream>
#include <vector>
#include <string>
#include <cmath>

unsigned long long int EulerFunction(unsigned long long int p, unsigned long long int q);
unsigned long long int MOD(unsigned long long int p, unsigned long long int q);
unsigned long long int EFunction(unsigned long long int f);
std::vector<bool> PrimeNumbers(unsigned long long int n);
unsigned long long int EuclidAlgorithm(unsigned long long int a, unsigned long long int b);
unsigned long long int EncryptionSymbol(unsigned long long int symbol, unsigned long long int e, unsigned long long int mod);
//char ReEncryptionSymbol(long long int symbol, long long int d, long long int mod);
unsigned long long int DFind(unsigned long long int f, unsigned long long int e);
unsigned long long int ReEncryptionSymbol(unsigned long long int number, unsigned long long int power, unsigned long long int n)
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
	unsigned long long int p = 3;
	unsigned long long int q = 23;
	unsigned long long int f = -1;
	unsigned long long int mod = -1;
	unsigned long long int e = -1;
	unsigned long long int d = -1;
	unsigned long long int data = 98;
	std::string data_number;
	std::string reEncriptionData = "";
	std::vector<int> encriptionDataCode;

	mod = MOD(p, q);
	f = EulerFunction(p, q);
	e = EFunction(f);

	//std::cin >> data;
	std::cout << data << std::endl;
	//std::cout << "Code: " << (int)data.data()[0] << std::endl;
	//std::cout << data << std::endl;
	//std::cout << "p: " << p << " q: " << q << " f: " << f << " mod: " << mod << " e: " << e << std::endl;
	//std::cout << "Encription code:" << std::endl;
	//for (int i = 0; i < data.size(); ++i) {
	//	encriptionDataCode.push_back(ReEncryptionSymbol((int)data.data()[i], e, mod));
	//	//std::cout << "EncryptionSymbol: " <<  EncryptionSymbol(static_cast<char>(data[i]), e, mod) << " ";
	//}
	//std::cout << std::endl;
	std::cout << "Encryption: " << (data = ReEncryptionSymbol(data, e, mod)) << std::endl;
	d = DFind(f, e);
	//std::cout << data_number << std::endl;
	/*for (auto i : encriptionDataCode) {
		char a = (char)ReEncryptionSymbol(i, d = 29, mod = 91);
		reEncriptionData += a;
		std::cout << "Code: " << (int)a;
	}*/
	//std::cout << reEncriptionData << std::endl;
	std::cout << "Reencryption: " << ReEncryptionSymbol(data, d, mod) << std::endl;
	//std::cout << "p: " << p << " q: " << q << " f: " << f << " mod: " << mod << " e: " << e << " d: " << d << std::endl;
	//std::cout << "Reencryption number: " << ReEncryptionSymbol(data_number, d, mod);
	return 0;
}

unsigned long long int EulerFunction(unsigned long long int p, unsigned long long int q) {
	return (p - 1) * (q - 1);
}

unsigned long long int MOD(unsigned long long int p, unsigned long long int q) {
	return p * q;
}

unsigned long long int EFunction(unsigned long long int f) {
	std::vector<bool> numbers = PrimeNumbers(f);
	int e = 1;

	do {
		while (!numbers[e]) {
			++e;
		}
		
	} while (EuclidAlgorithm(f, e) != 1);

	return e;
}

unsigned long long int EuclidAlgorithm(unsigned long long int a, unsigned long long int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		std::swap(a, b);
	}

	return a;
}

std::vector<bool> PrimeNumbers(unsigned long long int n) {
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

unsigned long long int EncryptionSymbol(unsigned long long int symbol, unsigned long long int e, unsigned long long int mod) {
	long long int up = static_cast<long long int>(pow(static_cast<long long int>(symbol), e));
	//std::cout << "Up: " << up << std::endl;
	return up % mod;
}

unsigned long long int DFind(unsigned long long int f, unsigned long long int e) {
	double d = 0;
	double intPart;
	int k = 0;
	
	do {
		++k;
		d = static_cast<double>(k * f + 1) / e;
	} while (std::modf(d, &intPart) != 0);

	return d;
}