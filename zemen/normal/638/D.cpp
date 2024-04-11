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

int n, m, k;
const int maxn = 104;
char a[maxn][maxn][maxn];

int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 0, 0, 1, 0};
int dz[] = {0, 0, -1, 0, 0, 1};

int get(int x, int y, int z) {
    if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= k)
        return 0;
    return a[x][y][z] - '0';
}

bool check(int x, int y, int z) {
    if (!get(x, y, z))
        return false;
    forn (d1, 3) {
        int x1 = x + dx[d1];
        int y1 = y + dy[d1];
        int z1 = z + dz[d1];
        if (!get(x1, y1, z1))
            continue;
        forab (d2, 3, 6) {
            int x2 = x + dx[d2];
            int y2 = y + dy[d2];
            int z2 = z + dz[d2];
            if (!get(x2, y2, z2))
                continue;
            if (d1 == d2 - 3)
                return true;
            int x3 = x + dx[d1] + dx[d2];
            int y3 = y + dy[d1] + dy[d2];
            int z3 = z + dz[d1] + dz[d2];
            if (!get(x3, y3, z3))
                return true;
        }
    }
    return false;
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> n >> m >> k;
    forn (i, n)
        forn (j, m)
            scanf("%s", a[i][j]);
    int res = 0;
    forn (i, n)
        forn (j, m)
            forn (l, k)
                res += check(i, j, l);
    cout << res << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}