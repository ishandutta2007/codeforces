#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010;
struct query
{
	int type,x,y;
}q[M]={};
struct node
{
	int l,r,tot;
	long long s,sd;
}t[(N+M+M)<<2]={};
int n,m,x[N]={},v[N+M+M]={},tot1=0;
long long s1=0,ans=0;
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
	}
	t[k].l=l;
	t[k].r=r;
}
void change(int pos,int c,int k)
{
	t[k].tot+=c;
	t[k].sd+=(long long)v[pos]*c;
	if(t[k].l==t[k].r)
		return;
	if(t[k<<1].r>=pos)
		change(pos,c,k<<1);
	else
		change(pos,c,(k<<1)|1);
	t[k].s=t[(k<<1)|1].sd*t[k<<1].tot - t[k<<1].sd*t[(k<<1)|1].tot + t[k<<1].s + t[(k<<1)|1].s;
}
void get_sum(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		ans+=t[k].s+t[k].sd*tot1 - s1*t[k].tot;
		tot1+=t[k].tot;
		s1+=t[k].sd;
		return;
	}
	if(t[k<<1].r>=l)
		get_sum(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		get_sum(l,r,(k<<1)|1);
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	int tot=0;
	for(int i=1;i<=n;++i)
		v[++tot]=x[i];
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&q[i].type,&q[i].x,&q[i].y);
		if(q[i].type==1)
		{
			v[++tot]=v[q[i].x];
			v[q[i].x]+=q[i].y;
			q[i].y=v[q[i].x];
			q[i].x=v[tot];
		}
		if(q[i].type==2)
			v[++tot]=q[i].x,v[++tot]=q[i].y;
	}
	sort(v+1,v+tot+1);
	make_tree(1,tot,1);
	for(int i=1;i<=n;++i)
	{
		x[i]=lower_bound(v+1,v+tot+1,x[i])-v;
		change(x[i],1,1);
	}
	for(int i=1;i<=m;++i)
	{
		q[i].x=lower_bound(v+1,v+tot+1,q[i].x)-v;
		q[i].y=lower_bound(v+1,v+tot+1,q[i].y)-v;
	}
}
void work()
{
	/*
	for(int i=1;i<=n;++i)
		cout<<x[i]<<' ';
	cout<<endl;
	for(int i=1;i<=m;++i)
		cout<<q[i].type<<' '<<q[i].x<<' '<<q[i].y<<endl;
	*/
	for(int i=1;i<=m;++i)
	{
		if(q[i].type==1)
		{
			change(q[i].x,-1,1);
			change(q[i].y,1,1);
		}
		if(q[i].type==2)
		{
			tot1=0,s1=ans=0ll;
			get_sum(q[i].x,q[i].y,1);
			printf("%I64d\n",ans);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}