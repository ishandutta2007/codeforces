#define ENABLE_LL
#include <bitset>
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

const int MOD = 100000007;
const int N = 200005;
char s[N];
int n, m;

void init() {
    scanf(II,&n,&m);
    scanf("%s",s);
}

bool equal(vector < int > & a , vector < int > & b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    repe (i,a) {
        ses(a[i]);see(b[i]);
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int power(int a, int b) {
    int res=1;
    while (b) {
        if (b&1) (res*=a) %=MOD;
        (a*=a) %=MOD;
        b>>=1;
    }
    return res;
}

int po[N];
int inv[N];
int __hash[N][26];
void solve() {
    po[0]=1; repa (i,N-1) po[i] = po[i-1]*2%MOD;
    rep (i,N) inv[i] = power(po[i],MOD-2);
    //rep (i,26) __hash[0][i] = 1;
    rep (i,n) {
        rep (j,26) __hash[i+1][j] = __hash[i][j];
        int c = s[i]-'a';
        (__hash[i+1][c] += po[i]) %= MOD;
        ses(c);see(bitset<30>(__hash[i+1][c]));
    }
    rep (i,m) {
        int x, y, z; scanf(III,&x,&y,&z); x--; y--;
        vector < int > a, b;
        ses(inv[x]);see(inv[y]);
        rep (i,26) a.push_back(((__hash[x+z][i]-__hash[x][i]+MOD)%MOD*inv[x]) % MOD);
        rep (i,26) b.push_back(((__hash[y+z][i]-__hash[y][i]+MOD)%MOD*inv[y]) % MOD);
        puts(equal(a,b) ? "YES" : "NO");
    }
}