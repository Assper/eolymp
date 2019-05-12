#include <math.h>
#include <fstream>

using namespace std;

long getMatches3d(int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int n = 0; inf >> n;
    outf << getMatches3d(n) << endl;

    inf.close();
    outf.close();
    return 0;
}

long getMatches3d(int n) {
    int c1 = (int)(pow(n,1.0/3)+0.5);
    int c2 = (int)(sqrt(n/c1)+0.5);
    int c3 = n/(c1*c2);
    int S = 3*c1*c2*c3+2*(c1*c2+c1*c3+c2*c3)+(c1+c2+c3);
    int h = n-c1*c2*c3;

    if (h!=0) {
        int d1 = (int)(sqrt(h)+0.5);
        if (d1*d1 > h) d1--;
        int d2=h/d1;
        S += 3*d1*d2+2*(d1+d2)+1;
        h -= d1*d2;
        if (h != 0) S+=3*h+2;
    }
    
    return S;
}
