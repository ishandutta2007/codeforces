#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

const int M = 998'244'353;
vector<int> A[202020];
vector<int> B[202020];
int dst[23][202020];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        A[x].push_back(y);
        B[y].push_back(x);
    }

    for(int i = 0; i <= 22; ++i)
        for(int j = 0; j < 202020; ++j) dst[i][j] = -1;

    priority_queue<piii, vector<piii>, greater<piii>> Q;
    Q.push({0, {0, 0}});
    while(Q.size())
    {
        piii t = Q.top(); Q.pop();
        piii p = t; if(p.ff >= 20) p.ff = 20 - (p.ff & 1);
        if(dst[p.ff][p.rr] != -1) continue;
        dst[p.ff][p.rr] = p.ee; if(p.ff >= 19) dst[p.ff + 2][p.rr] = t.ff;
        for(auto x : A[t.rr]) Q.push({(t.ff & 1 ? t.ff + 1 : t.ff), {t.ee + 1, x}});
        for(auto x : B[t.rr]) Q.push({(t.ff & 1 ? t.ff : t.ff + 1), {t.ee + 1, x}});
    }

    int ans = (int)1e9;
    for(int i = 0; i < 19; ++i)
    {
        if(dst[i][n - 1] != -1) ans = min(ans, (1 << i) - 1 + dst[i][n - 1]);
    }
    if(ans != (int)1e9) cout << ans;
    else if(dst[22][n - 1] == -1 || dst[21][n - 1] != -1 && dst[21][n - 1] < dst[22][n - 1])
    {
        ans = 1;
        for(int i = 0; i < dst[21][n - 1]; ++i) ans = 1ll * ans * 2 % M;
        ans = (1ll * ans + dst[19][n - 1] - 1) % M;
        if(ans < 0) ans += M;
        cout << ans;
    }
    else
    {
        ans = 1;
        for(int i = 0; i < dst[22][n - 1]; ++i) ans = 1ll * ans * 2 % M;
        ans = (1ll * ans + dst[20][n - 1] - 1) % M;
        if(ans < 0) ans += M;
        cout << ans;
    }
}