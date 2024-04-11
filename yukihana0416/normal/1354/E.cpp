#include <bits/stdc++.h>
using namespace std;

#define LL long long
//#define LL __int64
typedef pair<int, int> pii;
typedef pair<LL, LL> pLL;

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
template < typename T, typename ...Args > inline void read(T &x, Args &...args) {read(x); read(args...);}

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
#define mt make_tuple
#define pb push_back
#define all(a) a.begin(),a.end()

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
//const int MOD = (int) 1e9 + 7;
const int MOD = (int) 1000000007;
//const int MOD = 998244353;

template< typename T0, typename T1 > inline void depair(T0 &x, T1 &y, pair<T0, T1> &p) {x = p.fi, y = p.se;}
inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL mod = MOD)
{
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1; for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod; return res;
}

struct Mint
{
    int x;
    Mint() {x = 0;}
    Mint(int _x): x(_x) {if(x < 0 || x >= MOD) x = (x % MOD + MOD) % MOD;}
    Mint(LL _x): x(_x) {if(x < 0 || x >= MOD) x = (x % MOD + MOD) % MOD;}
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        return Mint(x + rhs.x >= MOD ? x + rhs.x - MOD : x + rhs.x);
    }
    Mint operator - (const Mint &rhs) const{
        return Mint(x - rhs.x < 0 ? x - rhs.x + MOD : x - rhs.x);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint((LL)x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint(x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = ((LL)x * rhs.x) % MOD; return *this;
    }
    bool operator == (const Mint &rhs) const{
        return x == rhs.x;
    }
    bool operator != (const Mint &rhs) const{
        return x != rhs.x;
    }
    friend ostream& operator << (ostream &out, const Mint &rhs){
        return out << rhs.x;
    }
    friend istream& operator >> (istream &in, Mint &rhs){
        return in >> rhs.x;
    }
};


const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

void work()
{
    int n, m;
    cin >>n >>m;
    int a, b, c;
    cin >>a >>b >>c;

    vector< vector<int> > G(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >>x >>y;
        G[x].pb(y);
        G[y].pb(x);
    }

    vector<int> vis(n + 1, -1);
    vector<int> p, q;

    vector< vector< vector<int> > > res;

    function<bool(int)> dfs = [&](int u) -> bool
    {
        if(vis[u] == 0) p.pb(u);
        else q.pb(u);

        for(auto v : G[u])
        {
            if(vis[v] != -1)
            {
                if(vis[v] == vis[u]) return 0;
            }
            else
            {
                vis[v] = vis[u] ^ 1;
                if(dfs(v) == 0) return 0;
            }
        }
        return 1;
    };

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == -1)
        {
            p.clear();
            q.clear();

            vis[i] = 0;
            if(dfs(i) == 0)
            {
                cout <<"NO" <<endl;
                return ;
            }

            vector< vector<int> > tmp(2);
            tmp[0] = p;
            tmp[1] = q;

            res.pb(tmp);

        }
    }

    vector< vector<int> > dp(res.size() + 1, vector<int> (2 * n + 1, 0));
    dp[0][n] = 1;
    for(int i = 0; i < res.size(); i++)
    {
        int d = res[i][0].size() - res[i][1].size();

        for(int j = 0; j <= 2 * n; j++)
        {
            if(0 <= j + d && j + d <= 2 * n)
                dp[i + 1][j + d] |= dp[i][j];
            if(0 <= j - d && j - d <= 2 * n)
                dp[i + 1][j - d] |= dp[i][j];
        }
    }

    int d = b - a - c;
    if(!dp[res.size()][d + n])
    {
        cout <<"NO" <<endl;
        return ;
    }

    vector<int> ans(n + 1);

    int nd = d + n, ni = res.size();
    while(ni)
    {
        auto &p = res[ni - 1][0];
        auto &q = res[ni - 1][1];
        int d = p.size() - q.size();

        if(nd - d >= 0 && nd - d <= 2 * n && dp[ni - 1][nd - d])
            nd -= d;
        else
            nd += d, swap(p, q);
        assert(nd <= 2 * n);
        ni--;

        for(auto x : p) ans[x] = 2;
        for(auto x : q) ans[x] = 3;
    }

    for(int i = 1, c = 0; i <= n && c < a; i++)
    {
        if(ans[i] == 3)
        {
            ans[i] = 1;
            c++;
        }
    }

    cout <<"YES" <<endl;
    for(int i = 1; i <= n; i++) cout <<ans[i];
    cout <<endl;
}

int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
//    pre();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}