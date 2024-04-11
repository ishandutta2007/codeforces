#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
#define M 1050000
using namespace std;

ll n,k,bb,t,first[N],size[N],dn[N],cnt[M],num[N],ans[N],zx,all;
string str;
bool vis[N];
struct Bn
{
	ll to,next;
} bn[N<<1];
map<ll,ll>mm;
vector<ll>xo,cle,tmp;

inline void add(ll u,ll v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void gs(ll now,ll last)
{
	ll p;
	size[now]=1;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(bn[p].to==last||vis[bn[p].to]) continue;
		gs(bn[p].to,now);
		size[now]+=size[bn[p].to];
	}
}

ll find(ll now,ll last,ll tot)
{
	ll p;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(vis[bn[p].to] || bn[p].to==last || 2*size[bn[p].to]<tot) continue;
		return find(bn[p].to,now,tot);
	}
	return now;
}

void dfs(ll now,ll last,ll sum)
{
	ll p;
	cnt[sum]++;
	cle.push_back(sum);
	num[now]=sum;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(vis[bn[p].to] || bn[p].to==last) continue;
		dfs(bn[p].to,now,sum^(1 << dn[bn[p].to]));
	}
}

void Dfs(ll now,ll last)
{
	ll p,q;
	tmp.push_back(num[now]);
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(bn[p].to==last || vis[bn[p].to]) continue;
		Dfs(bn[p].to,now);
	}
}

ll ask(ll now,ll last)
{
	ll i,j,p,q,res=0,t;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(bn[p].to==last || vis[bn[p].to]) continue;
		res+=ask(bn[p].to,now);
	}
	for(i=0; i<xo.size(); i++)
	{
		t=num[now]^xo[i]^(1 << dn[zx]);
		if(!t) all++;
//		cout<<"    "<<t<<endl;
		res+=cnt[t];
	}
	ans[now]+=res;
	return res;
}

void work(ll now)
{
	if(now==5)
		now=5;
	ll p,q,i,j;
	vis[now]=1,zx=now;
	cle.clear();
	cnt[0]=1;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(vis[bn[p].to]) continue;
		dfs(bn[p].to,now,(1 << dn[bn[p].to]));
	}
//	if(now==5) for(i=1;i<M;i++) if(cnt[i]) puts("666");
//	for(i=0;i<cle.size();i++) cout<<cle[i]<<" ";puts("");
	all=0;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(vis[bn[p].to]) continue;
		tmp.clear();
		Dfs(bn[p].to,now);
		for(i=0; i<tmp.size(); i++) cnt[tmp[i]]--;
		all+=ask(bn[p].to,now);
		for(i=0; i<tmp.size(); i++) cnt[tmp[i]]++;
	}
	ans[now]+=all/2;
	for(i=0; i<cle.size(); i++) cnt[cle[i]]=0;
//	return;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		if(vis[bn[p].to]) continue;
		gs(bn[p].to,now);
		work(find(bn[p].to,now,size[bn[p].to]));
	}
}

int main()
{
//	freopen("2.txt","r",stdin);
	memset(first,-1,sizeof(first));
	ll i,j,p,q;
	xo.push_back(0);
	for(i=1; i<1000000; i<<=1) xo.push_back(i);
//	for(i=0;i<xo.size();i++) cout<<xo[i]<<" ";return 0;
	cin>>n;
	for(i=1; i<n; i++)
	{
		scanf("%lld%lld",&p,&q);
		add(p,q),add(q,p);
	}
	cin>>str;
	for(i=0; i<str.size(); i++) dn[i+1]=str[i]-'a';
	gs(1,-1);
	work(find(1,-1,size[1]));
//	work(5);
	for(i=1; i<=n; i++) printf("%lld ",ans[i]+1);
}