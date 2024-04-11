/*

                               oooo$$$$$$$$$$$$oooo
                          oo$$$$$$$$$$$$$$$$$$$$$$$$o
                       oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$
     o $ oo          o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$
    oo $ $ "$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$
    "$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$
      $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$
      $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  """$$$
       "$$$""""$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$
        $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$o
       o$$"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o
       $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" "$$$$$$ooooo$$$$o
      o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$
      $$$$$$$$"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$""""""""
     """"       $$$$    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$"      o$$$
                "$$$o     """$$$$$$$$$$$$$$$$$$"$$"         $$$
                  $$$o          "$$""$$$$$$""""           o$$$
                   $$$$o                                o$$$"
                    "$$$$o      o$$$$$$o"$$$$o        o$$$$
                      "$$$$$oo     ""$$$$o$$$$$o   o$$$$""
                         ""$$$$$oooo  "$$$o$$$$$$$$$"""
                            ""$$$$$$$oo $$$$$$$$$$
                                    """"$$$$$$$$$$$
                                        $$$$$$$$$$$$
                                         $$$$$$$$$$"
                                          "$$$""""*/
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

const int N = 400005;
int t;
int fa[N][20];
int we[N][20];
int mx[N][20];
int last = 0;
int cnt=0;

void init() {
    scanf(I,&t); cnt++;
    rep (i,20) fa[cnt][i] = 0;
    we[cnt][0] = 0;
    we[cnt][1] = we[0][0];
    rep (i,20) mx[0][i] = mx[cnt][i] = 0x3f3f3f3f3f3f3f3f;
    mx[cnt][0] = 0;
}

inline int up(int u, int s) {
    repb(i,19,0) {
        int v = 1<<i;
        if (s >= v) {
            s -= v;
            u = fa[u][i];
        }
    }
    return u;
}

int getFa(int u, int w) {
    see(mx[u][0]);
    repb (i,19,0) {
        if (mx[u][i] < w) u = fa[u][i];
    }
    return u ;
}

void addV(int r, int w) {
    cnt++;
    r = getFa(r, w);
    see(r);
    fa[cnt][0] = r;
    rep (i,19) fa[cnt][i+1] = fa[ fa[cnt][i] ][i];
    we[cnt][0] = w;
    rep (i,19) we[cnt][i+1] = we[cnt][i] + we[ fa[cnt][i] ][i];
    mx[cnt][0] = w;
    rep (i,19) mx[cnt][i+1] = max(mx[cnt][i] , mx[fa[cnt][i]][i]);
}

int getAns(int u, int w) {
    int ans = 0;
    repb(i,19,0) {
        //see(we[u][i]);
        if (up(u,(1<<i)-1) == 0) continue; 
        if (we[u][i] <= w) {
            ans += (1<<i);
            w -= we[u][i];
            u = fa[u][i];
        }
    }
    return ans;
}

void solve() {
    while (t--) {
        int ty, p, q;
        scanf(III,&ty,&p,&q);
        int r=p^last  , w=q^last;
        ses(ty);ses(r);see(w);
        if (ty == 1) addV(r, w);
        else printf(IN, last = getAns(r,w));
    }
}