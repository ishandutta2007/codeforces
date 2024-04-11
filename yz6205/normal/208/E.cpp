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


const int N = 100005;
const int B = 20;
vector <int> e[N];
int n;

struct Query { int u,x; } qs[N];
struct Off { int d,id,ans; Off (int d, int id, int ans) : d(d), id(id), ans(ans) { ans = 0; } };
vector <Off> qn[N];
int q;

int len[N], ls[N], fa[N][B];
void dfs0 (int u, int f) {
    len[u] = 1;
    fa[u][0] = f; rep (i,B-1) fa[u][i+1] = fa[ fa[u][i] ][i];
    for (int v: e[u]) if (v!=f) {
        dfs0(v,u);
        if (checkMax(len[u], len[v]+1)) { ls[u] = v; } } }
int up(int u, int d) { 
    rep (i,B) if (d & (1<<i)) { u = fa[u][i]; }
    return u; }

void preInit() { } void init() {
    n = sc.n();
    repa (i,n) { e[ sc.n() ].push_back(i); }
    dfs0(0,0);
}

struct Vec {
    vector <int> a;
    int size() { return a.size(); }
    void pushFront(int u) { a.push_back(u); }
    int& operator [] (int id) { return a[size()-id-1]; }
    void inherit(Vec& B) { a = move(B.a); }
};

Vec dp[N];

void dfs2(int u, int f) {
    see(u,f,ls[u]);
    for (int v: e[u]) if (v!=f) { dfs2(v,u); }
    if (ls[u] != 0) { dp[u].inherit( dp[ls[u]] ); }
    for (int v: e[u]) if (v!=f && v!=ls[u]) {
        see(u,v);
        see(dp[u].size(), dp[v].size());
        rep (i, (int)dp[v].size()) { dp[u][i] += dp[v][i]; } }
    dp[u].pushFront(1);
    for (auto& q: qn[u]) {
        if (q.d >= dp[u].size()) { q.ans = 0; }
        else { q.ans = dp[u][q.d]; } } }

void solve() {
    q = sc.n();
    {
        int qnc = 0;
        rep (i,q) { 
            qs[i].u = sc.n(); qs[i].x = sc.n();
            int r = up( qs[i].u, qs[i].x );
            if (r == 0) { continue; }
            qn[ r ].push_back( {qs[i].x  , qnc,0} ); qnc++; }
    }
    dfs2(0,0);
    vector <Off> qq;
    repa (i,n) for (auto& q: qn[i]) qq.push_back(q); 
    sort(qq.begin(), qq.end(), [](Off a, Off b) { return a.id < b.id; } );
    {
        int qnc = 0;
        rep (i,q) { 
            int r = up( qs[i].u, qs[i].x );
            if (r == 0) { printf("%d ", 0); continue; }
            printf("%d ", qq[qnc].ans - 1);
            qnc++; }
    }
}