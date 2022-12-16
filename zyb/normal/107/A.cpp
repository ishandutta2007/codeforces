#include<stdio.h>
#include<algorithm>
#define N 1005
using namespace std;
int i,j,k,l,s,n,m,to[N],G[N],val[N],ans,v[N],da[N],x,y,z,f[N],V[N];
inline void dfs(int o) {
    while (o) {
        o=to[o];
        if (!o) return ;
        G[ans]=o;
        s=min(s,val[o]);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),to[x]=y,f[y]++,val[y]=z,V[x]=V[y]=1;
    for (i=1;i<=n;i++) {
        if (!f[i]&&V[i]) {
            s=1000000000;
            ans++;
            dfs(i);
            da[ans]=i; v[ans]=s;
        }
    }
    if (!m) {
        return printf("0\n"),0;
    }
    printf("%d\n",ans);
    for (i=1;i<=ans;i++) printf("%d %d %d\n",da[i],G[i],v[i]);
}