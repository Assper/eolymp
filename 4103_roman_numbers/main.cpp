#include <fstream>
#include <string>

using namespace std;

int getDecDigit(string);
int romanSum(string);
string getRomanDigit(string);

const int DIGITSLEN = 16;
const string ROM[DIGITSLEN] = { "I", "IV", "V", "VI", "IX", "X", "XL", "L", "LX", "XC", "C", "CD", "D", "DC", "CM", "M" };
const int DEC[DIGITSLEN] = { 1, 4, 5, 6, 9, 10, 40, 50, 60, 90, 100, 400, 500, 600, 900, 1000 };

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    string str; inf >> str;
    outf << romanSum(str) << endl;

    inf.close();
    outf.close();
    return 0;
}

int getDecDigit(string roman) {
    for (int i = 0; i < DIGITSLEN; i++) {
        if (ROM[i] == roman) { return DEC[i]; }
    }

    return 0;
}

string getRomanDigit(string roman) {
    if (roman.length() > 1) {
        const string digit = roman.substr(0, 2);
        for (int i = 0; i < DIGITSLEN; i++) {
            if (ROM[i] == digit) { return digit; }
        }
    }

    return roman.substr(0, 1);
}

int romanSum(string str) {
    int result = 0;

    while (!str.empty()) {
        string romanDigit = getRomanDigit(str);
        result += getDecDigit(romanDigit);
        str = str.substr(romanDigit.length());
    }

    return result;
}
