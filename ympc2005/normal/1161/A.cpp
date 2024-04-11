#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], s[N], t[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= m; i++) {
        cin>>a[i];
        t[a[i]] = i;

        if (!s[a[i]]) {
            s[a[i]] = i;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += !s[i];

        if (i < n) {
            ans += !s[i] || s[i] > t[i + 1];
        } 
        
        if (i > 1) {
            ans += !s[i] || s[i] > t[i - 1];
        }
    }

    cout<<ans<<'\n';
}