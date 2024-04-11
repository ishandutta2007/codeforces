#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef pair <P,P> PP;

struct edge
{
	int to;
	ll cost;
	edge(int to=0,ll cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
vector <P> up[SIZE];
vector <P> down[SIZE];
vector <int> vt[SIZE];
ll dep[SIZE];
int nd[SIZE],back[SIZE];
int pos[SIZE],cmb[SIZE];
int par[SIZE],len[SIZE];
PP now[SIZE];
int now_sz;

void dfs(int v=0,int p=-1,ll d=0)
{
	dep[v]=d;
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v,d+e.cost);
			nd[v]+=nd[e.to];
		}
	}
}
void heavy_light(int v=0,int p=-1,int b=-1)
{
	vt[now_sz].push_back(v);
	par[now_sz]=b;
	back[v]=b;
	pos[v]=len[now_sz]++;
	cmb[v]=now_sz;
	bool up=false;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&nd[e.to]*2>=nd[v])
		{
			heavy_light(e.to,v,b);
			up=true;
			break;
		}
	}
	if(!up)
	{
		now_sz++;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&nd[e.to]*2<nd[v])
		{
			heavy_light(e.to,v,v);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);a--,b--,c*=(ll) n,c--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	dfs();
	heavy_light();
	int m;
	scanf("%d",&m);
	ll all=0;
	for(int i=0;i<m;i++)
	{
		ll t;
		int f,v;
		scanf("%lld %d %d",&t,&f,&v);t*=(ll) n,v--;
		up[v].push_back(P(t+dep[v],f));
		down[v].push_back(P(t-dep[v]-1,f));
		all+=f;
	}
	ll ret=0;
	for(int t=now_sz-1;t>=0;t--)
	{
		int sz=0;
		for(int i=0;i<vt[t].size();i++)
		{
			int v=vt[t][i];
			for(int j=0;j<up[v].size();j++)
			{
				P p=up[v][j];
				now[sz++]=PP(P(p.first,-1),P(p.first-2LL*dep[v],p.second));
			}
			for(int j=0;j<down[v].size();j++)
			{
				P p=down[v][j];
				now[sz++]=PP(P(p.first+2LL*dep[v],1),p);
			}
		}
		multiset <P> st;
		multiset <P>::iterator it;
		sort(now,now+sz);/*
		if(t<=10)
		{
			printf("* %d %lld\n",t,ret);
			for(int i=0;i<sz;i++) printf("[%lld %lld] [%lld %lld]\n",now[i].first.first,now[i].first.second,now[i].second.first,now[i].second.second);
		}*/
		for(int i=sz-1;i>=0;i--)
		{
			if(now[i].first.second==-1)//query
			{
				P q=now[i].second;
				while(q.second>0)
				{
					it=st.lower_bound(P(q.first,-1));
					if(it!=st.end())
					{
						P p=*it;
						ll df=now[i].first.first-p.first;
						if(t==0||df>=2LL*dep[par[t]])
						{
							st.erase(it);
							ll c=min(q.second,p.second);
							ret+=c;
							q.second-=c;
							p.second-=c;
							if(p.second>0) st.insert(p);
						}
						else break;
					}
					else break;
				}
				if(q.second>0&&t>0) up[par[t]].push_back(P(now[i].first.first,q.second));
			}
			else//add
			{
				st.insert(now[i].second);
			}
		}
		if(t>0)
		{
			for(it=st.begin();it!=st.end();it++) down[par[t]].push_back(*it);
			st.clear();
		}
		//printf("* %d %lld\n",t,ret);
	}
	printf("%lld\n",all-ret);
	return 0;
}