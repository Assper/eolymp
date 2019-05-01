#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string, char);
int getDecDigit(string);
int romanToDec(string);
string getRomanDigit(string);
string decToRoman(int);

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    string expr; inf >> expr;
    vector<string> args = split(expr, '+');
    int dec = 0;

    for (string num : args) {
        dec += romanToDec(num);
    }
    outf << decToRoman(dec) << endl;

    inf.close();
    outf.close();
    return 0;
}

int getDecDigit(string roman) {
    const int DIGITSLEN = 16;
    const string ROM[DIGITSLEN] = { "I", "IV", "V", "VI", "IX", "X", "XL", "L", "LX", "XC", "C", "CD", "D", "DC", "CM", "M" };
    const int DEC[DIGITSLEN] = { 1, 4, 5, 6, 9, 10, 40, 50, 60, 90, 100, 400, 500, 600, 900, 1000 };

    for (int i = 0; i < DIGITSLEN; i++) {
        if (ROM[i] == roman) { return DEC[i]; }
    }

    return 0;
}

string getRomanDigit(string roman) {
    const int DIGITSLEN = 16;
    const string ROM[DIGITSLEN] = { "I", "IV", "V", "VI", "IX", "X", "XL", "L", "LX", "XC", "C", "CD", "D", "DC", "CM", "M" };

    if (roman.length() > 1) {
        const string digit = roman.substr(0, 2);
        for (int i = 0; i < DIGITSLEN; i++) {
            if (ROM[i] == digit) { return digit; }
        }
    }

    return roman.substr(0, 1);
}

string decToRoman(int number) {
    const int DIGITSLEN = 13;
    const int DEC[DIGITSLEN] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    const string ROM[DIGITSLEN] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    string result = "";

    for (int i = DIGITSLEN - 1; number > 0;) {
        if (number >= DEC[i]) {
            result += ROM[i];
            number -= DEC[i];
        } else {
            i--;
        }
    }

    return result;
}

int romanToDec(string number) {
    int result = 0;

    while (!number.empty()) {
        string romanDigit = getRomanDigit(number);
        result += getDecDigit(romanDigit);
        number = number.substr(romanDigit.length());
    }

    return result;
}

vector<string> split(string str, char sep) {
    vector<string> strs;
    int prevIndex = 0;

    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] == sep) {
            strs.push_back(str.substr(prevIndex, i - prevIndex));
            prevIndex = i + 1;
        }
    }

    if (prevIndex < (int)str.length()) {
        strs.push_back(str.substr(prevIndex));
    }

    return strs;
}
