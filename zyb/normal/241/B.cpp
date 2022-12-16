#include<stdio.h>
#include<algorithm>
#define N 50005
#define P 1000000007
using namespace std;
int i,j,k,l,s,n,m,a[N][35],c[N][35],si[N*25],tot;
int SS,x,L,ans,f[N*25][2],S[35];
int Si[N*25][35];
inline int quick(int o,int p) {
    int s=1;
    while (p) {
        if (p&1) s=1ll*s*o%P;
        o=1ll*o*o%P;
        p>>=1;
    }
    return s;
}
inline void build(int o) {
    int gt=1; 
    for (int i=L;i;i--) {
        si[gt]++;
        if (f[gt][a[o][i]]) gt=f[gt][a[o][i]];
        else f[gt][a[o][i]]=++tot,gt=tot;
        c[o][i]=gt;
        for (int j=i;j;j--) Si[gt][j]+=a[o][j];
    }
    si[gt]++;
}
inline int check(int p) {
    unsigned int ans=0;
    for (int i=1;i<=n;i++) {
        int PP=p,gt=1;
        for (int j=L;j;j--) {
            if (S[j]>=PP) {
                ans+=si[f[gt][a[i][j]^1]];
                gt=f[gt][a[i][j]];
            }
            else {
                PP-=S[j];
                gt=f[gt][a[i][j]^1];
            }
        }
    }
    return ans/2;
}       
inline int Work(int p) {
    int ans=0,Ans=0;
    for (int i=1;i<=n;i++) {
        int PP=p,gt=1,w=0;
        for (int j=L;j;j--) {
            if (S[j]>=PP) {
                for (int k=j;k;k--)
                if (!a[i][k])
                (ans+=1ll*Si[f[gt][a[i][j]^1]][k]*(S[k])%P)%=P;
                (Ans+=1ll*si[f[gt][a[i][j]^1]]*w%P)%=P;
                gt=f[gt][a[i][j]];
            }
            else {
                PP-=S[j];
                w+=S[j];
                gt=f[gt][a[i][j]^1];
            }
        }
    }
    return (ans+1ll*Ans*quick(2,P-2)%P)%P;
}       
int main() {
    scanf("%d%d",&n,&m);    
    tot=1;
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        s=0;
        while (x) a[i][++s]=x&1,x>>=1;
        L=max(L,s);
    }
    s=0;
    for (i=1;i<=L;i++) S[i]=1<<(i-1);
    for (i=1;i<=n;i++) build(i);
    int l=0,r=S[L]*2-1;
    while (l<=r) {
        int mid=(l+r)>>1;
        int gt=check(mid);
        if (gt>=m) s=mid,l=mid+1,SS=gt;
        else r=mid-1;
    }
    printf("%d\n",(Work(s)-1ll*(SS-m)*s%P+P)%P);
}