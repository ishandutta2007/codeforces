#define ENABLE_LL
#include <iostream>
#include <cstdio>
using namespace std; 
#ifndef _LIB_SCANNER
#define _LIB_SCANNER 1

#include <stdio.h>
#include <stdlib.h>

#ifdef ENABLE_LL 
#   define int long long 
#endif

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
#undef int
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
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } } 
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
    return 0;
}

#endif /* CUSTOM_MAIN */

// my code begins here



const int N = 200005;
vector <pr> e[N];
int dep[N], vis[N], fa[N], faDis[N];
int mark[N], st, ed;
vector <int> a,b;
int n;


void preInit() {
    n = sc.nextInt();
    rep (i,n) { 
        int u=sc.nextInt(), v=sc.nextInt(), w=sc.nextInt();
        e[u].push_back({v,w}); e[v].push_back({u,w}); }
}

int preAns;

void dfs(int u, int f) {
    vis[u] = 1; fa[u] = f;
    for (pr v: e[u]) if (v.L != f) {
        if (vis[v.L]) {
            if (dep[v.L] < dep[u]) {
                st = u; ed = v.L; }
            else {
                faDis[u] = v.R; } }
        else if (!vis[v.L]) {
            dep[v.L] = dep[u] + v.R;  faDis[v.L] = v.R;
            dfs(v.L,u); } } }

int dfs1(int u, int f) {
    int res = 0;
    for (pr v: e[u]) if (v.L!=f && !mark[v.L]) {
        int va = dfs1(v.L,u) + v.R; checkMax(preAns,res+va);
        checkMax(res, va); }
    return res; }

void init() {
    dfs(1,0);
    int u = st; while (u != ed) { mark[u] = 1; u = fa[u]; } mark[ed] = 1;
    b.push_back(faDis[ed]);
    u = st; while (u != ed) { 
        a.push_back(dfs1(u,0)); b.push_back(faDis[u]); 
        u = fa[u]; } 
    a.push_back(dfs1(ed,0)); 
}

struct Ds {
    multiset <pr> st;
    int g;

    Ds () { st.clear(); g=0; }
    void insert(pr u) {
        u.L -= g; st.insert(u); }
    void erase(pr u) {
        st.erase(st.find(u)); }
    void globalAdd(int u) {
        g += u; }
    pair<pr,pr> queryMax() {
        pr a = (*st.rbegin()); a.L += g;
        pr b = *(++st.rbegin()); b.L += g;
        return { a,b }; }
    void log() {
        see("Ds::log(): start");
        for (pr u: st) { ses(u.L+g); see(u.R); } }
};

vector <int> bSum;
void solve() {
    // n = 9; rep (i,n) { a.push_back(sc.nextInt()); b.push_back(sc.nextInt()); }
    n = (int)a.size(); rep (i,n) { a.push_back(a[i]); b.push_back(b[i]); }
    for (int ib: b) { if (bSum.size() != 0) { ib += bSum.back(); } bSum.push_back(ib); }
    rep (i,2*n) { ses(a[i]); see(b[i]); }
    int ans = 0x3f3f3f3f3f3f3f3f;
    Ds l,r;
    rep (i,n*2) {
        l.globalAdd(b[i]); r.globalAdd(-b[i]); 
        l.insert({a[i],i}); r.insert({a[i],i});
        if (i>=n) {
            l.erase({a[i-n]-bSum[i-n],i-n}); r.erase({a[i-n]+bSum[i-n],i-n}); }
        if (i == n-1) { see(""); }
        if (i>=n-1) {
            auto ll = l.queryMax(), rr = r.queryMax();
//                cout << ll.L.R << ' ' << ll.R.R << ' ' << rr.L.R << ' ' << rr.R.R << ' ' << 
//                    ll.L.L << ' ' << ll.R.L << ' ' << rr.L.L << ' ' << rr.R.L << endl;
            if (ll.L.R == rr.L.R) {
                checkMin(ans, max(ll.R.L+rr.L.L , ll.L.L+rr.R.L)); }
            else {
                checkMin(ans, ll.L.L + rr.L.L); } } }
    see(ans);
    printf(IN,max(preAns,ans));
}