#include <fstream>
#include <cmath>

using namespace std;

int num_len(int);
int* get_digits(int, int);
int join(int*, int);
int sum(int*, int);
int mul(int*, int);

int main() {
  ifstream inf("input.txt");
  ofstream ouf("output.txt");

  int n = 0; inf >> n;
  int max = pow(10, n);
  int min = 0;
  int first = -1;
  int count = 0;
  int* digits;

  if(max/10 == 1) min = 0;
  else min = max/10;

  for(int i = min; i < max; i++) {
    int len = num_len(i);
    digits = get_digits(i, len);

    if(sum(digits, len) == mul(digits, len)) {
      if(first == -1) first = join(digits, len);
      count++;
    }

    delete[] digits;
  }

  ouf << count << ' ' << first << endl;

  inf.close();
  ouf.close();
  return 0;
}

int num_len(int num) {
  int len = 1;
  for(; num/10 != 0; len++) num /= 10;
  return len;
}

int* get_digits(int num, int len) {
  int* digits = new int[len];

  for(int i = len - 1; i >= 0; i--) {
    digits[i] = num % 10;
    num /= 10;
  }

  return digits;
}

int join(int* digits, int len) {
  int res = digits[0];
  for(int i = 1; i < len; i++) res = res * 10 + digits[i];
  return res;
}

int sum(int* digits, int len) {
  int res = 0;
  for(int i = 0; i < len; i++) res += digits[i];
  return res;
}

int mul(int* digits, int len) {
  int res = 1;
  for(int i = 0; i < len; i++) res *= digits[i];
  return res;
}
