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

const int maxn = 1010;
char a[maxn][maxn];
int dist[maxn][maxn];
int m, n;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
map<char, int> cdir{{'L', 3}, {'R', 2}, {'U', 1}, {'D', 0}};

bool bad(int tx, int ty) {
    if (tx < 0 || tx >= n || ty < 0 || ty >= m)
        return true;
    return a[tx][ty] == '*';
}

pii q[maxn * maxn];
void bfs(int x, int y) {
    forn (i, n)
        forn (j, m)
            dist[i][j] = inf;
    dist[x][y] = 0;
    int qr = 0;
    q[qr++] = {x, y};
    forn (ii, qr) {
        x = q[ii].first, y = q[ii].second;
        forn (dir, 4) {
            int tx = x + dx[dir], ty = y + dy[dir];
            if (bad(tx, ty))
                continue;
            if (dist[tx][ty] < inf)
                continue;
            dist[tx][ty] = dist[x][y] + 1;
            q[qr++] = {tx, ty};
        }
    }
}

void ass(bool ex) {
    if (!ex) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #endif
    int k;
    cin >> n >> m >> k;
    int sx = -1, sy = -1;
    forn (i, n) {
        scanf("%s", a[i]);
        forn (j, m)
            if (a[i][j] == 'X')
                sx = i, sy = j;
    }
    assert(sx != -1);
    bfs(sx, sy);
    int x = sx, y = sy;
    string res = "";
    forn (i, k) {
        for (auto p: cdir) {
            char ch = p.first;
            int dir = p.second;
            int tx = x + dx[dir], ty = y + dy[dir];
            if (bad(tx, ty))
                continue;
            if (dist[tx][ty] > k - i - 1)
                continue;
            res += ch;
            x = tx, y = ty;
            break;
        }
        ass(sz(res) == i + 1);
    }
    cout << res << '\n';
}