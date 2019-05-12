#include <math.h>
#include <fstream>

using namespace std;

long getMatches2d(int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int n = 0; inf >> n;
    outf << getMatches2d(n) << endl;

    inf.close();
    outf.close();
    return 0;
}

long getMatches2d(int n) {
    int width = sqrt(n);
    int length = n / width; 
    int ost = n - width * length;
    long res = width * (length + 1) + length * (width + 1);
    return ost != 0 ? res + 2 * ost + 1 : res;
}
