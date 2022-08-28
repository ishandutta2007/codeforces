#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <functional>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <ll,P> PP;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++) reset(i);
	}
	void reset(int v)
	{
		par[v]=v;
		rank[v]=0;
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
}uf;
vector <PP> edge;
ll A[SIZE],rt[SIZE];
bool use[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*2LL%MOD;
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		edge.push_back(PP(A[a]^A[b],P(a,b)));
	}
	sort(edge.begin(),edge.end());
	ll all=(1LL<<k);
	uf.init(2*n+2);
	ll ret=0;
	for(int i=0;i<edge.size();)
	{
		all--;
		int f=i;
		for(;i<edge.size()&&edge[i].first==edge[f].first;i++);
		int cnt=n;
		vector <int> nd;
		for(int j=f;j<i;j++)
		{
			P p=edge[j].second;
			uf.reset(p.first);
			uf.reset(p.first+n);
			uf.reset(p.second);
			uf.reset(p.second+n);
			if(!use[p.first])
			{
				nd.push_back(p.first);
				use[p.first]=true;
				cnt--;
			}
			if(!use[p.second])
			{
				nd.push_back(p.second);
				use[p.second]=true;
				cnt--;
			}
		}
		int nm=0;
		for(int j=f;j<i;j++)
		{
			P p=edge[j].second;
			uf.unite(p.first,p.second+n);
			uf.unite(p.second,p.first+n);
			use[p.first]=use[p.second]=false;
		}
		for(int j=0;j<nd.size();j++)
		{
			int v=nd[j];
			if(uf.find(v)==v)
			{
				nm++;
			}
			if(uf.same(v,v+n))
			{
				nm=-1;
				break;
			}
		}
		if(nm!=-1)
		{
			cnt+=nm/2;
			ret+=rt[cnt];
			if(ret>=MOD) ret-=MOD;
		}
	}
	ret+=rt[n]*(all%MOD)%MOD;
	if(ret>=MOD) ret-=MOD;
	printf("%lld\n",ret);
	return 0;
}