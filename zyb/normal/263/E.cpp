#include<stdio.h>
#include<algorithm>
#define N 1005
using namespace std;
int i,j,l,s,n,m,ansx,ansy;
long long ans,k,A1[N][N],A2[N][N],A3[N][N],HE[N][N],SH[N][N],D[N][N],U[N][N],d[N][N],u[N][N],A4[N][N],S1[N][N],a[N][N],L[N][N],he[N][N],sh[N][N],R[N][N],S2[N][N],S3[N][N],S4[N][N];
inline int in() {
    char c=getchar();
    int s=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-48,c=getchar();
    return s;
}
int main() {
    scanf("%d%d%I64d",&n,&m,&k);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) a[i][j]=in();
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) he[i][j]=he[i][j-1]+a[i][j],sh[i][j]=sh[i-1][j]+a[i][j],R[i][j]=R[i-1][j+1]+a[i][j],L[i][j]=L[i-1][j-1]+a[i][j];
    for (i=1;i<=k;i++)
    for (j=1;j<=k;j++) S1[k][k]+=(a[i][j]*((abs(i-k)+abs(j-k))<k));
    for (i=k;i<=n;i++)
    for (j=1;j<=k;j++) S2[k][k]+=(a[i][j]*((abs(i-k)+abs(j-k))<k));
    for (i=1;i<=k;i++)
    for (j=k;j<=m;j++) S3[k][k]+=(a[i][j]*((abs(i-k)+abs(j-k))<k));
    for (i=k;i<=n;i++)
    for (j=k;j<=m;j++) S4[k][k]+=(a[i][j]*((abs(i-k)+abs(j-k))<k));
    for (i=k;i<=n-k+1;i++) for (j=k;j<=m-k+1;j++) {
        if (i==k&&j==k) continue;
        if (j>k)
        S1[i][j]=S1[i][j-1]+sh[i][j]-sh[i-k][j]-(R[i][j-k]-R[i-k][j]);
        else S1[i][j]=S1[i-1][j]+he[i][j]-he[i][j-k]-(R[i-1][j-k+1]-R[i-k-1][j+1]);
        if (j>k)
        S2[i][j]=S2[i][j-1]+sh[i+k-1][j]-sh[i-1][j]-(L[i+k-1][j-1]-L[i-1][j-k-1]);
        else S2[i][j]=S2[i-1][j]-(he[i-1][j]-he[i-1][j-k])+L[i+k-1][j]-L[i-1][j-k];     
        if (j>k)
        S3[i][j]=S3[i][j-1]+L[i][j+k-1]-L[i-k][j-1]-(sh[i][j-1]-sh[i-k][j-1]);
        else S3[i][j]=S3[i-1][j]+he[i][j+k-1]-he[i][j-1]-(L[i-1][j+k-1]-L[i-k-1][j-1]);
        if (j>k)
        S4[i][j]=S4[i][j-1]-(sh[i+k-1][j-1]-sh[i-1][j-1])+R[i+k-1][j]-R[i-1][j+k];
        else S4[i][j]=S4[i-1][j]-(he[i-1][j+k-1]-he[i-1][j-1])+R[i+k-1][j]-R[i-1][j+k];
    }
    ans=-1;
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) HE[i][j]=HE[i][j-1]+he[i][j-1]+a[i][j],SH[i][j]=SH[i-1][j]+sh[i-1][j]+a[i][j];
    for (i=n;i;i--) for (j=m;j;j--) u[i][j]=u[i+1][j]+a[i][j],d[i][j]=d[i][j+1]+a[i][j];
    for (i=n;i;i--) for (j=m;j;j--) U[i][j]=U[i+1][j]+u[i][j],D[i][j]=D[i][j+1]+d[i][j];
    for (i=1;i<=k;i++) 
    for (j=1;j<=k;j++) A1[k][k]+=(a[i][j]*(max(k-(abs(i-k)+abs(j-k)),0ll)));
    for (i=k;i<=n;i++)
    for (j=1;j<=k;j++) A2[k][k]+=(a[i][j]*(max(k-(abs(i-k)+abs(j-k)),0ll)));
    for (i=1;i<=k;i++)
    for (j=k;j<=m;j++) A3[k][k]+=(a[i][j]*(max(k-(abs(i-k)+abs(j-k)),0ll)));
    for (i=k;i<=n;i++)
    for (j=k;j<=m;j++) A4[k][k]+=(a[i][j]*(max(k-(abs(i-k)+abs(j-k)),0ll)));
    for (i=k;i<=n-k+1;i++) for (j=k;j<=m-k+1;j++) {
        if (i==k&&j==k) continue;
        if (j>k) 
        A1[i][j]=A1[i][j-1]-S1[i][j-1]+U[i-k+1][j]-U[i+1][j]-u[i+1][j]*k;
        else A1[i][j]=A1[i-1][j]-S1[i-1][j]+D[i][j-k+1]-D[i][j+1]-d[i][j+1]*k;
        if (j>k) 
        A2[i][j]=A2[i][j-1]-S2[i][j-1]+SH[i+k-1][j]-SH[i-1][j]-sh[i-1][j]*k;
        else A2[i][j]=A2[i-1][j]+S2[i][j]-(D[i-1][j-k+1]-D[i-1][j+1]-d[i-1][j+1]*k);
        if (j>k) 
        A3[i][j]=A3[i][j-1]+S3[i][j]-(U[i-k+1][j-1]-U[i+1][j-1]-u[i+1][j-1]*k);
        else A3[i][j]=A3[i-1][j]-S3[i-1][j]+HE[i][j+k-1]-HE[i][j-1]-(he[i][j-1]*k);
        if (j>k) 
        A4[i][j]=A4[i][j-1]+S4[i][j]-(SH[i+k-1][j-1]-SH[i-1][j-1]-sh[i-1][j-1]*k);
        else A4[i][j]=A4[i-1][j]+S4[i][j]-(HE[i-1][j+k-1]-HE[i-1][j-1]-he[i-1][j-1]*k);
    }
    for (i=k;i<=n-k+1;i++) for (j=k;j<=m-k+1;j++) {
        long long gt=A1[i][j]+A2[i][j]+A3[i][j]+A4[i][j]-(HE[i][j+k-1]-HE[i][j-1]-he[i][j-1]*k)-(D[i][j-k+1]-D[i][j+1]-d[i][j+1]*k)-(SH[i+k-1][j]-SH[i-1][j]-sh[i-1][j]*k)-(U[i-k+1][j]-U[i+1][j]-u[i+1][j]*k)+a[i][j]*k;   
        if (gt>ans) ans=gt,ansx=i,ansy=j;
    }
    printf("%d %d\n",ansx,ansy);
}