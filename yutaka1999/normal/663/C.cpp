#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

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
};
UF uf;
int left[SIZE],right[SIZE];
int tp[SIZE],cnt[SIZE];
int memo[SIZE];
bool use[SIZE];
char str[5];
vector <int> ans;
bool ch;
int n,m;

void solve(int t)
{
	uf.init(2*n+2);
	for(int i=0;i<m;i++)
	{
		if(tp[i]==t)
		{
			uf.unite(left[i],right[i]);
			uf.unite(left[i]+n,right[i]+n);
		}
		else
		{
			uf.unite(left[i],right[i]+n);
			uf.unite(left[i]+n,right[i]);
		}
	}
	for(int i=0;i<n;i++) if(uf.same(i,i+n)) return;
	memset(memo,-1,sizeof(memo));
	memset(cnt,0,sizeof(cnt));
	vector <int> now;
	int sz=0;
	for(int i=0;i<n;i++)
	{
		int p=uf.find(i);
		if(memo[p]==-1)
		{
			memo[p]=sz++;
			int q=uf.find(i+n);
			memo[q]=sz++;
		}
		cnt[memo[p]]++;
	}
	memset(use,false,sizeof(use));
	for(int i=0;i<sz;i+=2)
	{
		//printf("%d : %d %d\n",i,cnt[i],cnt[i+1]);
		if(cnt[i]>=cnt[i+1]) use[i+1]=true;
		else use[i]=true;
	}
	for(int i=0;i<n;i++) if(use[memo[uf.find(i)]]) now.push_back(i);
	if(!ch||ans.size()>=now.size())
	{
		ch=true;
		ans=now;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %s",&left[i],&right[i],str);
		tp[i]=str[0]=='R'?0:1;
		left[i]--,right[i]--;
	}
	ch=false;
	solve(0);
	solve(1);
	if(!ch) puts("-1");
	else
	{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",ans[i]+1);
		}puts("");
	}
	return 0;
}