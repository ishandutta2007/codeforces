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

const int N = 400005;
const int C = 22;
vector < int > co[C];
int n;

void init() {
    n = sc.nextInt();
    rep (i,n) co[sc.nextInt() - 1].push_back(i-1);
}

int swp[C][C];

void Swp() {
    rep (i,C) rep (j,C) {
        if (i == j) continue;
        if (co[i].size() == 0 || co[j].size() == 0) continue;
        int p2 = 0;
        rep (p1,(int)co[i].size()) {
            while (p2 != (int)co[j].size() - 1 && co[j][p2+1] < co[i][p1]) p2++;
            if (co[i][p1] > co[j][p2]) swp[i][j] += p2 + 1;
        }
    }   
    //rep (i,20) { rep(j,20) printf("%3d",swp[i][j]); puts(""); }
}

int dp[1 << 20];

void solve() {
    Swp();
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    rep (b,(1<<20)-1) {
        vector < int > w;
        rep (i,20) if ((b>>i) & 1) w.push_back(i);
        rep (i,20) {
            if ((b>>i) & 1) continue;

            int pa = 0; rep (j,(int)w.size()) pa += swp[ w[j] ][i];
            if (pa != 0) see(pa);
            checkMin(dp[b | (1<<i)],dp[b] + pa);
        }
    }
    printf(IN,dp[(1<<20) - 1]);
}

#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}