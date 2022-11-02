#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int x, i = 1; i <= n; i++) {
        cin>>x;
    }

    for (int x, i = 1; i <= n; i++) {
        cin>>x;
        a[x] = i;
    }

    if (a[1]) {
        bool ok = 1;

        for (int i = a[1]; i <= n; i++) {
            if (a[i - a[1] + 1] != i) {
                ok = 0;
            }
        }

        for (int i = n - a[1] + 2; i <= n; i++) {
            if (a[i] && (a[i] + n + 1 + n - i) >= a[1] + n) {
                ok = 0;
            }
        }

        if (ok) {
            cout<<a[1] - 1<<'\n';
            exit(0);
        }
    }

    int ans = 0;

     for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] + n + 1 + n - i - n);
    }

    cout<<ans<<'\n';
}