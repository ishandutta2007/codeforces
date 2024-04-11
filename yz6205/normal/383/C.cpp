
#ifndef _LIB_STREE
#define _LIB_STREE 1

#include <algorithm>

namespace STree {

// Template Node for maintain sums
struct NodeSum {
    int val; int tg;
    NodeSum (int val=0, int tg=0) : val(val), tg(tg) {}
    void update(int _val) {
        val += _val; tg += _val; }
    void pushUp (NodeSum a, NodeSum b) {
        val = a.val + b.val; }
    void pushDown (NodeSum &a, NodeSum &b) {
        a.val += tg; b.val += tg;
        a.tg += tg; b.tg += tg;
        tg = 0; }
};

// Template Node for maintain maxs
struct NodeMax {
    int val; int tg;
    NodeMax (int val=0, int tg=0) : val(val), tg(tg) {}
    void update(int _val) {
        val += _val; tg += _val; }
    void pushUp (NodeMax a, NodeMax b) {
        val = std::max(a.val, b.val); }
    void pushDown (NodeMax &a, NodeMax &b) {
        a.val += tg; b.val += tg;
        a.tg += tg; b.tg += tg;
        tg = 0; }
};

//Default STree for maintain maxs
template <int N, class Item=NodeMax> class STree {
protected:
    Item a[N*4];
    int g_l, g_r;

    template <class T> 
    void _modify(int l, int r, int sl, int sr, T val, int u) {
        if (sl <= l && r <= sr) {
            a[u].update(val); 
            return; }
        a[u].pushDown(a[u+u],a[u+u+1]); 
        int mid = (l+r)/2;
        if (sl <= mid)   _modify(l,mid,  sl,sr,val,u+u);
        if (sr > mid)    _modify(mid+1,r,sl,sr,val,u+u+1);
        a[u].pushUp(a[u+u],a[u+u+1]); }

    Item _query(int l, int r, int sl, int sr, int u) {
        if (sl <= l && r <= sr) {
            return a[u]; }
        a[u].pushDown(a[u+u],a[u+u+1]); 
        int mid = (l+r)/2;
        if (sl > mid)        return _query(mid+1,r,sl,sr,u+u+1); 
        else if (sr <= mid)  return _query(l,mid,sl,sr,u+u);
        else {   
            Item res; 
            res.pushUp( _query(l,mid,sl,sr,u+u), _query(mid+1,r,sl,sr,u+u+1) );
            return res; } }
public:
    void setLR(int _l, int _r) {
        g_l = _l, g_r = _r; }
    template <class T> 
    void modify(int l, int r, T val) {
        if (r > g_r) { r = g_r; }
        _modify(g_l,g_r,l,r,val,1); }
    Item query(int l, int r) {
        return _query(g_l,g_r,l,r,1); }
};

} /* namespace STree */ 

#endif /* _LIB_STREE */
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
vector <int> e[N];
int n,m, a[N];

void preInit() { } void init() {
    n = sc.n(); m = sc.n(); 
    repa (i,n) a[i] = sc.n();
    rep (i,n-1) { int u=sc.n(), v=sc.n(); e[u].push_back(v); e[v].push_back(u); }
}

int w[N], l[N], r[N];
void dfs(int u, int f) {
    static int dfn = 0;
    w[u] = -w[f]; l[u] = dfn++;
    for (int v: e[u]) if (v!=f) { dfs(v,u); } 
    r[u] = dfn-1; }

STree::STree<N, STree::NodeSum> ST;

void solve() {
    w[0] = -1; dfs(1,0);
    ST.setLR(0,n-1);
    repa (i,n) { ST.modify( l[i],l[i], a[i]*w[i] );  }
    rep (i,m) {
        int opt = sc.n();
        if (opt == 1) {
            int u=sc.n(), v=sc.n();
            ST.modify(l[u], r[u], w[u]*v); }
        else if (opt == 2) {
            int u=sc.n();
            printf("%d\n", ST.query(l[u],l[u]).val * w[u]); } }
}