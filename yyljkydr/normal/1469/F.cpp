#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

typedef long long ll;

int n,k;

int l[N];

int cnt;

struct T{
	int ls,rs;
	int l,r;
	ll sum,tag;
}t[N*2+1];

void pushdown(int x)
{
	if(t[x].tag)
	{
		t[t[x].ls].sum+=1ll*(t[t[x].ls].r-t[t[x].ls].l+1)*t[x].tag; 
		t[t[x].ls].tag+=t[x].tag;
		t[t[x].rs].sum+=1ll*(t[t[x].rs].r-t[t[x].rs].l+1)*t[x].tag; 
		t[t[x].rs].tag+=t[x].tag;
		t[x].tag=0;
	}
} 

void update(int x)
{
	t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

void change(int x,int l,int r,int v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].sum+=1ll*v*(t[x].r-t[x].l+1);
		t[x].tag+=v;
		return;
	}
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		change(t[x].ls,l,r,v);
	if(r>mid)
		change(t[x].rs,l,r,v);
	update(x);
}

int query(int x,int k)
{
	if(t[x].l==t[x].r)
		return t[x].sum?t[x].l:-1;
	pushdown(x);
	if(t[t[x].ls].sum>=k)
		return query(t[x].ls,k);
	else
		return query(t[x].rs,k-t[t[x].ls].sum);
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
	sort(l+1,l+n+1);
	reverse(l+1,l+n+1);
	build(1,1e6);
	change(1,1,1,1);
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int p=query(1,1);
		if(p==-1)
			break;
		change(1,p,p,-1);
		int L=(l[i]-1)/2,R=l[i]-1-L;
		change(1,p+2,p+2+L-1,1);
		change(1,p+2,p+2+R-1,1);
		int now=query(1,k)-1;
		if((ans==-1||now<ans)&&now>=0)
			ans=now;
	}
	printf("%d\n",ans);
}