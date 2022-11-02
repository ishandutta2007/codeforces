#include <iostream>
#include <cstdio>
using namespace std; 
#ifndef _LIB_SCANNER
#define _LIB_SCANNER 1

#include <stdio.h>
#include <stdlib.h>

class Scanner {
private:
    static const int BUFFER_SIZE = 10000;
    char buff[BUFFER_SIZE];
    int buffPos, buffLim;

public:
    Scanner () { 
        buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
        buffPos = 0;
    }

private:
    inline void flushBuff() {
        buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
        if (buffLim==0) {
            buff[buffLim++] = '\n';
        }
        buffPos = 0; 
    }

    inline bool isWS(char t) {
        return t==' ' || t=='\n';
    }

    inline bool isDig(char t) {
        return t>='0' && t<='9'; 
    }

    void nextPos() {
        buffPos++;
        if (buffPos == buffLim) {
            flushBuff();
        }
    }

#define getChar() buff[buffPos]

public:
    inline char getchar() {
        char ch=getChar();
        nextPos();
        return ch; 
    }

    inline void next(char* s) {
        while ( isWS(getChar()) ) {
            nextPos(); 
        }
        while ( !isWS(getChar()) ) {
            *s = getChar(); s++;
            nextPos();
        }
        *s = '\0';
    }

    inline void nextLine(char* s) {
        while ( getChar()!='\n' ) {
            nextPos();
        }
        if ( getChar()=='\n' ) {
            nextPos();
        }
        while ( getChar() != '\n' ) {
            *s = getChar(); s++;
            buffPos++;
        }
        *s = '\0';
    }

    inline int nextInt() {
        while ( !isDig(getChar()) ) {
            nextPos();
        }
        int sign = (getChar() == '-') ? nextPos(),-1 : 1;
        int res = 0;
        while (isDig(getChar())) {
            res = res*10 + getChar()-'0';
            nextPos();
        }
        return res * sign; 
    }

    inline double nextDouble() {
        while ( isWS(getChar()) ) {
            nextPos();
        }
        int sign = (getChar() == '-') ? nextPos(),-1 : 1;
        double res = 0;
        while (isDig(getChar())) {
            res = res * 10 + getChar()-'0';
            nextPos();
        }
        if (getChar() == '.') {
            nextPos();
            double ep = 1;
            while (isDig(getChar())) {
                ep *= 0.1;
                res += ep * (getChar()-'0');
                nextPos();
            }
        }
        return sign * res;
    }

    inline char nextChar() {
        while (isWS(getChar())) nextPos();
        char res = getChar(); nextPos();
        return res;
    }

#undef getChar
};
Scanner sc;
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

typedef pair < int , int > pr; 
typedef pair < pr  , int > prr; 
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); } 
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); } 
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw static_cast<string>("ALERT"); } } 
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }
#define L first
#define R second

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif

#ifndef CUSTOM_MAIN

void preInit();
void init(); 
void solve(); 

int32_t main(){ 
try {

preInit();

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
while(1) {
    try {init(); } 
    catch(bool t) {return 0;} 
    solve();
}
#else
init(); solve(); 
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */

#endif /* MULTIPLE_TEST_CASES_WITH_T */
} catch (string ss) { }
    return 0;
}

#endif /* CUSTOM_MAIN */



template <int N, class T> class Tree {
    protected:
        vector <int> e[N];
        T val[N];
     
    public:
        void addEdge(int u, int v) {
            e[u].push_back(v); e[v].push_back(u); }
        void setVal(int u, T _val) {
            val[u] = _val; }
};

template <int N, class T> class TreeLCA : public Tree<N,T> {
    protected:
        static const int B = 16;
        int fa[N][B], dep[N];

        void dfs(int u, int f) {
            dep[u] = dep[f] + 1;
            fa[u][0] = f; rep (i,B-1) { fa[u][i+1] = fa[ fa[u][i] ][i]; }
            for (int v: this->e[u]) if (v!=f) { dfs(v,u); } }

    public:
        void init(int st) {
            dfs(st,st); }
        inline void up(int& u, int d) {
            repb (i,B-1,0) { if ((d>>i)&1) { u=fa[u][i]; } } }
        T lca(int u, int v) {
            if (dep[u] < dep[v]) { swap(u,v); } up(u,dep[u]-dep[v]); 
            repb (i,B-1,0) { if (fa[u][i] != fa[v][i]) { u=fa[u][i]; v=fa[v][i]; } }
            return this->val[ (u==v)?u:fa[u][0] ]; }
};

template <int N> class Dsu {
    protected:
        int p[N];
    public:
        Dsu () { rep (i,N) p[i] = i; }
        int get(int u) { return (u==p[u]) ? u : p[u] = get(p[u]); }
        void merge(int u, int v) { p[get(v)] = get(u); }
        bool query(int u, int v) { return get(u) == get(v); } 
};

// my code begins here



const int N = 2500;
int a[N][N];
int n;

void preInit() {
    n = sc.nextInt();
    rep (i,n) rep (j,n) { a[i][j] = sc.nextInt(); }
}

void init() {
    rep (i,n) rep (j,n) { ALERT(a[i][j] != a[j][i], "NOT MAGIC"); } 
}

struct Edge { int u,v,w; };
TreeLCA <N*2,int> T;
vector <Edge> es;
Dsu<N*2> st;

void solve() {
    rep (i,n) rep (j,i) es.push_back( Edge( {i,j,a[i][j]} ) );
    sort(es.begin(), es.end(), [](Edge a, Edge b) { return a.w < b.w; });
    int nodeCnt=n;
    for (Edge e: es) {
        if (!st.query(e.u,e.v)) {
            T.setVal(nodeCnt, e.w); 
            T.addEdge(nodeCnt,st.get(e.u)); T.addEdge(nodeCnt,st.get(e.v)); 
            st.merge(nodeCnt, e.u); st.merge(nodeCnt, e.v); nodeCnt++; } }
    T.init(nodeCnt-1);
    rep (i,n) rep (j,n) { ses(i);ses(j);see(T.lca(i,j)); ALERT( a[i][j] > T.lca(i,j) , "NOT MAGIC" ); }
    puts("MAGIC");
}