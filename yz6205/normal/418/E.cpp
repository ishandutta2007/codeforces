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
using namespace std;

void init();
void solve();
int main(){
try { 

#ifndef CUSTOM_MAIN
#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif
#endif

} catch (const char* s) { return 0; }
    return 0;
}

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

const int N = 200005;
const int B = 2000;
int a[N]; 
int t[N], x[N], y[N], n, m, k;
int s[N]; int cc=0;

void init() {
    scanf(I,&m); rep (i,m) scanf(I,&a[i]); scanf(I,&k); rep (i,k) scanf(III,&t[i],&x[i],&y[i]);
    rep (i,m) s[cc++]=a[i]; rep (i,k) if (t[i]==1) s[cc++]=x[i]; sort(s,s+cc); cc=unique(s,s+cc)-s;
    rep (i,m) a[i]=lower_bound(s,s+cc,a[i])-s; rep (i,k) if (t[i]==1) x[i]=lower_bound(s,s+cc,x[i])-s;
}
int bcnt;
int c[N/B+5][N], f[N/B+5][N];

inline void insert(int c[], int f[], int u) {
    c[u]++; f[c[u]]++; }
inline void erase(int c[], int f[], int u) {
    f[c[u]]--; c[u]--; }

void initCF() {
    rep (i,N) { c[0][i]=0; } 
    repa (i,bcnt) {
        rep (j,N) c[i][j]=c[i-1][j]; rep (j,N) f[i][j]=f[i-1][j];
        int l=(i-1)*B, r=i*B-1;
        repi (j,l,r) insert(c[i],f[i],a[j]); } }
    
int query0(int u) {
    int completeBars=u/B; int startPoint=completeBars*B;
    repi (i,startPoint,u) insert(c[completeBars], f[completeBars], a[i]);
    int res= c[completeBars][a[u]]; 
    repi (i,startPoint,u) erase(c[completeBars], f[completeBars], a[i]);
    return res; }
int query1(int u) {
    rep (i,m) ses(a[i]); see("");
    int completeBars=u/B; int startPoint=completeBars*B;
    repi (i,startPoint,u) insert(c[completeBars], f[completeBars], a[i]);
    int res= f[completeBars][c[completeBars][a[u]]]; 
    repi (i,startPoint,u) erase(c[completeBars], f[completeBars], a[i]);
    return res; }

void update(int u, int t) {
    int startPoint=u/B;
    repi (i,startPoint+1,bcnt) { erase(c[i],f[i],a[u]); insert(c[i],f[i],t); }
    a[u] = t; }

void solve() {
    bcnt= m/B; initCF();
    rep (_,k) {
        if (t[_]==2) {
            if (x[_]==1) printf(IN,s[ a[y[_]-1] ]);
            else if (x[_]%2==0) printf(IN,query0( y[_]-1 ));
            else printf(IN,query1( y[_]-1 )); }
        else { update(y[_]-1, x[_]); } 
    }
}