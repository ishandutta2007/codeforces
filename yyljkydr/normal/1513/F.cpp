#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n;

struct P{
	int a,b;
}p[N];

vector<int>v,px[N];

int getp(int val)
{
	return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}

int tot,rt[N];

struct T{
	int ls,rs;
	int mx;
}t[N*21];

void insert(int x,int &y,int l,int r,int p,int v)
{
	y=++tot;
	t[y]=t[x];
	t[y].mx=max(t[y].mx,v);
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		insert(t[x].ls,t[y].ls,l,mid,p,v);
	else
		insert(t[x].rs,t[y].rs,mid+1,r,p,v);
}

int query(int x,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
		return t[x].mx;
	int mid=(l+r)>>1;
	int ret=-2e9;
	if(a<=mid)
		ret=max(ret,query(t[x].ls,l,mid,a,b));
	if(b>mid)
		ret=max(ret,query(t[x].rs,mid+1,r,a,b));
	return ret;
}

long long solve()
{
	long long ans=0,tt;
	for(int i=1;i<=n;i++)
		ans+=abs(p[i].a-p[i].b);
	tt=ans;
	for(int i=1;i<=n*2;i++)
		px[i].clear();
	for(int i=1;i<=n;i++)
		px[getp(p[i].b)].push_back(p[i].a);
	int nx=0;
	t[0].mx=-2e9;
	for(int i=1;i<=tot;i++)
		t[i].mx=0;
	tot=0;
	for(int i=1;i<=n*2;i++)
	{
		int mx=-2e9;
		if(px[i].size())
			mx=*max_element(px[i].begin(),px[i].end());
		insert(rt[i-1],rt[i],1,n*2,getp(mx),mx);
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].b<p[i].a)
			continue;
		int w=query(rt[getp(p[i].a)],1,2*n,getp(p[i].a),getp(p[i].b));
		ans=min(ans,tt-1ll*w*2+p[i].a*2);
	}
	for(int i=1;i<=n*2;i++)
		px[i].clear();
	for(int i=1;i<=n;i++)
		px[getp(p[i].a)].push_back(p[i].b);
	t[0].mx=-2e9;
	for(int i=1;i<=tot;i++)
		t[i].mx=0;
	tot=0;
	for(int i=1;i<=n*2;i++)
	{
		int mx=-2e9;
		if(px[i].size())
			mx=*max_element(px[i].begin(),px[i].end());
		insert(rt[i-1],rt[i],1,n*2,getp(mx),mx);
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].b>p[i].a)
			continue;
		int w=query(rt[getp(p[i].b)],1,2*n,getp(p[i].a),n*2);
		if(w!=-2e9)
		ans=min(ans,tt-p[i].a*2+p[i].b*2);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	long long ans=1e18;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i].a);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i].b);
	for(int i=1;i<=n;i++)
		v.push_back(p[i].a),v.push_back(p[i].b);
	sort(v.begin(),v.end());
	ans=min(ans,solve());
	for(int i=1;i<=n;i++)
		swap(p[i].a,p[i].b);
	ans=min(ans,solve());
	printf("%lld\n",ans);
}