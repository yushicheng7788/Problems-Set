#include <iostream>
using namespace std;

const int MAX_N = 500010;

int n, m;
int q[MAX_N], tr[MAX_N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}

int query(int k) {
    int res = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        add(i, q[i]);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            add(b, c);
        else
            cout << query(c) - query(b - 1) << endl;
    }
    return 0;
}