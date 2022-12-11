#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int, int> pii;

template< typename T > inline void read(T &x)
{
    static char _c;
    static bool _f;

    x = 0;
    _f = 0;
    _c = getchar();

    while(_c < '0' || '9' < _c) {if(_c == '-') _f = true; _c = getchar();}
    while('0' <= _c && _c <= '9') {x = (x << 1) + (x << 3) + (_c & 15); _c = getchar();}
    if(_f) x = -x;
}

template < typename T > inline void Min(T &x, T y) {if(y < x) x = y;}
template < typename T > inline void Max(T &x, T y) {if(x < y) x = y;}


#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) ((l)+(((r)-(l))>>1))
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL m = MOD) {LL res = 1; for(; n; n >>= 1, a = a * a % m) if(n & 1) res = res * a % m; return res;}

int n;
vector<int> G[3333];
int sz[3333][3333];
LL dp[3333][3333];

void dfs(int u, int f, int rt)
{
    sz[rt][u] = 1;
    for(auto v : G[u])
    {
        if(v == f) continue;
        dfs(v, u, rt);
        sz[rt][u] += sz[rt][v];
    }
}

LL DP(int u, int v)
{
    if(dp[u][v] != -1) return dp[u][v];
    if(G[u].size() == 1 && G[v].size() == 1 && u != v) return dp[u][v] = 0;

    LL tmp = 0;
    auto get = [](LL &a, LL b) {if(a < b) a = b;};

    for(auto k : G[u])
    {
        if(sz[v][k] > sz[v][u]) continue;
        get(tmp, min(DP(k, v), DP(v, k)) + sz[v][k] * sz[k][v]);
    }

    if(u != v)
    {
        for(auto k : G[v])
        {
            if(sz[u][k] > sz[u][v]) continue;
            get(tmp, min(DP(k, u), DP(u, k)) + sz[u][k] * sz[k][u]);
        }
    }

    return dp[u][v] = dp[v][u] = tmp;
}

void work()
{
    cin >>n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >>x >>y;
        G[x].pb(y);
        G[y].pb(x);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = -1;

    for(int i = 1; i <= n; i++) dfs(i, i, i);

    LL ans = 0;
    auto get = [](LL &a, LL b) {if(a < b) a = b;};

    for(int i = 1; i <= n; i++) get(ans, DP(i, i));

    cout <<ans <<endl;
}


int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}