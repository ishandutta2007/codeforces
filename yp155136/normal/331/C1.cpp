#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int ret = 0;
    while (x) {
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}

int main () {
    int n; cin >> n;
    int cnt = 0;
    while (n != 0) {
        n -= f(n);
        ++cnt;
    }
    cout << cnt << endl;
}