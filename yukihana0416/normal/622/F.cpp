#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>

#include <iostream>

#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <chrono>
#include <utility>
#include <random>
#include <memory>
#include <bitset>
#include <string>
#include <tuple>
#include <functional>
using namespace std;

#define endl '\n'
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
#define epb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using LL = long long;
using ULL = unsigned long long;
using pii = pair<int, int>;
using pLL = pair<LL, LL>;

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double DINF = 1e100;
const double eps = 1e-8;
const int MOD_1e9 = 1000000007;
const int MOD_998 = 998244353;

template< typename T > inline void get_min(T &x, T y) {if(y < x) x = y;}
template< typename T > inline void get_max(T &x, T y) {if(x < y) x = y;}
template< typename T > inline void get_unique(vector<T> &vec) {sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
template< typename T > inline LL fp(LL a, T n, int mod) {
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1;
    for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod;
    return res;
}

template< int mod > class Mint {
public:
    int x;
    Mint():x(0) {}
    Mint(int _x): x(_x) {if(x < 0 || x >= mod) x %= mod; if(x < 0) x += mod;}
    Mint(LL _x) {if(_x < 0 || _x >= mod) _x %= mod; if(_x < 0) _x += mod; x = _x;}
    Mint operator - () const {return Mint(x == 0 ? x : mod - x);}
    Mint operator + (const Mint &rhs) const {return Mint(x + rhs.x >= mod ? x + rhs.x - mod : x + rhs.x);}
    Mint operator - (const Mint &rhs) const {return Mint(x - rhs.x < 0 ? x - rhs.x + mod : x - rhs.x);}
    Mint operator * (const Mint &rhs) const {return Mint((LL)x * rhs.x % mod);}
    Mint operator / (const Mint &rhs) const {return Mint((LL)x * fp(rhs.x, -1, mod) % mod);}
    bool operator == (const Mint &rhs) const {return x == rhs.x;}
    bool operator != (const Mint &rhs) const {return x != rhs.x;}
    Mint &operator += (const Mint &rhs) {x += rhs.x; if(x >= mod) x -= mod; return *this;}
    Mint &operator -= (const Mint &rhs) {x -= rhs.x; if(x < 0) x += mod; return *this;}
    Mint &operator *= (const Mint &rhs) {x = (LL)x * rhs.x % mod; return *this;}
    Mint &operator /= (const Mint &rhs) {x = (LL)x * fp(rhs.x, -1, mod) % mod; return *this;}
    friend ostream &operator << (ostream &out, const Mint &rhs) {return out <<to_string(rhs.x);}
    Mint inv() const {return Mint(fp(x, -1, mod));}
    template< typename T > Mint pow(T k) const {return Mint(fp(x, k, mod));}
};

const int maxn = (int) 1e6 + 5;
const int maxm = (int) 20000 + 5;
using mint = Mint<MOD_998>;




const int mod = MOD_1e9;
namespace Lagrange
{
    int fpow(int a, int n)
    {
        int res = 1;
        for(; n; n >>= 1, a = (LL(a) * a) % mod) if(n & 1) res = LL(res) * a % mod;
        return res;
    }

    int n;
    vector<int> ifac;
    vector<int> suf;

    int solve(const vector<int> &f, int x)
    {
        n = f.size();
        if(x < n) return f[x];

        ifac.assign(n, 0);
        suf.assign(n, 0);

        int fac = 1;
        for(int i = 2; i < n; i++) fac = LL(fac) * i % mod;
        ifac[n - 1] = fpow(fac, mod - 2);
        for(int i = n - 2; i >= 0; i--) ifac[i] = LL(ifac[i + 1]) * (i + 1) % mod;
        suf[n - 1] = 1;
        for(int i = n - 1; i > 0; i--) suf[i - 1] = LL(suf[i]) * (x - i + mod) % mod;

        int ans = 0, pre = 1;
        for(int i = 0; i < n; i++)
        {
            int coef = LL(ifac[i]) * ifac[n - 1 - i] % mod * pre % mod * suf[i] % mod;
            if((n - 1 - i) & 1) coef = (mod - coef) % mod;
            ans = (ans + LL(coef) * f[i]) % mod;
            pre = LL(pre) * (x - i + mod) % mod;
        }
        return ans;
    }
}


void work()
{
    int n, k;
    cin >>n >>k;

    vector<int> a(k + 2);
    a[0] = 0;
    for(int i = 1; i <= k + 1; i++)
        a[i] = (fp(i, k, mod) + a[i - 1]) % mod;

    int ans = Lagrange::solve(a, n);
    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    ios::sync_with_stdio(false);

    int tc = 1;
//    cin >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
//        printf("Case #%d:\n", ca);
        work();
    }
    return 0;
}