#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define lowbit(x) x&-x
int n,m,ans,f[N],F[N],P[5],a[N],b[N];
inline int get(int x,int y) {
    if (x>n||y>m) return 0;
    if (x<=0||y<=0) return 0;
    return (x-1)*m+y;
}

int main() {
    P[1]=1000000007;
    P[2]=998244353;
    P[3]=1000000009;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) {
        char c=getchar();
        while (c!='.'&&c!='#') c=getchar();
        if (c=='.')
        a[get(i,j)]=0;
        else
        a[get(i,j)]=1;
    }
    int flag=0;
    for (int _i=1;_i<=3;_i++) {
        memset(f,0,sizeof(f));
        memset(F,0,sizeof(F));
        f[1]=1;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            int x=get(i,j);
            if (a[x]) continue;
            if (!f[x]) continue;
            int y=get(i+1,j);
            if (y&&!a[y]) (f[y]+=f[x])%=P[_i];
            y=get(i,j+1);
            if (y&&!a[y]) (f[y]+=f[x])%=P[_i];
        }
        if (f[n*m]) flag=1;
        F[n*m]=1;
        for (int i=n;i;i--)
        for (int j=m;j;j--) {
            int x=get(i,j);
            if (a[x]) continue;
            if (!f[x]) continue;
            int y=get(i-1,j);
            if (y&&!a[y]) (F[y]+=F[x])%=P[_i];
            y=get(i,j-1);
            if (y&&!a[y]) (F[y]+=F[x])%=P[_i];
        }
        for (int i=n;i;i--)
        for (int j=m;j;j--) {
            int x=get(i,j);
            if (x==1||x==n*m) continue;
            if (a[x]) continue;
            if (1ll*f[x]*F[x]%P[_i]==1ll*f[n*m]) b[x]++;
        }
    }
    if (!flag) return puts("0"),0;
    for (int i=n;i;i--)
    for (int j=m;j;j--) {
        int x=get(i,j);
        if (b[x]==3) return puts("1"),0;
    }
    puts("2");
}