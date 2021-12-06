#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 10;

int h[MAX_N], e[MAX_N], ne[MAX_N], idx;
int in_edge[MAX_N], top[MAX_N];

int n, m;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort() {
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (!in_edge[i])
            que.push(i);
    int i = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        top[i++] = t;
        
        for (int j = h[t]; j != -1; j = ne[j]) {
            int k = e[j];
            -- in_edge[k];
            if (in_edge[k] == 0)
                que.push(k);
        }
    }
    return i == n;
}

int main() {
    memset(h, -1, sizeof(h));
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        in_edge[b]++;
    }
    
    if (topsort())
        for (int i = 0; i < n; ++i)
            cout << top[i] << " ";
    else {
        puts("-1");
    }
    
    return 0;
}