#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#define SIZE 100005
#define MX 52

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
vector <int> rvec[SIZE];
vector <int> vs;
vector <int> nd[SIZE];
char str[MX];
string dat[SIZE];
bool use[SIZE];
int cmb[SIZE],dist[SIZE];
int dp[SIZE][MX];
int n,m,d;

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<vec[v].size();i++) if(!use[vec[v][i]]) dfs(vec[v][i]);
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	use[v]=true;
	cmb[v]=k;
	nd[k].push_back(v);
	for(int i=0;i<rvec[v].size();i++)
	{
		int to=rvec[v][i];
		if(!use[to]) rdfs(to,k);
	}
}
int scc()
{
	vs.clear();
	memset(use,false,sizeof(use));
 	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	return k;
}
int dfs2(int v,int D)
{
	dist[v]=D;
	int ret=d;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(use[to])
		{
			if(dist[to]==-1) ret=gcd(ret,dfs2(to,D+1));
			else ret=gcd(ret,abs(dist[to]-D-1));
		}
	}
	return ret;
}
int main()
{
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		dat[i]=str;
	}
	int sz=scc();
	memset(use,false,sizeof(use));
	for(int i=sz-1;i>=0;i--)
	{
		for(int j=0;j<nd[i].size();j++)
		{
			use[nd[i][j]]=true;
			dist[nd[i][j]]=-1;
		}
		int v=nd[i][0];
		int cyc=dfs2(v,0);
		for(int j=0;j<cyc;j++)
		{
			int sum=0,mx=0;
			for(int k=0;k<nd[i].size();k++)
			{
				int u=nd[i][k];
				int z=(j+dist[u])%cyc;
				bool up=false;
				for(int l=0;l<d/cyc;l++)
				{
					if(dat[u][z]=='1') up=true;
					for(int s=0;s<vec[u].size();s++)
					{
						int to=vec[u][s];
						if(!use[to]) mx=max(mx,dp[to][(z+1)%d]);
					}
					z+=cyc;
				}
				if(up) sum++;
			}
			for(int k=0;k<nd[i].size();k++)
			{
				int u=nd[i][k];
				int z=(j+dist[u])%cyc;
				for(int l=0;l<d/cyc;l++)
				{
					dp[u][z]=sum+mx;
					z+=cyc;
				}
			}
		}
		for(int j=0;j<nd[i].size();j++) use[nd[i][j]]=false;
	}
	printf("%d\n",dp[0][0]);
	return 0;
}