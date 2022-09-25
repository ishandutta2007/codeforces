#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 100001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1010;
char a[maxn][maxn];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool used[maxn][maxn];

int dist[maxn][maxn][3];

int col1[] = {'1', '2', '3'};
int col2[] = {'2', '3', '1'};

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
        scanf("%s", a[i]);
    vector<int> D;
    forn (i, n)
        forn (j, m)
            forn (qwer, 3)
                dist[i][j][qwer] = INF;
    forn (qwer, 3)
        {
            int FIRST = col1[qwer], SECOND = col2[qwer];
            queue<pair<int, int>> o;
            memset(used, 0, sizeof(used));
            forn (i, n)
                forn (j, m)
                {
                    if (a[i][j] == FIRST)
                    {
                        o.emplace(i, j);
                        used[i][j] = true;
                    }
                }
            o.emplace(-1, -1);
            int len = 0;
            int best = INF;
            while (sz(o) > 1)
            {
                int x = o.front().first;
                int y = o.front().second;
                o.pop();
                if (x == -1 && y == -1)
                {
                    ++len;
                    o.emplace(x, y);
                    continue;
                }
                dist[x][y][qwer] = len;
                if (a[x][y] == SECOND)
                    best = min(best, len);
                forn (dir, 4)
                {
                    int cx = x + dx[dir];
                    int cy = y + dy[dir];
                    if (cx < 0 || cx >= n || cy < 0 || cy >= m || a[cx][cy] == '#')
                        continue;
                    if (used[cx][cy])
                        continue;
                    used[cx][cy] = true;
                    o.emplace(cx, cy);
                }
            }
            D.push_back(best - 1);
        }
    int res = INF;
    res = min(res, D[0] + D[1]);
    res = min(res, D[1] + D[2]);
    res = min(res, D[0] + D[2]);

    forn (i, n)
        forn (j, m)
            res = min(res, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - 2);
    
    if (res >= INF / 2)
        res = -1;
    cout << res << '\n';
    return 0;
}