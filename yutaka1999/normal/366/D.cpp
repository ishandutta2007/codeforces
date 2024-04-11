#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1005
#define MX 6005

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;
typedef pair <P,P> DP;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(x==par[x]) return x;
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
};
UF uf[MX];
vector <PP> vec[MX];
vector <int> vx;
DP edge[MX];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);a--;b--;
		vx.push_back(c);
		vx.push_back(d);
		edge[i]=DP(P(a,b),P(c,d));
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<m;i++)
	{
		int s=edge[i].second.first,e=edge[i].second.second;
		s=lower_bound(vx.begin(),vx.end(),s)-vx.begin();
		e=lower_bound(vx.begin(),vx.end(),e)-vx.begin();
		vec[s].push_back(PP(e,edge[i].first));
	}
	for(int i=0;i<vx.size();i++) uf[i].init(n+2);
	int ret=0;
	for(int i=0;i<vx.size();i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j].second;
			int a=p.first,b=p.second,c=vec[i][j].first;
			for(;c>=0;c--)
			{
				uf[c].unite(a,b);
				if(uf[c].same(0,n-1))
				{
					ret=max(ret,vx[c]-vx[i]+1);
					break;
				}
			}
		}
	}
	if(ret) printf("%d\n",ret);
	else puts("Nice work, Dima!");
	return 0;
}