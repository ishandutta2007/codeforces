#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int T, n, fa[N], ans;

ll c[N], a[N], b[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>T;

    while (T--) {
        cin>>n;

        for (int i = 2; i <= n; i++) {
            cin>>fa[i];
        }

        for (int i = 1; i <= n; i++) {
            cin>>a[i]>>b[i];
            c[i] = 0;
        }

        ans = 0;

        for (int i = n; i; i--) {
            c[i] = min(c[i], b[i]);

            if (c[i] < a[i]) {
                c[i] = b[i];
                ans++;
            }

            c[fa[i]] += c[i];
        }

        cout<<ans<<'\n';
    }
}