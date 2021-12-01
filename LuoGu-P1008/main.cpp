#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int st[10];

bool check(int i, int j, int k) {
    memset(st, 0, sizeof(st));
    string tot = "";
    tot += to_string(i) + to_string(j) + to_string(k);
    for (auto c : tot) {
        if (c < '1' || c > '9')
            return false;
        if (st[c - '0'])
            return false;
        st[c - '0'] = 1;
    }
    return true;
}

int main() {
    for (int i = 123; i <= 333; ++i) {
        int j = 2 * i, k = 3 * i;
        if (check(i, j, k))
            cout << i << " " << j << " " << k << endl;
    }

    return 0;
}