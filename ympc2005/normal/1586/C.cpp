#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

string s[N];

int n, m, a[N], q;

int main() {
    ios :: sync_with_stdio(false);
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        cin>>s[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') {
                a[j] = 1;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        a[i] += a[i - 1];
    }

    cin>>q;

    for (int l, r, i = 1; i <= q; i++) {
        cin>>l>>r, l--, r--;
        cout<<(a[r] - a[l] ? "NO" : "YES")<<'\n';
    }
}