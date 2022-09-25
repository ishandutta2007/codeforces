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

const int maxn = 105;
int a[maxn][maxn];
pair<int, int> pos[maxn][maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    forn (i, n)
        forn (j, m)
            pos[i][j] = {i, j};
    forn (i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            --x;
            pos[x][m] = pos[x][0];
            forn (i, m)
                pos[x][i] = pos[x][i + 1];
        } else if (type == 2) {
            int x;
            cin >> x;
            --x;
            pos[n][x] = pos[0][x];
            forn (i, n)
                pos[i][x] = pos[i + 1][x];
        } else {
            int x, y, val;
            cin >> x >> y >> val;
            --x, --y;
            a[pos[x][y].first][pos[x][y].second] = val;
        }
    }
    forn (i, n) {
        forn (j, m) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}