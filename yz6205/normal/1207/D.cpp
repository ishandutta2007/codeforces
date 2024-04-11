#define ENABLE_LL
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const int N = 300005;
const int MOD = 998244353;
int fac[N];

void init_fac() {
    fac[0] = 1;
    repa (i,N-1) fac[i] = fac[i-1] * i % MOD;
}

pr a[N];
int n;

void init() {
    init_fac();
    scanf(I,&n);
    rep (i,n) scanf(II,&a[i].L,&a[i].R);
}

int ca() {
    int res = 1;
    sort(a, a + n);
    vector < int > parts;
    int last = 0;
    repa (i,n-1) {
        if (a[i].L != a[i-1].L) {
            parts.push_back( i - last );
            last = i;
        }
    }
    parts.push_back(n-last);
    foreach (i,parts) (res *= fac[ parts[i] ]) %= MOD;
    see(res);
    return res;
}

int cb() {
    int res = 1;
    sort(a, a + n, [](pr a, pr b) { return a.R == b.R ? a.L < b.L : a.R < b.R; } );
    vector < int > parts;
    int last = 0;
    repa (i,n-1) {
        if (a[i].R != a[i-1].R) {
            parts.push_back( i - last );
            last = i;
        }
    }
    parts.push_back(n-last);
    foreach (i,parts) (res *= fac[ parts[i] ]) %= MOD;
    see(res);
    return res;
}

int cu() {
    int res = 1;
    sort(a, a + n);
    rep (i,n-1) if (a[i].R > a[i+1].R) return 0;
    vector < int > parts;
    int last = 0;
    repa (i,n-1) {
        if (a[i] != a[i-1]) {
            parts.push_back( i - last );
            last = i;
        }
    }
    parts.push_back(n-last);
    foreach (i,parts) (res *= fac[ parts[i] ]) %= MOD;
    see(res);
    return res;
}

void solve() {
    printf(IN, (fac[n] - ca() - cb() + cu() + MOD * 5) % MOD);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}