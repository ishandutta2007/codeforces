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
const double pi = acos(-1.0);
const double eps = 1e-8;
const int e5 = 100000; // 1e5
const int e6 = 1000000; //1e6;
//const int MOD = 1000000007; //1e9 + 7
const int MOD = 998244353;
//const int MOD = 911451407;

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

    Mint inv() {return Mint(fp(x, -1));}
    Mint pow(int k) {return Mint(fp(x, k));}
    Mint pow(const Mint &t) {return Mint(fp(x, t.x));}
};


const int maxn = (int) 1e6 + 20;
const int maxm = (int) 2e6 + 20;

void work()
{
    int n, k;
    cin >>n >>k;

    LL ans = LINF;

    auto s2int = [](string s)
    {
        LL res = 0;
        for(auto x : s)
            res = res * 10 + x - '0';
        return res;
    };

    for(int last = 0; last <= 9; last++)
    {
        int cnt = 0;
        int inc = 0;
        for(int i = 0; i <= k; i++)
        {
            if(last + i >= 10)
                inc++;
            cnt += (last + i) % 10;
        }

        for(int dig = 0; dig <= 16; dig++)
        {
            int tmp = dig * 9 * (k + 1 - inc) + inc;;
            int tot = n - tmp - cnt;

            if(tot < 0 || tot % (k + 1) != 0) continue;

            tot /= k + 1;

            string s = "";

            if(tot >= 9)
            {
                s = "8";
                tot -= 8;
            }

            while(tot)
            {
                if(tot >= 9)
                {
                    s = "9" + s;
                    tot -= 9;
                }
                else
                {
                    s = (char)('0' + tot) + s;
                    tot = 0;
                }
            }

            for(int k = 0; k < dig; k++)
                s = s + "9";

            s = s + (char)(last + '0');

            ans = min(ans, s2int(s));
        }
    }
    if(ans >= LINF) ans = -1;
    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    int tc = 1;
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}