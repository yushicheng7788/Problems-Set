#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    int ans = 0x3f3f3f3f;
    int num = 0, price = 0;
    while (cin >> num >> price) {
        if (n % num == 0)
            ans = min(ans, n / num * price);
        else
            ans = min(ans, (n / num + 1) * price);
    }
    printf("%d\n", ans);
    return 0;
}