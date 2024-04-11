#pragma GCC optimize(3,"inline","Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll mod=1e9+7;
struct mat{
	ll a[3][3];
	void init0()
	{memset(a,0,sizeof a);}
	void init1()
	{
		memset(a,0,sizeof a);
		a[1][1]=a[2][2]=1;
	}
	void initf()
	{
		memset(a,0,sizeof a);
		a[1][2]=a[2][1]=a[2][2]=1;
	}
	bool ok()
	{
		if(a[1][1]!=1||a[2][2]!=1)return 1;
		if(a[1][2]!=0||a[2][1]!=0)return 1;
		return 0;
	}
}add[800010];
mat operator *(const mat x,const mat y)
{
	mat ans;
	ans.init0();
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return ans;			
}
pii operator *(const pii x,const mat y)
{
	pii res;
	res.first=(x.first*y.a[1][1]%mod+x.second*y.a[2][1]%mod)%mod;
	res.second=(x.first*y.a[1][2]%mod+x.second*y.a[2][2]%mod)%mod;
	return res;
}
mat qpow(mat a,ll b)
{
	mat ans;
	ans.init1();
	while(b)
	{
		if(b&1)ans=ans*a;
		b>>=1;a=a*a;
	}
	return ans;
}
int n,m;ll mp[100010];
pii nw[100010],seg[800010];
pii get(ll x)
{
	mat ha;pii res;
	ha.initf();
	ha=qpow(ha,x-1);
	res.first=1;res.second=1;
	res=res*ha;
	return res;
}
void push_up(int k)
{
	seg[k].first=(seg[k<<1].first+seg[k<<1|1].first)%mod;
	seg[k].second=(seg[k<<1].second+seg[k<<1|1].second)%mod;
}
void push_down(int k)
{
	if(add[k].ok())
	{
		seg[k<<1]=seg[k<<1]*add[k];
		seg[k<<1|1]=seg[k<<1|1]*add[k];
		add[k<<1]=add[k<<1]*add[k];
		add[k<<1|1]=add[k<<1|1]*add[k];
		add[k].init1();
	}
}
void build(int l,int r,int k)
{
	if(l==r)
	{
		seg[k]=nw[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	push_up(k);
}
void cg(int L,int R,int l,int r,int k,mat x)
{
	push_down(k);
	if(r<L||l>R)return;
	if(L<=l&&r<=R)
	{
		seg[k]=seg[k]*x;
		add[k]=add[k]*x;
		return;
	}
	int mid=(l+r)>>1;
	cg(L,R,l,mid,k<<1,x);
	cg(L,R,mid+1,r,k<<1|1,x);
	push_up(k);
}
ll ask(int L,int R,int l,int r,int k)
{
	push_down(k);
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[k].first;
	int mid=(l+r)>>1;
	return (ask(L,R,l,mid,k<<1)+ask(L,R,mid+1,r,k<<1|1))%mod;
}
int main()
{
	for(register int i=0;i<=800000;i++)add[i].init1();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&mp[i]),nw[i]=get(mp[i]);
	build(1,n,1);
	int op,l,r;mat tmp;ll x;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%lld",&x);
			tmp.initf();
			tmp=qpow(tmp,x);
			cg(l,r,1,n,1,tmp);
		}
		else printf("%lld\n",ask(l,r,1,n,1)%mod);
	}
}