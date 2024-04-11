#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, q, a[N], b[N], cnt, pos, A[N], B[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    a[pos] = -1;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];

        if (a[i] > a[pos]) {
            pos = i;
        }
    }

    for (int i = pos + 1; i <= n; i++) {
        b[cnt++] = a[i];
    }

    int mx = a[1];

    for (int i = 2; i <= pos; i++) {
        A[i - 1] = mx, B[i - 1] = a[i];
        
        if (a[i] > mx) {
            swap(a[i], mx);
        }

        b[cnt++] = a[i];
    }

    while (q--) {
        ll t;
        cin>>t;

        if (t < pos) {
            cout<<A[t]<<' '<<B[t]<<'\n';
        } else {
            cout<<mx<<' '<<b[(t - pos)%cnt]<<'\n';
        }
    }
}