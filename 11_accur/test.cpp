#include <iostream>
#include <string>
#include <random>
#include <assert.h>

using namespace std;

string getDecimal(int, int, int);
string getMantis(int, int, int);
int testGetMantis();

int main() {
	testGetMantis();
	cout << "All tests are done!" << endl;
	return 0;
}

int testGetMantis() {
	default_random_engine gen(time(0));
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i <= 1000; i++) {
		int m = dist(gen);
		int n = dist(gen);
		string num = getMantis(m % n, n, i);
		assert((uint)i == num.length());
	}

	return 0;
}

string getDecimal(int m, int n, int k) {
	int integral = m / n;
	int rem = m % n;
	string num = to_string(integral);
	return k != 0 ? num + "." + getMantis(rem, n, k) : num;
}

string getMantis(int m, int n, int k) {
	string mantis = "";

	for (int i = 0; i < k; i++) {
		mantis += to_string(m * 10 / n);
		m = m * 10 % n;
	}

	return mantis;
}
