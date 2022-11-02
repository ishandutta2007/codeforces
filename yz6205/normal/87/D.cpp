#include <iostream>
#include <cstdio>
using namespace std; 

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
    inline long long nextLong() { while ( !isDig(getChar()) && getChar() != '-' ) { nextPos(); } long long sign = (getChar() == '-') ? nextPos(),-1 : 1; long long res = 0; while (isDig(getChar())) { res = res*10 + getChar()-'0'; nextPos(); } return res * sign; } 
    inline int n() { while ( getChar()<'0' || getChar()>'9' ) { buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } int res = 0; while ( getChar()>='0' && getChar()<='9' ) { res = res*10 + (getChar()-'0'); buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } return res; }
    inline long long nl() { while ( getChar()<'0' || getChar()>'9' ) { buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } long long res = 0; while ( getChar()>='0' && getChar()<='9' ) { res = res*10 + (getChar()-'0'); buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } return res; }
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

#ifdef ENABLE_LL
#define int long long
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
template <typename T> void __ses(T a) { cout << a << " "; }
template <typename T, typename ... Args> void __ses(T a, Args... b) { cout << a << " "; __ses(b...); }
#define ses(...) { cout << #__VA_ARGS__ << " = "; __ses(__VA_ARGS__); }
#define see(...) { ses(__VA_ARGS__); cout << endl; }
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


const int N = 200005;
int sz[N], w[N], id[N];
int n;

struct Edge { int u,v,w,id; } es[N];

void preInit() { } void init() {
    n = sc.n();
    rep (i,n-1) { int u=sc.n(), v=sc.n(), w=sc.n(); es[i]={u,v,w,i+1}; } 
    sort(es, es+n-1, [](Edge a, Edge b) { return a.w < b.w; });
    repa (i,n) sz[i] = 1;
}

struct Dsu {
    int p[N], sz[N];
    Dsu () { rep (i,N) { p[i]=i; sz[i]=1; } }
    int get(int u) { return u==p[u] ? u : p[u] = get(p[u]); }
    void merge(int u, int v) {
        int uu=get(u), vv=get(v); if (uu==vv) { return; }
        p[vv] = uu; sz[uu] += sz[vv]; }
    int size(int u) { return sz[get(u)]; }
} st;

long long ans[N];

vector <pr> e[N];
int ww[N], vis[N];

void dfs(int u, int f) { 
    vis[u] = 1;
    for (pr v: e[u]) if (v.L!=f) {
        dfs(v.L,u); ww[u]+=ww[v.L]; } }
void dfs2(int u, int f, int ts) {
    vis[u] = 1;
    for (pr v: e[u]) if (v.L != f) {
        see(u, v.L, v.R);
        see(ts, ww[v.L]);
        dfs2(v.L,u, ts); 
        ans[v.R] = 1ll * ww[v.L] * (ts-ww[v.L]); } }

void solve() {
    int id = 0;
    while (id < n-1) {
        vector <Edge> current;
        int rid = id;
        while (rid < n-1 && es[rid].w == es[id].w) { 
            current.push_back( { st.get(es[rid].u), st.get(es[rid].v), 0, es[rid].id } );
            rid ++; }
        for (auto u: current) {
            e[u.u].clear(); e[u.v].clear();
            vis[u.u] = vis[u.v] = 0;
            ww[u.u] = st.size(u.u); ww[u.v] = st.size(u.v); }
        for (auto u: current) {
            e[u.u].push_back( { u.v, u.id } );
            e[u.v].push_back( { u.u, u.id } ); }
        for (auto u: current) {
            if (!vis[u.u]) { dfs(u.u,0); } 
            if (!vis[u.v]) { dfs(u.v,0); } }
        for (auto u: current) {
            vis[u.u] = vis[u.v] = 0; }
        for (auto u: current) {
            if (!vis[u.u]) { dfs2(u.u,0,ww[u.u]); } 
            if (!vis[u.v]) { dfs2(u.v,0,ww[u.u]); } } 
        for (auto u: current) {
            st.merge(u.u, u.v); }
        id = rid; }

    long long mx=0;
    vector <int> res;
    repa (i,n-1) {
        if (checkMax(mx, ans[i])) {
            res.clear(); res.push_back(i); }
        else if (mx == ans[i]) {
            res.push_back(i); } }
    sort(res.begin(), res.end());
    printf("%lld %lu\n", mx*2, res.size());
    for (int u: res) { printf("%d ", u); }
}