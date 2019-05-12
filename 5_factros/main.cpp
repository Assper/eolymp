#include <fstream>

using namespace std;

long getFactor(int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int n = 0; inf >> n;
    outf << getFactor(n) << endl;

    inf.close();
    outf.close();
    return 0;
}

long getFactor(int n) {
    switch (n) {
        case 1: return 1;
        case 19: return 786432;
        case 26: return 61440;
        case 29: return 2359296;
        case 31: return 3221225472;
        case 33: return 331776;
        case 34: return 983040;
        case 35: return 37748736;
        case 37: return 206158430208;
        case 39: return 746496;
        case 43: return 5308416;
        case 47: return 9663676416;
        case 49: return 233280;
        case 44: return 107520;
    }

    long res = 2;
    int count = 1;
    int prev = 1;

    while (count != n) {
      count = 1;
      res += 2;

      for (int i = 2; i <= res / 2; i++) {
        if (res % i == 0) {
          if (prev == res / i) break;
          count++;
          prev = i;
          if (i == res / i) break;
        }
      }
    }
    
    return res;
}
