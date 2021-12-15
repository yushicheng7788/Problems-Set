#include <iostream>
using namespace std;
const int MAX_N = 1e4 + 10;

int p[MAX_N];

int N, M;

int find(int x) {
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        p[i] = i;

    while (M --) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            p[find(y)] = p[find(z)]
        } else {
            if (find(y) == find(z))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    return 0;
}