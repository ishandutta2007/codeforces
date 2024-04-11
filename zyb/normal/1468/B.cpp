#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct pa {
    unsigned long long x,y;
    int id;
};
struct cmp1 {
    inline bool operator () (pa x,pa y) {
        if (x.x*y.y!=y.x*x.y)
            return x.x*y.y<y.x*x.y;
        return x.id<y.id;
    }
};
struct cmp2 {
    inline bool operator () (pa x,pa y) {
        if (x.x*y.y!=y.x*x.y)
            return x.x*y.y>y.x*x.y;
        return x.id<y.id;
    }
};
set<pa,cmp1>G;
set<pa,cmp2>G1;
multiset<int,greater<int>>Ans;
int n,m,a[N],b[N],fa[N],ans[N];
unsigned long long sum[N],len[N];
inline int get(int x) {
    if (fa[x]==x)  return x;
    return fa[x]=get(fa[x]);
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),fa[i]=i;
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    
    Ans.clear();
    for (int i=1;i<=n;i++) G1.insert(pa{sum[i]=a[i],len[i]=1,i}),Ans.insert(1);
    for (int i=1;i<=n+1;i++) fa[i]=i;
    for (int i=m;i;i--) {
        while (1) {
            if (!G1.size()) break;
            pa x=(*G1.begin());
            if (x.y*b[i]>=x.x) break;
            G1.erase(x);
            Ans.erase(Ans.find(x.y));
            int r=get(x.id+1);
            if (r!=n+1) {
                G1.erase(pa{sum[r],len[r],r});
                Ans.erase(Ans.find(len[r]));
                len[r]+=x.y;
                sum[r]+=x.x;
                G1.insert(pa{sum[r],len[r],r});
                Ans.insert(len[r]);
            }
            else len[n+1]+=x.y;
            fa[x.id]=r;
        }
        ans[i]=max(ans[i],(*Ans.begin()));
        ans[i]=max(ans[i],(int)len[n+1]);
    }
    for (int i=1;i<=m;i++) printf("%d ",ans[i]-1);
}