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
char t[N];
int n;

void init() {
    scanf(I,&n);
    scanf("%s%s",s,t); 
}

void p1() {
    int c0 = 0;
    rep (i,n) c0 += (s[i] == 'a');
    rep (i,n) c0 += (t[i] == 'a');
    if (c0 % 2 == 1) { puts("-1"); exit(0); }
}

void solve() {
    p1();
    vector < int > ab, ba;
    rep (i,n) {
        if (s[i] == 'a' && t[i] == 'b') ab.push_back(i);
        if (s[i] == 'b' && t[i] == 'a') ba.push_back(i);
    }
    vector < pr > res;
    for (int i = 0; i<(int)(ab.size()) - 1; i+=2) {
        res.push_back( pr(ab[i], ab[i+1]) );
    }
    for (int i = 0; i<(int)(ba.size()) - 1; i+=2) {
        res.push_back( pr(ba[i], ba[i+1]) );
    }
    if (ab.size() % 2 == 1) {
        int x = ab[(int)ab.size()-1], y = ba[(int)ba.size()-1];
        res.push_back( pr(x,x) );
        res.push_back( pr(x,y) );
    }
    printf(IN,(int)res.size());
    rep (i,(int)(res.size())) printf("%d %d\n", res[i].L+1, res[i].R+1);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}