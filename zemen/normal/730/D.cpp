#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
int l[maxn];
int t[maxn];
const ll B = 1e5;

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    ll r;
    cin >> n >> r;
    forn (i, n)
        cin >> l[i];
    forn (i, n) {
        cin >> t[i];
        if (t[i] < l[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<ll> v;
    ll res = 0;

    ll carry = 0;
    ll tm = 0;
    forn (i, n) {
        ll T = l[i] * 2 - carry;
        ll need = (T - t[i] + r - 1) / r;
        need = max(need, 0ll);
        res += need;

        if (need == 0) {
            if (carry >= l[i])
                tm += l[i];
            else
                tm += T;
            carry = max(0ll, carry - l[i]);
            continue;
        }

        carry = need * r - (T - t[i]);
        tm += t[i];

        if (res <= B) {
            vector<ll> v2;
            forn (i, need) {
                ll x = tm + carry - (i + 1) * r;
                v2.push_back(x);
            }
            reverse(v2.begin(), v2.end());
            v.insert(v.end(), v2.begin(), v2.end());
        }
    }
    //cerr << tm << '\n';
    cout << res << '\n';
    if (res <= B) {
        for (auto x: v)
            cout << x << ' ';
        cout << '\n';
    }
}