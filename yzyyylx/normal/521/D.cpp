#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

ll n,m,k,num[N],cz[N];
P chg[N];
inline ll gcd(ll u,ll v)
{
	for(;u&&v&&u!=v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}
struct Fs
{
	ll fz,fm,id;
	void yf()
	{
		ll g=gcd(fz,fm);
		fz/=g;
		fm/=g;
	}
	bool operator < (const Fs &u) const
	{
		return fz*u.fm<fm*u.fz;
	}
}tmp;
vector<P>add[N];
vector<ll>ans;
priority_queue<Fs>pq;

inline bool cmp(P u,P v){return u>v;}
inline bool cmp2(ll u,ll v){return cz[u]<cz[v];}

int main()
{
	ll i,j,o,p,q;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&o,&p,&q);
		cz[i]=o;
		if(o==1)
		{
			chg[p]=max(chg[p],mp(q-num[p],i));
		}
		else if(o==2)
		{
			add[p].push_back(mp(q,i));
		}
		else
		{
			tmp.fz=q-1;
			tmp.fm=1;
			tmp.id=i;
			pq.push(tmp);
		}
	}
//	for(i=1;i<=n;i++) cout<<chg[i].fi<<" ";return 0;
	for(i=1;i<=n;i++)
	{
		if(chg[i].fi) add[i].push_back(chg[i]);
		sort(add[i].begin(),add[i].end(),cmp);
//		cout<<" "<<i<<":";for(j=0;j<add[i].size();j++) cout<<add[i][j].fi<<' ';puts("");
		o=num[i];
		for(j=0;j<add[i].size();j++)
		{
			tmp.fz=add[i][j].fi;
			tmp.fm=o;
			tmp.id=add[i][j].se;
			tmp.yf();
			pq.push(tmp);
			o+=add[i][j].fi;
		}
	}
//	for(;!pq.empty();pq.pop()) cout<<pq.top().fz<<" "<<pq.top().fm<<endl;return 0;
	for(i=1;i<=k&&!pq.empty();i++)
	{
		ans.push_back(pq.top().id);
		pq.pop();
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end(),cmp2);
	for(i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}