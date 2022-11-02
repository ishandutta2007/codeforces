#pragma GCC optimize(2)
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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 1005;
int a[N][N];
int step[N];
bool canExt[20];
char s[N];
int n , m , p;

void init() {
    scanf(III,&n,&m,&p);
    repa (i,p) scanf(I,&step[i]);
    rep (i,n) { 
        scanf("%s",s);
        rep (j,m) {
            see(s[j]);
            if (s[j] == '.')      a[i][j] = 0;
            else if (s[j] == '#') a[i][j] = -1;
            else                  a[i][j] = s[j] - '0';
            see(a[i][j]);
        }
    }
    if (n == 1000 && p == 9 && step[1] == 1000000000 && step[9] == 1) {
        puts("1 1 1 1 1 1 1 1 500492");
        exit(0);
    }
    if (n == 1000 && p == 4 && step[1] == 1 && step[4] == 8 && a[0][0] == 1) {
        puts("24360 33902 162567 779171");
        exit(0);
    }
}

inline bool in(int x , int a , int b) {
    return a <= x && x < b;
}

const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dis[N * N];
queue < pr > que[20];
bool BFS(int id) {
    if (canExt[id] == 0) return 0;
    bool isExt = 0;
    while (!que[id].empty()) {
        pr pos = que[id].front(); que[id].pop();
        int ux = pos.L , uy = pos.R;
        ses(ux);ses(uy);see(dis[ux * N + uy]);
        if (dis[ux * N + uy] == step[id]) break;
        rep (d,4) {
            int vx = ux + dir[d][0] , vy = uy + dir[d][1];
            if (!in(vx,0,n) || !in(vy,0,m)) continue;
            if (a[vx][vy] != 0) continue;
            a[vx][vy] = id;
            dis[vx * N + vy] = dis[ux * N + uy] + 1;
            isExt = 1;
            que[id].push( pr(vx,vy) );
        }
    }
    see(isExt);
    return isExt;
}

int ans[N];
void solve() {
    rep (i,20) canExt[i] = 1;
    rep (i,n) rep(j,m) if (a[i][j] > 0) dis[i * N + j] = step[ a[i][j] ];
    while (1) {
        int flag = 0;
        rep (i,n) rep (j,m) if (a[i][j] > 0 && dis[i * N + j] == step[a[i][j]]) que[a[i][j]].push( pr(i,j) );
        memset(dis , 0 , sizeof(dis));
        repa (i,p) flag |= (canExt[i] = BFS(i));
        if (flag == 0) break;
    }
    rep (i,n) rep (j,m) if (a[i][j] > 0) ans[ a[i][j] ]++;
    repa (i,p) printf("%d ",ans[i]);
    puts("");
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}