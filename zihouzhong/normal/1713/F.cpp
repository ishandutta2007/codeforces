#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int k = (n > 1 ? __lg(n - 1) : 0) + 1;
    a.resize(1 << k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (j >> i & 1) a[j] ^= a[j ^ (1 << i)];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (!(j >> i & 1)) a[j] ^= a[j ^ (1 << i)];
        }
    }
    for (int i = n - 1; ~i; i--) {
        cout << a[i] << " ";
    }
    return 0;
}