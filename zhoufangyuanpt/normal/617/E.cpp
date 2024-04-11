#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans,Ans[110000],cnt[1048575];
int n,m,k,block,a[110000];
struct node{int l,r,id;}q[110000];
inline bool cmp(node x,node y){return x.l/block!=y.l/block?x.l<y.l:(x.l/block&1)?x.r<y.r:x.r>y.r;}
inline void add(int x)
{
    ans+=cnt[k^a[x]];
    cnt[a[x]]++;
}
inline void del(int x)
{
    cnt[a[x]]--;
    ans-=cnt[k^a[x]];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    block=ceil(n/sqrt(m*2/3));a[0]=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]^a[i-1];
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+m+1,cmp);
    int l=0,r=0;ans=0;add(0);
    for(int i=1;i<=m;i++)
    {
        while(l>=q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(l<q[i].l-1)del(l++);
        while(r>q[i].r)del(r--);
        Ans[q[i].id]=ans;
    }
    for(int i=1;i<=m;i++)printf("%I64d\n",Ans[i]);
    return 0;
}