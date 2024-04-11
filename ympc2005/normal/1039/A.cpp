#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, p[N];

ll t, a[N], b[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>t;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin>>p[i];
    }

    if (p[n] != n) {
        cout<<"No"<<'\n';
        exit(0);
    }

    for (int i = 1; i < n; i++) {
        if (p[i] != i && p[i] != p[i + 1]) {
            cout<<"No"<<'\n';
            exit(0);
        }
    }

    b[n] = a[n] + t + 1;

    for (int i = n - 1; i; i--) {
        if (p[i] == p[i + 1]) {
            b[i] = b[i + 1] - 1;
        } else {
            b[i] = min(a[i + 1] + t - 1, b[i + 1] - 1);
        }
    }

    for (int i = 1; i < n; i++) {
        if (p[i] == p[i + 1] && a[i + 1] + t > b[i]) {
            cout<<"No"<<'\n';
            exit(0);
        }
    }

    cout<<"Yes"<<'\n';

    for (int i = 1; i <= n; i++) {
        cout<<b[i]<<' ';
    }
}