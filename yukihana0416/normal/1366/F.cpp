#include <bits/stdc++.h>
using namespace std;

#define LL long long
//#define LL __int64
typedef pair<int, int> pii;
typedef pair<LL, LL> pLL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;

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
#define epb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;
//const int MOD = 998244353;
//const int MOD = (int) 911451407;

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
    Mint():x(0) {}
    Mint(int _x): x(_x)
    {
        if(x < 0 || x >= MOD) x %= MOD;
        if(x < 0) x += MOD;
    }
    Mint(LL _x)
    {
        if(_x < 0 || _x >= MOD) _x %= MOD;
        if(_x < 0) _x += MOD;
        x = _x;
    }
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        return Mint(x + rhs.x >= MOD ? x - MOD + rhs.x : x + rhs.x);
    }
    Mint operator - (const Mint &rhs) const{
        return Mint(x - rhs.x < 0 ? x - rhs.x + MOD : x - rhs.x);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint((LL)x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint((LL)x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator -= (const Mint &rhs) {
        x -= rhs.x; if(x < 0) x += MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = ((LL)x * rhs.x) % MOD; return *this;
    }
    Mint& operator /= (const Mint &rhs) {
        x = (LL)x * fp(rhs.x, -1) % MOD; return *this;
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

    Mint rev() {return Mint(fp(x, -1));}
    Mint pow(int k) {return Mint(fp(x, k));}
    Mint pow(const Mint &t) {return Mint(fp(x, t.x));}
};


const int maxn = (int) 1e5 + 20;
const int maxm = (int) 2e6 + 20;


void work()
{
    int n, m, q;
    cin >>n >>m >>q;
    vector< vector<pii> > G(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >>x >>y >>z;
        G[x].pb(mk(y, z));
        G[y].pb(mk(x, z));
    }

    vector< vector<int> > dp(m + 1, vector<int> (n + 1, -1));

    dp[0][1] = 0;
    for(int i = 0; i < m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(dp[i][j] == -1) continue;
            for(auto pr : G[j])
            {
                int to = pr.fi;
                int w = pr.se;
                Max(dp[i + 1][to], dp[i][j] + w);
            }
        }

    vector<int> t(n + 1, 0);
    for(int i = 1; i <= n; i++)
        for(auto pr : G[i])
            Max(t[i], pr.se);

    vector<pii> line(n);
    for(int i = 1; i <= n; i++)
        line[i - 1] = mk(dp[m][i], t[i]);

    sort(rall(line));
    vector<pii> lQ;
    vector<int> pQ;

    auto cross_point = [](pii v1, pii v2)
    {
        return (v1.fi - v2.fi) / (v2.se - v1.se);
    };

    lQ.pb(line[0]);
    for(int i = 1; i < n; i++)
    {
        pii v1 = line[i];
        if(lQ.size() && lQ.back().se >= v1.se) continue;

        while(lQ.size() >= 2 && cross_point(v1, lQ.back()) <= pQ.back())
        {
            lQ.pop_back();
            pQ.pop_back();
        }

        pQ.pb(cross_point(lQ.back(), v1));
        lQ.pb(v1);
    }

    Mint ans = 0;
    int now = 0;
    for(int i = 0; i < pQ.size() && now < q - m; i++)
    {
        now++;
        int nxt = min(pQ[i], q - m);
        Mint head = Mint(lQ[i].fi) + Mint(lQ[i].se) * Mint(now);
        Mint tail = Mint(lQ[i].fi) + Mint(lQ[i].se) * Mint(nxt);
        ans += (head + tail) * (nxt - now + 1) / 2;
        now = nxt;
    }

    if(now < q - m)
    {
        now++;
        int nxt = q - m;
        pii v1 = lQ.back();
        Mint head = Mint(v1.fi) + Mint(v1.se) * now;
        Mint tail = Mint(v1.fi) + Mint(v1.se) * nxt;
        ans += (head + tail) * (nxt - now + 1) / 2;
    }

    for(int i = 1; i <= m; i++)
    {
        int mx = 0;
        for(int j = 1; j <= n; j++)
            mx = max(mx, dp[i][j]);
        ans += mx;
    }

    cout <<ans <<endl;
}

int main()
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