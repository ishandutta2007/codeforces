#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vint;
typedef long long ll;
const int N = 100006;

vint v[N];
int sz[N];

int main () {
    int n; scanf("%d", &n);
    ll ans = 0;
    ll yes = 0;
    vector< pair<int, int> > all;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sz[i]);
        int mn = 1000007;
        int mx = -1;
        bool flag = false;
        for (int j = 0; j < sz[i]; ++j) {
            int x; scanf("%d", &x);
            v[i].push_back(x);
            if (mn < x) {
                flag = true;
            }
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if (flag) ++yes;
        else {
            all.push_back(make_pair(mn, mx));
        }
    }
    sort(all.begin(), all.end());
    int m = (int)all.size();
    for (int i = m - 1; i >= 0; --i) {
        auto iter = lower_bound(all.begin(), all.end(), make_pair(all[i].second, -1));
        ans += iter - all.begin();
        /*if (iter != all.begin()) {
            --iter;
            int pos = iter - all.begin() + 1;
            cout << "i = " << i << " , pos = " << pos << endl;
            ans += pos;
        }*/
    }
    ans += yes * n + (n - yes) * yes;
    cout << ans << endl;
}