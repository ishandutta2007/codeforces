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

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 200005;
const int E = 0x3f3f3f3f;
const int B = 18;
struct FenwickTree {
    int a[N];
    const int n;
    FenwickTree (int n) : n(n){
        memset(a,0,sizeof(a));
    }

    inline int lowbit (int x) {
        return x & (-x);
    }

    void modify (int pos , int x) {
        pos++;
        while (pos < n) {
            a[pos] = max(a[pos] , x);
            pos += lowbit(pos);
        }
    }

    int query (int pos) {
        pos++;
        int res = a[1];
        while (pos) {
            res = max(res , a[pos]);
            pos -= lowbit(pos);
        }
        return res;
    }
};

struct RMQ {
    int f[N][B];
    int b[N][B];

    void build (int r[] , int n) {
        rep (i,n) f[i][0] = b[i][0] = r[i];
        int d = 1;
        repa (bn,B - 1) {
            rep (i,n) if (i + d <  n) f[i][bn] = max ( f[i][bn - 1] , f[i + d][bn - 1] );
            rep (i,n) if (i - d >= 0) b[i][bn] = max ( b[i][bn - 1] , b[i - d][bn - 1] );
            d <<= 1;
        }
    }

    int query(int p , int q) {
        int x = 0;
        while ((1 << x) <= (q - p + 1)) x++;
        x--;
        return max (f[p][x] , b[q][x]);
    }
};

int p[N] , l[N] , rec[N];
int n;

RMQ rr;
void scan(){
    scanf("%d",&n);
    rep (i,n) scanf("%d%d",&p[i],&l[i]);
    p[n] = E;
    rep (i,n) rec[i] = p[i] + l[i];
    rr.build(rec , n);
}

int r[N][B] , nc[N][B];
void makeRNc() {
    memset(r,E,sizeof(r));
    memset(nc,E,sizeof(nc));
    FenwickTree mxr(n + 5);
    for (int i=n-1;i>=0;i--) {
        r[i][0] = i;
        int mri = upper_bound (p , p + n + 1, p[i] + l[i]) - p - 1;
        r[i][0] = max(r[i][0] , mxr.query(mri));
        mxr.modify (i , r[i][0]);
    }
    repa (b,B - 1) {
        rep (i,n) if (r[i][b-1] != E && r[ r[i][b-1]+1 ][ b-1 ] != E) 
                              r[i][b] = r[ r[i][b-1]+1 ][ b-1 ] ;
    }

    rep (i,n - 1) nc[i][0] = p[ r[i][0] + 1 ] - rr.query(i , r[i][0]);
    repa (b,B - 1) {
        rep (i,n) if (r[i][b-1] != E && nc[i][b-1] != E && nc[ r[i][b-1]+1 ][ b-1 ] != E) 
                            nc[i][b] =  nc[i][b-1] +       nc[ r[i][b-1]+1 ][ b-1 ] ;
    }

#ifdef __LOCALE__
    //*debug info 
    rep (i,B) { 
        rep (j,n) printf("%12d ",r[j][i]);
        puts("");
    }
    rep (i,B) { 
        rep (j,n) printf("%12d ",nc[j][i]);
        puts("");
    }//*/
#endif
}

void solve () {
    int q;
    scanf("%d",&q);
    while (q--) {
        see("BBBBBBBBEEEEEEEEGGGGGGGGIIIIIIIIINNNNNNNNNNN");
        int f , t;
        scanf("%d%d",&f,&t);
        f-- ; t--;
        int pos = f;
        int ans = 0;
        for (int b=B - 1;b>=0;b--) {
            if ( r[pos][b] == E || nc[pos][b] == E) continue;
            if ( r[pos][b] >= t) continue;
            ans += nc[pos][b];
            pos =  r[pos][b] + 1;
            see(ans);
            see(pos);
        }
        printf("%d\n",ans);
    }
}   

int main(){
    scan ();
    makeRNc ();
    solve ();
    return 0;
}