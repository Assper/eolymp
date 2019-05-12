#include <fstream>
#include <ctime>

using namespace std;

int countFridays(int, int, int);
int getWday(int, int, int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int k; inf >> k;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        int start; inf >> start;
        int end; inf >> end;
        sum += countFridays(start, end, 12);
    }

    outf << sum << endl;

    inf.close();
    outf.close();
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
