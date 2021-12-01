#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int Task;

void solve() {
    while (Task --) {
        int n;
        string str;
        cin >> n >> str;
        stack<int> stk;
        queue<int> que;
        if (str == "FIFO") {
            while (n --) {
                string temp;
                cin >> temp;
                if (temp == "OUT") {
                    if (!que.empty()) {
                        cout << que.front() << endl;
                        que.pop();
                    } else {
                        cout << "None" << endl;
                    }
                } else {
                    int N;
                    cin >> N;
                    que.push(N);
                }
            }
        } else {
            while (n --) {
                string temp;
                cin >> temp;
                if (temp == "OUT") {
                    if (!stk.empty()) {
                        cout << stk.top() << endl;
                        stk.pop();
                    } else {
                        cout << "None" << endl;
                    }
                } else {
                    int N;
                    cin >> N;
                    stk.push(N);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> Task;
    solve();
    return 0;
}