#include <fstream>

using namespace std;

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    

    inf.close();
    outf.close();
    return 0;
}
