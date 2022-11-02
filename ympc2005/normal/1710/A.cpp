#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, a[N], cnt;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        cin>>n>>m>>cnt;

        ll sum1 = 0, sum2 = 0;
        bool ok1 = 0, ok2 = 0;

        for (int i = 1; i <= cnt; i++) {
            cin>>a[i];

            if (a[i] >= 2*n) {
                sum1 += a[i]/n;
                ok1 |= a[i]/n > 2;
            }

            if (a[i] >= 2*m) {
                sum2 += a[i]/m;
                ok2 |= a[i]/m > 2;
            }
        }

        if ((sum1 >= m && (ok1 || m%2 == 0)) || (sum2 >= n && (ok2 || n%2 == 0))) {
            cout<<"Yes"<<'\n';
        } else {
            cout<<"No"<<'\n';
        }
    }
}