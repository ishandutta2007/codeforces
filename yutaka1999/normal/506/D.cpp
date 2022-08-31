#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <functional>
#define SIZE 100005
#define SQR 700

using namespace std;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=1;
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
UF uf;
vector <P> vec[SIZE];
vector <P> tag[SIZE];
vector <int> col[SIZE];
int left[SIZE],right[SIZE],ans[SIZE];
int id[SIZE],vt[SIZE],ans2[SIZE];
bool ok[2*SIZE];
int wh[SIZE],cnt[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;c--;
		vec[c].push_back(P(a,b));
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--;right[i]--;
		tag[left[i]].push_back(P(right[i],i));
		tag[right[i]].push_back(P(left[i],i));
	}
	memset(id,-1,sizeof(id));
	int all=0;
	for(int i=0;i<m;i++)
	{
		int sz=0;
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			if(id[p.first]==-1)
			{
				vt[sz]=p.first;
				id[p.first]=sz++;
			}
			if(id[p.second]==-1)
			{
				vt[sz]=p.second;
				id[p.second]=sz++;
			}
		}
		uf.init(sz);
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			uf.unite(id[p.first],id[p.second]);
		}
		for(int j=0;j<sz;j++) wh[j]=-1;
		for(int j=0;j<sz;j++)
		{
			int v=vt[j];
			int p=uf.find(j);
			if(wh[p]==-1) wh[p]=all++;
			col[v].push_back(wh[p]);
		}
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			id[p.first]=-1;
			id[p.second]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(col[i].size()>=SQR)
		{
			for(int j=0;j<col[i].size();j++) ok[col[i][j]]=true;
			for(int j=0;j<n;j++)
			{
				cnt[j]=0;
				for(int k=0;k<col[j].size();k++) if(ok[col[j][k]]) cnt[j]++;
			}
			for(int j=0;j<tag[i].size();j++)
			{
				P p=tag[i][j];
				int to=p.first;
				if(col[to].size()>=SQR&&to<i) continue;
				ans[p.second]=cnt[to];
			}
			for(int j=0;j<col[i].size();j++) ok[col[i][j]]=false;
		}
	}
	for(int i=0;i<q;i++)
	{
		int l=left[i],r=right[i];
		if(col[l].size()<SQR&&col[r].size()<SQR)
		{
			for(int j=0;j<col[l].size();j++) ok[col[l][j]]=true;
			for(int j=0;j<col[r].size();j++) if(ok[col[r][j]]) ans[i]++;
			for(int j=0;j<col[l].size();j++) ok[col[l][j]]=false;
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}