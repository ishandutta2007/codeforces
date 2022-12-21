#include<bits/stdc++.h>
#define N 200005
#define P 31607
using namespace std;

int n,ans,a[25][25],b[25][25];
int f[N],d[N];
inline int quick(int x,int y) {
    int s=1;
    for (;y;y>>=1) {
        if (y&1) s=1ll*s*x%P;
        x=1ll*x*x%P;
    }
    return s;
}
inline int inv(int x) {
    if (!x) return 1;
    if (!d[x]) {
        d[x]=quick(x,P-2);
    }
    return d[x];
}
inline void work(int x,int y) {
    if (x==n) {
        int w=1;
        for (int i=0;i<n;i++) (w*=(P+1-f[i]))%=P;
        (ans+=w*y%P)%=P;
        return;
    }
    for (int i=0;i<n;i++) (f[i]*=b[x][i])%=P;
    work(x+1,y);
    for (int i=0;i<n;i++) {
        (f[i]*=inv(b[x][i]))%=P;
        (y*=b[x][i])%=P;
    }
    work(x+1,P-y);
}
inline int solve() {
    ans=0;
    for (int i=0;i<n;i++) f[i]=1;
    work(0,1);
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) {
        if (b[i][j]==1) (ans*=a[i][j])%=P;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) {
        scanf("%d",&a[i][j]);
        (a[i][j]*=inv(10000))%=P;
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) b[i][j]=a[i][j];
    int ans=0;
    ans+=solve();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) b[i][j]=a[i][j];
        b[i][i]=1;
    }
    ans-=solve();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) b[i][j]=a[i][j];
        b[i][n-1-i]=1;
    }
    ans-=solve();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) b[i][j]=a[i][j];
        b[i][n-1-i]=1;
        b[i][i]=1;
    }
    ans+=solve();
    ans%=P;
    printf("%d\n",(P+1-ans)%P);
}