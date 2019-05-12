#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

long getMatches2d(int);
int testGetMatches2d();

int main() {
    testGetMatches2d();
    cout << "All tests are done!" << endl;
    return 0;
}

int testGetMatches2d() {
    long matches = getMatches2d(14);
    assert(matches == 36);

    matches = getMatches2d(5);
    assert(matches == 15);

    matches = getMatches2d(1);
    assert(matches == 4);

    matches = getMatches2d(2);
    assert(matches == 7);

    matches = getMatches2d(3);
    assert(matches == 10);

    return 0;
}

long getMatches2d(int n) {
    int width = sqrt(n);
    int length = n / width; 
    int ost = n - width * length;
    long res = width * (length + 1) + length * (width + 1);
    return ost != 0 ? res + 2 * ost + 1 : res;
}
