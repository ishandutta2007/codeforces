#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int T, n;

ll a[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>T;

    while (T--) {
        cin>>n;
        int pos = 0;

        for (int i = 1; i <= n; i++) {
            cin>>a[i];
            a[i] += a[i - 1];

            if (!a[i] && !pos) {
                pos = i;
            }
        }

        if (a[n]) {
            cout<<"No"<<'\n';
            continue;
        }

        int tag = 0;

        for (int i = pos + 1; i <= n; i++) {
            if (a[i]) {
                tag = 1;
            }
        }

        for (int i = 1; i <= pos; i++) {
            if (a[i] < 0) {
                tag = 1;
            }
        }

        if (tag) {
            cout<<"No"<<'\n';
        } else {
            cout<<"Yes"<<'\n';
        }
    }
}