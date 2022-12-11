#include<bits/stdc++.h>
#define ll long long 
ll rd() {
    ll x=0,f=1;
    char ch=getchar();
    for(;ch!=EOF&&ch!='-'&&!(ch>='0'&&ch<='9');ch=getchar());
    if (ch=='-') ch=getchar(),f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
#define maxn 105
#define B 50
int T,n;
int a[maxn],b[maxn];
ll f[maxn];
bool vis[maxn];
ll yes[maxn];
ll g[2][maxn];
bool solve(int x) {
    ll res=0;
    for(int i=1;i<=n;i++) {
        ll v=g[i==x][i];
        if (res&v) return 0;
        res|=v;
    }
    for(int i=0;i<=B;i++) if (res==yes[i])
        return 1;
    return 0;
}
int main() {
    T=rd();
    f[0]=1,f[1]=1;
    for(int i=2;i<=B;i++) f[i]=f[i-1]+f[i-2];
    yes[0]=1;
    for(int i=1;i<=B;i++) yes[i]=yes[i-1]*2+1;
    // printf("%lld\n",f[B]);
    while(T--) {
        n=rd();
        for(int i=1;i<=n;i++) {
            a[i]=rd();
            g[0][i]=0,g[1][i]=1;
            int x=a[i];
            for(int j=B;j>=0;j--) if (x>=f[j]){
                x-=f[j],g[0][i]^=(1ll<<j);
                j--;
            }
            x=a[i];
            for(int j=B;j>=2;j--) if (x>f[j]){
                x-=f[j],g[1][i]^=(1ll<<j);
                j--;
            }
            if (x>1) {
                g[1][i]=-1;
            }
            // printf("%d %d\n",g[0][i],g[1][i]);
        }
        memset(vis,0,sizeof vis);
        if (solve(0)) {
            printf("YES\n");
            continue;
        }
        bool flag=0;
        for(int i=1;i<=n;i++) if (g[1][i]!=-1){
            if (solve(i)) {
                printf("YES\n");
                flag=1;
                break;
            }
        }
        if (!flag)
            printf("NO\n");
    }
}