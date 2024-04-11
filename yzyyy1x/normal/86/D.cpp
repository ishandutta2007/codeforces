#pragma GCC optimize(3,"inline","Ofast")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int block=450;
struct ques{
	int l,r,id;
	void in()
	{scanf("%d%d",&l,&r);}
}q[200010];
int a[200010],b[200010],c[200010],n,Q,len;
int l=1,r=0;
int vis[200010];ll res=0,ans[200010];
bool cmp(ques x,ques y)
{return x.l/block==y.l/block?x.r<y.r:x.l/block<y.l/block;}
void add(int x)
{
	x=a[x];
	res-=(ll)vis[x]*vis[x]*c[x];
	vis[x]++;
	res+=(ll)vis[x]*vis[x]*c[x];
}
void del(int x)
{
	x=a[x];
	res-=(ll)vis[x]*vis[x]*c[x];
	vis[x]--;
	res+=(ll)vis[x]*vis[x]*c[x];
}
int main()
{
	int tp;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=a[i];	
	sort(b+1,b+n+1);len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		tp=a[i],a[i]=lower_bound(b+1,b+len+1,a[i])-b,c[a[i]]=tp;
	for(int i=1;i<=Q;i++)
		q[i].in(),q[i].id=i;
	sort(q+1,q+Q+1,cmp);
	for(int i=1;i<=Q;i++)
	{
		while(r<q[i].r)add(++r);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)del(r--);
		while(l<q[i].l)del(l++);
		ans[q[i].id]=res;
	}
	for(int i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
}