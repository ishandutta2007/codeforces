#include<stdio.h>
#include<algorithm>
#define N 3000*3000*3
using namespace std;
int fa[N],ans,i,j,k,l,x,y,s,n,m,Q;
int a[3005][6005];
inline int get(int o) {
    if (fa[o]==o) return o;
    return fa[o]=get(fa[o]);
}
inline int Get(int x,int y) {
    return get((x-1)*2*m+y);
}
inline bool check(int x,int y,int xx,int yy) {
    for (int i=-1;i<=1;i++)
    for (int j=-1;j<=1;j++)
    for (int k=-1;k<=1;k++)
    for (int l=-1;l<=1;l++) {
        if (x+i>0&&xx+k>0)
        if (x+i<=n&&xx+k<=n) {
            int gt=y+j,gtw=yy+l;
            if (gt<=0) gt+=2*m;
            else if (gt>2*m) gt-=2*m;
            if (gtw<=0) gtw+=2*m;
            else if (gtw>2*m) gtw-=2*m;
            if (a[x+i][gt]&&a[xx+k][gtw])
            if (Get(x+i,gt)==Get(xx+k,gtw)) return false;
        }
    }
    return true;
}
inline void work(int x,int y) {
    for (int i=-1;i<=1;i++)
    for (int j=-1;j<=1;j++)
    if (x+i>0&&x+i<=n) {
        int gt=y+j;
        if (gt<=0) gt+=2*m;
        else if (gt>2*m) gt-=2*m;
    if (a[x+i][gt]) fa[Get(x+i,gt)]=fa[Get(x,y)];
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&Q);
    for (i=1;i<=n;i++) for (j=1;j<=2*m;j++) fa[(i-1)*2*m+j]=(i-1)*2*m+j;
    for (i=1;i<=Q;i++) {
        scanf("%d%d",&x,&y);
        a[x][y]=a[x][y+m]=1;
        if (!check(x,y,x,y+m)) {
            a[x][y]=a[x][y+m]=0;
            continue;
        }
        ans++;
        work(x,y); work(x,y+m);
    
    }
    printf("%d\n",ans);
}