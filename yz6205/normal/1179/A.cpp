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

const int N = 200005;
int a[N];
int n, q;
int mid;

void init() {
    scanf(II,&n,&q);
    rep (i,n) scanf(I,&a[i]);
    repa (i,n-1) if (a[i] > a[mid]) mid = i;
    see(mid);
}

int a1[N], a2[N];
int p[N * 2];
void solve() {
    rep (i,n) p[i] = a[i];
    rep (i,mid) {
        a1[i] = p[i]; a2[i] = p[i+1];
        ses(a1[i]);see(a2[i]);
        p[n + i] = min(p[i], p[i + 1]);
        p[i + 1] = max(p[i], p[i + 1]);
        ses(p[n+i]);see(p[i+1]);
    } 
    rep (i,q) {
        int qs; scanf(I,&qs); qs--;
        if (qs < mid) printf("%lld %lld\n", a1[qs], a2[qs]);
        else printf("%lld %lld\n", p[mid], p[mid + (qs-mid) % (n-1) + 1]);
    }
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}