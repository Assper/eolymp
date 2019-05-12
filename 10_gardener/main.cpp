#include <fstream>

using namespace std;

int getFreeDays(int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int n = 0; inf >> n;
    outf << getFreeDays(n) << endl;

    inf.close();
    outf.close();
    return 0;
}

int getFreeDays(int n) {
    int res = 0;
    int days = 1;
    float part = 1.0 / (float)n;

    for (; part < 1; days++, n--, part += 1.0 / (float)n) {
        if (part < 0.5) res++;
    }

    return days - res;
}
