#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

long getMatches3d(int);
int testGetMatches3d();

int main() {
    testGetMatches3d();
    cout << "All tests are done!" << endl;
    return 0;
}

int testGetMatches3d() {
    long matches = getMatches3d(3);
    assert(matches == 28);

    matches = getMatches3d(2);
    assert(matches == 20);

    matches = getMatches3d(4);
    assert(matches == 33);

    matches = getMatches3d(5);
    assert(matches == 41);

    matches = getMatches3d(6);
    assert(matches == 46);

    matches = getMatches3d(7);
    assert(matches == 51);

    matches = getMatches3d(8);
    assert(matches == 54);

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
