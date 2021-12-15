#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
int n, q[MAX_N];

template<typename T>
void __quickSort3Ways(T arr[], int left, int right) {
    if (left >= right)
        return;
    srand(time(NULL));
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    int lt = left, gt = right + 1;
    int i = left + 1;
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[++lt], arr[i]);
            ++i;
        } else if (arr[i] == v) {
            ++i;
        } else {
            swap(arr[--gt], arr[i]);
        }
    }
    swap(arr[left], arr[lt]);
    __quickSort3Ways(arr, left, lt - 1);
    __quickSort3Ways(arr, gt, right);
}

template<typename T>
void quickSort(T arr[], int n) {
    __quickSort3Ways(arr, 0, n - 1);    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    quickSort(q, n);
    
    for (int i = 0; i < n; ++i)
        cout << q[i] << " ";
    cout << endl;
    return 0;
}