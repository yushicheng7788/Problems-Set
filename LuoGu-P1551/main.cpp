#include <iostream>
using namespace std;

const int MAX_N = 5010;

int n, m, q;
int p[MAX_N];

int find(int x) {
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    while (m--) {
        int m1, m2;
        cin >> m1 >> m2;
        p[find(m1)] = find(m2);
    }

    while (q--) {
        int m1, m2;
        cin >> m1 >> m2;
        if (find(m1) == find(m2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}