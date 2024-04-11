#include<bits/stdc++.h>
#define ll long long
#define N 400100
#define M 1000000007
using namespace std;

ll n,m,zz,ans,zs[N],ny[N],num[N];
char str[110];

inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

inline void get()
{
	ll i,j;
	for(i=2;i<=300;i++)
	{
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0) break;
		}
		if(j*j>i)
		{
			zs[++zz]=i;
			ny[i]=po(i,M-2);
		}
	}
}

inline ll ask(ll u)
{
	ll i,res=0;
	for(i=1;i<=zz;i++) if(u%zs[i]==0) res|=(1ll << (i-1));
	return res;
}

namespace A
{
	ll tt=1;
	struct Node
	{
		ll ls,rs,ji,dw,len;
	}node[N<<1];
	void down(ll now)
	{
		ll L=node[now].ls,R=node[now].rs;
		if(node[now].dw!=1)
		{
			node[L].dw*=node[now].dw,node[L].dw%=M;
			node[R].dw*=node[now].dw,node[R].dw%=M;
			node[L].ji*=po(node[now].dw,node[L].len),node[L].ji%=M;
			node[R].ji*=po(node[now].dw,node[R].len),node[R].ji%=M;
			node[now].dw=1;
		}
	}
	void build(ll now,ll l,ll r)
	{
		node[now].ji=node[now].dw=1;
		node[now].len=r-l+1;
		if(l==r)
		{
			node[now].ji=num[l];
			return;
		}
		ll mid=((l+r)>>1);
		node[now].ls=++tt;
		build(tt,l,mid);
		node[now].rs=++tt;
		build(tt,mid+1,r);
		node[now].ji=node[node[now].ls].ji*node[node[now].rs].ji%M;
	}
	void mul(ll now,ll l,ll r,ll u,ll v,ll w)
	{
		node[now].ji*=po(w,v-u+1);
		node[now].ji%=M;
		if(u==l&&v==r)
		{
			node[now].dw*=w,node[now].dw%=M;
			return;
		}
		ll mid=((l+r)>>1);
		if(u<=mid) mul(node[now].ls,l,mid,u,min(v,mid),w);
		if(mid<v) mul(node[now].rs,mid+1,r,max(u,mid+1),v,w);
	}
	ll ask(ll now,ll l,ll r,ll u,ll v)
	{
		if(u<=l&&r<=v) return node[now].ji;
		down(now);
		ll mid=((l+r)>>1),res=1;
		if(u<=mid) res=res*ask(node[now].ls,l,mid,u,v),res%=M;
		if(mid<v) res=res*ask(node[now].rs,mid+1,r,u,v),res%=M;
		return res;
	}
}

namespace B
{
	ll tt=1;
	struct Node
	{
		ll ls,rs,sum,dw;
	}node[N<<1];
	void build(ll now,ll l,ll r)
	{
		if(l==r)
		{
			node[now].sum=ask(num[l]);
			return;
		}
		ll mid=((l+r)>>1);
		node[now].ls=++tt;
		build(tt,l,mid);
		node[now].rs=++tt;
		build(tt,mid+1,r);
		node[now].sum=node[node[now].ls].sum|node[node[now].rs].sum;
	}
	void add(ll now,ll l,ll r,ll u,ll v,ll w)
	{
		node[now].sum|=w;
		if(u<=l&&r<=v)
		{
			node[now].dw|=w;
			return;
		}
		ll mid=((l+r)>>1);
		if(u<=mid) add(node[now].ls,l,mid,u,v,w);
		if(mid<v) add(node[now].rs,mid+1,r,u,v,w);
	}
	ll ask(ll now,ll l,ll r,ll u,ll v)
	{
		if(u<=l&&r<=v) return node[now].sum;
		ll mid=((l+r)>>1),res=node[now].dw;
		if(u<=mid) res|=ask(node[now].ls,l,mid,u,v);
		if(mid<v) res|=ask(node[now].rs,mid+1,r,u,v);
		return res;
	}
}

int main()
{
	get();
	ll i,j,a,b,p,q,o;
//	cout<<zz<<endl;
//	for(i=1;i<=zz;i++) cout<<zs[i]<<" "<<ny[zs[i]]<<endl;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	A::build(1,1,n),B::build(1,1,n);
	while(m--)
	{
		scanf("%s%lld%lld",str+1,&p,&q);
		if(str[1]=='T')
		{
			a=A::ask(1,1,n,p,q);
			b=B::ask(1,1,n,p,q);
//			cerr<<" "<<a<<" "<<b<<endl;
			for(i=1;i<=62;i++)
			{
				if((1ll << (i-1))&b)
				{
//					cerr<<zs[i]<<' ';
					a=a*(zs[i]-1)%M;
					a=a*ny[zs[i]]%M;
				}
			}
			printf("%lld\n",a);
		}
		else
		{
			scanf("%lld",&o);
			A::mul(1,1,n,p,q,o);
			B::add(1,1,n,p,q,ask(o));
		}
	}
}