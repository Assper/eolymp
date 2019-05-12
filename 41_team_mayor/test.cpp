#include <iostream>
#include <assert.h>

using namespace std;

int testLength();
int testArrayCompare();
int testSort();
bool arrayCompare(int*, int*, int);
void sort(int*, int);

int main() {
    testArrayCompare();
    testSort();
    cout << "All tests are done!" << endl;
    return 0;
}

int testArrayCompare() {
    int len = 5;
    int* nums = new int[len] { 1, 2, 3, 4, 5 };
    int* sameNums = new int[len] { 1, 2, 3, 4, 5 };
    assert(arrayCompare(nums, sameNums, len));
    delete[] nums;
    delete[] sameNums;

    len = 5;
    nums = new int[len] { 1, 2, 4, 3, 5 };
    sameNums = new int[len] { 1, 2, 3, 4, 5 };
    assert(!arrayCompare(nums, sameNums, len));
    delete[] nums;
    delete[] sameNums;

    return 0;
}

int testSort() {
    int len = 5;
    int* nums = new int[len] { 4, 2, 3, 1, 5 };
    int* sorted = new int[len] { 1, 2, 3, 4, 5 };

    sort(nums, len);
    assert(arrayCompare(nums, sorted, len));

    delete[] nums;
    delete[] sorted;
    return 0;
}

bool arrayCompare(int* a, int* b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

void sort(int* nums, int n) {
    for(int k = n / 2; k > 0; k /= 2) {
        for(int i = k; i < n; i++) {
            int t = nums[i];
            int j = i;

            for(; j >= k; j -= k) {
                if(t < nums[j - k]) nums[j] = nums[j - k];
                else break;
            }

            nums[j] = t;
        }
    }
}
