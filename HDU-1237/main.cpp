#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

double cal() {
    stack<double> nums;
    char preSign = '+';
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ')
            continue;
        else if (isdigit(str[i])) {
            double num = 0.0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                ++i;
            }
            --i;
            if (preSign == '+')
                nums.push(num);
            else if (preSign == '-') {
                nums.push(-num);
            } else if (preSign == '*') {
                auto t = nums.top(); nums.pop();
                nums.push(t * num);
            } else {
                auto t = nums.top(); nums.pop();
                nums.push(t / num);
            }
        } else {
            preSign = str[i];
        }
    }
    double res = 0;
    while (!nums.empty()) {
        res += nums.top();
        nums.pop();
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    while (getline(cin, str) && str != "0") {
        printf("%.2lf\n", cal());
    }
    return 0;
}