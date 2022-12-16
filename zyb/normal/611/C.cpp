#include<stdio.h>
#define N 505
using namespace std;
int Q,i,j,k,l,s,n,m,x,y,xx,yy,b[N][N],c[N][N],a[N][N];
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) {
        char C=getchar();
        while (C!='#'&&C!='.') C=getchar();
        if (C=='.') a[i][j]=1;
        if (a[i][j]&&a[i][j-1]) b[i][j]=1;
        if (a[i][j]&&a[i-1][j]) c[i][j]=1;
        b[i][j]+=(b[i-1][j]+b[i][j-1]-b[i-1][j-1]);
        c[i][j]+=(c[i-1][j]+c[i][j-1]-c[i-1][j-1]);
    }
    scanf("%d",&Q);
    for (i=1;i<=Q;i++) {
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        y++;
        int gt=b[xx][yy]-b[xx][y-1]-b[x-1][yy]+b[x-1][y-1];
        y--; x++;
        gt+=c[xx][yy]-c[xx][y-1]-c[x-1][yy]+c[x-1][y-1];
        printf("%d\n",gt);
    }
}