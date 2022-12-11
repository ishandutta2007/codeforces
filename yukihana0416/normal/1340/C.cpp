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

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
//int MOD = 998244353;

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


const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

int n, m;
int dp[11111][1111];
int d[11111];
int g, r;

void work()
{
    read(n, m);
    for(int i = 1; i <= m; i++) read(d[i]);
    read(g, r);
    sort(d + 1, d + 1 + m);

    for(int i = 1; i <= m; i++)
        for(int j = 0; j <= g; j++)
            dp[i][j] = -1;

    deque< tuple<int, int, int> > dq;

    dq.emplace_front(mt(1, 0, 0));
    while(!dq.empty())
    {
        int x, y, z;
        tie(x, y, z) = dq.front();
        dq.pop_front();

        if(dp[x][y] != -1) continue;
        dp[x][y] = z;

        if(y == g) dq.emplace_back(mt(x, 0, z + 1));
        if(x > 1 && y + d[x] - d[x - 1] <= g) dq.emplace_front(mt(x - 1, y + d[x] - d[x - 1], z));
        if(x < m && y + d[x + 1] - d[x] <= g) dq.emplace_front(mt(x + 1, y + d[x + 1] - d[x], z));
    }

    LL ans = -1;
    for(int j = 0; j <= g; j++)
        if(dp[m][j] != -1)
        {
            if(ans == -1) ans = (LL)dp[m][j] * (r + g) + j;
            Min(ans, (LL) dp[m][j] * (r + g) + j);
        }
    cout <<ans <<endl;
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