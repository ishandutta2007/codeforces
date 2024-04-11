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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 300050;
int a[N] , s[N];
int n , m , k;

void init() {
    scanf(III,&n,&m,&k);
    rep (i,n) scanf(I,&a[i]);
    s[0] = a[0] ; repa (i,n - 1) s[i] = s[i - 1] + a[i];
}

int _mn[N];
void solve() {
    rep (i,n) {
        _mn[i] = s[i];
        for (int j = i + 1;j < n && j - i < m;j++) _mn[i] = min( _mn[i] , s[j] );
        see(_mn[i]);
    }
    int ans = 0;
    rep (b , min(m , n)) {
        int mn = 0; rep (i,b) mn = min(mn , s[i]);
        int pos = b;
        while (pos < n) {
            mn += k;
            ses(pos);ses(mn);see(s[pos] - mn);
            ans = max(ans , s[pos] - mn);
            mn = min(mn , _mn[pos]);
            pos += m;
        }
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