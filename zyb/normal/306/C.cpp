#include<stdio.h>
#include<algorithm>
#define N 4005
#define P 1000000009
using namespace std;
int jc[N],ny[N],ans,i,n,m,b;
inline int C(int o,int p) {
    if (o>p) return 0;
    return 1ll*jc[p]*ny[o]%P*ny[p-o]%P;
}
inline int quick(int o,int p) {
    int s=1;
    while (p) {
        if (p&1) s=1ll*s*o%P;
        o=1ll*o*o%P;
        p>>=1;
    }
    return s;
}
int main() {
    scanf("%d%d%d",&n,&m,&b);
    jc[0]=1; ny[0]=quick(1,P-2);
    int pp=max(m,b);
    for (i=1;i<=pp;i++) jc[i]=1ll*jc[i-1]*i%P,ny[i]=quick(jc[i],P-2);
    for (i=2;i<=n;i++) 
    ans=(ans+1ll*C(i-1,m-1)*C(n-i-1,b-1)%P*(i-1))%P;
    ans=1ll*ans*jc[m]%P*jc[b]%P;
    printf("%d\n",ans);
}