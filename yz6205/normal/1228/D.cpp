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

const int N = 100005;
vector < int >  e[N];
int n, m;

void init() {
    scanf(II,&n,&m);
    rep (i,m) {
        int u, v; scanf(II,&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    } 
}

vector < vector < int > > kd;
vector < vector < int > > kds;

bool judge(vector < int > a, vector < int > b) {
    return (int)a.size() + (int)b.size() == n;
}

bool cmp(vector < int >& a,vector < int >& b) {
    if (a.size() != b.size()) return 0;
    foreach (i,a) if (a[i] != b[i]) return 0;
    return 1;
}

int ans[N];
void solve() {
    repa (i,n) sort(e[i].begin(), e[i].end());
    repa (i,n) {
        foreach (j,kd) {
            if (cmp(kd[j], e[i])) { kds[j].push_back(i); goto nxt; }
        }
        kd.push_back(e[i]); kds.push_back( vector < int > (1,i) );
        ses(i);see(kd.size());
        if ((int)kd.size() > 3) { puts("-1"); return; }
nxt:;
    }
    see("ps0");
    if (kd.size() != 3) { puts("-1"); return; }
    see("ps1");
    rep (i,3) if (!judge(kd[i],kds[i])) { puts("-1"); return; }
    rep (i,3) foreach(j,kds[i]) ans[kds[i][j]] = i + 1;
    repa (i,n) printf("%d ",ans[i]);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}