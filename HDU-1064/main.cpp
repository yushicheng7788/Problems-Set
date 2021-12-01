#include <iostream>
#include <stack>
using namespace std;

int n;
char ch;

void solve() {
    while (n--) {
        stack<char> stk;
        while (true) {
            ch = getchar();
            if (ch == ' ' || ch == '\n' || ch == EOF) {
                while (!stk.empty()) {
                    printf("%c", stk.top());
                    stk.pop();
                }        
                if (ch == '\n' || ch == EOF)
                    break;
                printf(" ");
            } else {
                stk.push(ch);
            }
        }
        cout << endl;
    }
}

int main() {
    scanf("%d", &n);
    getchar();

    solve();

    return 0;
}