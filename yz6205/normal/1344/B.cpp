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
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;}};
Scanner sc(cin);
bool alert(bool _judgement, const char* error) { if (_judgement) printf("%s",error); return _judgement; }

const int N = 1005;
bool matrix[N][N];
int n, m;

void init() {
    scanf("%d%d",&n,&m);
    repa (i,n) repa (j,m) matrix[i][j] = (sc.nextChar()=='#' ? 1 : 0);; 
}

int bars_row[N], bars_column[N];

void genBars() {
    repa (i,n) repa (j,m) if (matrix[i][j-1] == 0 && matrix[i][j] == 1) bars_row[i]++;
    repa (i,m) repa (j,n) if (matrix[j-1][i] == 0 && matrix[j][i] == 1) ++bars_column[i]; 
}

bool judge0() {
    repa (i,n) if (alert(bars_row[i] > 1, "-1\n")) return 1;
    repa (i,m) if (alert(bars_column[i] > 1, "-1\n")) return 1;
    return 0;
}

bool judge1() {
    bool isEmptyRow=0, isFullColumn=1;
    bool isEmptyColumn=0, isFullRow=1;
    repa (i,n) if (!bars_row[i]) isEmptyRow=1;
    repa (i,n) if (!bars_row[i]) isFullRow=0;
    repa (i,m) if (!bars_column[i]) isEmptyColumn=1;
    repa (i,m) if (!bars_column[i]) isFullColumn=0;
    ses(isEmptyRow);ses(isEmptyColumn);ses(isFullRow);see(isFullColumn);
    return alert((isEmptyRow==1&&isFullColumn==1) || (isEmptyColumn==1&&isFullRow==1), "-1\n");
}

struct DisjointSet {
    int p[N*N];

    DisjointSet () {
        rep (i,N*N) p[i] = i;
    } 

    int get(int u) {
        return u==p[u] ? u : (p[u] = get(p[ p[u] ]));
    }

    void merge(int u, int v) {
        p[get(u)] = get(v);
    }
} isUnion;

inline int codePair(int u, int v) {
    return u*N+v;
}

int getIndependence() {
    repa (i,n) repa (j,m) if (matrix[i][j]==1) {
       if (matrix[i-1][j] == 1) isUnion.merge(codePair(i-1,j), codePair(i,j));
       if (matrix[i][j-1] == 1) isUnion.merge(codePair(i,j-1), codePair(i,j));
    }
    set < int > count;
    repa (i,n) repa (j,m) if (matrix[i][j]==1) {
        count.insert( isUnion.get( codePair(i,j) ) );
    }
    return count.size();
}

void solve() {
    genBars(); 
    if (judge0()) return;
    if (judge1()) return;
    printf("%d\n",getIndependence()); 
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}