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
#define long long long long
#endif

#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (long long a=0;a<(long long)b.size();a++)
#define rep(i,n) for (long long i=0;i<n;i++)
#define repa(i,n) for (long long i=1;i<=n;i++)
#define repi(i,a,b) for (long long i=a;i<=b;i++) 
#define repb(i,a,b) for (long long i=a;i>=b;i--)
typedef pair < long long , long long > pr;
typedef pair < pr  , long long > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const long long N = 1000005;
const long long B = 20;
long long n, w;
long long a[N];

void modify(long long l, long long r, long long u) {
    a[l] += u;
    a[r + 1] -= u;
}

void tot() {
    repa (i,w-1) a[i] += a[i-1];
}

long long sz[N];
vector < long long > os[N];

void init() {
    scanf(II,&n,&w);
    rep (i,n) {
        scanf(I,&sz[i]);
        os[i].resize( sz[i] );
        rep (j,sz[i]) scanf(I,&os[i][j]);
    }
}

inline long long getW(long long u) {
    long long res = 0;
    while (u) {
        u >>= 1; res++;
    }
    return res;
}

struct RMQ{
    int mxf[N][B], mxb[N][B];
    int idd;

    void init(long long id) {
        idd = id;
        rep (i,sz[id]) mxf[i][0] = mxb[i][0] = os[id][i];
        rep (b,B-1) {
            long long len = 1 << b;
            rep (j,sz[id]) {
                if (j + len < sz[id]) mxf[j][b+1] = max(mxf[j][b], mxf[j + len][b]);
                if (j - len>= 0) mxb[j][b+1] = max(mxb[j][b], mxb[j - len][b]);
            }
        }
    }

    int query(long long l, long long r) {
        int ans = -0x3f3f3f3f;
        if (l == -1) { ans = 0; l++; }
        if (sz[idd] == r) {ans = 0; r--; }
        long long len = r - l + 1;
        long long b = getW(len) - 1;
        ses(l);ses(r);see(max(mxf[l][b], mxb[r][b]));
        checkMax(ans, max(mxf[l][b], mxb[r][b]));
        return ans;
    }
};

RMQ st;
long long pa[N];
void solve() {
    rep (i,n) {
        st.init(i);
        rep (j,sz[i]) pa[j] = 0; repb (j,w-1,w-sz[i]) pa[j] = -0x3f3f3f3f;
        rep (j,sz[i]) checkMax(pa[j], (long long)st.query( max(-1LL,sz[i] + j - w), j ) );
        repb(j,w-1,w-sz[i]) checkMax(pa[j], (long long)st.query( sz[i]-w+j, min(sz[i], j) ) );
        rep (j,w) ses(pa[j]); see("");
        if (sz[i] * 2 <= w) {
            rep (j,sz[i]) modify(j,j,pa[j]);
            repb(j,w-1,w-sz[i]) modify(j,j,pa[j]);
            modify(sz[i], w-sz[i]-1, max(0, st.query(0,sz[i]-1)) );
        }else {
            rep (j,w) modify(j,j,pa[j]);
        }
    }
    tot();
    rep (i,w) printf("%lld ",a[i]);
}


#ifdef ENABLE_LL
#undef long long
#endif
int main(){
    init();
    solve();
    return 0;
}