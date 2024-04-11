#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 998244353;

int n, m, a[N], b[N];

void work_() {
    cin>>n>>m;

    for (int i = 1; i <= m; i++) {
        cin>>a[i];
    }

    if (m == 1) {
        if (n == 2) {
            cout<<1<<'\n';
        } else {
            cout<<2<<'\n';
        }

        return;
    }

    sort(a + 1, a + m + 1);
    int tot = 0;

    for (int i = 1; i < m; i++) {
        b[++tot] = a[i + 1] - a[i] - 1;
    }

    b[++tot] = n - a[m] + a[1] - 1;
    sort(b + 1, b + tot + 1);
    reverse(b + 1, b + tot + 1);

    int cnt = 0;

    for (int i = 1; i <= tot; i++) {
        int x = b[i] - 4*(i - 1);

        if (x > 0) {
            cnt++;
            x -= 2;

            if (x > 0) {
                cnt += x;
            }
        }
    }

    cout<<n - cnt<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}