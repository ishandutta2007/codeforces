#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

int cnt;

struct T{
	int l,r,ls,rs;
	int mn;
}t[N*2+1];

void update(int x)
{
	t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].mn=0;
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int p,int v)
{
	if(t[x].l==t[x].r)
	{
		t[x].mn=v;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		change(t[x].ls,p,v);
	else
		change(t[x].rs,p,v);
	update(x);
}

int query(int x,int p)
{
	if(t[x].r<=p)
		return t[x].mn;
	if(t[x].l>p)
		return 1e9;
	return min(query(t[x].ls,p),query(t[x].rs,p));
}

vector<int>v[N];

int vis[N],ok[N];

int main()
{
	scanf("%d",&n);
	build(1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		{
			ok[1]=1;
			int fir=query(1,a[i]-1);
			if(fir>vis[a[i]])
				ok[a[i]]=1;
		}
		change(1,a[i],i);
		vis[a[i]]=i;
	}
	for(int i=2;i<=n+1;i++)
	{
		int fir=query(1,i-1);
		if(fir>vis[i])
			ok[i]=1;
	}
	for(int i=1;;i++)
	{
		if(!ok[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
}