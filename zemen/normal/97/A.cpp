#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100;
string s[maxn];
bool f[maxn][maxn];
int a[maxn][maxn];

vector<pair<pii, pii>> d;

const int MUL = 5040;
ll res = 0;

int id[maxn];

char ans[maxn][maxn];
bool NO_ANS = true;

bool check() {
    vector<pii> dom;
    for (auto p: d) {
        pii A, B;
        tie(A, B) = p;
        int c1 = id[a[A.first][A.second]];
        int c2 = id[a[B.first][B.second]];
        if (c1 > c2)
            swap(c1, c2);
        dom.emplace_back(c1, c2);
    }
    sort(dom.begin(), dom.end());
    forn (i, sz(dom) - 1)
        if (dom[i] == dom[i + 1])
            return false;
    if (NO_ANS) {
        NO_ANS = false;
        for (auto p: d) {
            pii A, B;
            tie(A, B) = p;
            int c1 = id[a[A.first][A.second]];
            int c2 = id[a[B.first][B.second]];
            ans[A.first][A.second] = '0' + c1;
            ans[B.first][B.second] = '0' + c2;
        }
    }
    return true;
}

void rec(int i = 0, int k = 0) {
    if (i == 14) {
        assert(k == 7);
        if (check())
            res += MUL;
        return;
    }
    if (id[i] != -1) {
        rec(i + 1, k);
        return;
    }
    for (int mt = i + 1; mt < 14; ++mt) {
        if (id[mt] != -1)
            continue;
        id[i] = id[mt] = k;
        rec(i + 1, k + 1);
        id[i] = id[mt] = -1;
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        cin >> s[i];
        forn (j, m) {
            f[i][j] = s[i][j] != '.';
            ans[i][j] = s[i][j];
        }
    }
    int k = 0;
    forn (i, n - 1)
        forn (j, m - 1) {
            if (f[i][j] && f[i][j + 1] && f[i + 1][j] && f[i + 1][j + 1]) {
                f[i][j] = f[i][j + 1] = f[i + 1][j] = f[i + 1][j + 1] = false;
                a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = k++;
            }
        }
    forn (i, n)
        forn (j, m) {
            if (s[i][j] == '.')
                continue;
            if (i + 1 < n && s[i][j] == s[i + 1][j]) {
                d.emplace_back(pii{i, j}, pii{i + 1, j});
            }
            if (j + 1 < m && s[i][j] == s[i][j + 1]) {
                d.emplace_back(pii{i, j}, pii{i, j + 1});
            }
        }
    //forn (i, n) {
        //forn (j, m)
            //cerr << a[i][j] << ' ';
        //cerr << '\n';
    //}
    assert(sz(d) == 28);
    assert(k == 14);
    forn (i, 14)
        id[i] = -1;
    rec();
    cout << res << '\n';
    forn (i, n)
        cout << ans[i] << '\n';
}