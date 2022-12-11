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
//const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
int MOD = 998244353;
const int e5 = (int) 1e5 + 5;
const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL mod = MOD)
{
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1; for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod; return res;
}

struct Mint
{
    LL x;
    Mint() {x = 0;}
    Mint(int _x): x(_x) {}
    Mint(LL _x): x(_x) {}
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        LL res = x + rhs.x; if(res >= MOD) res -= MOD; return Mint(res);
    }
    Mint operator - (const Mint &rhs) const{
        LL res = x - rhs.x; if(res < 0) res += MOD; return Mint(res);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint(x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint(x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = (x * rhs.x) % MOD; return *this;
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

int n;
int a[5 * e5];
int b[5 * e5];

int m;
int c[5 * e5];

LL dp[5 * e5];
LL T[5 * e5];

void add(int pos, LL v)
{
    for(int i = pos; i; i -= lowbit(i))
    {
        T[i] += v;
    }
}

LL sum(int pos)
{
    LL res = 0;
    for(int i = pos; i <= n + 3; i += lowbit(i))
    {
        res += T[i];
    }
    return res;
}

int idx[5 * e5];
bool vis[5 * e5];

void work()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int i = 1; i <= n; i++) read(b[i]);

    read(m);
    for(int i = 1; i <= m; i++) read(c[i]);

    for(int i = 1; i <= n; i++) a[i]++;
    for(int i = 1; i <= m; i++) c[i]++;

    c[0] = 1;
    c[++m] = n + 2;
    a[n + 1] = n + 2;
    b[n + 1] = 0;

    for(int i = 0; i <= m; i++) idx[c[i]] = i;

//    for(int i = 2; i <= n + 3; i++) add(i, 3e14);

//    add(1, -sum(1));

    vis[1] = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        int j = idx[a[i]];
        if(j)
        {
            dp[i] = sum(c[j - 1]);
            if(vis[c[j - 1]] == 0) dp[i] = 1e16;
        }

        if(b[i] < 0) add(n + 3, b[i]);
        else add(a[i] - 1, b[i]);

        if(j)
        {
            LL t = dp[i] - sum(a[i]);

            if(t < 0 || vis[a[i]] == 0)
            {
                add(a[i], t);
                add(a[i] - 1, -t);

                vis[a[i]] = 1;
            }
        }
    }

    if(dp[n + 1] > 1e15)
    {
        cout <<"NO" <<endl;
    }
    else
    {
        cout <<"YES" <<endl;
        cout <<dp[n + 1] <<endl;
    }
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