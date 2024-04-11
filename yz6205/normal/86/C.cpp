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

const int MOD = (int)(1e9)+9;
const int N =  11;
const int M = 1024;
char s[N][N];
int a[N][N];
int n, m;

char mp[128];

struct Node {
    Node* s[4]; 
    Node* fail;
    int id; int tg;

    Node (int _id = 0) {
        rep (i,4) { s[i] = NULL; }
        fail = NULL; id=_id; tg=0; }
};

struct AhoCorasick {
    Node* R; Node *fr[105];
    int validEnd[105];
    int cnt;

    AhoCorasick () {
        cnt=0;
        fr[0] = R = new Node(cnt++); }

    void insert(int *a) {
        Node* p=R; int len = 0;
        while (*a != -1) {
            len ++;
            if (p->s[*a] == NULL) { p->s[*a] = fr[cnt] = new Node(cnt); cnt++; }
            p = p->s[*a]; a++; }
        p->tg = len; }

    void build() {
        Node *E = R->fail = new Node(-1); 
        rep (i,4) E->s[i] = R;
        queue < Node* > que;
        que.push( R );
        while (!que.empty()) {
            Node* u=que.front(); que.pop();
            validEnd[ u->id ] = u->tg;
            rep (i,4) {
                Node* v=u->s[i];
                if (v == NULL) {
                    u->s[i] = u->fail->s[i]; } 
                else {
                    v->fail = u->fail->s[i];
                    checkMax(v->tg, v->fail->tg);
                    que.push(v); } } } }
};

void init() {
    scanf(II,&n,&m);
    rep (i,m) scanf("%s", s[i]);
    mp[(int)'A'] = 0;    mp[(int)'C'] = 1;    mp[(int)'G'] = 2;    mp[(int)'T'] = 3; mp[0] = -1;
    rep (i,m) rep (j,N) a[i][j] = mp[(int)s[i][j]];
}

AhoCorasick ac;

int dp[M][M][N];

void solve() {
    rep (i,m) ac.insert(a[i]);
    ac.build();
    dp[0][0][0] = 1;
    rep (i,n) rep (p,ac.cnt) rep (l,11) {
        int u = dp[i][p][l];
        if (u) rep (j,4) {
            int pos = ac.fr[p]->s[j]->id;
            (dp[i+1][pos][ ac.fr[pos]->tg > l ? 0 : min(10,l+1) ] += u) %= MOD; } }
    int ans = 0;
    rep (i,ac.cnt) (ans += dp[n][i][0]) %= MOD; 
    rep (i,ac.cnt) { ses(dp[n][i][0]); see(""); }
    printf(IN,ans);
}








void preInit() { }