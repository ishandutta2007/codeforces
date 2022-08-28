#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <functional>
#include <string>
#include <set>
#include <map>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int U[SIZE];
int n,m,H;
vector <int> vec[SIZE];
vector <int> rvec[SIZE];
vector <int> nd[SIZE];
vector <int> vs;
bool use[SIZE];
int cmb[SIZE];
bool bad[SIZE];

void add(int s,int e)
{
	vec[s].push_back(e);
	rvec[e].push_back(s);
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
	for(int i=0;i<rvec[v].size();i++) if(!use[rvec[v][i]]) rdfs(rvec[v][i],k);
}
int scc()
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			if(cmb[to]!=cmb[i])
			{
				bad[cmb[i]]=true;
			}
		}
	}
	return k;
}
int main()
{
	scanf("%d %d %d",&n,&m,&H);
	for(int i=0;i<n;i++) scanf("%d",&U[i]);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		if((U[a]+1)%H==U[b]) add(a,b);
		if((U[b]+1)%H==U[a]) add(b,a);
	}
	int sz=scc();
	int mn=n;
	for(int i=0;i<sz;i++)
	{
		if(!bad[i])
		{
			mn=min(mn,(int) nd[i].size());
		}
	}
	for(int i=0;i<sz;i++)
	{
		if(!bad[i]&&nd[i].size()==mn)
		{
			printf("%d\n",mn);
			for(int j=0;j<nd[i].size();j++)
			{
				if(j!=0) printf(" ");
				printf("%d",nd[i][j]+1);
			}puts("");
			break;
		}
	}
	return 0;
}