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
char s[N];

int pnx[N], pxx[N], pny[N], pxy[N];
int snx[N], sxx[N], sny[N], sxy[N];
void init() {
    scanf("%s",s);
    memset(pnx,0,sizeof(pnx)); 
    memset(pxx,0,sizeof(pnx)); 
    memset(pny,0,sizeof(pnx)); 
    memset(pxy,0,sizeof(pnx)); 
    memset(snx,0,sizeof(snx)); 
    memset(sxx,0,sizeof(snx)); 
    memset(sny,0,sizeof(snx)); 
    memset(sxy,0,sizeof(snx)); 
}

void solve() {
    int x = 0, y = 0, len = strlen(s);
    rep (i,len) {
        if (s[i] == 'A') y--;
        if (s[i] == 'S') x++;
        if (s[i] == 'D') y++;
        if (s[i] == 'W') x--;
        pnx[i+1] = min(pnx[i] , x);
        pxx[i+1] = max(pxx[i] , x);
        pny[i+1] = min(pny[i] , y);
        pxy[i+1] = max(pxy[i] , y);
    }
    snx[len] = sxx[len] = x; sny[len] = sxy[len] = y;
    repb (i,len,1) {
        if (s[i] == 'A') y++;
        if (s[i] == 'S') x--;
        if (s[i] == 'D') y--;
        if (s[i] == 'W') x++;
        snx[i-1] = min(snx[i] , x);
        sxx[i-1] = max(sxx[i] , x);
        sny[i-1] = min(sny[i] , y);
        sxy[i-1] = max(sxy[i] , y);
    }
    int lx = pxx[len] - pnx[len], ly = pxy[len] - pny[len];
    int dx = lx, dy = ly;
    x = 0; y = 0;
    rep (i,len+1) {
        if (i) { if (s[i-1] == 'A') y--; 
                 if (s[i-1] == 'S') x++;
                 if (s[i-1] == 'D') y++; 
                 if (s[i-1] == 'W') x--; }
        int jnx=0, jny=0, jxx=0, jxy=0;
        if (x == pxx[i]) jxx = 1;
        if (x == pnx[i]) jnx = 1;
        if (y == pxy[i]) jxy = 1;
        if (y == pny[i]) jny = 1;
        ses(x);see(y);
        ses(pnx[i]);ses(pny[i]);ses(pxx[i]);see(pxy[i]);
        ses(jnx); ses(jny); ses(jxx); see(jxy);
        checkMin(dx, max(pxx[i], sxx[i]-1) - min(pnx[i]-jnx, snx[i]-1) );
        checkMin(dx, max(pxx[i]+jxx, sxx[i]+1) - min(pnx[i], snx[i]+1) );
        checkMin(dy, max(pxy[i], sxy[i]-1) - min(pny[i]-jny, sny[i]-1) );
        checkMin(dy, max(pxy[i]+jxy, sxy[i]+1) - min(pny[i], sny[i]+1) );
    }
    ses(lx);ses(ly);ses(dx);see(dy);
    printf(IN, min( (dx+1)*(ly+1), (lx+1)*(dy+1) ) );
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    long long T; scanf(I,&T);
    while (T--) {
        init();
        solve();
    }
    return 0;
}