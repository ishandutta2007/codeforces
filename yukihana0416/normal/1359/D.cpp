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


const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

int n;
int a[maxn];

int f[maxn << 2];
int T[maxn << 2];

void build(int l, int r, int id)
{
    f[id] = T[id] = 0;
    if(l == r) return ;
    int mid = MID(l, r);
    build(lson);
    build(rson);
}

void lazy(int id)
{
    if(f[id])
    {
        f[ls] += f[id];
        f[rs] += f[id];

        T[ls] += f[id];
        T[rs] += f[id];

        f[id] = 0;
    }
}

void add(int L, int R, int v, int l, int r, int id)
{
    if(L <= l && r <= R)
    {
        f[id] += v;
        T[id] += v;
        return ;
    }

    lazy(id);

    int mid = MID(l, r);
    if(L <= mid) add(L, R, v, lson);
    if(mid < R) add(L, R, v, rson);

    T[id] = max(T[ls], T[rs]);
}

void work()
{
    read(n);
    build(1, n, 1);

    int ans = 0;
    stack< pair<int, int> > S;
    for(int i = 1; i <= n; i++)
    {
        int x; read(x);
        add(1, i, x, 1, n, 1);

        while(S.size() && S.top().fi <= x)
        {
            int y = S.top().fi;
            int q = S.top().se;
            S.pop();

            int p = 0;
            if(S.size()) p = S.top().se;

            add(p + 1, q, y, 1, n, 1);
        }

        int L = 0;
        if(S.size()) L = S.top().se;
        S.push(mk(x, i));
        add(L + 1, i, -x, 1, n, 1);

        ans = max(ans, T[1]);

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