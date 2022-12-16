#include<stdio.h>
#define P 1000000007
using namespace std;
int a[1005][1005],v[15],Q[10005][15],b[10005],i,j,k,l,s,n,m,x;
long long ans;
inline void dfs(int o,int p) {
    if (o>n) {
        ans++; return ;
    }
    if (p>m) {
        dfs(o+1,1); return ;
    }
    int w=a[o][p];
    int gt=a[o-1][p]|a[o][p-1];
    if (b[gt]<n-o+m-p+1) return ;
    if (a[o][p]) {
        if (a[o][p]&gt) return ;
        a[o][p]|=gt; dfs(o,p+1); a[o][p]=w; return ;
    }
    //for (int i=1;i<=b[gt];i++) a[o][p]=(gt|(1<<(Q[gt][i]-1))),dfs(o,p+1);
    long long temp=-1;
    for (int i=1;i<=k;i++) {
        if (gt&(1<<(i-1))) continue;
        if (v[i]) a[o][p]=gt|(1<<(i-1)),dfs(o,p+1);
        else {
            if (temp>=0) ans+=temp;
            else temp=ans,a[o][p]=gt|(1<<(i-1)),v[i]=1,dfs(o,p+1),v[i]=0,temp=ans-temp;
        }
    }
    a[o][p]=0;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (i=0;i<(1<<k);i++) {
        int p=i;
        for (j=1;j<=k;j++,p>>=1) if (!(p&1)) Q[i][++b[i]]=j;
    }
    if (n+m-1>k) return printf("0"),0;
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) {
        scanf("%d",&x); if (x) a[i][j]=1<<(x-1),v[x]=1;
    }
    dfs(1,1);
    printf("%I64d\n",ans%P);
}