#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int qzfkcnt[810];
int block,ans,cnt[510000];
int n,m,a[510000],Ans[510000];
struct node{int l,r,id;}q[510000];
inline bool cmp(node x,node y){return x.l/block!=y.l/block?x.l<y.l:x.l/block&1?x.r<y.r:x.r>y.r;}
inline void add(int x)
{
	if(cnt[a[x]]==1)qzfkcnt[a[x]/700]--;
	cnt[a[x]]++;
	if(cnt[a[x]]==1)qzfkcnt[a[x]/700]++;
}
inline void del(int x)
{
	if(cnt[a[x]]==1)qzfkcnt[a[x]/700]--;
	cnt[a[x]]--;
	if(cnt[a[x]]==1)qzfkcnt[a[x]/700]++;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	block=ceil(n/sqrt(m*2.0/3));
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	int l=0,r=0;cnt[0]=1;qzfkcnt[0]=1;
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(l<q[i].l)del(l++);
		while(r>q[i].r)del(r--);
		int qzfk=-1;
		for(int i=0;i<=714;i++)if(qzfkcnt[i]>0){qzfk=i;break;}
		if(qzfk==-1)
		{
			Ans[q[i].id]=0;continue;
		}
		for(int i=qzfk*700;;i++)if(cnt[i]==1){qzfk=i;break;}
		Ans[q[i].id]=qzfk;
	}
	for(int i=1;i<=m;i++)printf("%d\n",Ans[i]);
	return 0;
}