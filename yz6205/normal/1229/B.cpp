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
const int N = 100005;
int a[N];
vector < int > e[N];
int n;

struct List {
    int i, n;
    List () {}
    List (int i,int n) : i(i), n(n) {}
};

void init() {
    scanf(I,&n);
    repa (i,n) scanf(I,&a[i]);
    rep (i,n-1) {
        int u, v; scanf(II,&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    } 
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int dfs(int u, int f, vector < List > l) {
    l.push_back( List(a[u], 1) );
    foreach (i,l) l[i].i = gcd(a[u], l[i].i);
    vector < List > vl;
    foreach (i,l) {
        if (i && vl[(int)vl.size()-1].i == l[i].i) vl[(int)vl.size()-1].n += l[i].n;
        else vl.push_back( l[i] );
    }
    int ans = 0;
    foreach (i,vl) ( ans += vl[i].i * vl[i].n ) %= MOD;
    foreach (i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        (ans += dfs(v,u,vl)) %= MOD;
    }
    ses(u);see(ans);
    return ans;
}

void solve() {
    vector < List > Nu;
    printf(IN,dfs(1,0, Nu));
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}