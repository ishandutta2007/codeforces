#include<stdio.h>
#include<set>
#define N 100005
#define inf 200000000000000000ll
#define P 314000000ll
#include<algorithm>
using namespace std;
struct lhy {
    long long v,id;
}f[N];
struct syf {
    bool operator()(const lhy &a,const lhy &b)  {
        if (a.v!=b.v)
        return a.v<b.v;
        return a.id<b.id;
    }
};
struct node {
    long long tot,next[N],last[N],to[N];
    inline void add(long long o,long long p) {
        next[++tot]=last[o]; last[o]=tot; to[tot]=p;
    }
}a,b,c;
set<lhy,syf>gt;
long long ans2[N],p,x[N],y,v[N],t[N],ans1[N],i,j,k,l,s,n,m,sum[N],Sum[N];
inline void dfs(long long o) {
    v[o]=1;
    for (long long i=a.last[o];i;i=a.next[i]) {
        long long gt=a.to[i];
        long long s=sum[gt],bb=0;
        for (long long j=c.last[gt];j;j=c.next[j]) {
            long long gtw=c.to[j];
            if (v[gtw]==-1) {
                s=bb=0; break;
            }
            if (v[gtw]==2) {
                if (ans2[gtw]==inf) bb=1;
                else s+=ans2[gtw],s=min(s,P);
            }
            else  if (v[gtw]==1) {
                bb=1; v[o]=2;
            }
            else {
                dfs(gtw); if (ans2[gtw]==inf) bb=1;
                else s+=ans2[gtw],s=min(s,P);
            }
        }
        if (bb) ans2[o]=inf;
        else ans2[o]=max(ans2[o],s);
    }
    v[o]=2;
}
int main() {
    scanf("%I64d%I64d",&m,&n);
    for (i=1;i<=n;i++) f[f[i].id=i].v=inf,ans1[i]=-1;
    for (i=1;i<=m;i++) {
        scanf("%I64d",&x[i]);
        a.add(x[i],i);
        scanf("%I64d",&p);
        for (j=1;j<=p;j++) {
            scanf("%I64d",&y); 
            if (y==-1) Sum[i]++,sum[i]++;
            else c.add(i,y),b.add(y,i),t[i]++;
        }
        if (!t[i]) f[x[i]].v=min(f[x[i]].v,sum[i]);
    }
    for (i=1;i<=n;i++) if (f[i].v!=inf) gt.insert(f[i]);
    while (gt.size()) {
        lhy gtw=(*gt.begin());
        gt.erase(gt.begin());
        if (v[gtw.id]) continue;
        ans1[gtw.id]=gtw.v; v[gtw.id]=1;
        for (long long i=b.last[gtw.id];i;i=b.next[i]) {
            t[b.to[i]]--;
            Sum[b.to[i]]+=ans1[gtw.id];
            Sum[b.to[i]]=min(Sum[b.to[i]],P);
            if (t[b.to[i]]==0) if (Sum[b.to[i]]<f[x[b.to[i]]].v) f[x[b.to[i]]].v=Sum[b.to[i]],gt.insert(f[x[b.to[i]]]);
        }
    }
    for (i=1;i<=n;i++) v[i]=0;
    for (i=1;i<=n;i++) if (ans1[i]==-1) v[i]=-1;
    for (i=1;i<=n;i++) {
        if (ans1[i]==-1) ans2[i]=0;
        else if (!v[i]) dfs(i);
    }
    for (i=1;i<=n;i++) {
        if (ans1[i]!=-1) printf("%I64d ",min(ans1[i],P));
        else printf("-1 ");
        if (ans2[i]>=inf) printf("-2\n");
        else if (!ans2[i]) printf("-1\n");
        else printf("%I64d\n",min(ans2[i],P));
    }
}