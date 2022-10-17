#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 10000
#define N 300100
#define M 
using namespace std;

ll T,n,m,ans,ds[N],num[N],mx[N];
vector<ll>to[N];

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline bool cmp(ll u,ll v){return mx[u]>mx[v];}
void dfs(ll now,ll last)
{
	mx[now]=num[now];
	ll i,t;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(t==last) continue;
		dfs(t,now);
		Max(mx[now],mx[t]);
	}
}

void Dfs(ll now,ll last,ll w)
{
//	cout<<" "<<now<<" "<<last<<" "<<w<<endl;
	if(ds[now]==1)
	{
		ans+=max(w,num[now]);
		return;
	}
	Max(w,num[now]);
	ll i,t,mxx=0,pos;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(t==last) continue;
		if(mx[t]>mxx) mxx=mx[t],pos=t;
	}
	if(mxx>w)
	{
		for(i=0;i<to[now].size();i++)
		{
			t=to[now][i];
			if(t==last) continue;
			Dfs(t,now,0);
		}
	}
	else
	{
		Dfs(pos,now,w);
		for(i=0;i<to[now].size();i++)
		{
			t=to[now][i];
			if(t==last || t==pos) continue;
			Dfs(t,now,0);
		}
	}
}

int main()
{
	ll i,j,k,p,q,t=0;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]),Max(t,num[i]);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&p,&q);
		to[p].push_back(q);
		to[q].push_back(p);
		ds[p]++,ds[q]++;
	}
	for(i=1;i<=n;i++) if(ds[i]>2) break;
	if(i>n)
	{
		cout<<t*2;
		return 0;
	}
	q=0;
	for(i=1;i<=n;i++)
	{
		if(num[i]>q)
		{
			q=num[i];
			p=i;
		}
	}
	dfs(p,-1);
	if(ds[p]==1)
	{
		ans=num[p];
		Dfs(to[p][0],p,num[p]);
		cout<<ans;
		return 0;
	}
	sort(to[p].begin(),to[p].end(),cmp);
	Dfs(to[p][0],p,num[p]);
	Dfs(to[p][1],p,num[p]);
	for(i=2;i<to[p].size();i++) Dfs(to[p][i],p,0);
	cout<<ans;
}