#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], t[N], q, tot, b[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    cin>>q;

    for (int op, x, y, i = 1; i <= q; i++) {
        cin>>op;

        if (op == 1) {
            cin>>x>>y;
            t[x] = tot;
            a[x] = y;
        } else {
            ++tot;
            cin>>b[tot];
        }
    }

    for (int i = tot; i; i--) {
        b[i] = max(b[i + 1], b[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout<<max(b[t[i] + 1], a[i])<<' ';
    }
}