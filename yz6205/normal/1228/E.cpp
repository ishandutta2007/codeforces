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
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; }};
Scanner sc(cin);

const int MOD = 1e9 + 7;
const int N = 305;
int n, m;

int nCr[N][N], fac[N], inv[N];
int dp[N][N];

void init() {
    scanf(II,&n,&m);
    nCr[0][0] = 1;
    fac[0] = 1;
    inv[0] = 1;
    repa (i,n) {
        nCr[i][0] = 1;
        inv[i] = (inv[i-1] * m) % MOD;
		fac[i] = fac[i-1] * (m-1) % MOD;
		repa (j,n) nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;
    }
}

void solve() {
    dp[0][0] = 1;
    repa (i,n) {
        repa (j,n) {
            dp[i][j] = dp[i-1][j] * fac[n-j] % MOD * (inv[j]-fac[j]+MOD) % MOD;
            rep (k,j) {
                (dp[i][j]+=dp[i-1][k]*nCr[n-k][j-k]%MOD * inv[k]%MOD * fac[n-j]%MOD) %= MOD;
            }
        }
    }
    printf(IN,dp[n][n]);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}