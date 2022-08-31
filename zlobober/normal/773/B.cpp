#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n;
int cnt[5];
int ta[5];
int tb[5];

int x[5];

int sc[] = {500, 1000, 1500, 2000, 2500, 3000};

int s[5];
int score(int *t, int k) {
    forn (i, 5) {
        int p = x[i];
        int q = n + k;
        int d = 0;
        while (d < 5 && p * (2 << d) <= q)
            ++d;
        s[i] = sc[d];
    }
    int res = 0;
    forn (i, 5) {
        if (t[i] == -1)
            continue;
        res += s[i] - (s[i] / 250) * t[i];
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, 5) {
        cin >> ta[i];
        if (ta[i] != -1)
            cnt[i]++;
    }
    forn (i, 5) {
        cin >> tb[i];
        if (tb[i] != -1)
            cnt[i]++;
    }
    forn (ii, n - 2) {
        forn (i, 5) {
            int t;
            cin >> t;
            if (t != -1)
                cnt[i]++;
        }
    }
    const int B = 1e5;
    for (int k = 0; k < B; ++k) {
        forn (i, 5)
            x[i] = cnt[i];
        forn (i, 5) {
            if (ta[i] == -1 || tb[i] == -1)
                continue;
            if (ta[i] <= tb[i])
                continue;
            x[i] += k;
        }
        if (score(ta, k) > score(tb, k)) {
            cout << k << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}