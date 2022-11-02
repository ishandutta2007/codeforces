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
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; }};
Scanner sc(cin);

const int MOD = 1e9 + 7;
int x, n;

void init() {
    scanf(II,&x,&n);
}

vector < int > primeFactors(int x) {
    vector < int > res;
    int l = sqrt(x);
    for (int t=2;t<=l;t++) {
        if (x % t == 0) res.push_back(t);
        while (x % t == 0) x /= t;
    }
    if (x != 1) res.push_back(x);
    return res;
}

int power(int bs, int ex) {
    int res = 1;
    bs %= MOD;
    while (ex) {
        if (ex & 1) (res *= bs) %= MOD;
        (bs *= bs) %= MOD;
        ex >>= 1;
    }
    return res;
}

int get(int u, int n) {
    int ans = 0;
    int bss = 1;
    while (1) {
        bss *= u;
        int extra = n / bss;
        ans += extra;
        if (extra < u) return ans;
    }
}

void solve() {
    vector < int > fac = primeFactors(x);
    see(fac.size());
    int ans = 1;
    rep (i,(int)fac.size()) { (ans *= power(fac[i], get(fac[i], n))) %= MOD; see(ans); }
    printf(IN,ans);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}