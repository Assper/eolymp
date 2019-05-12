#include <iostream>
#include <assert.h>

using namespace std;

int getFreeDaysTest();
int getFreeDays(int);

int main() {
    getFreeDaysTest();
    cout << "All tests are done!" << endl;
    return 0;
}

int getFreeDaysTest() {
    assert(getFreeDays(3) == 2);
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
