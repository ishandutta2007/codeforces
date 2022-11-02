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

const int N = 105;
int n, r;
vector < pr > pos, neg;
int chp[N], chn[N];

void init() {
    scanf(II,&n,&r);
    rep (i,n) {
        int l, p; scanf(II,&l,&p);
        if (p >= 0) pos.push_back( pr(l,p) );
        else        neg.push_back( pr(l,p) );
    }
}

void sub1() {
    rep (i,(int)pos.size()) {
        int id = -1;
        rep (j,(int)pos.size()) if (!chp[j] && pos[j].L <= r) id = j;
        if (id == -1) { puts("NO"); exit(0); }
        chp[id] = 1; r += pos[id].R;
    }
}

void solve() {
    sub1();
    sort (neg.begin(), neg.end(), [](pr a, pr b) { return a.L + a.R > b.L + b.R; } );
    rep (i,(int)neg.size()) {
        if (r < neg[i].L) { puts("NO"); exit(0); }
        r += neg[i].R;
    }
    if (r < 0) puts("NO");
    else       puts("YES");
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}