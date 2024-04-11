#include<stdio.h>
#define N 1000005
#include<cstring>
using namespace std;
int i,j,k,s,L,n,m,l[N],S[N],T[N],f[N][35],ans,ans1,st[N],LL;
char c[N*10],cc[N*100];
int main() {
    scanf("%d%d%d",&n,&m,&L);
    for (i=1;i<=n;i++) {
        scanf("%s",c);
        l[i]=strlen(c);
        st[i]=LL;
        for (j=0;j<l[i];j++) cc[LL++]=c[j];
        S[i]=S[i-1]+l[i]+1;
    }
    st[n+1]=LL;
    for (i=1;i<=n;i++) {
        int l=i,r=n,s=i-1;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (S[mid]-S[i-1]-1<=L) s=mid,l=mid+1;
            else r=mid-1;
        }
        T[i]=s+1;
    }
    T[n+1]=n+1;
    for (i=1;i<=n+1;i++) f[i][0]=T[i];
    for (i=1,j=1;j<=n;j*=2,i++) 
    for (k=1;k<=n+1;k++) f[k][i]=f[f[k][i-1]][i-1];
    for (i=1;i<=n;i++) {
        int p=m; j=0; s=i;
        while (p) {
            if (p&1) s=f[s][j];
            p>>=1; j++;
        }
        if (s-i>ans) ans=s-i,ans1=i;
    }
    int j=ans1;
    for (i=1;i<=m;i++) {
        for (k=j;k<T[j];k++) {
            for (int o=0;o<l[k];o++) printf("%c",cc[st[k]+o]);
            if (k!=T[j]-1)
            putchar(' ');
        }
        puts("");
        j=T[j];
    }
}