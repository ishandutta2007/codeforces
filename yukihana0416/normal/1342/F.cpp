#include <bits/stdc++.h>
using namespace std;

//#define LL long long
#define LL __int64
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


const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;


void work()
{
    int n;
    read(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) read(a[i]);

    vector<vector<int> > masks(n);

    for(int i = 0; i < (1 << n); i++)
        if(__builtin_popcount(i) < n)
            masks[__builtin_popcount(i)].pb(i);

    for(int ii = 0; ii < n; ii++)
    {
        for(auto mask : masks[ii])
        {
            vector<int> p, q;
            for(int i = 0; i < n; i++)
                if((mask >> i) & 1) q.pb(i);
                else p.pb(i);

            int nn = p.size(), mm = q.size();

            vector<int> sum(1 << mm, 0);
            for(int i = 0; i < (1 << mm); i++)
            {
                for(int j = 0; j < mm; j++)
                    if((i >> j) & 1)
                        sum[i] += a[q[j]];
            }

            vector< vector<int> > dp(nn, vector<int> (1 << mm, -1));
//            vector< vector< vector<pair<int, int> > > > steps(nn, vector< vector<pair<int, int> > > (1 << mm));

            dp[0][0] = a[p[0]];
            for(int i = 1; i < nn; i++)
            {
                for(int j = 0; j < (1 << mm); j++)
                        for(int k = j; ; k = j & (k - 1))
                        {
                            if(dp[i - 1][j ^ k] != -1 && a[p[i]] + sum[k] > dp[i - 1][j ^ k] && (dp[i][j] == -1 || dp[i][j] > a[p[i]] + sum[k]))
                            {
                                dp[i][j] = a[p[i]] + sum[k];
//                                steps[i][j] = steps[i - 1][j ^ k];
//                                for(int c = 0; c < mm; c++)
//                                    if((k >> c) & 1)
//                                        steps[i][j].pb(mk(q[c], p[i]));
                            }
                            if(k == 0) break;
                        }
            }

            int flag = 0;
            vector<pair<int, int> > fullstep;
            for(int j = 0; j < (1 << mm); j++)
                if(dp[nn - 1][j] != -1)
                {
//                    fullstep = steps[nn - 1][j];
                    for(int k = 0; k < mm; k++)
                        if(!((j >> k) & 1))
                            fullstep.pb(mk(q[k], p[nn - 1]));

                    int ni = nn - 1, nj = j;
                    while(ni)
                    {
                            for(int k = nj; ; k = nj & (k - 1))
                            {
                                if(dp[ni - 1][nj ^ k] != -1 && a[p[ni]] + sum[k] > dp[ni - 1][nj ^ k] && dp[ni][nj] == a[p[ni]] + sum[k])
                                {
                                    for(int c = 0; c < mm; c++)
                                        if((k >> c) & 1)
                                            fullstep.pb(mk(q[c], p[ni]));
                                    ni--;
                                    nj ^= k;
                                    break;
                                }
                            }
                    }

                    flag = 1;
                    break;
                }
            if(!flag) continue;

            cout <<fullstep.size() <<endl;
            vector<int> miss;
            for(auto pr : fullstep)
            {
                int x = pr.fi, y = pr.se;
                int xx = x, yy = y;
                for(auto k : miss)
                {
                    if(x > k) xx--;
                    if(y > k) yy--;
                }

                cout <<xx + 1 <<" " <<yy + 1 <<endl;
                miss.pb(x);
            }
            return ;
        }
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
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}