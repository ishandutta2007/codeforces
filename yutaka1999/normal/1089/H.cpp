#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

char str[SIZE];
vector <int> vec[SIZE];
vector <int> rvec[SIZE];
vector <int> dag[SIZE];
vector <int> vs;
bool use[SIZE];
int cmb[SIZE];
int down[SIZE],up[SIZE];

int chid(int x)
{
	if(x>0) x--,x*=2;
	else x=-x,x--,x=x*2+1;
	return x;
}
void add(int a,int b)
{
	a=chid(a),b=chid(b);
	vec[a].push_back(b);
	rvec[b].push_back(a);
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
	for(int i=0;i<rvec[v].size();i++) if(!use[rvec[v][i]]) rdfs(rvec[v][i],k);
}
int scc(int n)
{
	vs.clear();
	for(int i=0;i<n;i++) use[i]=false;
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	for(int i=0;i<n;i++) use[i]=false;
	int k=0;
	for(int i=n-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	for(int i=0;i<k;i++) dag[i].clear();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			if(cmb[i]!=cmb[to]) dag[cmb[i]].push_back(cmb[to]);
		}
	}
	return k;
}
void solve()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<2*n;i++)
	{
		vec[i].clear();
		rvec[i].clear();
	}
	scanf("%s",&str);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		add(-a,b);
		add(-b,a);
	}
	int sz=scc(2*n);
	//for(int i=0;i<2*n;i++) printf("%d ",cmb[i]);puts("");
	for(int i=0;i<n;i++)
	{
		if(cmb[2*i]==cmb[2*i+1])
		{
			puts("FALSE");
			return;
		}
	}
	for(int i=0;i<sz;i++) down[i]=up[i]=-1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='A')
		{
			down[cmb[2*i]]=2*i;
			down[cmb[2*i+1]]=2*i+1;
			up[cmb[2*i]]=2*i;
			up[cmb[2*i+1]]=2*i+1;
		}
	}
	for(int i=sz-1;i>=0;i--)
	{
		for(int j=0;j<dag[i].size();j++)
		{
			int to=dag[i][j];
			down[i]=max(down[i],down[to]);
		}
	}
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<dag[i].size();j++)
		{
			int to=dag[i][j];
			up[to]=max(up[to],up[i]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(str[i]=='E')
		{
			if(up[cmb[2*i]]>2*i&&down[cmb[2*i]]>2*i)
			{
				puts("FALSE");
				return;
			}
		}
		else
		{
			if(up[cmb[2*i]]!=2*i||down[cmb[2*i]]!=2*i)
			{
				puts("FALSE");
				return;
			}
		}
	}
	puts("TRUE");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}