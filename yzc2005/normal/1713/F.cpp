#include <bits/stdc++.h>
using namespace std;
int n, f[1 << 19];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    int k = 1;
    while (1 << k < n) {
        ++k;
    }
    for (int i = 0; i < k; ++i) {
        for (int s = 0; s < 1 << k; ++s) {
            if (s >> i & 1) {
                f[s] ^= f[s ^ (1 << i)];
            }
        }
    }
    for (int i = n; i < 1 << k; ++i) {
        f[i] = 0;
    }
    for (int i = 0; i < k; ++i) {
        for (int s = 0; s < 1 << k; ++s) {
            if (s >> i & 1) {
                f[s] ^= f[s ^ (1 << i)];
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int s = 0; s < 1 << k; ++s) {
            if (s >> i & 1) {
                f[s ^ (1 << i)] ^= f[s];
            }
        }
    }
    for (int i = (1 << k) - n; i < 1 << k; ++i) {
        cout << f[i] << " \n"[i == (1 << k) - 1];
    }
    return 0;
}