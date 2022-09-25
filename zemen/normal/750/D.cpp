#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 33;
int a[maxn];
int n;
const int maxb = 308;

bool was[maxb][maxb];
char d[maxb][maxb][maxn][5][3][3];

void go(int x, int y, int id, int t, int dx, int dy) {
    char &mm = d[x][y][id][t][dx + 1][dy + 1];
    if (mm)
        return;
    mm = true;
    was[x][y] = true;
    if (t + 1 == a[id]) {
        if (id + 1 == n)
            return;
        int dx1, dy1, dx2, dy2;
        if (abs(dx) + abs(dy) == 1) {
            if (abs(dx) == 1) {
                dx1 = dx2 = dx;
                dy1 = -1, dy2 = 1;
            } else {
                dy1 = dy2 = dy;
                dx1 = -1, dx2 = 1;
            }
        } else {
            dx1 = dx;
            dy1 = 0;
            dx2 = 0;
            dy2 = dy;
        }
        go(x + dx1, y + dy1, id + 1, 0, dx1, dy1);
        go(x + dx2, y + dy2, id + 1, 0, dx2, dy2);
        return;
    }
    go(x + dx, y + dy, id, t + 1, dx, dy);
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        cin >> a[i];
    go(maxb / 2, maxb / 2, 0, 0, 0, 1);
    int res = 0;
    forn (i, maxb)
        forn (j, maxb) {
            res += was[i][j];
        }
    cout << res << '\n';
}