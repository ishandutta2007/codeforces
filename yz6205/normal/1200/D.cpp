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

const int N = 2005;
char s[N];
int a[N][N];
int n, k;

void init() {
    scanf(II,&n,&k);
    rep (i,n) {
        scanf("%s",s);
        rep (j,n) a[i][j] = (s[j] == 'B');
    }
}

int sufr[N][N], sufc[N][N];
void sub0() {
    rep (i,n) {
        sufr[i][0] = a[i][0];
        repa (j,n-1) sufr[i][j] = sufr[i][j-1] + a[i][j];
    }
    rep (i,n) {
        sufc[0][i] = a[0][i];
        repa (j,n-1) sufc[j][i] = sufc[j-1][i] + a[j][i];
    }
}

int jur[N][N], juc[N][N];
void sub1() {
    rep (i,n) {
        rep (j,n-k+1) jur[i][j] = ( (sufr[i][j+k-1] - (j?sufr[i][j-1]:0)) == sufr[i][n-1] );
        rep (j,n-k+1) ses(jur[i][j]); see("");
    }
    rep (i,n) {
        rep (j,n-k+1) juc[j][i] = ( (sufc[j+k-1][i] - (j?sufc[j-1][i]:0)) == sufc[n-1][i] );
        rep (j,n-k+1) ses(juc[j][i]); see("");
    }
}

int jcr[N], jcc[N];
void sub2() {
    rep (i,n) jcr[i] = (i?jcr[i-1]:0) + (sufr[i][n-1] == 0);
    rep (i,n) jcc[i] = (i?jcc[i-1]:0) + (sufc[n-1][i] == 0);
}

int jr[N][N], jc[N][N];
void sub3() {
    rep (i,n) {
        rep (j,n) jr[i][j] = (j?jr[i][j-1]:0) + juc[i][j];
        rep (j,n) ses(jr[i][j]); see("");
    }
    rep (i,n) {
        rep (j,n) jc[j][i] = (j?jc[j-1][i]:0) + jur[j][i];
        rep (j,n) ses(jc[j][i]); see("");
    }
}

void solve() {
    sub0(); sub1(); sub2(); sub3();
    int ans = 0;
    rep (i,n-k+1) rep (j,n-k+1) {
        int rr = jcr[n-1] - (jcr[i+k-1] - (i?jcr[i-1]:0));
        int rc = jcc[n-1] - (jcc[j+k-1] - (j?jcc[j-1]:0));
        int ar = jc[i+k-1][j] - (i?jc[i-1][j]:0);
        int ac = jr[i][j+k-1] - (j?jr[i][j-1]:0);
        ses(rr);ses(rc);ses(ar);see(ac);
        checkMax(ans, rr+rc+ar+ac);
    }
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