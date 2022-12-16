#include<stdio.h>
#include<algorithm>
#define P 1000000007
using namespace std;
int i,j,k,l,s,n,m,o,ans,p,C[105][105];
int f[3][105][105][105];
inline void jia(int &o,long long p) {
    o+=p; if (o>=P) o-=P;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    C[0][0]=1;
    n++;
    for (i=1;i<=n;i++) C[i][0]=1;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) {
        C[i][j]=C[i-1][j]+C[i-1][j-1];
        if (C[i][j]>k) C[i][j]=k+1;
    }
    /*for (i=1;i<=min(n,m);i++) */f[1][1][1][1]=1;
    for (i=1;i<=m;i++) {
        int gt=i%2;
        int gtw=gt^1;
    for (j=1;j<=n;j++)
    for (l=1;l<=n;l++)
    for (p=1;p<=k;p++) {
        if (!f[gt][j][l][p]) continue;
        for (o=1;o*2+l<=n;o++) 
        if (p*C[j+o-1][j-1]<=k) jia(f[gtw][o][o*2+l][p*C[j+o-1][j-1]],f[gt][j][l][p]);
        if (l>1) 
        jia(ans,1ll*(m-i+1)*f[gt][j][l][p]);
        f[gt][j][l][p]=0;
    }       
    }
/*  for (i=1;i<=m;i++) {
        int gt=i%2;
    for (j=1;j<=n;j++)
    for (l=1;l<=k;l++) 
    for (o=2;o<=n;o++) jia(ans,1ll*(m-i+1)*f[gt][j][o][l]);
    }*/
    printf("%d\n",ans);
}