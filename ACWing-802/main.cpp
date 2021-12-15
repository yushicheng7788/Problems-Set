#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

const int MAX_N = 300010;

int n, m;
vector<PII> add, query;
vector<int> alls;
int q[MAX_N], preSum[MAX_N];

int find(int x) {
    int left = 0, right = alls.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (alls[mid] == x)
            return mid + 1;    // 前缀和下标从1开始比较好处理
        else if (alls[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    while (n --) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    while (m --) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 离散化
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理添加
    for (auto t : add) {
        int x = find(t.first);
        q[x] += t.second;
    }

    // 处理前缀和
    for (int i = 0; i < alls.size(); ++i) {
        preSum[i + 1] = preSum[i] + q[i + 1];
    }
    
    // 处理询问
    for (auto t : query) {
        int l = find(t.first), r = find(t.second);
        cout << preSum[r] - preSum[l - 1] << endl;
    }
    return 0;
}