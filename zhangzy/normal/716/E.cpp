#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#define xxx 520233
#define ll long long
#define hm 1000007
using namespace std;
struct R{
	ll to,val,nex;
}r[xxx<<1];
ll n,m,hea[xxx],cnt=1,siz[xxx],die[xxx],ans=0,ny[xxx],zy[xxx];

ll f[233],x,y;
void K(ll a,ll b)
{
	if (b==1)
	{
		x=0;y=1;
		return;
	}
	K(b,a%b);
	swap(x,y);
	y=y-a/b*x;
	return;
}

ll vv[xxx],g=0;
ll mp[hm<<1],val[hm<<1];
ll has(ll v)
{
	ll t=v%hm;
	while (val[t]!=0&&val[t]!=v) t++;
	val[t]=v;
	vv[++g]=t;
	return t;
}

void P()
{
	ny[0]=zy[0]=1;
	for (ll i=1;i<=100002;i++)
		zy[i]=zy[i-1]*10%m;
	for (ll i=1;i<=100002;i++)
	{
		K(zy[i],m);
		ny[i]=(x%m+m)%m;
	}
	return;
}

void A(ll x,ll fa,ll dep,ll v)
{
	mp[has(v)]++;
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		A(r[i].to,x,dep+1,(r[i].val*zy[dep]+v)%m);
	}
	return;
}

ll B(ll x,ll fa,ll dep,ll v)
{
	ll turn=mp[ has( ((-v)%m+m)*ny[dep]%m ) ];
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		turn+=B(r[i].to,x,dep+1,(v*10+r[i].val)%m);
	}
	return turn;
}

ll C(ll x,ll stdep,ll v)
{
	for (int i=1;i<=g;i++)
		mp[vv[i]]=val[vv[i]]=0;
	g=0;
	A(x,-1,stdep,v);
	return B(x,-1,stdep,v);
}

void S(ll x,ll fa)
{
	siz[x]=1;
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		S(r[i].to,x);
		siz[x]+=siz[r[i].to];
	}
	return;
}

ll H(ll x,ll fa,ll totsiz)
{
	for (ll i=hea[x];i>0;i=r[i].nex)
		if (siz[r[i].to]*2>totsiz&&!die[r[i].to]&&r[i].to!=fa)
			return H(r[i].to,x,totsiz);
	return x;
}

void D(ll x,ll fa)
{
	die[x]=1;
	ans+=C(x,0,0);
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		ans-=C(r[i].to,1,r[i].val);
		S(r[i].to,-1);
		D(H(r[i].to,-1,siz[r[i].to]),x);
	}
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	P();
	ll u,v,w;
	for (ll i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&u,&v,&w);
		w%=m;
		r[++cnt]=(R){v,w,hea[u]};
		hea[u]=cnt;
		r[++cnt]=(R){u,w,hea[v]};
		hea[v]=cnt;
	}
	S(0,-1);
	D(H(0,-1,siz[0]),-1);
	ans-=n;
	cout<<ans;
}