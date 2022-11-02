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

void init();
void solve();
int main(){
try { 

#ifndef CUSTOM_MAIN
#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif
#endif

} catch (const char* s) { return 0; }
    return 0;
}

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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr; typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;} }; Scanner sc(cin);
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } }
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }

const int N = 500005;
int a[N];
int n, m;

void init() {
    scanf(II,&n,&m);
    rep (i,n) scanf(I,&a[i]);
    sort(a, a+n);    
}

int d[N];
int okl[N], okr[N];

namespace Manacher {
    int s[N];
    int reach[N];
    int nn;

    void init() {
        nn = n*2-1;
        rep (i,n-1) s[i*2+1] = d[i];
        rep (i,n) s[i*2] = -1;
    }

    void manacher() {
        int r=-1 , m=0;
        rep (i,nn) {
            if (i%1000==0) ses(i);
            if (r < i) {
                int t=0;
                while (i-t-1>=0 && i+t+1<nn && s[i-t-1]==s[i+t+1]) t++;
                reach[i] = t;
                r=i+reach[i]; m=i;
            } else {
                int j = m*2 - i;
                reach[i] = min(r-i, reach[j]);
                int t=reach[i];
                while (i-t-1>=0 && i+t+1<nn && s[i-t-1]==s[i+t+1]) t++;
                reach[i] = t;
                if (checkMax(r, i+reach[i])) m=i;
            }
        }
    }

    void isOk () {
        rep (i,n) okl[i] = (reach[i]==i);
        rep (i,n) okr[n-i-1] = (reach[nn-i-1]==i);
    }

    void main() {
        init();
        manacher();
        isOk();
    }
};

void solve() {
    rep (i,n-1) d[i] = a[i+1]-a[i];
    see("init");
    Manacher::main();
    see("manacher");
    vector < int > ans;
    if (okl[n-1]) ans.push_back((a[0]+a[n-1]) % m);
    rep (i,n-1) {
        if (!okl[i] || !okr[i+1]) continue;
        if ((a[0]+a[i])%m != (a[i+1]+a[n-1])%m) continue;
        ans.push_back(a[0]+a[i]);
    }
    see("tot");
    sort(ans.begin(), ans.end());
    printf(IN,(int)ans.size());
    for (int u: ans) printf("%d ", u);
}