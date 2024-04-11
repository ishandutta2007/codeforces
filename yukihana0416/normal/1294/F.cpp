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
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL m = MOD) {LL res = 1; for(; n; n >>= 1, a = a * a % m) if(n & 1) res = res * a % m; return res;}

int n;
vector<int> G[maxn];
int dp[maxn][3];
vector<int> vec[maxn][3];

vector<int> mer(vector<int> &lhs, vector<int> &rhs)
{
    vector<int> res(lhs);
    for(auto v : rhs) res.pb(v);
    return res;
}

void dfs(int u, int fa)
{
    int *f = dp[u];
    f[0] = 0;
    f[1] = -n;
    f[2] = -n;

    vector<int> *fv = vec[u];
    for(int i = 0; i < 3; i++) fv[i].pb(u);

    for(auto v : G[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        int *g = dp[v];
        vector<int> *gv = vec[v];

        int t[3] = {0};
        vector<int> tv[3];

        for(int i = 0; i < 3; i++)
        {
            if(f[i] > g[i] + (i == 2 ? 0 : 1))
            {
                t[i] = f[i];
                tv[i] = fv[i];
            }
            else
            {
                t[i] = g[i] + (i == 2 ? 0 : 1);
                tv[i] = gv[i];
            }
        }

        if(t[1] < f[0] + g[0] + 1)
        {
            t[1] = f[0] + g[0] + 1;
            tv[1] = mer(fv[0], gv[0]);
        }
        if(t[2] < f[0] + g[1] + 1)
        {
            t[2] = f[0] + g[1] + 1;
            tv[2] = mer(fv[0], gv[1]);
        }
        if(t[2] < f[1] + g[0] + 1)
        {
            t[2] = f[1] + g[0] + 1;
            tv[2] = mer(fv[1], gv[0]);
        }

        for(int i = 0; i < 3; i++) f[i] = t[i], fv[i] = tv[i];
    }
}

void work()
{
    read(n);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        read(x), read(y);
        G[x].pb(y);
        G[y].pb(x);
    }

    dfs(1, 1);
    cout <<dp[1][2] <<endl;
    for(auto v : vec[1][2]) cout <<v <<" "; cout <<endl;
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