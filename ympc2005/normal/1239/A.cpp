#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, m, f[N];

int main() {
    cin>>n>>m;

    if (n < m) {
        swap(n, m);
    }

    f[0] = 2;

    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];

        if (i > 1) {
            f[i] = (f[i] + f[i - 2])%mod;
        }
    }

    int ans = (f[n] + f[m] - 2)%mod;
    printf("%d\n", (ans%mod + mod)%mod);
}