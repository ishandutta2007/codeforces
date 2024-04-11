#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll P=998244353;

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

const int N=4e5+1e3+7,BLK=2000;

int n,q;

int p[N];

ll a[N],b[N],S[N];

int cnt=0;

struct T{
	int ls,rs,l,r;
	ll a,b,s,v,tag;
}t[N*2+1];

void update(int x)
{
	t[x].s=(t[t[x].ls].s+t[t[x].rs].s)%P;
	t[x].b=(t[t[x].ls].b+t[t[x].rs].b)%P;
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		t[t[x].ls].tag=(t[t[x].ls].tag+t[x].tag)%P;
		t[t[x].ls].s=(t[t[x].ls].s+t[x].tag*t[t[x].ls].b%P)%P;
		t[t[x].rs].tag=(t[t[x].rs].tag+t[x].tag)%P;
		t[t[x].rs].s=(t[t[x].rs].s+t[x].tag*t[t[x].rs].b%P)%P;
		t[x].tag=0;
	}
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(t[x].l==t[x].r)
	{
		t[x].a=a[l];
		t[x].b=b[l];
		t[x].v=S[l-1];
		t[x].s=(t[x].a+t[x].b*t[x].v%P)%P;
		S[l]=(S[l-1]+t[x].s)%P;
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int l,int r,ll v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].tag=(t[x].tag+v)%P;
		t[x].s=(t[x].s+v*t[x].b%P)%P;
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

ll query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].s;
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	ll ret=0;
	if(l<=mid)
		ret=(ret+query(t[x].ls,l,r))%P;
	if(r>mid)
		ret=(ret+query(t[x].rs,l,r))%P;
	return ret;
}

set<int>s;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),p[i]=p[i]*qpow(100,P-2)%P,a[i]=qpow(p[i],P-2),b[i]=(1-p[i]+P)%P*a[i]%P;
	build(1,n);
	s.insert(1);
	s.insert(n+1);
	printf("%lld\n",t[1].s);
}