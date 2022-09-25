#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1005;
int a[maxn][maxn];
int n;

vector<int> ask(vector<int> v) {
    if (v.empty())
        return vector<int>(n, inf);
    sort(v.begin(), v.end());
    cout << sz(v) << endl;
    for (int x: v) {
        cout << x + 1 << ' ';
        assert(0 <= x && x < n);
    }
    cout << endl;

    vector<int> res(n);
#ifdef LOCAL
    forn (i, n) {
        int r = inf;
        for (int x: v)
            r = min(r, a[i][x]);
        res[i] = r;
    }
#else
    forn (i, n)
        cin >> res[i];
#endif
    return res;
}

void answer(vector<int> v) {
    cout << -1 << endl;
    for (int x: v)
        cout << x << ' ';
    cout << endl;
    exit(0);
}

vector<int> d[2][10];

bool bit(int x, int n) {
    return (x >> n) & 1;
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    cin >> n;
#ifdef LOCAL
    forn (i, n)
        forn (j, n)
            cin >> a[i][j];
#endif
    forn (t, 2) {
        forn (q, 10) {
            vector<int> v;
            forn (i, n) {
                if (bit(i, q) == t)
                    v.push_back(i);
            }
            d[t][q] = ask(v);
        }
    }
    vector<int> ans(n);
    forn (i, n) {
        int r = inf;
        forn (q, 10) {
            bool t = !bit(i, q);
            r = min(r, d[t][q][i]);
        }
        ans[i] = r;
    }
    answer(ans);
}