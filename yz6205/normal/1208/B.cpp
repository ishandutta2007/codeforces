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
int a[N];
int cnt[N];
int n, cnt2;

void init() {
    scanf(I,&n);
    rep (i,n) scanf(I,&a[i]);
    vector < int > v;
    rep (i,n) v.push_back(a[i]);
    sort(v.begin(), v.end());
    rep (i,n) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    rep (i,n) cnt[ a[i] ]++;
    rep (i,n) cnt2 += (cnt[i] >= 2);
}

void solve() {
    int ans = 0x3f3f3f3f;
    int l=0, r=0;
    while (cnt2 && r <= n) { cnt[ a[r] ]--; cnt2 -= (cnt[a[r]] == 1); r++; see(cnt2);}
    while (l < n && r <= n) {
        ses(l);see(r);
        checkMin(ans, r - l);
        if (r > l) { cnt[ a[l] ]++; cnt2 += (cnt[a[l]] == 2); } 
        else r++;
        l++;
        while (cnt2 && r <= n) { cnt[ a[r] ]--; cnt2 -= (cnt[a[r]] == 1); r++; }
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