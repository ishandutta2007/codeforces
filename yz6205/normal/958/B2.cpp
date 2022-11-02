#include <iostream>
#include <cstdio>
using namespace std; 
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

const int N = 100005;
vector <int> e[N];
int n;



void preInit() {
    scanf(I,&n); 
    rep (i,n-1) { int u,v; scanf(II,&u,&v); e[u].push_back(v); e[v].push_back(u); }
}

int maxDep, root;
vector <int> anss;
int he[N];

void dfs(int u, int f, int d) {
    if (checkMax(maxDep,d)) { root = u; }
    for (int v: e[u]) if (v!=f) { dfs(v,u,d+1); } }
void dfs0(int u, int f) {
    he[u] = 1;
    for (int v: e[u]) if (v!=f) {
        dfs0(v,u); checkMax(he[u],he[v]+1); } }
void dfs1(int u, int f, int d) {
    if (f!=0 && e[u].size() == 1) {
        anss.push_back(d); return; }
    int maxHe = 0; for (int v: e[u]) if (v!=f) checkMax(maxHe,he[v]);
    for (int v:e[u]) if (v!=f) {
        if (he[v] == maxHe) {
            maxHe = 0x3f3f3f3f; dfs1(v,u,d+1); }
        else {
            dfs1(v,u,1) ;} } }

void init() {
    dfs(1,0,1);
}

void solve() {
    dfs0(root,0);
    dfs1(root,0,0);
    sort(anss.begin(), anss.end(), [](int a, int b) { return a>b; });
    anss.insert(anss.begin(), 1);
    rep (i,(int)anss.size()-1) { anss[i+1] += anss[i]; }
    for (int a: anss) { printf("%d ",a); }
    rep (i,n-(int)anss.size()) { printf("%d ",n); }
}