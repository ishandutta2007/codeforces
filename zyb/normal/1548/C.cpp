#include<bits/stdc++.h>
#define N 3000005
using namespace std;
#define P 1000000007
int n,a[N],b[N],ans,m;
long long f[N][3],jc[N],ny[N];
inline long long calc(int x,int y) {
    return 1ll*jc[x]*ny[y]%P*ny[x-y]%P;
}
inline long long quick(int x,int y) {
    long long s=1;
    for (;y;y>>=1) {
        if (y&1) s=1ll*s*x%P;
        x=1ll*x*x%P;
    }
    return s;
}
int main() {
    jc[0]=1;
    for (int i=1;i<N;i++) jc[i]=1ll*jc[i-1]*i%P;
    ny[N-1]=quick(jc[N-1],P-2);
    for (int i=N-2;i>=0;i--) ny[i]=1ll*ny[i+1]*(i+1)%P;
    scanf("%d%d",&n,&m);
    f[0][0]=f[0][1]=n;
    f[0][2]=n+1;
    for (int i=1;i<=3*n;i++) {
        long long x=calc(3*n+1,i+1);
        x-=2*f[i-1][0];
        x-=f[i-1][1];
        x%=P;
        f[i][0]=2*x%P*ny[3]%P;
        f[i][1]=(f[i][0]+f[i-1][0])%P;
        f[i][2]=(f[i][1]+f[i-1][1])%P;
    }
    for (int i=1;i<=m;i++) {
        int x;
        scanf("%d",&x);
        printf("%lld\n", (f[x][2]+P)%P);
    }
            
}