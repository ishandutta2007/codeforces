#include<bits/stdc++.h>
#define ll long long
#define N 300100
#define M 
using namespace std;
 
ll n,m,top,tt,sta[N],pp[N],fa[N],in[N],out[N],dfn[N],cs[N],rk[N],gg[N];
char str[N];
struct Sz
{
	ll n;
	vector<ll>num;
	inline void init(ll u){n=u,num.resize(n+1);}
	inline ll lb(ll u){return u&(-u);}
	inline void add(ll u,ll v){for(;u<=n;u+=lb(u)) num[u]+=v;}
	inline ll ask(ll u){ll res=0;for(;u;u-=lb(u)) res+=num[u];return res;}
	inline ll ask(ll u,ll v){return ask(v)-ask(u-1);}
}sz[N],num;
vector<ll>to[N];
 
inline ll calc(ll u){return u*(u+1)/2;}
void dfs(ll now,ll last)
{
	dfn[++tt]=now;
	in[now]=tt;
	ll i,t;
	cs[now]=to[now].size();
//	cout<<" "<<now<<" "<<cs[now]<<endl;
	num.add(in[now],calc(cs[now]));
	sz[now].init(cs[now]);
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(t==last) continue;
		rk[t]=i+1;
		sz[now].add(i+1,1);
		dfs(t,now);
	}
	out[now]=tt;
}
 
int main()
{
	ll i,j,p,q,o,t;
	cin>>n>>m;
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(str[i]=='(') sta[++top]=i;
		else
		{
			if(top) pp[i]=sta[top],pp[sta[top]]=i,top--;
			else str[i]='.';
		}
	}
	for(;top;top--) str[sta[top]]='.';
	t=++tt;
	for(i=1;i<=n;i++)
	{
		if(str[i]=='(')
		{
			to[t].push_back(++tt);
			fa[tt]=t;
			gg[i]=t=tt;
		}
		else if(str[i]==')') gg[i]=t,t=fa[t];
	}
//	for(i=1;i<=n;i++) cout<<gg[i]<<" ";return 0;
	num.init(tt);
	tt=0;
	dfs(1,-1);
	
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&o,&p,&q);
		if(o==1)
		{
			num.add(fa[gg[p]],-(cs[fa[gg[p]]]--));
			sz[fa[gg[p]]].add(rk[gg[p]],-1);
		}
		else
		{
			p=gg[p],q=gg[q];
//			cout<<p<<" "<<q<<endl<<in[p]<<" "<<out[q]<<endl<<fa[p]<<" "<<cs[fa[p]]<<" "<<rk[p]<<" "<<rk[q]<<endl;
			printf("%lld\n",num.ask(in[p],out[q])+calc(sz[fa[p]].ask(rk[p],rk[q])));
		}
	}
}