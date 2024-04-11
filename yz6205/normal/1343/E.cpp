#define ENABLE_LL
#define MULTIPLE_TEST_CASES_WITH_T
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
typedef pair < int , int > pr; typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;} }; Scanner sc(cin);
#define ALERT(judgememt, phrase) if (judgememt) { puts(phrase); throw "ALERT"; }
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts("phrase"); return judgememt; }

const int N = 200005;
int n, m, a, b, c;
vector < int > w;
vector < int > e[N];

void init() {
    scanf(II,&n,&m);
    scanf(III,&a,&b,&c);
    w.clear();
    rep (i,m) w.push_back( sc.nextInt() );
    rep (i,N) e[i].clear();
    rep (i,m) {
        int u, v; scanf(II,&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sort(w.begin() , w.end());
}

int dis[N];
vector < int > Path (int u) {
    repa (i,n) dis[i] = 0x3f3f3f3f; 
    dis[u] = 0;
    queue < int > que;
    que.push(u);
    while (!que.empty()) {
        int u=que.front(); que.pop();
        repe (i, e[u]) {
            int v = e[u][i];
            if (dis[v] != 0x3f3f3f3f) continue;
            dis[v] = dis[u] + 1;
            que.push(v);    
        }
    }
    vector < int > res(n+1,0);
    repa (i,n) res[i] = dis[i];
    return res;
}

void solve() {
    vector < int > fa = Path(a);
    vector < int > fb = Path(b);
    vector < int > fc = Path(c);
    vector < int > prefix(1,0);
    rep (i,m) prefix.push_back(prefix.back() + w[i]);
    int ans = 0x3f3f3f3f3f3f3f3f;
    repa (i,n) {
        int da = fa[i];
        int db = fb[i];
        int dc = fc[i];
        ses(i);ses(da);ses(db);see(dc);
        if (da + db + dc > m) continue;
        checkMin(ans, prefix[db] + prefix[da+db+dc]);
    }
    printf(IN,ans);
}

#ifdef ENABLE_LL
#undef int
#endif
int main(){
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
    return 0;
}