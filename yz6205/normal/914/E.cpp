#ifndef _LIB_TREE
#define _LIB_TREE

#include <iterator>
#include <cstring>

namespace Tree {

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

    template <int N> class TreeDfn : virtual public TreeBase<N> {
        protected:
            int dfnCnt; 

        public:
            using TreeBase<N>::ev;
            using TreeBase<N>::getNodes;

            int dfnL[N], dfnR[N];
            TreeDfn() { dfnCnt = 0; }
            void getDfn(int u, int f=0) {
                dfnL[u] = dfnCnt++; 
                auto vs = getNodes(u);
                for (auto v: vs) if (v != f) { getDfn(v, u); }
                dfnR[u] = dfnCnt; }
    };

    template <int N> class TreeLca : virtual public TreeBase<N> {
        protected:
            static const int B = 24;

        public:
            using TreeBase<N>::ev;
            using TreeBase<N>::getNodes;
            int fa[N][B], d[N];

            TreeLca () { memset(fa,0,sizeof(fa)); memset(d,0,sizeof(d)); }
            void initLca(int u, int f=0) {
                d[u] = d[f] + 1;
                fa[u][0] = f; for (int i=0;i<B-1;i++) { fa[u][i+1] = fa[ fa[u][i] ][i]; }
                auto vs = getNodes(u);
                for (auto v: vs) if (v != f) { initLca(v,u); } }
            int up(int u, int d) {
                for (int i=0;i<B;i++) { if ((d>>i)&1) { u = fa[u][i]; } }
                return u; }
            int lca(int u, int v) {
                if (d[u] < d[v]) { int tmp=u; u=v; v=tmp; } u = up(u, d[u]-d[v]); 
                for (int i=B-1; i>=0; i--) { if (fa[u][i] != fa[v][i]) { u=fa[u][i]; v=fa[v][i]; } }
                return u==v ? u : fa[u][0]; }
    };

}

#endif /* _LIB_TREE */
#define ENABLE_LL
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
#define ses(...) cout << #__VA_ARGS__ << " = "; __ses(__VA_ARGS__)
#define see(...) ses(__VA_ARGS__); cout << endl
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



#ifndef _LIB_ARRAY
#define _LIB_ARRAY 1
namespace Array { 
template <int N, class T> class Array {
protected: T a[N]; int upt[N]; int t; 
public: Array () { t=0; for (int i=0;i<N;i++) upt[i]=0; } T& operator [] (const int i) { if (upt[i] < t) { a[i] = T(); upt[i] = t; } return a[i]; } void clear() { t++; } }; 
}
#endif /* _LIB_ARRAY */


const int N = 200005;
struct Tr : public Tree::TreeBase<N> {
    static const int B = 20;
    using TreeBase<N>::getNodes;

    int val[N]; 
    int sz[N], vis[N], root, size;
    int ans[N];

    Tr () { memset(ans,0,sizeof(ans)); }
    
    void getSize(int u, int f) {
        sz[u] = 1;
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f && !vis[v]) {
            getSize(v,u); sz[u] += sz[v]; } }
    void getRoot(int u, int f) {
        int maj = size-sz[u];
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f && !vis[v]) { 
            checkMax(maj, sz[v]);
            getRoot(v,u); } 
        if (maj * 2 <= size) { root = u; } }

    Array::Array<(1<<B), int> cnt;
    Array::Array<N, int> pans;
    void getState(int u, int f, int st, int del) {
        st ^= (1<<val[u]); cnt[st] += del;
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f && !vis[v]) {
            getState(v,u,st,del); } }
    void updAns(int u, int f, int st) {
        st ^= (1<<val[u]);
        ans[u] += cnt[st]; pans[u] += cnt[st];
        rep (i,B) { ans[u] += cnt[st ^ (1<<i)]; pans[u] += cnt[st ^ (1<<i)]; }
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f && !vis[v]) {
            updAns(v,u,st); ans[u] += pans[v]; pans[u] += pans[v]; } }
    int updRoot(int u, int f, int st, int rst) {
        st ^= (1<<val[u]);
        int ans = 0;
        if (st == rst) { ans++; }
        rep (i,B) if ( (st^(1<<i)) == rst ) { ans++; }
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f && !vis[v]) {
            ans += updRoot(v,u,st,rst); }
        return ans; }
    void dfs(int u) {
        see(u);
        cnt.clear(); pans.clear();
        int pos = 1<<val[u];
        cnt[pos] = 1;
        auto vs = getNodes(u);
        for (int v: vs) if (!vis[v]) {
            getState(v,u,pos,1); }
        int delu = 0;
        for (int v: vs) if (!vis[v]) {
            getState(v,u,pos,-1); 
            updAns(v,u,0); delu += pans[v] + updRoot(v,u,0,pos);
            getState(v,u,pos,1); }
        see(delu);
        ans[u] += delu/2;
        vis[u] = 1;
        for (int v: vs) if (!vis[v]) {
            getSize(v,u); size=sz[v]; getRoot(v,u);
            dfs(root); } }
} T;

int n;
char s[N];

void preInit() { } void init() {
    n=sc.n();
    rep (i,n-1) { int u=sc.n(), v=sc.n(); T.addEdge(u,v); }
    rep (i,n) T.val[i+1] = sc.nextChar()-'a';
}

void solve() {
    T.dfs(1);
    repa (i,n) printf("%lld%c", T.ans[i]+1, " \n"[i==n]);
}