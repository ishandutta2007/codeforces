#define ENABLE_LL
#include <iostream>
#include <cstdio>

#ifndef _LIB_SCANNER
#define _LIB_SCANNER 1 
#include <stdio.h>
#include <stdlib.h> 
class Scanner {
private:
    static const int BUFFER_SIZE = 10000; char buff[BUFFER_SIZE]; int buffPos, buffLim; 
public:
    Scanner () { buffLim = fread(buff, 1, BUFFER_SIZE, stdin); buffPos = 0; } 
private:
    inline void flushBuff() { buffLim = fread(buff, 1, BUFFER_SIZE, stdin); if (buffLim==0) { buff[buffLim++] = '\n'; } buffPos = 0; } 
    inline bool isWS(char t) { return t==' ' || t=='\n'; } 
    inline bool isDig(char t) { return t>='0' && t<='9'; } 
    void nextPos() { buffPos++; if (buffPos == buffLim) { flushBuff(); } } 
#define getChar() buff[buffPos]
public:
    inline char getchar() { char ch=getChar(); nextPos(); return ch; } 
    inline void next(char* s) { while ( isWS(getChar()) ) { nextPos(); } while ( !isWS(getChar()) ) { *s = getChar(); s++; nextPos(); } *s = '\0'; } 
    inline void nextLine(char* s) { while ( getChar()!='\n' ) { nextPos(); } if ( getChar()=='\n' ) { nextPos(); } while ( getChar() != '\n' ) { *s = getChar(); s++; buffPos++; } *s = '\0'; } 
    inline int nextInt() { while ( !isDig(getChar()) && getChar() != '-' ) { nextPos(); } int sign = (getChar() == '-') ? nextPos(),-1 : 1; int res = 0; while (isDig(getChar())) { res = res*10 + getChar()-'0'; nextPos(); } return res * sign; } 
    inline int n() { while ( getChar()<'0' || getChar()>'9' ) { buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } int res = 0; while ( getChar()>='0' && getChar()<='9' ) { res = res*10 + (getChar()-'0'); buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } return res; }
    inline double nextDouble() { while ( isWS(getChar()) ) { nextPos(); } int sign = (getChar() == '-') ? nextPos(),-1 : 1; double res = 0; while (isDig(getChar())) { res = res * 10 + getChar()-'0'; nextPos(); } if (getChar() == '.') { nextPos(); double ep = 1; while (isDig(getChar())) { ep *= 0.1; res += ep * (getChar()-'0'); nextPos(); } } return sign * res; } 
    inline char nextChar() { while (isWS(getChar())) nextPos(); char res = getChar(); nextPos(); return res; }
#undef getChar
}; Scanner sc;
#endif /* _LIB_SCANNER */

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
#include <bitset>
#include <sstream>

#ifdef ENABLE_LL
#define int long long
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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)

typedef std::pair < int , int > pr; 
typedef std::pair < pr  , int > prr; 
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); } 
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); } 
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } } 
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }
#define L first
#define R second

#ifdef __LOCALE__
template <typename T> void __ses(T a) { std::cout << a << " "; }
template <typename T, typename ... Args> void __ses(T a, Args... b) { std::cout << a << " "; __ses(b...); }
#define ses(...) std::cout << #__VA_ARGS__ << " = "; __ses(__VA_ARGS__)
#define see(...) ses(__VA_ARGS__); std::cout << std::endl
#define slog(format, ...) printf(format, __VA_ARGS__)
#else
#define see(...) 
#define ses(...)
#define slog(format, ...)
#endif


#ifndef CUSTOM_MAIN
void preInit(); void init(); void solve(); int32_t main(){ preInit(); 
#ifdef MULTIPLE_TEST_CASES_WITH_T
int T; 
#ifdef _LIB_SCANNER
T = sc.nextInt();
#else
scanf("%d",&T); 
#endif /* _LIB_SCANNER */
while(T--) {init(); solve();} 
#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T 
while(1) { try {init(); } catch(bool t) {return 0;} solve(); }
#else
init(); solve(); 
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */
#endif /* MULTIPLE_TEST_CASES_WITH_T */
    return 0; }
#endif /* CUSTOM_MAIN */

// my code begins here

#define Vec std::vector

struct Node {
    long long cnt, sum;
    void init() { cnt=1; sum=0; }
    Node suc() {
        return { cnt, sum+cnt }; }
    Node add(Node B) {
        return { cnt+B.cnt, sum+B.sum }; }
    Node sub(Node B) {
        return { cnt-B.cnt, sum-B.sum }; }
};

const int N = 100005;
Vec<int> e[N];
int n, m;


void preInit() { } void init() {
    n = sc.n(); m = sc.n();
    rep (i,n-1) { int u=sc.n(), v=sc.n(); e[u].push_back(v); e[v].push_back(u); }
}

Node a[N], b[N];
void dfs(int u, int f) {
    a[u].init();
    for (int v: e[u]) if (v!=f) {
        dfs(v,u); a[u] = a[u].add( a[v].suc() ); } }
void dfs2(int u, int f, Node up={0,0}) {
    b[u] = a[u].add( up );
    for (int v: e[u]) if (v!=f) {
        dfs2(v,u, b[u].sub( a[v].suc() ).suc()); } } 

const int B = 20;
int fa[N][B], d[N];
void dfs1(int u, int f) {
    d[u] = d[f] + 1;
    fa[u][0]=f; rep (i,B-1) fa[u][i+1] = fa[ fa[u][i] ][i]; 
    for (int v:e[u]) if (v!=f) { dfs1(v,u); } }
void up(int &u, int d) {
    rep (i,B) if ((d>>i)&1) { u = fa[u][i]; } }
int lca(int u, int v) {
    if (d[u] < d[v]) { std::swap(u,v); } up(u, d[u]-d[v]);
    repb (i,B-1,0) if (fa[u][i] != fa[v][i]) { u=fa[u][i]; v=fa[v][i]; }
    return u==v ? u : fa[u][0]; }
int dis(int u, int v) { return d[u]+d[v]-2*d[lca(u,v)]; }

void solve() {
    dfs1(1,0); dfs(1,0); dfs2(1,0);
    while (m--) {
        int u=sc.n(), v=sc.n();
        if (d[u] < d[v]) { std::swap(u,v); }
        int l = lca(u,v); 
        if (l == v) {
            Node au = a[u];
            int us = u; up(us, d[u]-d[v]-1);
            see(b[v].cnt, b[v].sum);
            Node av = b[v].sub( a[us].suc() ); 
            long double cnt = 1.0*au.cnt*av.cnt; 
            long double sum = 1.0*au.sum*av.cnt + 1.0*au.cnt*av.sum + 1.0*cnt*(dis(u,v)+1);
            printf("%.12Lf\n", sum/cnt); }
        else {
            Node au=a[u], av=a[v];
            long double cnt = 1.0*au.cnt*av.cnt; 
            long double sum = 1.0*au.sum*av.cnt + 1.0*au.cnt*av.sum + 1.0*cnt*(dis(u,v)+1);
            printf("%.12Lf\n", sum/cnt); } }
}