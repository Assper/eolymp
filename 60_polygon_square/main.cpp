#include <fstream>
#include <iomanip>

using namespace std;

double getSquare(int(*)[2], int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int length; inf >> length;
    int (*coords)[2] = new int[length][2];

    for (int i = 0; i < length; i++) {
        int x; inf >> x;
        int y; inf >> y;
        coords[i][0] = x;
        coords[i][1] = y;
    }

    outf << fixed << setprecision(3) << getSquare(coords, length) << endl;
    delete[] coords;

    inf.close();
    outf.close();
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
