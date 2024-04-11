#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 300005
#define INF 1000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,ll> P;

vector <int> vec[SIZE];
vector <P> back[SIZE];
set <P> st[SIZE];//P(-depth,cost-add[v]) , depthcost
set <P>::iterator it,its;
ll sum[SIZE];//Jo[Kvcost
ll add[SIZE];
int dep[SIZE];
P now[SIZE];
bool up;
int n,m;

void dfs(int v=0,int p=-1,int d=0)
{
	dep[v]=d;
	st[v].clear();
	sum[v]=add[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v,d+1);
			if(!up) return;
			//merge 
			if(st[v].size()<st[to].size())
			{
				swap(st[v],st[to]);
				swap(add[v],add[to]);
				swap(sum[v],sum[to]);
			}
			add[v]+=sum[to];
			for(it=st[to].begin();it!=st[to].end();it++)
			{
				P p=*it;
				p.second+=add[to]+sum[v]-add[v];
				//pinsertAKX
				its=st[v].lower_bound(P(p.first,-INF));
				if(its!=st[v].end()&&its->second<=p.second) continue;
				while(1)
				{
					its=st[v].lower_bound(P(p.first+1,-INF));
					if(its==st[v].begin()) break;
					its--;
					if(its->second<p.second) break;
					st[v].erase(its);
				}
				st[v].insert(p);
			}
			sum[v]+=sum[to];
		}
	}
	for(int i=((int) back[v].size())-1;i>=0;i--)
	{
		P p=back[v][i];
		p.first=-(dep[p.first]+1);
		p.second+=sum[v]-add[v];
		its=st[v].lower_bound(P(p.first,-INF));
		if(its!=st[v].end()&&its->second<=p.second) continue;
		while(1)
		{
			its=st[v].lower_bound(P(p.first+1,-INF));
			if(its==st[v].begin()) break;
			its--;
			if(its->second<p.second) break;
			st[v].erase(its);
		}
		st[v].insert(p);
	}
	while(!st[v].empty())
	{
		it=st[v].begin();
		if(-it->first>=dep[v]+1) st[v].erase(it);
		else break;
	}
	if(p!=-1)
	{
		if(!st[v].empty()) sum[v]=st[v].begin()->second+add[v];
		else up=false;
	}
	//printf("%d %lld : %lld\n",v,add[v],sum[v]);
	//for(it=st[v].begin();it!=st[v].end();it++) printf("[%d %lld] ",it->first,it->second+add[v]);puts("");
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		back[a].push_back(P(b,c));
	}
	up=true;
	dfs();
	if(!up) puts("-1");
	else printf("%lld\n",sum[0]);
	return 0;
}