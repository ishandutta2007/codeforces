#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct edge
{
	int to,rev;
	bool ok;
	edge(int to,int rev,bool ok):to(to),rev(rev),ok(ok){}
};
vector <edge> vec[SIZE];
vector <int> dp[SIZE];
int cnt[SIZE],nd[SIZE];
int n;

bool ok(int x)
{
	while(x>0)
	{
		if(x%10!=4&&x%10!=7) return false;
		x/=10;
	}
	return true;
}
void make(int v=0,int p=-1)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			make(e.to,v);
			nd[v]+=nd[e.to];
		}
	}
}
void dfs(int v=0,int p=-1)
{
	dp[v].resize(vec[v].size());
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v);
			if(e.ok) dp[v][i]=nd[e.to];
			else dp[v][i]=cnt[e.to];
			cnt[v]+=dp[v][i];
		}
	}
}
ll dfs2(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to==p)
		{
			if(e.ok) dp[v][i]=n-nd[v];
			else dp[v][i]=cnt[e.to]-dp[e.to][e.rev];
			cnt[v]+=dp[v][i];
			break;
		}
	}
	ll ret=(ll) cnt[v]*(ll) (cnt[v]-1);
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) ret+=dfs2(e.to,v);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		bool u=ok(c);
		int sa=vec[a].size(),sb=vec[b].size();
		vec[a].push_back(edge(b,sb,u));
		vec[b].push_back(edge(a,sa,u));
	}
	make();
	dfs();
	printf("%I64d\n",dfs2());
	return 0;
}