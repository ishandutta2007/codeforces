#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, a[N], b[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        cin>>n;

        for (int i = 1; i <= n; i++) {
            cin>>a[i];
        }

        sort(a + 1, a + n + 1);

        if (n&1) {
            cout<<"NO"<<'\n';
            continue;
        }

        for (int i = 1; i <= n/2; i++) {
            b[i*2 - 2] = a[i + n/2];
        }

        b[n - 1] = a[1];

        for (int i = 2; i <= n/2; i++) {
            b[(i - 1)*2 - 1] = a[i];
        }

        bool ok = 1;

        for (int i = 0; i < n; i++) {
            int l = b[(i - 1 + n)%n];
            int r = b[(i + 1 + n)%n];

            if (!(b[i] < l && b[i] < r) && !(b[i] > l && b[i]>r)) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout<<"YES"<<'\n';

            for (int i = 0; i < n; i++) {
                cout<<b[i]<<' ';
            }

            cout<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
    }
}