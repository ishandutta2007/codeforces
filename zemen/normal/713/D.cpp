#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1026;
const int LG = 10;
int a[maxn][maxn];
int pr[maxn][maxn];
int n, m;

bool bad(int x1, int x2, int y1, int y2) {
    if (x2 > n || y2 > m)
        return true;
    return pr[x2][y2] + pr[x1][y1] - pr[x2][y1] - pr[x1][y2] > 0;
}

int lg[maxn];
short sp[maxn][maxn][LG][LG];

int get(int x1, int x2, int y1, int y2) {
    int dx = lg[x2 - x1];
    int dy = lg[y2 - y1];
    int res = 0;
    int sx = 1 << dx;
    int sy = 1 << dy;
    res = max(res, (int) sp[x1][y1][dx][dy]);
    res = max(res, (int) sp[x2 - sx][y1][dx][dy]);
    res = max(res, (int) sp[x1][y2 - sy][dx][dy]);
    res = max(res, (int) sp[x2 - sx][y2 - sy][dx][dy]);
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    for (int i = 1; i < maxn; ++i) {
        lg[i] = lg[i - 1];
        if ((2 << lg[i]) <= i)
            ++lg[i];
    }

    scanf("%d%d", &n, &m);
    forn (i, n)
        forn (j, m)
            scanf("%d", a[i] + j);
    forn (i, n)
        forn (j, m)
            pr[i + 1][j + 1] = pr[i + 1][j] + pr[i][j + 1] + (a[i][j] == 0) - pr[i][j];
    forn (i, n)
        forn (j, m) {
            int r = 0;
            if (i > 0)
                r = sp[i - 1][j][0][0] - 1;
            while (!bad(i, i + r + 1, j, j + r + 1))
                ++r;
            sp[i][j][0][0] = r;
        }
    forn (di, LG)
        forn (dj, LG) {
            if (!di && !dj)
                continue;
            for (int i = 0; i + (1 << di) <= n; ++i)
                for (int j = 0; j + (1 << dj) <= m; ++j) {
                    if (dj) {
                        int s = 1 << (dj - 1);
                        sp[i][j][di][dj] = max(sp[i][j][di][dj - 1], sp[i][j + s][di][dj - 1]);
                    } else {
                        int s = 1 << (di - 1);
                        sp[i][j][di][dj] = max(sp[i][j][di - 1][dj], sp[i + s][j][di - 1][dj]);
                    }
                }
        }
    int q;
    scanf("%d", &q);
    forn (i, q) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1, --y1;
        int L = 0, R = min(x2 - x1, y2 - y1) + 1;
        while (L + 1 < R) {
            int C = (L + R) / 2;
            int val = get(x1, x2 - C + 1, y1, y2 - C + 1);
            if (val >= C)
                L = C;
            else
                R = C;
        }
        cout << L << '\n';
    }
}