#include <iostream>
#include <vector>

using namespace std;

long long dp[3030][3030];
int sz[3030][3030];
int dist[3030][3030];
vector<int> gph[3030];

int dfs(int x, int p, int r, int dis)
{
    dist[r][x] = dis;
    int ret = 1;
    for(auto y : gph[x]) if(y != p) ret += dfs(y, x, r, dis + 1);
    return sz[p][x] = ret;
}

long long f(int x, int y)
{
    if(dp[x][y]) return dp[x][y];
    if(dp[y][x]) return dp[y][x];

    long long ret = 0;
    int xsz = 1, ysz = 1;
    for(auto _x : gph[x])
    {
        if(dist[_x][y] < dist[x][y]) continue;
        ret = max(ret, f(_x, y));
        xsz += sz[x][_x];
    }
    for(auto _y : gph[y])
    {
        if(dist[x][_y] < dist[x][y]) continue;
        ret = max(ret, f(x, _y));
        ysz += sz[y][_y];
    }

    return dp[x][y] = ret + xsz * ysz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    for(int i = 0; i < n; ++i) dfs(i, -1, i, 0);

    long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(auto j : gph[i]) ans = max(ans, f(i, j));

    cout << ans;
    return 0;
}