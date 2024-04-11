#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long i64;
typedef long double ld;

const int INF = 1000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 10101;

int n;
int l[maxn], r[maxn];
int shr[maxn], k;
i64 d[2][maxn];
int pos;

int solve() {
    scanf("%d", &n);
    scanf("%d", &pos);
    shr[k++] = pos;
    forn(i, n) {
        scanf("%d%d", &l[i], &r[i]);
        shr[k++] = l[i];
        shr[k++] = r[i];
    }
    sort(shr, shr+k);
    k = unique(shr, shr+k) - shr;
    forn(i, n) {
        l[i] = lower_bound(shr, shr+k, l[i]) - shr;
        r[i] = lower_bound(shr, shr+k, r[i]) - shr;
    }
    pos = lower_bound(shr, shr+k, pos) - shr;

    forn(i, k) d[0][i] = abs(shr[i] - shr[pos]);

    forn(I, n) {
        int x = I%2;
//        forn(i, k) cout << d[x][i] << " "; cout << endl;
        int y = !x;
        i64 mn = 1e18;
        for (int i = 0; i != l[I]; ++i) {
            mn = min(mn, d[x][i] - shr[i]);
            d[y][i] = mn + shr[l[I]];
        }
        for (int i = l[I]; i <= r[I]; ++i) {
            d[y][i] = d[x][i];
        }
        mn = 1e18;
        for (int i = k-1; i != r[I]; --i) {
            mn = min(mn, d[x][i] + shr[i]);
            d[y][i] = mn - shr[r[I]];
        }
        for (int i = 1; i < k; ++i) {
            d[y][i] = min(d[y][i], d[y][i-1] + shr[i] - shr[i-1]);
        }
        for (int i = k-2; i >= 0; --i) {
            d[y][i] = min(d[y][i], d[y][i+1] + shr[i+1] - shr[i]);
        }
    }
//    forn(i, k) cout << d[n/2][i] << " "; cout << endl;
    cout << *min_element(d[n%2], d[n%2]+k) << endl;
    return 0;
}