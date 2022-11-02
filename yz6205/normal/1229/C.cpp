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

const int N = 100005;
struct Ver {
    int l, h;
};

Ver v[N];
vector < int > e[N];
vector < int > eg[N];
vector < int > eup[N];
bool gr[N];
int vp[N]; 
int n, m;

void pg() {
    int gl = (int)sqrt(n);
    repa (i,n) gr[i] = (int)e[i].size() > gl;
    repa (i,n) {
        foreach (j,e[i]) {
            int u = e[i][j];
            if (gr[u]) eg[i].push_back(u);
        }
    }
}

int ans;

void init() {
    scanf(II,&n,&m);
    rep (i,m) {
        int u, v; scanf(II,&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    } 
    pg();
    repa (i,n) {
        vp[i] = i;
    }
    repa (i,n) {
        foreach (j,e[i]) {
            int _v = e[i][j];
            if (vp[_v] < vp[i]) v[i].l++;
            else v[i].h++;
        }
    }
    repa (i,n) ans += v[i].l * v[i].h;
    repa (i,n) eup[i] = e[i];
}

inline void up0(int u) {
    ans -= v[u].l * v[u].h;
    v[u].l += v[u].h;
    v[u].h = 0;
}

inline void up1(int u) {
    ans -= v[u].l * v[u].h;
    v[u].l--; v[u].h++;
    ans += v[u].l * v[u].h;    
}

void solve() {
    printf(IN,ans);
    int q; scanf(I,&q);
    repa (_,q) {
        int u; scanf(I,&u);
        if (gr[u]) {
            sort (eup[u].begin(), eup[u].end());
            eup[u].erase( unique(eup[u].begin(), eup[u].end()), eup[u].end() );
            foreach(i,eup[u]) {
                int v = eup[u][i];
                if (vp[v] > vp[u]) up1(v);
            }
            up0(u);
            vp[u] = n + _;
            eup[u].resize(0);
        } else {
            foreach (i,e[u]) {
                int v = e[u][i];
                if (vp[v] > vp[u]) up1(v);
            } 
            up0(u);
            vp[u] = n + _;
        }

        foreach (i,eg[u]) {
            int v = eg[u][i];
            eup[v].push_back(u);
        }
        
        printf(IN,ans);
    }
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}