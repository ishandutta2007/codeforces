#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m, a[N];

bool chk_(int x) {
    int val = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] + x < m) {
            if (a[i] + x < val) {
                return 0;
            }

            val = max(a[i], val);
            continue;
        }

        if (a[i] + x - m >= val) {
            continue;
        }

        val = max(a[i], val);
    }

    return 1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    int l = 0, r = m - 1;

    while (l < r) {
        int mid = (l + r)>>1;

        if (chk_(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout<<l<<'\n';
}