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
 
const int N = 2000005;
 
const int e1 = 137, e2 = 257;
const int e3 = 147, e4 = 267;
const int M1 = 111926082723367, M2 = 122949100123337;
const int M3 = 111949194910017, M4 = 139326192608007;
char s[N];
int st[N];
int n;
 
void init() {
    scanf(I,&n);
	rep (i,n) {
        scanf("%s",s + st[i]);
        st[i + 1] = st[i] + strlen(s + st[i]) + 1;
    }
}
 
int get(char* a, int la, char* b) {
    int lb = strlen(b);
    int res = 0;
    int ha1 = 0, ha2 = 0, hb1 = 0, hb2 = 0, eb1 = 1, eb2 = 1;
    int ha3 = 0, ha4 = 0, hb3 = 0, hb4 = 0, eb3 = 1, eb4 = 1;
    int ans = 0;
    while (res < la && res < lb) {
        (ha1 *= e1) %= M1; (ha2 *= e2) %= M2; (ha1 += (a[la-res-1])) %= M1; (ha2 += (a[la-res-1])) %= M2;
        (ha3 *= e3) %= M3; (ha4 *= e4) %= M4; (ha3 += (a[la-res-1])) %= M3; (ha4 += (a[la-res-1])) %= M4;
        (hb1 += eb1 * b[res]) %= M1; (hb2 += eb2 * b[res]) %= M2; (eb1 *= e1) %= M1; (eb2 *= e2) %= M2;
        (hb3 += eb3 * b[res]) %= M3; (hb4 += eb4 * b[res]) %= M4; (eb3 *= e3) %= M3; (eb4 *= e4) %= M4;
        see(res);
        ses(ha1);ses(ha2);ses(hb1);see(hb2);
        if (ha1 == hb1 && ha2 == hb2 && ha3 == hb3 && ha4 == hb4) checkMax(ans, res + 1);
        res++;
    }
    return ans;
}
 
char ans[N];
void solve() {
    sprintf(ans,"%s",s);
    int len = strlen(ans);
    rep (i,n-1) {
        //nst[i + 1] = st[i + 1] + get(s + st[i], s + st[i + 1]);
        int l = get(ans, len, s + st[i+1]);
        see(l);
        char* ss = s + st[i+1] + l;
        while (*ss) {
            ans[len++]=*ss;
            ss++;
        }
    }
    printf("%s",ans);
}
 
 
#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}