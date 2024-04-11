#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;

    point(int xx = 0,int yy = 0):x(xx),y(yy){}
};

const int N = 2005;
const int M = N * N;
int n,m;
char mp[N][N];
point que[M * 2];
int ux[M * 2];
int uy[M * 2];
int vis[N][N];

inline void push(int idx,point pt,int x,int y){
    que[idx] = pt;
    ux[idx] = x;
    uy[idx] = y;
    vis[pt.x][pt.y] = 1;
}

inline bool canGo(int x,int y){
    return ((mp[x][y] == '.') && ((x >= 1) && (x <= n)) && ((y >= 1) && (y <= m)) && !vis[x][y]);
}

int main(){
    int x,y,u,v;
    cin >> n >> m >> u >> v >> x >> y;
    for (int i=1;i<=n;i++){
        scanf("%s",mp[i] + 1);
    }
    int front = M,back = M;
    push(back++,point(u,v),x,y);
    int ans = 1;
    while (front < back){
        int idx = front;
        point foo = que[front++];
        int nx = foo.x,ny = foo.y;
        int gx,gy;
        //cout << nx << ' ' << ny << endl;
        //upp
        gx = nx - 1;gy = ny;
        if (canGo(gx,gy)){
            push(--front,point(gx,gy),ux[idx],uy[idx]);
            ans++;
        }
        //down
        gx = nx + 1;gy = ny;
        if (canGo(gx,gy)){
            push(--front,point(gx,gy),ux[idx],uy[idx]);
            ans++;
        }
        //left
        gx = nx;gy = ny - 1;
        if (canGo(gx,gy) && ux[idx]){
            push(back++,point(gx,gy),ux[idx] - 1,uy[idx]);
            ans++;
        }
        //right
        gx = nx;gy = ny + 1;
        if (canGo(gx,gy) && uy[idx]){
            push(back++,point(gx,gy),ux[idx],uy[idx] - 1);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}