#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000005],ans,P[1000005],i,j,k,p,l,s,n,m,S[1000005],f[5005][5005],ff[3][5005];
inline int in() {
    char c=getchar();
    int s=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-48,c=getchar();
    return s;
}
int main() {
    scanf("%d%d%d",&n,&m,&p);
    S[0]=1;
    for (i=1;i<=m;i++) S[i]=1ll*S[i-1]*i%p; 
    P[0]=1;
    for (i=m;i;i--) P[m-i+1]=1ll*P[m-i]*i%p;
    for (i=1;i<=n;i++) a[i]=in();
    f[0][0]=1;
    for (i=1;i<=5000;i++) for (j=1;j<=i;j++) f[i][j]=(f[i-1][j-1]+1ll*(j-1)*f[i-1][j]%p)%p;
    ff[0][0]=1;
    for (i=0;i<=n;i++) {
        int gt=i%2;
        int gtw=gt^1;
        int syf=min(a[i],m);
        for (j=1;j<=syf;j++) {
            ff[gt][j]=1ll*f[a[i]][j]*P[j]%p*ans%p;
            ff[gt][j]=(ff[gt][j]-(1ll*ff[gtw][j]*S[j]%p*f[a[i]][j]%p)+p)%p;
        }
        ans=0;
        int dxe=min(a[i-1],5000);
        for (j=0;j<=syf;j++) (ans+=ff[gt][j])%=p;
        for (j=0;j<=dxe;j++) ff[gtw][j]=0;
    }
    printf("%d\n",ans);
}