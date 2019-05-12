#include <fstream>
#include <string>

using namespace std;

string getDecimal(int, int, int);
string getMantis(int, int, int);

int main() {
	ifstream inf("input.txt");
    ofstream outf("output.txt");

    int m = 0; inf >> m;
    int n = 0; inf >> n;
    int k = 0; inf >> k;
    outf << getDecimal(m, n, k) << endl;

    inf.close();
    outf.close();
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
