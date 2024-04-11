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

const int N = 400005;
const int B = 22;

struct RMQ {
    int lg[N];
    int n;
    int pre[B][N], suf[B][N];

    void assign(int* a, int s) {
        n = s;
        lg[1] = 0;
        repi (i,2,n) lg[i] = lg[i >> 1] + 1;
        rep (i,n) pre[0][i] = suf[0][i] = a[i];
        rep (b, B-1) rep (i,n) {
            int l = (1<<b);
            if (i + l < n) pre[b+1][i] = max(pre[b][i], pre[b][i+l]);
            if (i - l >=0) suf[b+1][i] = max(suf[b][i], suf[b][i-l]);
        }
    }

    int query(int l, int r) {
        int len = r - l;
        return max(pre[ lg[len] ][l], suf[ lg[len] ][r-1]);
    }
};

struct Disc {
    vector < int > ele;

    void clear() { ele.clear(); }
    void insert(int u) { ele.push_back(u); }
    void set() { sort(ele.begin(), ele.end()); }
    int  query(int u) { return lower_bound(ele.begin(), ele.end(), u) - ele.begin(); }
};

vector < pr > shuf ( vector < pr > u ) {
    sort(u.begin(), u.end());
    vector < pr > res;
    repe (i,u) {
        while (res.size() && res.back().R <= u[i].R) res.pop_back();
        res.push_back( u[i] );
    }
    return res;
}

int n, m;
int monsters[N];
vector < pr > heroes;
int require[N];
Disc ova;
RMQ maxMonsters;

bool checkWinnable () {
    int hr=0, ms=0;
    rep (i,n) checkMax(ms, monsters[i]);
    repe(i,heroes) checkMax(hr, heroes[i].L);
    ses(hr);see(ms);
    if (hr >= ms) return 1;
    else return 0;
}

void setRequire () {
    int lass = 0;
    repe (i,heroes) {
        repi (j,lass,heroes[i].L) require[j] = i;
        lass = heroes[i].L+1;
    }
}

void buildRmq () {
    maxMonsters.assign(monsters, n);
}

void init() {
    heroes.clear();
    scanf(I,&n);
    rep (i,n) scanf(I,&monsters[i]);
    scanf(I,&m);
    rep (i,m) {
        int x, y; scanf(II,&x,&y);
        heroes.push_back( pr(x, y) );
    }
    heroes = shuf( heroes );
    ova.clear();
    rep (i,n) ova.insert(monsters[i]);
    repe(i,heroes) ova.insert(heroes[i].L); 
    ova.set();
    rep (i,n) monsters[i] = ova.query(monsters[i]);
    repe(i,heroes) heroes[i].L = ova.query( heroes[i].L );
    rep (i,n) see(monsters[i]);
    repe(i,heroes) { ses(heroes[i].L); see(heroes[i].R); }
    buildRmq();
}

bool juryBeatable(int l, int r) {
    int powerRequire = maxMonsters.query(l, r);
    see(powerRequire);
    see(require[powerRequire]);
    return heroes[ require[powerRequire] ].R >= r-l;
}

void solve() {
    if (!checkWinnable()) { puts("-1"); return; }
    setRequire() ;

    int s = 0;
    int ans = 0;
    while (s < n) {
        ans++;
        int l=s+1, r=n;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (juryBeatable(s, m)) l = m;
            else                r = m-1;
        }
        s = l;
    }
    printf(IN,ans);
}

#ifdef ENABLE_LL
#undef int
#endif
int main(){
    int T; scanf(I,&T);
    while (T--) {
        init();
        solve();
    }
    return 0;
}