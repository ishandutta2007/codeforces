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
LL a[6 * e5], b[6 * e5];
LL c[6 * e5];

void work()
{
    read(n);
    for(int i = 0; i < n; i++) read(a[i]), read(b[i]);

    for(int i = 0; i < n; i++) a[i + n] = a[i], b[i + n] = b[i];

    for(int i = 1; i < n * 2; i++)
        c[i] = max(0LL, a[i] - b[i - 1]);

//    for(int i = 0; i < 2 * n; i++) cout <<c[i] <<" "; cout <<endl;

    LL tot = a[0];
    for(int i = 1; i < n; i++) tot += c[i];

//    cout <<tot <<endl;

    LL ans = tot;
    for(int i = 1; i < n; i++)
    {
        tot -= a[i - 1];
        tot -= c[i];
        tot += a[i];
        tot += c[i + n - 1];

//        cout <<i <<" " <<tot <<endl;

        Min(ans, tot);
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
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}