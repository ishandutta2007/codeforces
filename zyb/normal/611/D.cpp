#include<stdio.h>
#define N 5005
#define P 1000000007
using namespace std;
int n,i,j,k,l,s,ans,a[N],f[N][N],b[N][N];
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        char c=getchar();
        while (c<'0'||c>'9') c=getchar();
        a[i]=c-48;
    }
    for (i=n;i;i--) for (j=n;j;j--) 
    if (a[i]!=a[j]) f[i][j]=0;
    else f[i][j]=f[i+1][j+1]+1;
    b[0][0]=1;
    for (i=1;i<=n;i++)
    for (j=1;j<=i;j++) {
        (b[i][j]+=b[i-1][j-1])%=P;
        if (i+j>n||!a[i+1]||!a[i-j+1]) continue;
        int gt=f[i-j+1][i+1];
        if (a[i-j+1+gt]<a[i+1+gt]&&gt<j) (b[i+j][j]+=b[i][j])%=P;
        else (b[i+j+1][j+1]+=b[i][j])%=P;
    }
    for (i=1;i<=n;i++) (ans+=b[n][i])%=P;
    printf("%d\n",ans);
}