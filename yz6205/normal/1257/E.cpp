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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
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

const int N = 200005;
int n, a, b, c;
int x[N], y[N], z[N];
int pz[N], sx[N];
int ma[N], mc[N];

void init() {
    scanf(III,&a,&b,&c); n = a+b+c;
    rep (i,a) x[sc.nextInt() -1] = 1;
    rep (i,b) y[sc.nextInt() -1] = 1;
    rep (i,c) z[sc.nextInt() -1] = 1; 
    repa (i,n) pz[i] = pz[i-1] + z[i-1];
    repb (i,n-1,0) sx[i] = sx[i+1] + x[i];
    ma[0] = a;
    repa (i,n) ma[i] = ma[i-1] + (x[i-1] ? -1 : 1);
    mc[n] = c;
    repb (i,n-1,0) mc[i] = mc[i+1] + (z[i] ? -1 : 1); 
}

int af[N], ab[N];

void se(int* a) {
    rep (i,n+1) ses(a[i]); see("");
}

void solve() {
    af[0] = ma[0] - pz[0];
    repa (i,n) af[i] = min(af[i-1], ma[i] - pz[i]);
    ab[n] = mc[n] - sx[n];
    repb (i,n-1,0) ab[i] = min(ab[i+1], mc[i] - sx[i]);
    int ans = 0x3f3f3f3f;
    rep (i,n+1) checkMin(ans, af[i] + ab[i]);
    printf(IN,ans);

    se(pz);se(sx);se(ma);se(mc);se(af);se(ab);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}