#define CUSTOM_MAIN
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

const int N = 5005;
int n, m;
int n1, n2, n3;
vector < int > e[N];

void init() {
    scanf(II,&n,&m); 
    scanf(III,&n1,&n2,&n3);
    rep (i,m) {
        int u, v; scanf(II,&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

int color[N]; 
vector < pair < vector < int > , vector < int > > > pairs;

void get(int u, bool c=0) {
    color[u] = c;
    (c?pairs.back().R : pairs.back().L) .push_back(u);
    repe (i,e[u]) {
        int v = e[u][i];
        ALERT( color[v] == c , "NO" );
        if (color[v] == -1) get(v, !c);
    }
}

void solve() {
    memset(color, -1, sizeof(color)); 
    repa (i,n) {
        if (color[i] != -1) continue;
        pairs.push_back( pair < vector < int > , vector < int > > ( vector < int > () , vector < int > ()) );
        get(i);
    }
}

bool dp[N][N];
int from[N][N];
vector < int > *_from[N][N];
int dye[N];

void ans() {
    dp[0][0] = 1;
    repe (_i, pairs ) {
        int i = _i+1;
        vector < int > &a = pairs[_i].L, &b = pairs[_i].R;
        int sa = a.size(), sb = b.size();
        ses(sa);see(sb);
        repb (j,n,min(sa,sb)) {
            if (j-sa<0) goto nxt;
            if (dp[i][j] || !dp[i-1][j-sa]) goto nxt;
            dp[i][j] = 1; from[i][j] = j-sa;
            _from[i][j] = &a;
nxt:;
            if (j-sb<0) continue;
            if (dp[i][j] || !dp[i-1][j-sb]) continue;
            dp[i][j] = 1; from[i][j] = j-sb;
            _from[i][j] = &b;
        }
        repa (j,n) ses(dp[i][j]);see("");
    }
    ALERT( dp[pairs.size()][n2] == 0, "NO" );
    vector < int > dye2s;
    int pos=n2;
    repb (i,pairs.size(),1) {
        vector < int > & p = *_from[i][pos];
        repe (i,p) dye2s.push_back( p[i] );
        pos = from[i][pos];
    }
    repe (i,dye2s) { dye[ dye2s[i] ] = 2; see(dye2s[i]); }
    repa (i,n) {
        if (dye[i]) continue;
        if (n1) {
            dye[i] = 1;
            n1--;
        } else {
            dye[i] = 3;
        }
    }
    puts("YES");
    repa (i,n) printf(I,dye[i]);
}

#ifdef ENABLE_LL
#undef int
#endif
int main(){
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
    init();
    try { solve(); see("TEST"); ans(); } catch (...) { return 0; }
    return 0;
}