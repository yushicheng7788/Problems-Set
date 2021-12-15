#include <iostream>

using namespace std;

const int MAX_N = 500010;

int n, m;
int q[MAX_N];
int tr[MAX_N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for (int i = x; i <=n; i += lowbit(i))
        tr[i] += k;
}

int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x))
        res += tr[x];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        add(i, q[i] - q[i - 1]);
    }

    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        } else {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}