#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct tree
{
	int ls[1000010];
	int rs[1000010];
	int n;
	int rt;
	tree()
	{
		memset(ls,0,sizeof ls);
		memset(rs,0,sizeof rs);
		rt=0;
		n=0;
	}
	void build(int &p,int l,int r)
	{
		p=++n;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(ls[p],l,mid);
		build(rs[p],mid+1,r);
	}
	void find(int p,int l,int r,int L,int R,list<int> &v)
	{
		if(l<=L&&r>=R)
		{
			v.push_back(p);
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)
			find(ls[p],l,r,L,mid,v);
		if(r>mid)
			find(rs[p],l,r,mid+1,R,v);
	}
};
typedef pair<int,ll> pii;
list<pii> e[1000010];
void add(int x,int y,ll z)
{
	e[x].push_back(pii(y,z));
}
tree a;
list<int> v1,v2;
queue<int> q;
ll d[1000010];
int b[1000010];
int id[1000010];
int main()
{
	//a1-> 
	//a2-> 
//	freopen("cf787d.in","r",stdin);
//	freopen("cf787d.out","w",stdout);
	int n,m,st;
	scanf("%d%d%d",&n,&m,&st);
	a.build(a.rt,1,n);
	int u,v,l,r,w,i,c;
	for(i=1;i<=a.n;i++)
	{
		if(a.ls[i])
		{
			add(a.ls[i],i,0);
			add(i+a.n,a.ls[i]+a.n,0);
		}
		if(a.rs[i])
		{
			add(a.rs[i],i,0);
			add(i+a.n,a.rs[i]+a.n,0);
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&c);
		v1.clear();
		v2.clear();
		if(c==1)
		{
			scanf("%d%d%d",&u,&v,&w);
			a.find(a.rt,u,u,1,n,v1);
			a.find(a.rt,v,v,1,n,v2);
		}
		else if(c==2)
		{
			scanf("%d%d%d%d",&u,&l,&r,&w);
			a.find(a.rt,u,u,1,n,v1);
			a.find(a.rt,l,r,1,n,v2);
		}
		else
		{
			scanf("%d%d%d%d",&u,&l,&r,&w);
			a.find(a.rt,l,r,1,n,v1);
			a.find(a.rt,u,u,1,n,v2);
		}
		for(auto x1:v1)
			for(auto x2:v2)
				add(x1,x2+a.n,w);
	}
	for(i=1;i<=n;i++)
	{
		v1.clear();
		a.find(a.rt,i,i,1,n,v1);
		id[i]=v1.front();
		add(id[i]+a.n,id[i],0);
	}
	memset(d,0x7f,sizeof d);
	d[id[st]]=0;
	q.push(id[st]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		b[x]=0;
		for(auto v:e[x])
			if(d[x]+v.second<d[v.first])
			{
				d[v.first]=d[x]+v.second;
				if(!b[v.first])
				{
					b[v.first]=1;
					q.push(v.first);
				}
			}
	}
	for(i=1;i<=n;i++)
		if(d[id[i]]==0x7f7f7f7f7f7f7f7fll)
			printf("-1 ");
		else
			printf("%I64d ",d[id[i]]);
	return 0;
}