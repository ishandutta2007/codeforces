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

const int N = 2000005;
vector < string > mp;
vector < vector<int> > vis;
int n, m;

void init() {
    scanf(II,&n,&m);
    rep (i,n) mp.push_back( sc.next() );
}

vector < vector<int> > vab;
void pre0() {
    rep (i,n) vab.push_back( vector<int>(m,0) );
    vab[n-1][m-1] = 1;
    repb (l,n+m-3,0) {
        repi (i,max(0,l-m+1),min(l,n-1)) { ses(i);see(l-i);if (mp[i][l-i] != '#') vab[i][l-i] = ((i+1<n)?vab[i+1][l-i]:0) || ((l-i+1<m)?vab[i][l-i+1]:0);}
    }
}

const int Move[2][2] = {{1,0},{0,1}};
int dis[N];
void solve() {
    pre0();
    rep (i,n) vis.push_back( vector<int>(m,0) );
    queue < prr > que;
    que.push( prr( pr(0,0), 0) );
    while (!que.empty()) {
        prr pos = que.front(); que.pop();
        int ux = pos.L.L, uy = pos.L.R;
        int di = pos.R;
        dis[di]++;
        rep (d,2) {
            int vx = ux + Move[d][0];
            int vy = uy + Move[d][1];
            ses(vx);see(vy);
            if (vx >= n || vy >= m) continue;
            if (!vab[vx][vy]) continue;
            if (mp[vx][vy] == '#') continue;
            if (vis[vx][vy]) continue;
            vis[vx][vy] = 1;
            que.push( prr( pr(vx,vy), di+1 ) );
        }
    }
    int ans = n;
    repa (i,n+m-3) checkMin(ans, dis[i]); 
    printf(IN,ans);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}