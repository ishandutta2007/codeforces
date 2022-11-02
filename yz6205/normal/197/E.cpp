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

#define int long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 

struct Point {
    int x,y,org;
};

int sx,sy;

bool cmp (Point A,Point B) {
    A.x -= sx;
    A.y -= sy;
    B.x -= sx;
    B.y -= sy;
    return (A.y * B.x) < (A.x * B.y);
}

istream& operator >> (istream& in , Point& X) {
    in >> X.x >> X.y;
    return in;
}

const int N = 3005;
vector < int > e[N];
int size[N];
int ans[N];
Point pt[N];
int n;

void init(){
    scanf("%lld",&n);
    rep (i , n - 1) {
        int u,v;
        scanf("%lld%lld",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    repa (i,n) {
        cin >> pt[i];
        pt[i].org = i;
    }
}

void Size(int u = 1,int f = 0){ 
    size[u] = 1;
    foreach (i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        Size(v,u);
        size[u] += size[v];
    }
}

void solve(int l = 1 , int r = n , int u = 1,int f = 0) {
    //cout << l << ' ' << r << ' ' << u << ' ' << f << endl;
    repi (i,l + 1 , r) if (pt[i].x < pt[l].x) swap(pt[l] , pt[i]);
    sx = pt[l].x;
    sy = pt[l].y;
    sort(pt + l + 1, pt + r + 1,cmp);
    //repi (i,l , r) {
    //    cout << pt[i].x << ' '<< pt[i].y << ' ' << pt[i].org << endl;
    //}
    ans[ pt[l].org ] = u;
    int fs = l + 1;
    foreach (i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        solve(fs , fs + size[v] - 1 , v , u);
        fs += size[v];
    }
}

#undef int
int main(){
    init();
    Size(); 
    solve();
    repa (i,n) printf("%lld ",ans[i]);
    puts("");
    return 0;
}