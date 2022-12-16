#include<stdio.h>
using namespace std;
double f[1005][1005],ans;
int i,x,y,j,k,l,s,n,m,a[1005];
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) f[i][j]=(a[i]>a[j]);
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        for (j=1;j<=n;j++) {
            if (j==x||j==y) continue;
            f[x][j]=f[y][j]=(f[x][j]+f[y][j])*0.5;
            f[j][x]=f[j][y]=(f[j][x]+f[j][y])*0.5;
        }
        f[x][y]=0.5;
        f[y][x]=0.5;
    }
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (i<j) ans+=f[i][j];
    printf("%.10lf\n",ans);
}