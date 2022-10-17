#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M
using namespace std;

ll T,n,m,R,B,W,lea,ans,deep[N],tt,dfn[N],in[N],out[N],fa[N];
bool lef[N],gg[N];
struct Node
{
	ll ls,rs,sub;
	P mx;
}node[N<<1];
vector<ll>to[N];

void dfs(ll now,ll last)
{
	ll i,t;
	dfn[++tt]=now;
	in[now]=tt;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(t==last) continue;
		deep[t]=deep[now]+1;
		fa[t]=now;
		lef[now]=0;
		dfs(t,now);
	}
	out[now]=tt;
}

inline void down(ll now)
{
	ll L=node[now].ls,R=node[now].rs;
	if(node[now].sub)
	{
		node[L].sub+=node[now].sub;
		node[L].mx.fi-=node[now].sub;
		node[R].sub+=node[now].sub;
		node[R].mx.fi-=node[now].sub;
		node[now].sub=0;
	}
}

void build(ll now,ll l,ll r)
{
	if(l==r)
	{
//		cout<<now<<" "<<l<<" "<<dfn[l]<<" "<<deep[dfn[l]]<<endl;
		node[now].mx=mp(deep[dfn[l]],dfn[l]);
		return;
	}
	ll mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
	node[now].mx=max(node[node[now].ls].mx,node[node[now].rs].mx);
}

void chg(ll now,ll l,ll r,ll u,ll v,ll w)
{
//	cout<<"chg:"<<now<<l<<r<<u<<v<<endl;
	if(u<=l && r<=v)
	{
		node[now].mx.fi-=w;
		node[now].sub+=w;
		return;
	}
	down(now);
	ll mid=((l+r)>>1);
	if(u<=mid) chg(node[now].ls,l,mid,u,v,w);
	if(mid<v) chg(node[now].rs,mid+1,r,u,v,w);
	node[now].mx=max(node[node[now].ls].mx,node[node[now].rs].mx);
}

P ask(ll now,ll l,ll r,ll u,ll v)
{
//	cout<<"ask:"<<now<<l<<r<<u<<v<<endl;
	if(u<=l && r<=v) return node[now].mx;
	down(now);
	ll mid=((l+r)>>1);
	P res=mp(0,0);
	if(u<=mid) res=max(res,ask(node[now].ls,l,mid,u,v));
	if(mid<v) res=max(res,ask(node[now].rs,mid+1,r,u,v));
	return res;
}

void Out(ll now,ll l,ll r)
{
//	cout<<" "<<now<<" "<<l<<" "<<r<<endl;
	if(l==r)
	{
		cout<<now<<" "<<node[now].mx.fi<<" "<<node[now].mx.se<<endl;
		return;
	}
	down(now);
	ll mid=((l+r)>>1);
	Out(node[now].ls,l,mid);
	Out(node[now].rs,mid+1,r);
}

int main()
{
	ll i,j,t,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++) lef[i]=1;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&p,&q);
		to[p].push_back(q);
		to[q].push_back(p);
	}
	deep[1]=1;
	dfs(1,-1);
	for(i=1;i<=n;i++) if(lef[i]) lea++;
	if(m>=lea)
	{
		if(m>=n/2)
		{
			if(lea<=n/2) printf("%lld\n",n/2*(n-n/2));
			else printf("%lld\n",lea*(n-lea));
		}
		else printf("%lld\n",m*(n-m));
		return 0;
	}
	tt=1;
	build(1,1,n);
	gg[0]=1;
	
//	Out(1,1,n);return 0;
//	for(i=1;i<=n;i++) cout<<dfn[i]<<" ";puts("");
//	for(i=1;i<=n;i++) cout<<in[i]<<" ";puts("");
//	for(i=1;i<=n;i++) cout<<out[i]<<" ";puts("");
	for(i=1;i<=m;i++)
	{
//		cout<<i<<endl;
		P now=ask(1,1,n,1,n);
		ans+=now.fi;
		for(j=now.se;!gg[j];j=fa[j])
		{
//			cout<<" "<<j<<endl;
			chg(1,1,n,in[j],out[j],1);
			gg[j]=1;
//			Out(1,1,n);puts("");
		}
//		chg(1,1,n,in[now.se],in[now.se],n);
	}
//	cout<<n<<" "<<m<<" "<<ans<<endl;
	R=m,W=ans-m,B=n-ans;
	ll mn=INF;
	for(i=0;i<=B;i++) mn=min(mn,(n-i-m)*(m-i));
	cout<<mn;
}