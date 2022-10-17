#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m,l[N],r[N];

int ans[N];

struct BIT{
	vector<int>v,d;
	void ins(int x)
	{
		v.push_back(x);
	}
	void init()
	{
		v.push_back(0);
		d.resize(v.size());
		for(auto &x:d)
			x=m+1;
		sort(v.begin(),v.end());
	}
	void add(int x,int va)
	{
		int p=lower_bound(v.begin(),v.end(),x)-v.begin();
		while(p<d.size())
		{
			d[p]=min(d[p],va);
			p+=p&-p;
		}
	}
	int query(int x)
	{
		int p=upper_bound(v.begin(),v.end(),x)-v.begin()-1;
		int ret=m+1;
		while(p)
		{
			ret=min(ret,d[p]);
			p-=p&-p;
		}
		return ret;
	}
}c[N];

void ins(int l,int r)
{
	for(int i=l;i;i-=i&-i)
		c[i].ins(r);
}

void add(int l,int r,int v)
{
	for(int i=l;i;i-=i&-i)
		c[i].add(r,v);
}

int query(int l,int r)
{
	int ret=m+1;
	for(int i=l;i<=n;i+=i&-i)
		ret=min(ret,c[i].query(r));
	return ret;
}

vector<int>ran[N];

int solve(int a,int b)
{
	if(a>b)
		return 0;
	int t=query(a,b);
	if(t==m+1)
		return 0;
	return r[t]-l[t]+1+solve(a,l[t]-1)+solve(r[t]+1,b);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		ins(l[i],r[i]);
		ran[r[i]-l[i]+1].push_back(i);
	}
	for(int i=1;i<=n;i++)
		c[i].init();
	for(int i=n;i>=1;i--)
	{
		for(auto x:ran[i])
			add(l[x],r[x],x);
		ans[i]=solve(1,n);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}