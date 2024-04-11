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
const int MOD = 998244353;
int a[N];
int n, k;
vector < int > e[2];

void init() {
    scanf(II,&n,&k);
    rep (i,n) scanf(I,&a[i]);
    rep (i,n) e[i&1].push_back(a[i]);
}

int power(int base, int exp) {
    int res=1;
    while( exp) {
        if (exp&1) (res*=base) %=MOD;
        (base*=base)%=MOD;
        exp>>=1;
    }
    return res;
}

int dp[N][2];
int go(vector < int > & a) {
    if (a.size() == 0) return 1;
    int ans=1;
    vector < int > ps;
    repe (i,a) if (a[i] != -1) ps.push_back(i);

    if (ps.size() == 0) return (dp[a.size()][0] + dp[a.size()][1]) * k % MOD;

    int lenb = ps[0], lena = a.size()-ps.back()-1;
    (ans *= dp[lenb+1][0]+dp[lenb+1][1]) %= MOD;
    (ans *= dp[lena+1][0]+dp[lena+1][1]) %= MOD;
    

    rep (i,(int)ps.size()-1) {
        int l=ps[i], r=ps[i+1];
        int len = r-l+1;
        if (a[l] == a[r]) {
            (ans *= dp[len][1]) %= MOD;
        } else {
            (ans *= dp[len][0] * power(k-1,MOD-2) % MOD) %= MOD;
        }
    }
    return ans;
}

void solve() {
    dp[1][0] = 0; dp[1][1] = 1;
    repi (i,2,n) {
        dp[i][0] = (dp[i-1][0] * (k-2) % MOD + dp[i-1][1] * (k-1) % MOD) % MOD;
        dp[i][1] = dp[i-1][0];
    }
    printf(IN, go(e[0]) * go(e[1]) % MOD);
}