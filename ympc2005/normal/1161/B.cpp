#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, m, a[N], b[N];

map <pii, int> mp;

bool chk_(int k) {
    for (int i = 1; i <= m; i++) {
        if (!mp.count(pii((a[i] + k)%n, (b[i] + k)%n))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= m; i++) {
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        mp[pii(a[i], b[i])] = mp[pii(b[i], a[i])] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (n%i == 0 && chk_(i)) {
            cout<<"Yes"<<'\n';
            exit(0);
        }
    }

    cout<<"No"<<'\n';
}