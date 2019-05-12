#include <iostream>
#include <ctime>
#include <assert.h>

using namespace std;

int testGetWday();
int testCountFridays();
int countFridays(int, int, int);
int getWday(int, int, int);

int main() {
    testGetWday();
    testCountFridays();
    cout << "All tests are done!" << endl;
    return 0;
}

int testGetWday() {
    assert(getWday(2019, 3, 24) == 3);
    assert(getWday(2019, 0, 0) == 1);
    return 0;
}

int testCountFridays() {
    int mday = 12;
    int first = countFridays(1999, 2000, mday);
    int second = countFridays(1991, 1997, mday);
    assert(first + second == 13);
    return 0;
}

int countFridays(int start, int end, int mday) {
    int sum = 0;

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < 12; j++) {
            sum += getWday(i, j, mday) == 4 ? 1 : 0;
        }
    }

    return sum;
}

int getWday(int year, int month, int day) {
    time_t rawtime;
    struct tm* st = localtime(&rawtime);

    time (&rawtime);
    st->tm_year = year - 1900;
    st->tm_mon = month;
    st->tm_mday = day;
    mktime(st);

    return st->tm_wday;
}
