

#ifndef _LIB_ARRAY
#define _LIB_ARRAY 1
namespace Array { 
template <int N, class T> class Array {
protected: T a[N]; int upt[N]; int t; 
public: Array () { t=0; for (int i=0;i<N;i++) upt[i]=0; } T& operator [] (const int i) { if (upt[i] < t) { a[i] = T(); upt[i] = t; } return a[i]; } void clear() { t++; } }; 
}
#endif /* _LIB_ARRAY */


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
                protected: int id; const TreeBase *th;
                public:
                    Edges (int id, const TreeBase *th) : id(id) , th(th) {}
                    class iterator : public std::iterator <std::input_iterator_tag, int> {
                        protected: int eid; const TreeBase *th;
                        public:
                              iterator (int _eid, const TreeBase *th) : eid(_eid) , th(th) {}
                              iterator& operator ++ () { eid = th->en[eid]; return *this; }
                              bool operator != (iterator b) const { return eid != b.eid; }
                              int operator * () const { return eid; } }; 
                    iterator begin() { return iterator(id, th); }
                    iterator end() { return iterator(-1, th); }  };
            Edges getEdges(int u) { return Edges( ef[u], this ); }

            class Nodes {
                protected: int id; const TreeBase *th;
                public:
                    Nodes (int id, const TreeBase *th) : id(id), th(th) {}
                    class iterator : public std::iterator <std::input_iterator_tag, int> {
                        protected: int eid; const TreeBase *th;
                        public:
                              iterator (int _eid, const TreeBase *th) : eid(_eid) , th(th) {}
                              iterator& operator ++ () { eid = th->en[eid]; return *this; }
                              bool operator != (iterator b) const { return eid != b.eid; }
                              int operator * () const { return th->ev[eid]; } }; 
                    iterator begin() { return iterator(id, th); }
                    iterator end() { return iterator(-1, th); }  };
            Nodes getNodes(int u) { return Nodes( ef[u], this ); }
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

const int N = 200005;
int n;

namespace Math {
    int fac[N*105], facSt[N], facCnt;
    void _factor(int u) {
        facSt[u] = facCnt;
        for (int i=1;i*i<=u;i++) {
            if (u%i == 0) {
                fac[facCnt++] = i;
                if (i*i!=u) fac[facCnt++] = u/i; } } }
    void initFac() { facCnt=0; rep (i,N) _factor(i); }
    int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }
    int mu[N], isp[N]; vector <int> prime;
    void initMul() {
        mu[1] = 1; rep (i,N) isp[i] = 1;
        repi (i,2,N-1) {
            if (isp[i]) { prime.push_back(i); mu[i] = -1; }
            for (int j: prime) {
                int u=i*j;
                if (u >= N) { break; }
                isp[u] = 0; 
                if (i % j == 0) { mu[u] = 0; break; }
                else { mu[u] = -mu[i]; } } } }
};

int uval[N*2];

struct Tr2 : public Tree::TreeBase<N*2> {
    using Tree::TreeBase<N*2>::getEdges;
    using Tree::TreeBase<N*2>::ev;
    using Tree::TreeBase<N*2>::ef;
    using Tree::TreeBase<N*2>::en;

    int ec[N*4], sz[N*2];
    int eU, eV, eI, eC, size;
    Tr2 () { memset(ec, 0, sizeof(ev)); }

    void getSize(int u, int f) {
        sz[u] = 1;
        for (int e=ef[u]; e!=-1; e=en[e]) if (ev[e] != f && !ec[e]) {
            getSize( ev[e], u ); sz[u] += sz[ ev[e] ]; } }
    void getEdge(int u, int f) {
        for (int e=ef[u]; e!=-1; e=en[e]) if (ev[e] != f && !ec[e]) {
            int v = ev[e];
            int vC = max( sz[v], size-sz[v] ); 
            if (checkMin(eC, vC)) { eU=u; eV=v; eI=e; }
            getEdge(v,u); } }
    bool get(int u) {
        getSize(u, 0); size = sz[u];
        if (size == 1) { return 1; }
        eC = 0x3f3f3f3f; 
        getEdge(u,0);
        ec[eI]=ec[eI^1]=1;
        return 0; }
    
    long long ans[N];
    typedef Array::Array<N,int> Arr;
    Arr cnt;

    void getAns(int u, int f, int pg) {
        pg = Math::gcd(pg, uval[u]); 
        if (u <= n) { 
            repi (i, Math::facSt[pg], Math::facSt[pg+1]-1) {
                cnt[ Math::fac[i] ] ++; } }
        auto es = getEdges(u);
        for (int e: es) if (ev[e] != f && !ec[e]) {
            getAns(ev[e], u, pg); } }
    void getAns2(int u, int f, int pg) {
        pg = Math::gcd(pg, uval[u]); 
        if (u <= n) { 
            repi (i, Math::facSt[pg], Math::facSt[pg+1]-1) {
                ans[ Math::fac[i] ] += cnt[ Math::fac[i] ]; } }
        auto es = getEdges(u);
        for (int e: es) if (ev[e] != f && !ec[e]) {
            getAns2(ev[e], u, pg); } }
    void dfs(int u) {
        if (get(u)) { return; }
        cnt.clear(); 
        getAns(eU, 0, 0); getAns2(eV, 0, 0);
        int _eU = eU, _eV = eV;
        dfs(_eU); dfs(_eV); }
} T2;

struct Tr1 : public Tree::TreeBase<N> {
    using Tree::TreeBase<N>::getNodes;

    int st; Tr2 *T;
    void set(int n, Tr2 *_T) { st=n+1; T=_T; }

    void dfs(int u, int f) {
        int pre = u;
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f) {
            uval[pre] = uval[u]; 
            T->addEdge(pre, st); T->addEdge(st, v); pre=st; st++; }
        for (int v: vs) if (v!=f) { dfs(v,u); } }
} T1;

long long ans[N];
void trans(long long a[], int n) {
    repa (i,n-1) {
        if (a[i] == 0) { continue; }
        see(i, a[i]);
        repi (j, Math::facSt[i], Math::facSt[i+1]-1) {
            ans[ Math::fac[j] ] += a[i] * Math::mu[ i/Math::fac[j] ]; } } }

void preInit() { Math::initMul(); Math::initFac(); } void init() {
    n = sc.n();
    repa (i,n) uval[i] = sc.n();
    rep (i,n-1) T1.addEdge( sc.n(), sc.n() ); 
}

void solve() {
    T1.set(n, &T2);
    T1.dfs(1,0);
    T2.dfs(1);
    trans( T2.ans, N );
    repa (i,n) ans[ uval[i] ] ++; 
    repa (i,N-1) { if (ans[i] != 0) { printf("%d %lld\n", i, ans[i]); } }
}