#define ENABLE_LL
#include <iostream>
#include <cstdio>
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
using namespace std;

#ifndef CUSTOM_MAIN
void init();
void solve();
int main(){
try { 

#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif

} catch (...) { return 0; }
    return 0;
}
#endif

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
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

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr; typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;} }; Scanner sc(cin);
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } }
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }

const int N = 1000015;
const int INF = 1000000;
struct Line {
    int d,f,t;
    Line() { d=f=t=0; }
    void read() { scanf(III,&d,&f,&t); } 
    bool operator < (const Line& B) const {
        return d < B.d; } };
Line R[N],C[N];
int n,m;

void init() {
    scanf(II,&n,&m);
    rep (i,n) R[i].read(); rep (i,m) C[i].read();
}

struct FTree {
    int a[N];
    inline int low(int u) { return u&(-u); }
    FTree() { memset(a,0,sizeof(a)); }
    
    void modify(int u, int del) {
        ses(u);see(del);
        u += 5;
        while (u<N) { a[u] += del; u += low(u); } }
    int _query(int u) {
        u += 5; int res = 0;
        while (u) { res += a[u]; u -= low(u); } 
        return res; }
    int query(int l, int r) {
        ses(l);see(r);
        return _query(r) - _query(l-1); }
};

FTree st;
struct Inter {
    int l, r;
    Inter (int l=0, int r=0) : l(l),r(r) {} };
vector <Inter> Cs[N];

void solve() {
    int ans0=0, ans1=0;

    rep (i,n) if (R[i].f == 0 && R[i].t == INF) ans0++;
    rep (i,m) if (C[i].f == 0 && C[i].t == INF) ans0++;
    
    rep (i,m) {
        Cs[ C[i].f ] .push_back( Inter( C[i].d, 1 ) );
        Cs[ C[i].t+1 ] .push_back( Inter( C[i].d, -1 ) ); }
    sort(R,R+n);
    int cur = -1;
    rep (i,n) {
        while (cur < R[i].d) { cur++; for (auto& u: Cs[cur]) { st.modify( u.l, u.r ); } }
        ans1 += st.query(R[i].f, R[i].t); 
        ses(i);see(ans1); }
    
    ses(ans0);see(ans1);    
    printf(IN,ans0+ans1+1);
}