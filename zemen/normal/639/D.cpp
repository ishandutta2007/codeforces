#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n, k, B, C;
const int maxn = 200200;
vector<int> a[5];
vector<int> vals[5];

int L[5], R[5];

ll cost(int from, int to) {
    assert(to >= from);
    ll diff = to - from;
    return (diff % 5) * C + (diff / 5) * B;
}

void solve() {
    ll res = infl;
    forn (ii, 5) {
        ll total = 0;
        int cnt = 0;
        forn (i, 5)
            L[i] = R[i] = 0;
        forn (qw, sz(vals[ii])) {
            int val = vals[ii][qw];

            forn (i, 5) {
                while (R[i] < sz(a[i]) && a[i][R[i]] <= val) {
                    total += cost(a[i][R[i]], val);
                    ++cnt;
                    ++R[i];
                }
            }
            while (cnt > k) {
                int best = -1;
                ll bestCost = -infl;
                forn (i, 5) {
                    if (L[i] >= R[i])
                        continue;
                    ll cCost = cost(a[i][L[i]], val);
                    if (cCost > bestCost)
                        best = i, bestCost = cCost;
                }
                assert(best != -1);
                total -= bestCost;
                --cnt;
                L[best]++;
            }
            if (cnt == k)
                res = min(res, total);

            if (qw + 1 < sz(vals[ii])) {
                int nx = vals[ii][qw + 1];
                total += cnt * ll((nx - val) / 5) * ll(B);
            }
        }
    }
    cout << res << '\n';
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> n >> k >> B >> C;
    B = min(B, 5 * C);
    forn (i, n) {
        int x;
        scanf("%d", &x);
        int xrem = ((x % 5) + 5) % 5;
        a[xrem].push_back(x);
        forn (j, 5)
            vals[(xrem + j) % 5].push_back(x + j);
    }
    forn (i, 5) {
        sort(vals[i].begin(), vals[i].end());
        sort(a[i].begin(), a[i].end());
    }
    solve();

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}