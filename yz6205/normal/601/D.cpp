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


// Integer under mod

#ifndef _LIB_INTM
#define _LIB_INTM

namespace Intm { 
class Intm {
    protected:
        static const unsigned long long MOD;
        unsigned long long a;

    public:
        inline static void getModSub(unsigned long long & a) { if (a>=MOD) a-=MOD; }
        inline static void getMod(unsigned long long & a) { a %= MOD; }
        inline static unsigned long long power(unsigned long long a, unsigned long long b) {
            unsigned long long r = 1; while (b) { if (b&1) getMod(r*=a); getMod(a*=a); b>>=1; } return r; }

        Intm () { a=0; }
        Intm (unsigned long long _a) : a(_a) { getMod(a); }
        Intm& operator += (const Intm b) { a += b.a; getModSub(a); return *this; }
        Intm operator + (const Intm b) const { Intm R(a); return (R += b); }
        Intm& operator -= (const Intm b) { a += MOD-b.a; getModSub(a); return *this; }
        Intm operator - (const Intm b) const { Intm R(a); return (R -= b); }
        Intm& operator *= (const Intm b) { a *= b.a; getMod(a); return *this; }
        Intm operator * (const Intm b) const { Intm R(a); return (R *= b); }
        Intm& operator /= (const Intm b) { a *= power(b.a,MOD-2); getMod(a); return *this; }
        Intm operator / (const Intm b) const { Intm R(a); return (R /= b); }
        Intm pow(long long e) { return Intm(power(a,e)); }
        operator long long()  { getModSub(a); return (long long)a; } }; 
const unsigned long long Intm::MOD = 999999137; }

#endif /* _LIB_INTM */


struct HashSet {
    struct Int : public Intm::Intm {
        Int () : Intm(0) {}
        Int (unsigned long long _a) : Intm(_a) {} 
        bool operator < (const Int& B) const { return a < B.a; } };
    static const Int SEED1, SEED2;
    set <pair<Int,Int>> st;
    Int mul1, add1;
    Int mul2, add2;
    
    HashSet () { mul1=mul2=1; add1=add2=0; }
    void inherit(HashSet &B) {
        st = std::move( B.st );
        mul1 = B.mul1; add1 = B.add1; 
        mul2 = B.mul2; add2 = B.add2; }
    inline void push(Int del) {
        mul1 *= SEED1; add1 *= SEED1; add1 += del; 
        mul2 *= SEED2; add2 *= SEED2; add2 += del; }
    inline void insert(pair<Int,Int> u) {
        u.L -= add1; u.L /= mul1;
        u.R -= add2; u.R /= mul2;
        st.insert(u); }
    inline void merge(HashSet &B) {
        for (auto u: B.st) {
            u.L *= B.mul1; u.L += B.add1;
            u.R *= B.mul2; u.R += B.add2;
            insert(u); } }
    inline int size() {
        return st.size(); }
};
const HashSet::Int HashSet::SEED1 = 17;
const HashSet::Int HashSet::SEED2 = 13;

const int N = 300005;
struct Tr : public Tree::TreeBase<N> {
    using Tree::TreeBase<N>::getNodes;

    int sz[N], ws[N], val[N];
    Tr () { memset(sz,0,sizeof(sz)); memset(ws,0,sizeof(ws)); }
    void dfs1(int u, int f) {
        sz[u] = 1; int mv = 0;
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f) {
            dfs1(v,u); sz[u] += sz[v]; 
            if (checkMax(mv, sz[v])) { ws[u] = v; } } }

    int ans[N];
    HashSet st[N];
#define DDDD see(st[u].mul, st[u].add); for (HashSet::Int u: st[u].st) { see("Inner: ", u); }
    void dfs2(int u, int f) {
        auto vs = getNodes(u);
        for (int v: vs) if (v!=f) { dfs2(v,u);  }
        if (ws[u] != 0) { st[u].inherit(st[ws[u]]);  }
        st[u].insert( pr(0,0) );
        for (int v: vs) if (v!=f && v!=ws[u]) {
            st[u].merge( st[v] ); }
        st[u].push( val[u] ); 
        see(u,f,ws[u],st[u].size());
        ans[u] += st[u].size(); }
};

Tr T;
int n;

void preInit() { }
void init() {
    n = sc.n(); 
    repa (i,n) T.ans[i] = sc.n();
    repa (i,n) T.val[i] = sc.nextChar()-'a'+1;
    rep (i,n-1) { int u=sc.n(), v=sc.n(); T.addEdge(u,v); }
}

void solve() {
    T.dfs1(1,0);
    T.dfs2(1,0);
    int mx=0, cnt=0;
    repa (i,n) {
        if (checkMax(mx, T.ans[i])) { cnt = 1; }
        else if (mx == T.ans[i]) { cnt++; } }
    printf(IN,mx); printf(IN,cnt);
}