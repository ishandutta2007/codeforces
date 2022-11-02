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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
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

const int N = 200005;
int n, m;
vector < int > e[N];
vector < int > re[N];
int t;
int s[N];

void init() {
    scanf(II,&n,&m);
    rep (i,m) {
        int a, b; scanf(II,&a,&b);
        e[b].push_back(a);
        re[a].push_back(b);
    } 
    scanf(I,&t);
    rep (i,t) scanf(I,&s[i]);
}

int S;
int d[N];

void dij() {
    memset(d, 0x3f, sizeof(d));
    S = s[t-1];
    d[S] = 0;
    queue < int > que;
    que.push ( S );
    while (!que.empty()) {
        int ui = que.front(); que.pop(); int ud = d[ui];
        repe (i,e[ui]) {
            int v = e[ui][i];
            if (checkMin(d[v], ud+1)) {
                que.push(v);
            }
        }
    }
}

void solve() {
    dij();
    int mna = 0, mxa = 0;
    rep (i,t-1) {
        int mn=0x3f3f3f3f, ms=0;
        int u = s[i];
        repe (j,re[u]) {
            int v=  re[u][j];
            if (mn == d[v]) ms++;
            if (mn >  d[v]) { mn = d[v]; ms=1; }
        }
        if (d[s[i+1]] > mn) {
            mna++; mxa++;
        }else {
            if (ms != 1) mxa++;
        }
    }
    printf("%d %d\n",mna,mxa);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}