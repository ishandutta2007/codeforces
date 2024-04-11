#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; 2*i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout<<i<<' '<<j<<'\n'<<n - i + 1<<' '<<m - j + 1<<'\n';
        }
    }

    if (n&1) {
        int l = 1, r = m;

        while (l <= r) {
            cout<<n/2 + 1<<' '<<l++<<'\n';

            if (l <= r) {
                cout<<n/2 + 1<<' '<<r--<<'\n';
            }
        }
    }
}