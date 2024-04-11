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

template <int N> struct STree {
    struct Node {
        int minVal, minCnt, tag;
        Node () { minVal=0; minCnt=0; tag=0; }
        void pushUp(Node &l, Node &r) {
            if (l.minVal < r.minVal) { minVal = l.minVal; minCnt = l.minCnt; }
            else if (r.minVal < l.minVal) { minVal = r.minVal; minCnt = r.minCnt; }
            else { minVal = l.minVal; minCnt = l.minCnt + r.minCnt; } }
        void pushAdd(int u) {
            minVal+=u; tag+=u; }
        void pushDown(Node &l, Node &r) {
            l.pushAdd(tag); r.pushAdd(tag); tag=0; }
    };

    static const int R = 1;
    Node p[N*4];

    void build(int l, int r, int u = R) {
        p[u].minCnt = r - l + 1;
        if (l == r) { return; }
        int mid = (l+r)/2;
        build(l, mid, u+u); build(mid+1, r, u+u+1); }
    void modify(int l, int r, int sl, int sr, int val, int u=R) {
        if (sl <= l && r <= sr) { p[u].pushAdd(val); return; }
        p[u].pushDown(p[u+u], p[u+u+1]);
        int mid = (l+r)/2;
        if (sl <= mid) modify(l,mid, sl,sr, val, u+u); 
        if (sr > mid ) modify(mid+1,r, sl,sr, val, u+u+1);
        p[u].pushUp(p[u+u], p[u+u+1]); }
    Node queryCnt(int l, int r, int sl, int sr, int u=R) {
        if (sl <= l && r <= sr) { return p[u]; }
        p[u].pushDown(p[u+u], p[u+u+1]);
        int mid = (l+r)/2;
        if (sl > mid) { return queryCnt(mid+1,r, sl,sr, u+u+1); }
        if (sr <= mid) { return queryCnt(l,mid, sl,sr, u+u); }
        Node la = queryCnt(l,mid,sl,sr,u+u), ra = queryCnt(mid+1,r,sl,sr,u+u+1);
        Node res; res.pushUp(la, ra);
        return res; }
};

template <int N> class TreeBase {
    public:
        int ef[N], en[N*2], ev[N*2], ec;
        TreeBase () { memset(ef, -1, sizeof(ef)); memset(en, -1, sizeof(en)); ec=0; }
        void addEdge(int u, int v) {
            en[ec] = ef[u]; ef[u] = ec; ev[ec] = v; ec++;
            en[ec] = ef[v]; ef[v] = ec; ev[ec] = u; ec++; }

        class Edges {
            protected: int id; const int *en;
            public:
                Edges (int id, const int *en) : id(id) , en(en) {}
                class iterator : public std::iterator <std::input_iterator_tag, int> {
                    protected: int eid; const int *en;
                    public:
                          iterator (int _eid, const int *_en) : eid(_eid) , en(_en) {}
                          iterator& operator ++ () { eid = en[eid]; return *this; }
                          bool operator != (iterator b) const { return eid != b.eid; }
                          int operator * () const { return eid; } }; 
                iterator begin() { return iterator(id, en); }
                iterator end() { return iterator(-1, en); }  };
        Edges getEdges(int u) { return Edges( ef[u], en ); }

        class Nodes {
            protected: int id; const int *en, *ev;
            public:
                Nodes (int id, const int *en, const int *ev) : id(id) , en(en) , ev(ev) {}
                class iterator : public std::iterator <std::input_iterator_tag, int> {
                    protected: int eid; const int *en, *ev;
                    public:
                          iterator (int _eid, const int *_en, const int *_ev) 
                              : eid(_eid) , en(_en) , ev(_ev) {}
                          iterator& operator ++ () { eid = en[eid]; return *this; }
                          bool operator != (iterator b) const { return eid != b.eid; }
                          int operator * () const { return ev[eid]; } }; 
                iterator begin() { return iterator(id, en, ev); }
                iterator end() { return iterator(-1, en, ev); }  };
        Nodes getNodes(int u) { return Nodes( ef[u], en, ev ); }
};

template <int N> class TreeDfn : public TreeBase<N> {
    protected:
        int dfnCnt; 

    public:
        using TreeBase<N>::ev;
        using TreeBase<N>::getEdges;

        int dfnL[N], dfnR[N];
        TreeDfn() { dfnCnt = 0; }
        void getDfn(int u, int f=0) {
            dfnL[u] = dfnCnt++; 
            auto li = getEdges(u);
            for (auto e: li) if (ev[e] != f) { getDfn(ev[e], u); }
            dfnR[u] = dfnCnt; }
};

const int N = 100005;
int n, m;

struct Tree : public TreeDfn<N> {
    typedef std::pair<int, int> Inter;
    vector <Inter> le[N];
    using TreeDfn::dfnL;
    using TreeDfn::dfnR;
    using TreeBase::ev;
    STree<N> T;

    void init() {
        TreeDfn::getDfn(1,0);
        T.build(0,n); }
    void update(int u, int v) {
        int ul = dfnL[u], ur = dfnR[u];
        int vl = dfnL[v], vr = dfnR[v];
        Inter uu(ul,ur) , vv(vl,vr);
        if ( ul<=vl && ur>=vr ) { le[u].push_back(uu); }
        else if ( vl<=ul && vr>=ur ) { le[v].push_back(vv); }
        else {
            le[u].push_back(uu); le[u].push_back(vv); 
            le[v].push_back(uu); le[v].push_back(vv); } }
    int ans[N];
    void dfs(int u, int f) {
        for (Inter i: le[u]) { T.modify(0,n, i.L,i.R-1, 1); }
        auto res = T.queryCnt(0,n,0,n); 
        ans[u] = n+1 - res.minCnt - (T.queryCnt(0,n, dfnL[u], dfnL[u]).minVal != 0);
        for (int v: this->getNodes(u)) if (v != f) {
            dfs(v, u); }
        for (Inter i: le[u]) { T.modify(0,n, i.L,i.R-1, -1); } }
};

Tree T;
STree <N> ST;

void preInit() { } 
void init() {
    n = sc.n(); m = sc.n();
    rep (i,n-1) T.addEdge( sc.n(), sc.n() );
    T.init();
    rep (i,m) { T.update(sc.n(), sc.n()); }
}

void solve() {
    T.dfs(1,0);
    repa (i,n) { printf("%d%c", T.ans[i], " \n"[i==n]); }
}