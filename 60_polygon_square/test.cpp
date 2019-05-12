#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

int testGetSquare();
double getSquare(int(*)[2], int);

int main() {
    testGetSquare();
    cout << "All tests are done!" << endl;
    return 0;
}

int testGetSquare() {
    int length = 3;
    int (*coords)[2] = new int[length][2]{ {0, 0}, {0, 2}, {2, 0} };
    double square = getSquare(coords, length);
    delete[] coords;

    cout << fixed << setprecision(3) << square << endl;
    assert(square == 2.0);

    length = 5;
    coords = new int[length][2]{ {-3, -2}, {-1, 4}, {6, 1}, {3, 10}, {-4, 9} };
    square = getSquare(coords, length);
    delete[] coords;

    cout << fixed << setprecision(3) << square << endl;
    assert(square == 60.0);
    return 0;
}

double getSquare(int (*coords)[2], int length) {
    int xSum = 0;
    int ySum = 0;

    for (int i = 0; i < length - 1; i++) {
        xSum += coords[i][0] * coords[i + 1][1];
        ySum += coords[i][1] * coords[i + 1][0];
    }

    xSum += coords[length - 1][0] * coords[0][1];
    ySum += coords[length - 1][1] * coords[0][0];
    return abs(xSum - ySum) / 2;
}
