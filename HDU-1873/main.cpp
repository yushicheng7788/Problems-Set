#include <iostream>
#include <queue>
#include <string>
using namespace std;

int Task;

struct Node {
    int pri; 
    int id;
    Node(int x, int y)
        : pri(x), id(y) {}
    friend bool operator <(const Node &lhs, const Node &rhs) {
        return lhs.pri == rhs.pri ? lhs.id > rhs.id : lhs.pri < rhs.pri;
    }
};

void solve() {
    priority_queue<Node> q[3];
    int id = 0;
    string op;
    int a, b;
    while (Task--) {
        cin >> op;
        if (op == "IN") {
            cin >> a >> b;
            q[a - 1].push({b, ++id});
        } else if (op == "OUT") {
            cin >> a;
            if (q[a - 1].empty())
                cout << "EMPTY" << endl;
            else {
                cout << q[a - 1].top().id << endl;
                q[a - 1].pop();
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    while (cin >> Task) {
        solve();
    }
    return 0;
}