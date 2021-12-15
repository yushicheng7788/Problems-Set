#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
int q[MAX_N], n, k;

template<typename T>
int __quickSort3Ways(T arr[], int left, int right, int k) {
    if (left == right)
        return arr[left];
        
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    // 将整个数组分为三部分
    int lt = left, gt = right + 1;      // [left + 1, lt] < v, [gt, right] > v
    int i = left + 1;       // [lt + 1, i) == v
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[++lt]);
            ++i;
        } else if (arr[i] > v) {
            swap(arr[i], arr[--gt]);
        } else {
            ++i;
        }
    }
    swap(arr[left], arr[lt]);
    --lt;
    if (k <= lt)
        __quickSort3Ways(arr, left, lt, k);
    else if (k >= gt)
        __quickSort3Ways(arr, gt, right, k);
    else
        return v;
}

template<typename T>
int selection(T arr[], int n, int k) {
    srand(time(NULL));
    return __quickSort3Ways(arr, 0, n - 1, k - 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    int ans  = selection(q, n, k);
    cout << ans << endl;
    return 0;
}